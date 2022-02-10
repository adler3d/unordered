//t_inl_file_lexem
//time = 103.02 ms.
class t_inl_file
{
public:
  //===>>===i_class_stat_visitor
  class i_class_stat;
  class t_access_mod_class_stat;
  class t_fv_class_stat;
  class t_typedef_class_stat;
  class t_dtor_class_stat;
  class t_ctor_class_stat;
  class t_oper_cast_class_stat;
  class t_common_oper_class_stat;
  class t_namespace_class_stat;
  class t_template_class_stat;
  class t_enum_class_stat;
  class t_using_class_stat;
  class t_pragma_class_stat;
  class t_include_class_stat;
  class t_preproc_if_class_stat;
  class t_preproc_else_class_stat;
  class t_preproc_endif_class_stat;
  class t_define_class_stat;
  class t_undef_class_stat;
  class t_sep_class_stat;
  class t_null_class_stat;
  class t_class_class_stat;
  class i_class_stat_visitor
  {
  public:
    typedef t_inl_file::i_class_stat i_class_stat;
  public:
    virtual void Do(t_access_mod_class_stat*p)=0;
    virtual void Do(t_fv_class_stat*p)=0;
    virtual void Do(t_typedef_class_stat*p)=0;
    virtual void Do(t_dtor_class_stat*p)=0;
    virtual void Do(t_ctor_class_stat*p)=0;
    virtual void Do(t_oper_cast_class_stat*p)=0;
    virtual void Do(t_common_oper_class_stat*p)=0;
    virtual void Do(t_namespace_class_stat*p)=0;
    virtual void Do(t_template_class_stat*p)=0;
    virtual void Do(t_enum_class_stat*p)=0;
    virtual void Do(t_using_class_stat*p)=0;
    virtual void Do(t_pragma_class_stat*p)=0;
    virtual void Do(t_include_class_stat*p)=0;
    virtual void Do(t_preproc_if_class_stat*p)=0;
    virtual void Do(t_preproc_else_class_stat*p)=0;
    virtual void Do(t_preproc_endif_class_stat*p)=0;
    virtual void Do(t_define_class_stat*p)=0;
    virtual void Do(t_undef_class_stat*p)=0;
    virtual void Do(t_sep_class_stat*p)=0;
    virtual void Do(t_null_class_stat*p)=0;
    virtual void Do(t_class_class_stat*p)=0;
  public:
    typedef t_inl_file::t_access_mod_class_stat t_access_mod_class_stat;
    typedef t_inl_file::t_fv_class_stat t_fv_class_stat;
    typedef t_inl_file::t_typedef_class_stat t_typedef_class_stat;
    typedef t_inl_file::t_dtor_class_stat t_dtor_class_stat;
    typedef t_inl_file::t_ctor_class_stat t_ctor_class_stat;
    typedef t_inl_file::t_oper_cast_class_stat t_oper_cast_class_stat;
    typedef t_inl_file::t_common_oper_class_stat t_common_oper_class_stat;
    typedef t_inl_file::t_namespace_class_stat t_namespace_class_stat;
    typedef t_inl_file::t_template_class_stat t_template_class_stat;
    typedef t_inl_file::t_enum_class_stat t_enum_class_stat;
    typedef t_inl_file::t_using_class_stat t_using_class_stat;
    typedef t_inl_file::t_pragma_class_stat t_pragma_class_stat;
    typedef t_inl_file::t_include_class_stat t_include_class_stat;
    typedef t_inl_file::t_preproc_if_class_stat t_preproc_if_class_stat;
    typedef t_inl_file::t_preproc_else_class_stat t_preproc_else_class_stat;
    typedef t_inl_file::t_preproc_endif_class_stat t_preproc_endif_class_stat;
    typedef t_inl_file::t_define_class_stat t_define_class_stat;
    typedef t_inl_file::t_undef_class_stat t_undef_class_stat;
    typedef t_inl_file::t_sep_class_stat t_sep_class_stat;
    typedef t_inl_file::t_null_class_stat t_null_class_stat;
    typedef t_inl_file::t_class_class_stat t_class_class_stat;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(t_access_mod_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_fv_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_typedef_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_dtor_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_ctor_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_oper_cast_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_common_oper_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_namespace_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_template_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_enum_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_using_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_pragma_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_include_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_preproc_if_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_preproc_else_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_preproc_endif_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_define_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_undef_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_sep_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_null_class_stat*p)
      {
        ptr=get(p);
      } void Do(t_class_class_stat*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(i_class_stat*p)
    {
      if (!p)return nullptr;
      Is<TYPE,i_class_stat_visitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
  //===<<===i_class_stat_visitor
  //class t_visitor:public t_inl_file::i_class_stat_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_access_mod_class_stat*p){}
  //  void Do(t_fv_class_stat*p){}
  //  void Do(t_typedef_class_stat*p){}
  //  void Do(t_dtor_class_stat*p){}
  //  void Do(t_ctor_class_stat*p){}
  //  void Do(t_oper_cast_class_stat*p){}
  //  void Do(t_common_oper_class_stat*p){}
  //  void Do(t_namespace_class_stat*p){}
  //  void Do(t_template_class_stat*p){}
  //  void Do(t_enum_class_stat*p){}
  //  void Do(t_using_class_stat*p){}
  //  void Do(t_pragma_class_stat*p){}
  //  void Do(t_include_class_stat*p){}
  //  void Do(t_preproc_if_class_stat*p){}
  //  void Do(t_preproc_else_class_stat*p){}
  //  void Do(t_preproc_endif_class_stat*p){}
  //  void Do(t_define_class_stat*p){}
  //  void Do(t_undef_class_stat*p){}
  //  void Do(t_sep_class_stat*p){}
  //  void Do(t_null_class_stat*p){}
  //  void Do(t_class_class_stat*p){}
  //};
public:
  class i_class_stat
  {
    //=====+>>>>>i_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef i_class_stat SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
    }
    //==Declaration Constructors==//
  public:
    i_class_stat(const i_class_stat&)=delete;
    i_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    i_class_stat(i_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(i_class_stat&&_Right)
    {
      if (&_Right==this)return;
      {
      }
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="i_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "i_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====i_class_stat
  public:
    typedef i_class_stat_visitor i_visitor;
    virtual void Use(i_visitor&A)
    {
      QapDebugMsg("no way.");/*A.Do(this);*/
    }
  public:
    virtual bool go(i_dev&dev)
    {
      QapDebugMsg("no way.");
      return false;
    };
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      template<int>
      bool load()
      {
        //[Line](=>)
        go_for<t_access_mod_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_fv_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_typedef_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_dtor_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_ctor_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_oper_cast_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_common_oper_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_namespace_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_template_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_enum_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_using_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_pragma_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_include_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_preproc_if_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_preproc_else_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_preproc_endif_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_define_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_undef_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_sep_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_null_class_stat>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_class_class_stat>();
        //[Line](<=)
        (void)count;
        (void)first_id;
        (void)out_arr;
        (void)this;
        main();
        return scope.ok;
      }
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        vector<t_out_rec> out_arr;
        static int out_arr_size=0;
        out_arr.reserve(out_arr_size);
        t_fallback scope(dev,__FUNCTION__);
        int count=0;
        int first_id=-1;
        auto&Env=dev.getEnv();
        static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
        t_poly_tool::go_poly<SelfClass> solver_impl=
        {
          out_arr,dev,ref,scope,count,first_id,strbasetype,Env
        };
        t_poly_impl&solver=(t_poly_impl&)solver_impl;
        solver.load<0>();
        out_arr_size=out_arr.size();
        return scope.ok;
      }
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
      {
        t_fallback scope(dev,__FUNCTION__);
        bool&ok=scope.ok;
        if (!std::is_polymorphic<SelfClass>::value)if (!ref)
          {
            return false;
          }
        if (!ref)return false;
        QapAssert(ref);
        auto*p=ref.get();
        ok=p->go(dev);
        return ok;
      }
    };
  };
public:
  //===>>===i_expr_visitor
  class i_expr;
  class t_call_expr;
  class t_bool_expr;
  class t_string_expr;
  class t_char_expr;
  class t_num_expr;
  class t_real_expr;
  class t_nullptr_expr;
  class t_or_expr;
  class t_hex_expr;
  class t_var_expr;
  class i_expr_visitor
  {
  public:
    typedef t_inl_file::i_expr i_expr;
  public:
    virtual void Do(t_call_expr*p)=0;
    virtual void Do(t_bool_expr*p)=0;
    virtual void Do(t_string_expr*p)=0;
    virtual void Do(t_char_expr*p)=0;
    virtual void Do(t_num_expr*p)=0;
    virtual void Do(t_real_expr*p)=0;
    virtual void Do(t_nullptr_expr*p)=0;
    virtual void Do(t_or_expr*p)=0;
    virtual void Do(t_hex_expr*p)=0;
    virtual void Do(t_var_expr*p)=0;
  public:
    typedef t_inl_file::t_call_expr t_call_expr;
    typedef t_inl_file::t_bool_expr t_bool_expr;
    typedef t_inl_file::t_string_expr t_string_expr;
    typedef t_inl_file::t_char_expr t_char_expr;
    typedef t_inl_file::t_num_expr t_num_expr;
    typedef t_inl_file::t_real_expr t_real_expr;
    typedef t_inl_file::t_nullptr_expr t_nullptr_expr;
    typedef t_inl_file::t_or_expr t_or_expr;
    typedef t_inl_file::t_hex_expr t_hex_expr;
    typedef t_inl_file::t_var_expr t_var_expr;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(t_call_expr*p)
      {
        ptr=get(p);
      } void Do(t_bool_expr*p)
      {
        ptr=get(p);
      } void Do(t_string_expr*p)
      {
        ptr=get(p);
      } void Do(t_char_expr*p)
      {
        ptr=get(p);
      } void Do(t_num_expr*p)
      {
        ptr=get(p);
      } void Do(t_real_expr*p)
      {
        ptr=get(p);
      } void Do(t_nullptr_expr*p)
      {
        ptr=get(p);
      } void Do(t_or_expr*p)
      {
        ptr=get(p);
      } void Do(t_hex_expr*p)
      {
        ptr=get(p);
      } void Do(t_var_expr*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(i_expr*p)
    {
      if (!p)return nullptr;
      Is<TYPE,i_expr_visitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
  //===<<===i_expr_visitor
  //class t_visitor:public t_inl_file::i_expr_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_call_expr*p){}
  //  void Do(t_bool_expr*p){}
  //  void Do(t_string_expr*p){}
  //  void Do(t_char_expr*p){}
  //  void Do(t_num_expr*p){}
  //  void Do(t_real_expr*p){}
  //  void Do(t_nullptr_expr*p){}
  //  void Do(t_or_expr*p){}
  //  void Do(t_hex_expr*p){}
  //  void Do(t_var_expr*p){}
  //};
public:
  class i_expr
  {
    //=====+>>>>>i_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef i_expr SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
    }
    //==Declaration Constructors==//
  public:
    i_expr(const i_expr&)=delete;
    i_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    i_expr(i_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(i_expr&&_Right)
    {
      if (&_Right==this)return;
      {
      }
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="i_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "i_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====i_expr
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A)
    {
      QapDebugMsg("no way.");/*A.Do(this);*/
    }
  public:
    virtual bool go(i_dev&dev)
    {
      QapDebugMsg("no way.");
      return false;
    };
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      template<int>
      bool load()
      {
        //[Line](=>)
        go_for<t_call_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_bool_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_string_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_char_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_num_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_real_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_nullptr_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_or_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_hex_expr>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_var_expr>();
        //[Line](<=)
        (void)count;
        (void)first_id;
        (void)out_arr;
        (void)this;
        main();
        return scope.ok;
      }
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        vector<t_out_rec> out_arr;
        static int out_arr_size=0;
        out_arr.reserve(out_arr_size);
        t_fallback scope(dev,__FUNCTION__);
        int count=0;
        int first_id=-1;
        auto&Env=dev.getEnv();
        static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
        t_poly_tool::go_poly<SelfClass> solver_impl=
        {
          out_arr,dev,ref,scope,count,first_id,strbasetype,Env
        };
        t_poly_impl&solver=(t_poly_impl&)solver_impl;
        solver.load<0>();
        out_arr_size=out_arr.size();
        return scope.ok;
      }
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
      {
        t_fallback scope(dev,__FUNCTION__);
        bool&ok=scope.ok;
        if (!std::is_polymorphic<SelfClass>::value)if (!ref)
          {
            return false;
          }
        if (!ref)return false;
        QapAssert(ref);
        auto*p=ref.get();
        ok=p->go(dev);
        return ok;
      }
    };
  };
public:
  //===>>===i_func_body_visitor
  class i_func_body;
  class t_zero_func_body;
  class t_null_func_body;
  class t_delete_func_body;
  class t_impl_func_body;
  class i_func_body_visitor
  {
  public:
    typedef t_inl_file::i_func_body i_func_body;
  public:
    virtual void Do(t_zero_func_body*p)=0;
    virtual void Do(t_null_func_body*p)=0;
    virtual void Do(t_delete_func_body*p)=0;
    virtual void Do(t_impl_func_body*p)=0;
  public:
    typedef t_inl_file::t_zero_func_body t_zero_func_body;
    typedef t_inl_file::t_null_func_body t_null_func_body;
    typedef t_inl_file::t_delete_func_body t_delete_func_body;
    typedef t_inl_file::t_impl_func_body t_impl_func_body;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor
    {
      TYPE*ptr;
      Is():ptr(nullptr) {}
public:
      template<class U>static TYPE*get(U*p)
      {
        return nullptr;
      }
      template<>static TYPE*get<TYPE>(TYPE*p)
      {
        return p;
      }
public:
      void Do(t_zero_func_body*p)
      {
        ptr=get(p);
      } void Do(t_null_func_body*p)
      {
        ptr=get(p);
      } void Do(t_delete_func_body*p)
      {
        ptr=get(p);
      } void Do(t_impl_func_body*p)
      {
        ptr=get(p);
      }
    };
    template<class TYPE>
    static TYPE*UberCast(i_func_body*p)
    {
      if (!p)return nullptr;
      Is<TYPE,i_func_body_visitor> IS;
      p->Use(IS);
      return IS.ptr;
    }
  };
  //===<<===i_func_body_visitor
  //class t_visitor:public t_inl_file::i_func_body_visitor{
  //public:
  //  class t_dev{
  //  public:
  //  };
  //  t_dev&dev;
  //  t_visitor(t_dev&dev):dev(dev){}
  //public:
  //  void Do(t_zero_func_body*p){}
  //  void Do(t_null_func_body*p){}
  //  void Do(t_delete_func_body*p){}
  //  void Do(t_impl_func_body*p){}
  //};
public:
  class i_func_body
  {
    //=====+>>>>>i_func_body
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef i_func_body SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
    }
    //==Declaration Constructors==//
  public:
    i_func_body(const i_func_body&)=delete;
    i_func_body()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    i_func_body(i_func_body&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(i_func_body&&_Right)
    {
      if (&_Right==this)return;
      {
      }
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="i_func_body";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "i_func_body";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====i_func_body
  public:
    typedef i_func_body_visitor i_visitor;
    virtual void Use(i_visitor&A)
    {
      QapDebugMsg("no way.");/*A.Do(this);*/
    }
  public:
    virtual bool go(i_dev&dev)
    {
      QapDebugMsg("no way.");
      return false;
    };
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      template<int>
      bool load()
      {
        //[Line](=>)
        go_for<t_zero_func_body>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_null_func_body>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_delete_func_body>();
        //[Line](<=)
        //[Line](=>)
        go_for<t_impl_func_body>();
        //[Line](<=)
        (void)count;
        (void)first_id;
        (void)out_arr;
        (void)this;
        main();
        return scope.ok;
      }
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        vector<t_out_rec> out_arr;
        static int out_arr_size=0;
        out_arr.reserve(out_arr_size);
        t_fallback scope(dev,__FUNCTION__);
        int count=0;
        int first_id=-1;
        auto&Env=dev.getEnv();
        static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
        t_poly_tool::go_poly<SelfClass> solver_impl=
        {
          out_arr,dev,ref,scope,count,first_id,strbasetype,Env
        };
        t_poly_impl&solver=(t_poly_impl&)solver_impl;
        solver.load<0>();
        out_arr_size=out_arr.size();
        return scope.ok;
      }
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
      {
        t_fallback scope(dev,__FUNCTION__);
        bool&ok=scope.ok;
        if (!std::is_polymorphic<SelfClass>::value)if (!ref)
          {
            return false;
          }
        if (!ref)return false;
        QapAssert(ref);
        auto*p=ref.get();
        ok=p->go(dev);
        return ok;
      }
    };
  };
  class t_lev03
  {
    //=====+>>>>>t_lev03
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev03 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string oper;
    TAutoPtr<i_expr> expr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->oper);
      detail::FieldTryDoReset(this->expr);
    }
    //==Declaration Constructors==//
  public:
    t_lev03(const t_lev03&)=delete;
    t_lev03()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev03(t_lev03&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev03&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->oper=std::move(_Right.oper);
      this->expr=std::move(_Right.expr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev03";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<i_expr>>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev03";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev03
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-,!,~",","));
      O+=dev.go_any_str_from_vec(oper,g_static_var_0);
      if (!ok)return ok;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev05
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev05 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,%",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev05 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev03 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev05
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev05 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev03 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev05(const t_lev05&)=delete;
    t_lev05()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev05(t_lev05&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev05&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev05";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev05";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev05
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev06
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev06 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev06 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev05 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev06
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev06 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev05 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev06(const t_lev06&)=delete;
    t_lev06()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev06(t_lev06&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev06&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev06";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev06";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev06
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev07
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev07 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<<,>>",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev07 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev06 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev07
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev07 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev06 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev07(const t_lev07&)=delete;
    t_lev07()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev07(t_lev07&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev07&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev07";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev07";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev07
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev08
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev08 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<,<=,>,>=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev08 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev07 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev07>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev08
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev08 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev07 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev08(const t_lev08&)=delete;
    t_lev08()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev08(t_lev08&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev08&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev08";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev07>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev08";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev08
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev09
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev09 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("==,!=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev09 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev08 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev08>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev09
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev09 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev08 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev09(const t_lev09&)=delete;
    t_lev09()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev09(t_lev09&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev09&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev09";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev08>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev09";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev09
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev10
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev10 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev10 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev09 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev10
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev10 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev09 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev10(const t_lev10&)=delete;
    t_lev10()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev10(t_lev10&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev10&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev10";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev10";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev10
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev11
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev11 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("^",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev11 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev10 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev11
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev11 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev10 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev11(const t_lev11&)=delete;
    t_lev11()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev11(t_lev11&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev11&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev11";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev11";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev11
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev12
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev12 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("|",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev12 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev11 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev12
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev12 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev11 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev12(const t_lev12&)=delete;
    t_lev12()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev12(t_lev12&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev12&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev12";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev12";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev12
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev13
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev13 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev13 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev12 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev13
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev13 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev12 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev13(const t_lev13&)=delete;
    t_lev13()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev13(t_lev13&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev13&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev13";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev13";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev13
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_lev14
  {
  public:
    class t_oper
    {
      //=====+>>>>>t_oper
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev14 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_oper SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_oper(const t_oper&)=delete;
      t_oper()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_oper(t_oper&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_oper&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_oper";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_oper";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("||",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_lev14 OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_oper oper;
      t_lev13 expr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->expr);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->oper=std::move(_Right.oper);
        this->expr=std::move(_Right.expr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if (!ok)return ok;
        D+=dev.go_auto(expr);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_lev14
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_lev14 SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev13 expr;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_lev14(const t_lev14&)=delete;
    t_lev14()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_lev14(t_lev14&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_lev14&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->expr=std::move(_Right.expr);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_lev14";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_lev14";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_lev14
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_expr
  {
    //=====+>>>>>t_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_expr SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_lev14 body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_expr(const t_expr&)=delete;
    t_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_expr(t_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_expr&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_lev14>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_expr
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_access_mod
  {
    //=====+>>>>>t_access_mod
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_access_mod SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string keyword;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->keyword);
    }
    //==Declaration Constructors==//
  public:
    t_access_mod(const t_access_mod&)=delete;
    t_access_mod()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_access_mod(t_access_mod&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_access_mod&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->keyword=std::move(_Right.keyword);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_access_mod";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_access_mod";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_access_mod
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("public,protected,private",","));
      D+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_access_mod_class_stat:public i_class_stat
  {
    //=====+>>>>>t_access_mod_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_access_mod_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_access_mod mod;
    t_sep sep;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->mod);
      detail::FieldTryDoReset(this->sep);
    }
    //==Declaration Constructors==//
  public:
    t_access_mod_class_stat(const t_access_mod_class_stat&)=delete;
    t_access_mod_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_access_mod_class_stat(t_access_mod_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_access_mod_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->mod=std::move(_Right.mod);
      this->sep=std::move(_Right.sep);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_access_mod_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_access_mod>::GetRTTI(RTTI),"mod",int(&(((SelfClass*)nullptr)->*(&SelfClass::mod))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_access_mod_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_access_mod_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(mod);
      if (!ok)return ok;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      M+=dev.go_const(":");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_raw_func_body
  {
  public:
    //===>>===i_item_visitor
    class i_item;
    class t_sep_item;
    class t_s_item;
    class t_c_item;
    class t_code_item;
    class t_div_item;
    class t_block_item;
    class i_item_visitor
    {
    public:
      typedef t_raw_func_body::i_item i_item;
    public:
      virtual void Do(t_sep_item*p)=0;
      virtual void Do(t_s_item*p)=0;
      virtual void Do(t_c_item*p)=0;
      virtual void Do(t_code_item*p)=0;
      virtual void Do(t_div_item*p)=0;
      virtual void Do(t_block_item*p)=0;
    public:
      typedef t_raw_func_body::t_sep_item t_sep_item;
      typedef t_raw_func_body::t_s_item t_s_item;
      typedef t_raw_func_body::t_c_item t_c_item;
      typedef t_raw_func_body::t_code_item t_code_item;
      typedef t_raw_func_body::t_div_item t_div_item;
      typedef t_raw_func_body::t_block_item t_block_item;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_sep_item*p)
        {
          ptr=get(p);
        } void Do(t_s_item*p)
        {
          ptr=get(p);
        } void Do(t_c_item*p)
        {
          ptr=get(p);
        } void Do(t_code_item*p)
        {
          ptr=get(p);
        } void Do(t_div_item*p)
        {
          ptr=get(p);
        } void Do(t_block_item*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_item*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_item_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
    //===<<===i_item_visitor
    //class t_visitor:public t_raw_func_body::i_item_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_sep_item*p){}
    //  void Do(t_s_item*p){}
    //  void Do(t_c_item*p){}
    //  void Do(t_code_item*p){}
    //  void Do(t_div_item*p){}
    //  void Do(t_block_item*p){}
    //};
  public:
    class i_item
    {
      //=====+>>>>>i_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_raw_func_body OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef i_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
      }
      //==Declaration Constructors==//
    public:
      i_item(const i_item&)=delete;
      i_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      i_item(i_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(i_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="i_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "i_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====i_item
    public:
      typedef i_item_visitor i_visitor;
      virtual void Use(i_visitor&A)
      {
        QapDebugMsg("no way.");/*A.Do(this);*/
      }
    public:
      virtual bool go(i_dev&dev)
      {
        QapDebugMsg("no way.");
        return false;
      };
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        template<int>
        bool load()
        {
          //[Line](=>)
          go_for<t_sep_item>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_s_item>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_c_item>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_code_item>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_div_item>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_block_item>();
          //[Line](<=)
          (void)count;
          (void)first_id;
          (void)out_arr;
          (void)this;
          main();
          return scope.ok;
        }
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          vector<t_out_rec> out_arr;
          static int out_arr_size=0;
          out_arr.reserve(out_arr_size);
          t_fallback scope(dev,__FUNCTION__);
          int count=0;
          int first_id=-1;
          auto&Env=dev.getEnv();
          static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
          t_poly_tool::go_poly<SelfClass> solver_impl=
          {
            out_arr,dev,ref,scope,count,first_id,strbasetype,Env
          };
          t_poly_impl&solver=(t_poly_impl&)solver_impl;
          solver.load<0>();
          out_arr_size=out_arr.size();
          return scope.ok;
        }
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          t_fallback scope(dev,__FUNCTION__);
          bool&ok=scope.ok;
          if (!std::is_polymorphic<SelfClass>::value)if (!ref)
            {
              return false;
            }
          if (!ref)return false;
          QapAssert(ref);
          auto*p=ref.get();
          ok=p->go(dev);
          return ok;
        }
      };
    };
    class t_sep_item:public i_item
    {
      //=====+>>>>>t_sep_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_raw_func_body OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_sep_item SelfClass;
    public:
      typedef i_item ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->sep);
      }
      //==Declaration Constructors==//
    public:
      t_sep_item(const t_sep_item&)=delete;
      t_sep_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_sep_item(t_sep_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_sep_item&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_item(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_item::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->sep=std::move(_Right.sep);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_sep_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_sep_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_sep_item
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(sep);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_s_item:public i_item
    {
      //=====+>>>>>t_s_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_raw_func_body OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_s_item SelfClass;
    public:
      typedef i_item ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_s_item(const t_s_item&)=delete;
      t_s_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_s_item(t_s_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_s_item&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_item(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_item::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_s_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_s_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_s_item
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_str<t_str_item::t_impl>(value);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_c_item:public i_item
    {
      //=====+>>>>>t_c_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_raw_func_body OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_c_item SelfClass;
    public:
      typedef i_item ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_c_item(const t_c_item&)=delete;
      t_c_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_c_item(t_c_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_c_item&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_item(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_item::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_c_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_c_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_c_item
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_str<t_char_item::t_impl>(value);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_code_item:public i_item
    {
      //=====+>>>>>t_code_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_raw_func_body OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_code_item SelfClass;
    public:
      typedef i_item ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string code;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->code);
      }
      //==Declaration Constructors==//
    public:
      t_code_item(const t_code_item&)=delete;
      t_code_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_code_item(t_code_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_code_item&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_item(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_item::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->code=std::move(_Right.code);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_code_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"code",int(&(((SelfClass*)nullptr)->*(&SelfClass::code))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_code_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_code_item
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("AZaz09")+"+-*?<>[](),.:;~!@#$_=%^&\\|");
        D+=dev.go_any(code,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_div_item:public i_item
    {
      //=====+>>>>>t_div_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_raw_func_body OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_div_item SelfClass;
    public:
      typedef i_item ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
      }
      //==Declaration Constructors==//
    public:
      t_div_item(const t_div_item&)=delete;
      t_div_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_div_item(t_div_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_div_item&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_item(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_item::operator=(std::move(_Right));
          //[Line](<=)
        }
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_div_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_div_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_div_item
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("/");
        if (!ok)return ok;
        return ok;
      }
    };
    class t_block_item:public i_item
    {
      //=====+>>>>>t_block_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_raw_func_body OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_block_item SelfClass;
    public:
      typedef i_item ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      TAutoPtr<t_raw_func_body> body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_block_item(const t_block_item&)=delete;
      t_block_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_block_item(t_block_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_block_item&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_item(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_item::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_block_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_raw_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_block_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_block_item
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_raw_func_body
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_raw_func_body SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    vector<TAutoPtr<i_item>> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->sep);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_raw_func_body(const t_raw_func_body&)=delete;
    t_raw_func_body()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_raw_func_body(t_raw_func_body&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_raw_func_body&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_raw_func_body";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_item>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_sep_item>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_s_item>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_c_item>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_code_item>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_div_item>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_block_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_raw_func_body";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_raw_func_body
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{");
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      M+=dev.go_const("}");
      if (!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_raw_func_body::TYPE TYPE;
    //  F(i_item);
    //  F(t_sep_item);
    //  F(t_s_item);
    //  F(t_c_item);
    //  F(t_code_item);
    //  F(t_div_item);
    //  F(t_block_item);
    //  #undef F
    //public:
    //  void Do(t_sep_item&ref){}
    //  void Do(t_s_item&ref){}
    //  void Do(t_c_item&ref){}
    //  void Do(t_code_item&ref){}
    //  void Do(t_div_item&ref){}
    //  void Do(t_block_item&ref){}
    //};
  };
  class t_func_path
  {
  public:
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_func_path OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string value;
      t_sep sep0;
      t_sep sep1;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->value);
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->sep1);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->value=std::move(_Right.value);
        this->sep0=std::move(_Right.sep0);
        this->sep1=std::move(_Right.sep1);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_str<t_name>(value);
        if (!ok)return ok;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_const("::");
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_func_path
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_func_path SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_func_path(const t_func_path&)=delete;
    t_func_path()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_func_path(t_func_path&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_func_path&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_func_path";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_func_path";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_func_path
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(arr);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_fv_class_stat:public i_class_stat
  {
  public:
    class t_type_expr
    {
    public:
      //===>>===i_name_part_visitor
      class i_name_part;
      class t_brackets_name_part;
      class t_raw_name_part;
      class i_name_part_visitor
      {
      public:
        typedef t_type_expr::i_name_part i_name_part;
      public:
        virtual void Do(t_brackets_name_part*p)=0;
        virtual void Do(t_raw_name_part*p)=0;
      public:
        typedef t_type_expr::t_brackets_name_part t_brackets_name_part;
        typedef t_type_expr::t_raw_name_part t_raw_name_part;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor
        {
          TYPE*ptr;
          Is():ptr(nullptr) {}
public:
          template<class U>static TYPE*get(U*p)
          {
            return nullptr;
          }
          template<>static TYPE*get<TYPE>(TYPE*p)
          {
            return p;
          }
public:
          void Do(t_brackets_name_part*p)
          {
            ptr=get(p);
          } void Do(t_raw_name_part*p)
          {
            ptr=get(p);
          }
        };
        template<class TYPE>
        static TYPE*UberCast(i_name_part*p)
        {
          if (!p)return nullptr;
          Is<TYPE,i_name_part_visitor> IS;
          p->Use(IS);
          return IS.ptr;
        }
      };
      //===<<===i_name_part_visitor
      //class t_visitor:public t_type_expr::i_name_part_visitor{
      //public:
      //  class t_dev{
      //  public:
      //  };
      //  t_dev&dev;
      //  t_visitor(t_dev&dev):dev(dev){}
      //public:
      //  void Do(t_brackets_name_part*p){}
      //  void Do(t_raw_name_part*p){}
      //};
    public:
      class i_name_part
      {
        //=====+>>>>>i_name_part
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef i_name_part SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
        }
        //==Declaration Constructors==//
      public:
        i_name_part(const i_name_part&)=delete;
        i_name_part()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        i_name_part(i_name_part&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(i_name_part&&_Right)
        {
          if (&_Right==this)return;
          {
          }
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="i_name_part";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "i_name_part";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====i_name_part
      public:
        typedef i_name_part_visitor i_visitor;
        virtual void Use(i_visitor&A)
        {
          QapDebugMsg("no way.");/*A.Do(this);*/
        }
      public:
        virtual bool go(i_dev&dev)
        {
          QapDebugMsg("no way.");
          return false;
        };
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          template<int>
          bool load()
          {
            //[Line](=>)
            go_for<t_brackets_name_part>();
            //[Line](<=)
            //[Line](=>)
            go_for<t_raw_name_part>();
            //[Line](<=)
            (void)count;
            (void)first_id;
            (void)out_arr;
            (void)this;
            main();
            return scope.ok;
          }
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            vector<t_out_rec> out_arr;
            static int out_arr_size=0;
            out_arr.reserve(out_arr_size);
            t_fallback scope(dev,__FUNCTION__);
            int count=0;
            int first_id=-1;
            auto&Env=dev.getEnv();
            static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
            t_poly_tool::go_poly<SelfClass> solver_impl=
            {
              out_arr,dev,ref,scope,count,first_id,strbasetype,Env
            };
            t_poly_impl&solver=(t_poly_impl&)solver_impl;
            solver.load<0>();
            out_arr_size=out_arr.size();
            return scope.ok;
          }
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            t_fallback scope(dev,__FUNCTION__);
            bool&ok=scope.ok;
            if (!std::is_polymorphic<SelfClass>::value)if (!ref)
              {
                return false;
              }
            if (!ref)return false;
            QapAssert(ref);
            auto*p=ref.get();
            ok=p->go(dev);
            return ok;
          }
        };
      };
    public:
      //===>>===i_func_param_visitor
      class i_func_param;
      class t_pfunc_func_param;
      class t_var_args_func_param;
      class t_type_func_param;
      class t_expr_func_param;
      class i_func_param_visitor
      {
      public:
        typedef t_type_expr::i_func_param i_func_param;
      public:
        virtual void Do(t_pfunc_func_param*p)=0;
        virtual void Do(t_var_args_func_param*p)=0;
        virtual void Do(t_type_func_param*p)=0;
        virtual void Do(t_expr_func_param*p)=0;
      public:
        typedef t_type_expr::t_pfunc_func_param t_pfunc_func_param;
        typedef t_type_expr::t_var_args_func_param t_var_args_func_param;
        typedef t_type_expr::t_type_func_param t_type_func_param;
        typedef t_type_expr::t_expr_func_param t_expr_func_param;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor
        {
          TYPE*ptr;
          Is():ptr(nullptr) {}
public:
          template<class U>static TYPE*get(U*p)
          {
            return nullptr;
          }
          template<>static TYPE*get<TYPE>(TYPE*p)
          {
            return p;
          }
public:
          void Do(t_pfunc_func_param*p)
          {
            ptr=get(p);
          } void Do(t_var_args_func_param*p)
          {
            ptr=get(p);
          } void Do(t_type_func_param*p)
          {
            ptr=get(p);
          } void Do(t_expr_func_param*p)
          {
            ptr=get(p);
          }
        };
        template<class TYPE>
        static TYPE*UberCast(i_func_param*p)
        {
          if (!p)return nullptr;
          Is<TYPE,i_func_param_visitor> IS;
          p->Use(IS);
          return IS.ptr;
        }
      };
      //===<<===i_func_param_visitor
      //class t_visitor:public t_type_expr::i_func_param_visitor{
      //public:
      //  class t_dev{
      //  public:
      //  };
      //  t_dev&dev;
      //  t_visitor(t_dev&dev):dev(dev){}
      //public:
      //  void Do(t_pfunc_func_param*p){}
      //  void Do(t_var_args_func_param*p){}
      //  void Do(t_type_func_param*p){}
      //  void Do(t_expr_func_param*p){}
      //};
    public:
      class i_func_param
      {
        //=====+>>>>>i_func_param
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef i_func_param SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
        }
        //==Declaration Constructors==//
      public:
        i_func_param(const i_func_param&)=delete;
        i_func_param()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        i_func_param(i_func_param&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(i_func_param&&_Right)
        {
          if (&_Right==this)return;
          {
          }
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="i_func_param";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "i_func_param";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====i_func_param
      public:
        typedef i_func_param_visitor i_visitor;
        virtual void Use(i_visitor&A)
        {
          QapDebugMsg("no way.");/*A.Do(this);*/
        }
      public:
        virtual bool go(i_dev&dev)
        {
          QapDebugMsg("no way.");
          return false;
        };
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          template<int>
          bool load()
          {
            //[Line](=>)
            go_for<t_pfunc_func_param>();
            //[Line](<=)
            //[Line](=>)
            go_for<t_var_args_func_param>();
            //[Line](<=)
            //[Line](=>)
            go_for<t_type_func_param>();
            //[Line](<=)
            //[Line](=>)
            go_for<t_expr_func_param>();
            //[Line](<=)
            (void)count;
            (void)first_id;
            (void)out_arr;
            (void)this;
            main();
            return scope.ok;
          }
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            vector<t_out_rec> out_arr;
            static int out_arr_size=0;
            out_arr.reserve(out_arr_size);
            t_fallback scope(dev,__FUNCTION__);
            int count=0;
            int first_id=-1;
            auto&Env=dev.getEnv();
            static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
            t_poly_tool::go_poly<SelfClass> solver_impl=
            {
              out_arr,dev,ref,scope,count,first_id,strbasetype,Env
            };
            t_poly_impl&solver=(t_poly_impl&)solver_impl;
            solver.load<0>();
            out_arr_size=out_arr.size();
            return scope.ok;
          }
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            t_fallback scope(dev,__FUNCTION__);
            bool&ok=scope.ok;
            if (!std::is_polymorphic<SelfClass>::value)if (!ref)
              {
                return false;
              }
            if (!ref)return false;
            QapAssert(ref);
            auto*p=ref.get();
            ok=p->go(dev);
            return ok;
          }
        };
      };
    public:
      //===>>===i_func_param_value_visitor
      class i_func_param_value;
      class t_expr_ext;
      class t_func_ref_ext;
      class i_func_param_value_visitor
      {
      public:
        typedef t_type_expr::i_func_param_value i_func_param_value;
      public:
        virtual void Do(t_expr_ext*p)=0;
        virtual void Do(t_func_ref_ext*p)=0;
      public:
        typedef t_type_expr::t_expr_ext t_expr_ext;
        typedef t_type_expr::t_func_ref_ext t_func_ref_ext;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor
        {
          TYPE*ptr;
          Is():ptr(nullptr) {}
public:
          template<class U>static TYPE*get(U*p)
          {
            return nullptr;
          }
          template<>static TYPE*get<TYPE>(TYPE*p)
          {
            return p;
          }
public:
          void Do(t_expr_ext*p)
          {
            ptr=get(p);
          } void Do(t_func_ref_ext*p)
          {
            ptr=get(p);
          }
        };
        template<class TYPE>
        static TYPE*UberCast(i_func_param_value*p)
        {
          if (!p)return nullptr;
          Is<TYPE,i_func_param_value_visitor> IS;
          p->Use(IS);
          return IS.ptr;
        }
      };
      //===<<===i_func_param_value_visitor
      //class t_visitor:public t_type_expr::i_func_param_value_visitor{
      //public:
      //  class t_dev{
      //  public:
      //  };
      //  t_dev&dev;
      //  t_visitor(t_dev&dev):dev(dev){}
      //public:
      //  void Do(t_expr_ext*p){}
      //  void Do(t_func_ref_ext*p){}
      //};
    public:
      class i_func_param_value
      {
        //=====+>>>>>i_func_param_value
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef i_func_param_value SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
        }
        //==Declaration Constructors==//
      public:
        i_func_param_value(const i_func_param_value&)=delete;
        i_func_param_value()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        i_func_param_value(i_func_param_value&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(i_func_param_value&&_Right)
        {
          if (&_Right==this)return;
          {
          }
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="i_func_param_value";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "i_func_param_value";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====i_func_param_value
      public:
        typedef i_func_param_value_visitor i_visitor;
        virtual void Use(i_visitor&A)
        {
          QapDebugMsg("no way.");/*A.Do(this);*/
        }
      public:
        virtual bool go(i_dev&dev)
        {
          QapDebugMsg("no way.");
          return false;
        };
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          template<int>
          bool load()
          {
            //[Line](=>)
            go_for<t_expr_ext>();
            //[Line](<=)
            //[Line](=>)
            go_for<t_func_ref_ext>();
            //[Line](<=)
            (void)count;
            (void)first_id;
            (void)out_arr;
            (void)this;
            main();
            return scope.ok;
          }
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            vector<t_out_rec> out_arr;
            static int out_arr_size=0;
            out_arr.reserve(out_arr_size);
            t_fallback scope(dev,__FUNCTION__);
            int count=0;
            int first_id=-1;
            auto&Env=dev.getEnv();
            static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
            t_poly_tool::go_poly<SelfClass> solver_impl=
            {
              out_arr,dev,ref,scope,count,first_id,strbasetype,Env
            };
            t_poly_impl&solver=(t_poly_impl&)solver_impl;
            solver.load<0>();
            out_arr_size=out_arr.size();
            return scope.ok;
          }
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            t_fallback scope(dev,__FUNCTION__);
            bool&ok=scope.ok;
            if (!std::is_polymorphic<SelfClass>::value)if (!ref)
              {
                return false;
              }
            if (!ref)return false;
            QapAssert(ref);
            auto*p=ref.get();
            ok=p->go(dev);
            return ok;
          }
        };
      };
      class t_first_scope
      {
        //=====+>>>>>t_first_scope
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_first_scope SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        string body;
        t_sep sep;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->body);
          detail::FieldTryDoReset(this->sep);
        }
        //==Declaration Constructors==//
      public:
        t_first_scope(const t_first_scope&)=delete;
        t_first_scope()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_first_scope(t_first_scope&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_first_scope&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->body=std::move(_Right.body);
          this->sep=std::move(_Right.sep);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_first_scope";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_first_scope";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_first_scope
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("::");
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_const_with_sep
      {
        //=====+>>>>>t_const_with_sep
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_const_with_sep SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        string keyword;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->keyword);
        }
        //==Declaration Constructors==//
      public:
        t_const_with_sep(const t_const_with_sep&)=delete;
        t_const_with_sep()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_const_with_sep(t_const_with_sep&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_const_with_sep&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          this->keyword=std::move(_Right.keyword);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_const_with_sep";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_const_with_sep";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_const_with_sep
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          static const auto g_static_var_1=QapStrFinder::fromArr(split("typename,const,unsigned",","));
          M+=dev.go_any_str_from_vec(keyword,g_static_var_1);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_type_with_sep
      {
      public:
        //===>>===i_param_visitor
        class i_param;
        class t_type_param;
        class t_num_param;
        class i_param_visitor
        {
        public:
          typedef t_type_with_sep::i_param i_param;
        public:
          virtual void Do(t_type_param*p)=0;
          virtual void Do(t_num_param*p)=0;
        public:
          typedef t_type_with_sep::t_type_param t_type_param;
          typedef t_type_with_sep::t_num_param t_num_param;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_type_param*p)
            {
              ptr=get(p);
            } void Do(t_num_param*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_param*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_param_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
        //===<<===i_param_visitor
        //class t_visitor:public t_type_with_sep::i_param_visitor{
        //public:
        //  class t_dev{
        //  public:
        //  };
        //  t_dev&dev;
        //  t_visitor(t_dev&dev):dev(dev){}
        //public:
        //  void Do(t_type_param*p){}
        //  void Do(t_num_param*p){}
        //};
      public:
        class i_param
        {
          //=====+>>>>>i_param
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_type_with_sep OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef i_param SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
          }
          //==Declaration Constructors==//
        public:
          i_param(const i_param&)=delete;
          i_param()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          i_param(i_param&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(i_param&&_Right)
          {
            if (&_Right==this)return;
            {
            }
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="i_param";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "i_param";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====i_param
        public:
          typedef i_param_visitor i_visitor;
          virtual void Use(i_visitor&A)
          {
            QapDebugMsg("no way.");/*A.Do(this);*/
          }
        public:
          virtual bool go(i_dev&dev)
          {
            QapDebugMsg("no way.");
            return false;
          };
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            template<int>
            bool load()
            {
              //[Line](=>)
              go_for<t_type_param>();
              //[Line](<=)
              //[Line](=>)
              go_for<t_num_param>();
              //[Line](<=)
              (void)count;
              (void)first_id;
              (void)out_arr;
              (void)this;
              main();
              return scope.ok;
            }
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
              vector<t_out_rec> out_arr;
              static int out_arr_size=0;
              out_arr.reserve(out_arr_size);
              t_fallback scope(dev,__FUNCTION__);
              int count=0;
              int first_id=-1;
              auto&Env=dev.getEnv();
              static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
              t_poly_tool::go_poly<SelfClass> solver_impl=
              {
                out_arr,dev,ref,scope,count,first_id,strbasetype,Env
              };
              t_poly_impl&solver=(t_poly_impl&)solver_impl;
              solver.load<0>();
              out_arr_size=out_arr.size();
              return scope.ok;
            }
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              t_fallback scope(dev,__FUNCTION__);
              bool&ok=scope.ok;
              if (!std::is_polymorphic<SelfClass>::value)if (!ref)
                {
                  return false;
                }
              if (!ref)return false;
              QapAssert(ref);
              auto*p=ref.get();
              ok=p->go(dev);
              return ok;
            }
          };
        };
        class t_type_param:public i_param
        {
          //=====+>>>>>t_type_param
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_type_with_sep OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_type_param SelfClass;
        public:
          typedef i_param ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          vector<t_const_with_sep> cvs;
          TAutoPtr<t_type_expr> body;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
            detail::FieldTryDoReset(this->cvs);
            detail::FieldTryDoReset(this->body);
          }
          //==Declaration Constructors==//
        public:
          t_type_param(const t_type_param&)=delete;
          t_type_param()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_type_param(t_type_param&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_type_param&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_param(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_param::operator=(std::move(_Right));
              //[Line](<=)
            }
            //[Line](=>)
            this->cvs=std::move(_Right.cvs);
            this->body=std::move(_Right.body);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_type_param";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<vector<t_const_with_sep>>::GetRTTI(RTTI),"cvs",int(&(((SelfClass*)nullptr)->*(&SelfClass::cvs))),"DEF","$");
              Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_type_param";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_type_param
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            O+=dev.go_auto(cvs);
            if (!ok)return ok;
            M+=dev.go_auto(body);
            if (!ok)return ok;
            return ok;
          }
        };
        class t_num_param:public i_param
        {
          //=====+>>>>>t_num_param
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_type_with_sep OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_num_param SelfClass;
        public:
          typedef i_param ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          string body;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
            detail::FieldTryDoReset(this->body);
          }
          //==Declaration Constructors==//
        public:
          t_num_param(const t_num_param&)=delete;
          t_num_param()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_num_param(t_num_param&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_num_param&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_param(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_param::operator=(std::move(_Right));
              //[Line](<=)
            }
            //[Line](=>)
            this->body=std::move(_Right.body);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_num_param";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_num_param";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_num_param
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
            D+=dev.go_any(body,g_static_var_0);
            if (!ok)return ok;
            return ok;
          }
        };
        class t_params
        {
        public:
          class t_type_expr_with_sep
          {
            //=====+>>>>>t_type_expr_with_sep
            //==Declaration SelfClass,ParentClass,OwnerClass==//
            //[Line](=>)
          public:
            typedef t_params OwnerClass;
            //[Line](<=)
            //[Line](=>)
          public:
            typedef t_type_expr_with_sep SelfClass;
            //[Line](<=)
            //==Declaration Members==//
          public:
            //[Line](=>)
            t_sep sep_bef;
            TAutoPtr<i_param> param;
            t_sep sep_aft;
            //[Line](<=)
            //==Declaration DoReset==//
          public:
            void DoReset()
            {
              {
              }
              detail::FieldTryDoReset(this->sep_bef);
              detail::FieldTryDoReset(this->param);
              detail::FieldTryDoReset(this->sep_aft);
            }
            //==Declaration Constructors==//
          public:
            t_type_expr_with_sep(const t_type_expr_with_sep&)=delete;
            t_type_expr_with_sep()
            {
              DoReset();
            };
            //==Declaration Equal Operator==//
            //==Declaration Copy Constructor==//
          public:
            t_type_expr_with_sep(t_type_expr_with_sep&&_Right)
            {
              operator=(std::move(_Right));
            }
            void operator=(t_type_expr_with_sep&&_Right)
            {
              if (&_Right==this)return;
              {
              }
              //[Line](=>)
              this->sep_bef=std::move(_Right.sep_bef);
              this->param=std::move(_Right.param);
              this->sep_aft=std::move(_Right.sep_aft);
              //[Line](<=)
            }
            //==Declaration GetRTTI==//
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              template<class QAP_RTTI>
              static metatype*GetRTTI(QAP_RTTI&RTTI)
              {
                //[Line](=>)
                static const string Name="t_type_expr_with_sep";
                //[Line](<=)
                TTypeStruct*Info=nullptr;
                if (RTTI.Register<SelfClass>(Info,Name))
                {
                  return Info;
                }
                else
                {
                  Info->SubType=nullptr;
                  Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
                }
                //[Line](=>)
                Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep_bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep_bef))),"DEF","$");
                Info->AddMemberDEF(Sys$$<TAutoPtr<i_param>>::GetRTTI(RTTI),"param",int(&(((SelfClass*)nullptr)->*(&SelfClass::param))),"DEF","$");
                Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep_aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep_aft))),"DEF","$");
                //[Line](<=)
                {
                  RTTI.OnRegEnd(Info);
                }
                {
                }
                Info->SelfTesting();
                return Info;
              }
              static string GetFullName()
              {
                //[Line](=>)
                return "t_type_expr_with_sep";
                //[Line](<=)
              }
            };
          public:
            //<<<<<+=====t_type_expr_with_sep
          public:
            bool go(i_dev&dev)
            {
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              O+=dev.go_auto(sep_bef);
              if (!ok)return ok;
              M+=dev.go_auto(param);
              if (!ok)return ok;
              O+=dev.go_auto(sep_aft);
              if (!ok)return ok;
              return ok;
            }
          };
        public:
          //=====+>>>>>t_params
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_type_with_sep OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_params SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          t_sep sep;
          vector<t_type_expr_with_sep> arr;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
            detail::FieldTryDoReset(this->sep);
            detail::FieldTryDoReset(this->arr);
          }
          //==Declaration Constructors==//
        public:
          t_params(const t_params&)=delete;
          t_params()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_params(t_params&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_params&&_Right)
          {
            if (&_Right==this)return;
            {
            }
            //[Line](=>)
            this->sep=std::move(_Right.sep);
            this->arr=std::move(_Right.arr);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_params";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
              Info->AddMemberDEF(Sys$$<vector<t_type_expr_with_sep>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
                //[Line](=>)
                Info->AddNested(Sys$$<t_type_expr_with_sep>::GetRTTI(RTTI));
                //[Line](<=)
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_params";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_params
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            O+=dev.go_auto(sep);
            if (!ok)return ok;
            M+=dev.go_const("<");
            if (!ok)return ok;
            O+=dev.go_vec(arr,",");
            if (!ok)return ok;
            M+=dev.go_const(">");
            if (!ok)return ok;
            return ok;
          }
        };
      public:
        //=====+>>>>>t_type_with_sep
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_type_with_sep SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        string name;
        TAutoPtr<t_params> params;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->name);
          detail::FieldTryDoReset(this->params);
        }
        //==Declaration Constructors==//
      public:
        t_type_with_sep(const t_type_with_sep&)=delete;
        t_type_with_sep()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_type_with_sep(t_type_with_sep&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_type_with_sep&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          this->name=std::move(_Right.name);
          this->params=std::move(_Right.params);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_type_with_sep";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
              //[Line](=>)
              Info->AddNested(Sys$$<t_type_param>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_num_param>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_params>::GetRTTI(RTTI));
              //[Line](<=)
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_type_with_sep";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_type_with_sep
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          M+=dev.go_str<t_name>(name);
          if (!ok)return ok;
          O+=dev.go_auto(params);
          if (!ok)return ok;
          return ok;
        }
      public:
        //class t_static_visitor{
        //public:
        //  #define F(TYPE)typedef t_type_with_sep::TYPE TYPE;
        //  F(i_param);
        //  F(t_type_param);
        //  F(t_num_param);
        //  F(t_params);
        //  #undef F
        //public:
        //  void Do(t_type_param&ref){}
        //  void Do(t_num_param&ref){}
        //  void Do(t_params&ref){}
        //};
      };
      class t_scope_with_sep
      {
        //=====+>>>>>t_scope_with_sep
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_scope_with_sep SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep);
        }
        //==Declaration Constructors==//
      public:
        t_scope_with_sep(const t_scope_with_sep&)=delete;
        t_scope_with_sep()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_scope_with_sep(t_scope_with_sep&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_scope_with_sep&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_scope_with_sep";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_scope_with_sep";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_scope_with_sep
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          M+=dev.go_const("::");
          if (!ok)return ok;
          return ok;
        }
      };
      class t_scope
      {
        //=====+>>>>>t_scope
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_scope SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
        }
        //==Declaration Constructors==//
      public:
        t_scope(const t_scope&)=delete;
        t_scope()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_scope(t_scope&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_scope&&_Right)
        {
          if (&_Right==this)return;
          {
          }
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_scope";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_scope";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_scope
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_const("::");
          if (!ok)return ok;
          return ok;
        }
      };
      class t_ptr
      {
        //=====+>>>>>t_ptr
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_ptr SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->cv);
          detail::FieldTryDoReset(this->sep);
        }
        //==Declaration Constructors==//
      public:
        t_ptr(const t_ptr&)=delete;
        t_ptr()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_ptr(t_ptr&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_ptr&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->cv=std::move(_Right.cv);
          this->sep=std::move(_Right.sep);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_ptr";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_ptr";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_ptr
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(cv);
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          M+=dev.go_const("*");
          if (!ok)return ok;
          return ok;
        }
      };
      class t_ref
      {
        //=====+>>>>>t_ref
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_ref SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep;
        string ref;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->cv);
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->ref);
        }
        //==Declaration Constructors==//
      public:
        t_ref(const t_ref&)=delete;
        t_ref()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_ref(t_ref&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_ref&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->cv=std::move(_Right.cv);
          this->sep=std::move(_Right.sep);
          this->ref=std::move(_Right.ref);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_ref";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"ref",int(&(((SelfClass*)nullptr)->*(&SelfClass::ref))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_ref";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_ref
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(cv);
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          static const auto g_static_var_2=QapStrFinder::fromArr(split("&&,&",","));
          M+=dev.go_any_str_from_vec(ref,g_static_var_2);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_scopes
      {
      public:
        class t_item
        {
          //=====+>>>>>t_item
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_scopes OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_item SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          t_scope_with_sep sws;
          t_type_with_sep body;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
            detail::FieldTryDoReset(this->sws);
            detail::FieldTryDoReset(this->body);
          }
          //==Declaration Constructors==//
        public:
          t_item(const t_item&)=delete;
          t_item()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_item(t_item&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_item&&_Right)
          {
            if (&_Right==this)return;
            {
            }
            //[Line](=>)
            this->sws=std::move(_Right.sws);
            this->body=std::move(_Right.body);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_item";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<t_scope_with_sep>::GetRTTI(RTTI),"sws",int(&(((SelfClass*)nullptr)->*(&SelfClass::sws))),"DEF","$");
              Info->AddMemberDEF(Sys$$<t_type_with_sep>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_item";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_item
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_auto(sws);
            if (!ok)return ok;
            D+=dev.go_auto(body);
            if (!ok)return ok;
            return ok;
          }
        };
      public:
        //=====+>>>>>t_scopes
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_scopes SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_type_with_sep first;
        vector<t_item> arr;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->first);
          detail::FieldTryDoReset(this->arr);
        }
        //==Declaration Constructors==//
      public:
        t_scopes(const t_scopes&)=delete;
        t_scopes()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_scopes(t_scopes&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_scopes&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->first=std::move(_Right.first);
          this->arr=std::move(_Right.arr);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_scopes";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_type_with_sep>::GetRTTI(RTTI),"first",int(&(((SelfClass*)nullptr)->*(&SelfClass::first))),"DEF","$");
            Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
              //[Line](=>)
              Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
              //[Line](<=)
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_scopes";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_scopes
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(first);
          if (!ok)return ok;
          O+=dev.go_auto(arr);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_keyword
      {
        //=====+>>>>>t_keyword
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_keyword SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        string keyword;
        t_sep sep;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->keyword);
          detail::FieldTryDoReset(this->sep);
        }
        //==Declaration Constructors==//
      public:
        t_keyword(const t_keyword&)=delete;
        t_keyword()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_keyword(t_keyword&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_keyword&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->keyword=std::move(_Right.keyword);
          this->sep=std::move(_Right.sep);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_keyword";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_keyword";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_keyword
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          static const auto g_static_var_0=QapStrFinder::fromArr(split("friend,typename,extern,explicit,constexpr,virtual,const,static,inline,unsigned",","));
          M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_type_expr_with_sep_and_cv
      {
        //=====+>>>>>t_type_expr_with_sep_and_cv
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_type_expr_with_sep_and_cv SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        vector<t_const_with_sep> cvs;
        TAutoPtr<t_type_expr> body;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->cvs);
          detail::FieldTryDoReset(this->body);
        }
        //==Declaration Constructors==//
      public:
        t_type_expr_with_sep_and_cv(const t_type_expr_with_sep_and_cv&)=delete;
        t_type_expr_with_sep_and_cv()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_type_expr_with_sep_and_cv(t_type_expr_with_sep_and_cv&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_type_expr_with_sep_and_cv&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->cvs=std::move(_Right.cvs);
          this->body=std::move(_Right.body);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_type_expr_with_sep_and_cv";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<vector<t_const_with_sep>>::GetRTTI(RTTI),"cvs",int(&(((SelfClass*)nullptr)->*(&SelfClass::cvs))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_type_expr_with_sep_and_cv";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_type_expr_with_sep_and_cv
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(cvs);
          if (!ok)return ok;
          M+=dev.go_auto(body);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_name_part
      {
        //=====+>>>>>t_name_part
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_name_part SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        TAutoPtr<i_name_part> body;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->body);
        }
        //==Declaration Constructors==//
      public:
        t_name_part(const t_name_part&)=delete;
        t_name_part()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_name_part(t_name_part&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_name_part&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->body=std::move(_Right.body);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_name_part";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<TAutoPtr<i_name_part>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_name_part";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_name_part
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_auto(body);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_arr_body
      {
        //=====+>>>>>t_arr_body
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_arr_body SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep0;
        t_sep sep1;
        t_expr expr;
        t_sep sep2;
        t_sep sep3;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep0);
          detail::FieldTryDoReset(this->sep1);
          detail::FieldTryDoReset(this->expr);
          detail::FieldTryDoReset(this->sep2);
          detail::FieldTryDoReset(this->sep3);
        }
        //==Declaration Constructors==//
      public:
        t_arr_body(const t_arr_body&)=delete;
        t_arr_body()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_arr_body(t_arr_body&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_arr_body&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep0=std::move(_Right.sep0);
          this->sep1=std::move(_Right.sep1);
          this->expr=std::move(_Right.expr);
          this->sep2=std::move(_Right.sep2);
          this->sep3=std::move(_Right.sep3);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_arr_body";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_arr_body";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_arr_body
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep0);
          if (!ok)return ok;
          M+=dev.go_const("[");
          if (!ok)return ok;
          O+=dev.go_auto(sep1);
          if (!ok)return ok;
          M+=dev.go_auto(expr);
          if (!ok)return ok;
          O+=dev.go_auto(sep2);
          if (!ok)return ok;
          M+=dev.go_const("]");
          if (!ok)return ok;
          O+=dev.go_auto(sep3);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_brackets_name_part:public i_name_part
      {
      public:
        //===>>===i_part_visitor
        class i_part;
        class t_amp_part;
        class t_star_part;
        class i_part_visitor
        {
        public:
          typedef t_brackets_name_part::i_part i_part;
        public:
          virtual void Do(t_amp_part*p)=0;
          virtual void Do(t_star_part*p)=0;
        public:
          typedef t_brackets_name_part::t_amp_part t_amp_part;
          typedef t_brackets_name_part::t_star_part t_star_part;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_amp_part*p)
            {
              ptr=get(p);
            } void Do(t_star_part*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_part*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_part_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
        //===<<===i_part_visitor
        //class t_visitor:public t_brackets_name_part::i_part_visitor{
        //public:
        //  class t_dev{
        //  public:
        //  };
        //  t_dev&dev;
        //  t_visitor(t_dev&dev):dev(dev){}
        //public:
        //  void Do(t_amp_part*p){}
        //  void Do(t_star_part*p){}
        //};
      public:
        class i_part
        {
          //=====+>>>>>i_part
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_brackets_name_part OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef i_part SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
          }
          //==Declaration Constructors==//
        public:
          i_part(const i_part&)=delete;
          i_part()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          i_part(i_part&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(i_part&&_Right)
          {
            if (&_Right==this)return;
            {
            }
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="i_part";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "i_part";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====i_part
        public:
          typedef i_part_visitor i_visitor;
          virtual void Use(i_visitor&A)
          {
            QapDebugMsg("no way.");/*A.Do(this);*/
          }
        public:
          virtual bool go(i_dev&dev)
          {
            QapDebugMsg("no way.");
            return false;
          };
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            template<int>
            bool load()
            {
              //[Line](=>)
              go_for<t_amp_part>();
              //[Line](<=)
              //[Line](=>)
              go_for<t_star_part>();
              //[Line](<=)
              (void)count;
              (void)first_id;
              (void)out_arr;
              (void)this;
              main();
              return scope.ok;
            }
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
              vector<t_out_rec> out_arr;
              static int out_arr_size=0;
              out_arr.reserve(out_arr_size);
              t_fallback scope(dev,__FUNCTION__);
              int count=0;
              int first_id=-1;
              auto&Env=dev.getEnv();
              static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
              t_poly_tool::go_poly<SelfClass> solver_impl=
              {
                out_arr,dev,ref,scope,count,first_id,strbasetype,Env
              };
              t_poly_impl&solver=(t_poly_impl&)solver_impl;
              solver.load<0>();
              out_arr_size=out_arr.size();
              return scope.ok;
            }
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              t_fallback scope(dev,__FUNCTION__);
              bool&ok=scope.ok;
              if (!std::is_polymorphic<SelfClass>::value)if (!ref)
                {
                  return false;
                }
              if (!ref)return false;
              QapAssert(ref);
              auto*p=ref.get();
              ok=p->go(dev);
              return ok;
            }
          };
        };
        class t_amp
        {
          //=====+>>>>>t_amp
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_brackets_name_part OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_amp SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          string body;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
            detail::FieldTryDoReset(this->body);
          }
          //==Declaration Constructors==//
        public:
          t_amp(const t_amp&)=delete;
          t_amp()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_amp(t_amp&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_amp&&_Right)
          {
            if (&_Right==this)return;
            {
            }
            //[Line](=>)
            this->body=std::move(_Right.body);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_amp";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_amp";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_amp
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            static const auto g_static_var_0=QapStrFinder::fromArr(split("&,&&",","));
            D+=dev.go_any_str_from_vec(body,g_static_var_0);
            if (!ok)return ok;
            return ok;
          }
        };
        class t_amp_part:public i_part
        {
          //=====+>>>>>t_amp_part
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_brackets_name_part OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_amp_part SelfClass;
        public:
          typedef i_part ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          t_amp body;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
            detail::FieldTryDoReset(this->body);
          }
          //==Declaration Constructors==//
        public:
          t_amp_part(const t_amp_part&)=delete;
          t_amp_part()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_amp_part(t_amp_part&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_amp_part&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_part(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_part::operator=(std::move(_Right));
              //[Line](<=)
            }
            //[Line](=>)
            this->body=std::move(_Right.body);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_amp_part";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<t_amp>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_amp_part";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_amp_part
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_auto(body);
            if (!ok)return ok;
            return ok;
          }
        };
        class t_star_part:public i_part
        {
          //=====+>>>>>t_star_part
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_brackets_name_part OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_star_part SelfClass;
        public:
          typedef i_part ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          string stars;
          TAutoPtr<t_amp> amp;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
            detail::FieldTryDoReset(this->stars);
            detail::FieldTryDoReset(this->amp);
          }
          //==Declaration Constructors==//
        public:
          t_star_part(const t_star_part&)=delete;
          t_star_part()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_star_part(t_star_part&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_star_part&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_part(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_part::operator=(std::move(_Right));
              //[Line](<=)
            }
            //[Line](=>)
            this->stars=std::move(_Right.stars);
            this->amp=std::move(_Right.amp);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_star_part";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"stars",int(&(((SelfClass*)nullptr)->*(&SelfClass::stars))),"DEF","$");
              Info->AddMemberDEF(Sys$$<TAutoPtr<t_amp>>::GetRTTI(RTTI),"amp",int(&(((SelfClass*)nullptr)->*(&SelfClass::amp))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_star_part";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_star_part
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            static const auto g_static_var_0=CharMask::fromStr("*");
            M+=dev.go_any(stars,g_static_var_0);
            if (!ok)return ok;
            O+=dev.go_auto(amp);
            if (!ok)return ok;
            return ok;
          }
        };
      public:
        //=====+>>>>>t_brackets_name_part
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_brackets_name_part SelfClass;
      public:
        typedef i_name_part ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        TAutoPtr<i_part> stamp_part;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
        TAutoPtr<t_arr_body> arrbody;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->stamp_part);
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->namepart);
          detail::FieldTryDoReset(this->arrbody);
        }
        //==Declaration Constructors==//
      public:
        t_brackets_name_part(const t_brackets_name_part&)=delete;
        t_brackets_name_part()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_brackets_name_part(t_brackets_name_part&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_brackets_name_part&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_name_part(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_name_part::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->stamp_part=std::move(_Right.stamp_part);
          this->sep=std::move(_Right.sep);
          this->namepart=std::move(_Right.namepart);
          this->arrbody=std::move(_Right.arrbody);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_brackets_name_part";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<TAutoPtr<i_part>>::GetRTTI(RTTI),"stamp_part",int(&(((SelfClass*)nullptr)->*(&SelfClass::stamp_part))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_name_part>>::GetRTTI(RTTI),"namepart",int(&(((SelfClass*)nullptr)->*(&SelfClass::namepart))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_arr_body>>::GetRTTI(RTTI),"arrbody",int(&(((SelfClass*)nullptr)->*(&SelfClass::arrbody))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
              //[Line](=>)
              Info->AddNested(Sys$$<t_amp>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_amp_part>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_star_part>::GetRTTI(RTTI));
              //[Line](<=)
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_brackets_name_part";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_brackets_name_part
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("(");
          if (!ok)return ok;
          M+=dev.go_auto(stamp_part);
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          O+=dev.go_auto(namepart);
          if (!ok)return ok;
          M+=dev.go_const(")");
          if (!ok)return ok;
          O+=dev.go_auto(arrbody);
          if (!ok)return ok;
          return ok;
        }
      public:
        //class t_static_visitor{
        //public:
        //  #define F(TYPE)typedef t_brackets_name_part::TYPE TYPE;
        //  F(i_part);
        //  F(t_amp);
        //  F(t_amp_part);
        //  F(t_star_part);
        //  #undef F
        //public:
        //  void Do(t_amp&ref){}
        //  void Do(t_amp_part&ref){}
        //  void Do(t_star_part&ref){}
        //};
      };
      class t_raw_name_part:public i_name_part
      {
        //=====+>>>>>t_raw_name_part
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_raw_name_part SelfClass;
      public:
        typedef i_name_part ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        string name;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->name);
        }
        //==Declaration Constructors==//
      public:
        t_raw_name_part(const t_raw_name_part&)=delete;
        t_raw_name_part()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_raw_name_part(t_raw_name_part&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_raw_name_part&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_name_part(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_name_part::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->name=std::move(_Right.name);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_raw_name_part";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_raw_name_part";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_raw_name_part
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_str<t_name>(name);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_pfunc_func_param:public i_func_param
      {
      public:
        class t_addr
        {
          //=====+>>>>>t_addr
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_pfunc_func_param OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_addr SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          t_type_expr_with_sep_and_cv type;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
            detail::FieldTryDoReset(this->type);
          }
          //==Declaration Constructors==//
        public:
          t_addr(const t_addr&)=delete;
          t_addr()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_addr(t_addr&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_addr&&_Right)
          {
            if (&_Right==this)return;
            {
            }
            //[Line](=>)
            this->type=std::move(_Right.type);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_addr";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_addr";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_addr
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_auto(type);
            if (!ok)return ok;
            M+=dev.go_const("::");
            if (!ok)return ok;
            return ok;
          }
        };
      public:
        //=====+>>>>>t_pfunc_func_param
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_pfunc_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_type_expr_with_sep_and_cv type;
        t_addr addr;
        string name;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->type);
          detail::FieldTryDoReset(this->addr);
          detail::FieldTryDoReset(this->name);
        }
        //==Declaration Constructors==//
      public:
        t_pfunc_func_param(const t_pfunc_func_param&)=delete;
        t_pfunc_func_param()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_pfunc_func_param(t_pfunc_func_param&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_pfunc_func_param&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_func_param::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->type=std::move(_Right.type);
          this->addr=std::move(_Right.addr);
          this->name=std::move(_Right.name);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_pfunc_func_param";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_addr>::GetRTTI(RTTI),"addr",int(&(((SelfClass*)nullptr)->*(&SelfClass::addr))),"DEF","$");
            Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
              //[Line](=>)
              Info->AddNested(Sys$$<t_addr>::GetRTTI(RTTI));
              //[Line](<=)
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_pfunc_func_param";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_pfunc_func_param
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(type);
          if (!ok)return ok;
          M+=dev.go_const("(");
          if (!ok)return ok;
          O+=dev.go_auto(addr);
          if (!ok)return ok;
          M+=dev.go_const("*");
          if (!ok)return ok;
          M+=dev.go_str<t_name>(name);
          if (!ok)return ok;
          M+=dev.go_const(")");
          if (!ok)return ok;
          M+=dev.go_const("()");
          if (!ok)return ok;
          return ok;
        }
      };
      class t_var_args_func_param:public i_func_param
      {
        //=====+>>>>>t_var_args_func_param
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_var_args_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
        }
        //==Declaration Constructors==//
      public:
        t_var_args_func_param(const t_var_args_func_param&)=delete;
        t_var_args_func_param()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_var_args_func_param(t_var_args_func_param&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_var_args_func_param&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_func_param::operator=(std::move(_Right));
            //[Line](<=)
          }
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_var_args_func_param";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_var_args_func_param";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_var_args_func_param
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_const("...");
          if (!ok)return ok;
          return ok;
        }
      };
      class t_type_func_param:public i_func_param
      {
        //=====+>>>>>t_type_func_param
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_type_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_type_expr_with_sep_and_cv type;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->type);
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->namepart);
        }
        //==Declaration Constructors==//
      public:
        t_type_func_param(const t_type_func_param&)=delete;
        t_type_func_param()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_type_func_param(t_type_func_param&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_type_func_param&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_func_param::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->type=std::move(_Right.type);
          this->sep=std::move(_Right.sep);
          this->namepart=std::move(_Right.namepart);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_type_func_param";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_name_part>>::GetRTTI(RTTI),"namepart",int(&(((SelfClass*)nullptr)->*(&SelfClass::namepart))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_type_func_param";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_type_func_param
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(type);
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          O+=dev.go_auto(namepart);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_expr_func_param:public i_func_param
      {
        //=====+>>>>>t_expr_func_param
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_expr_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_expr body;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->body);
        }
        //==Declaration Constructors==//
      public:
        t_expr_func_param(const t_expr_func_param&)=delete;
        t_expr_func_param()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_expr_func_param(t_expr_func_param&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_expr_func_param&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_func_param::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->body=std::move(_Right.body);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_expr_func_param";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_expr_func_param";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_expr_func_param
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_minor<t_type_func_param>(body);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_expr_ext:public i_func_param_value
      {
        //=====+>>>>>t_expr_ext
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_expr_ext SelfClass;
      public:
        typedef i_func_param_value ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_expr body;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->body);
        }
        //==Declaration Constructors==//
      public:
        t_expr_ext(const t_expr_ext&)=delete;
        t_expr_ext()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_expr_ext(t_expr_ext&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_expr_ext&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_func_param_value(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_func_param_value::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->body=std::move(_Right.body);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_expr_ext";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_expr_ext";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_expr_ext
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_auto(body);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_func_ref_ext:public i_func_param_value
      {
        //=====+>>>>>t_func_ref_ext
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_func_ref_ext SelfClass;
      public:
        typedef i_func_param_value ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        t_type_expr_with_sep_and_cv type;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->type);
        }
        //==Declaration Constructors==//
      public:
        t_func_ref_ext(const t_func_ref_ext&)=delete;
        t_func_ref_ext()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_func_ref_ext(t_func_ref_ext&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_func_ref_ext&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_func_param_value(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_func_param_value::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          this->type=std::move(_Right.type);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_func_ref_ext";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_func_ref_ext";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_func_ref_ext
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("&");
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          M+=dev.go_auto(type);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_func_param_value
      {
        //=====+>>>>>t_func_param_value
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_func_param_value SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        TAutoPtr<i_func_param_value> value;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->value);
        }
        //==Declaration Constructors==//
      public:
        t_func_param_value(const t_func_param_value&)=delete;
        t_func_param_value()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_func_param_value(t_func_param_value&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_func_param_value&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          this->value=std::move(_Right.value);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_func_param_value";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_func_param_value";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_func_param_value
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("=");
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          M+=dev.go_auto(value);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_func_param
      {
        //=====+>>>>>t_func_param
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_func_param SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep0;
        TAutoPtr<i_func_param> body;
        t_sep sep1;
        TAutoPtr<t_func_param_value> value;
        t_sep sep2;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep0);
          detail::FieldTryDoReset(this->body);
          detail::FieldTryDoReset(this->sep1);
          detail::FieldTryDoReset(this->value);
          detail::FieldTryDoReset(this->sep2);
        }
        //==Declaration Constructors==//
      public:
        t_func_param(const t_func_param&)=delete;
        t_func_param()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_func_param(t_func_param&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_func_param&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep0=std::move(_Right.sep0);
          this->body=std::move(_Right.body);
          this->sep1=std::move(_Right.sep1);
          this->value=std::move(_Right.value);
          this->sep2=std::move(_Right.sep2);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_func_param";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_param>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_func_param";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_func_param
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep0);
          if (!ok)return ok;
          M+=dev.go_auto(body);
          if (!ok)return ok;
          O+=dev.go_auto(sep1);
          if (!ok)return ok;
          O+=dev.go_auto(value);
          if (!ok)return ok;
          O+=dev.go_auto(sep2);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_func_params
      {
        //=====+>>>>>t_func_params
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_func_params SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        vector<t_func_param> arr;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep);
          detail::FieldTryDoReset(this->arr);
        }
        //==Declaration Constructors==//
      public:
        t_func_params(const t_func_params&)=delete;
        t_func_params()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_func_params(t_func_params&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_func_params&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          this->arr=std::move(_Right.arr);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_func_params";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            Info->AddMemberDEF(Sys$$<vector<t_func_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_func_params";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_func_params
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          M+=dev.go_const("(");
          if (!ok)return ok;
          O+=dev.go_vec(arr,",");
          if (!ok)return ok;
          M+=dev.go_const(")");
          if (!ok)return ok;
          return ok;
        }
      };
      class t_fv_stat
      {
      public:
        //===>>===i_fv_body_visitor
        class i_fv_body;
        class t_impl_func_body;
        class t_zero_func_body;
        class t_delete_func_body;
        class i_fv_body_visitor
        {
        public:
          typedef t_fv_stat::i_fv_body i_fv_body;
        public:
          virtual void Do(t_impl_func_body*p)=0;
          virtual void Do(t_zero_func_body*p)=0;
          virtual void Do(t_delete_func_body*p)=0;
        public:
          typedef t_fv_stat::t_impl_func_body t_impl_func_body;
          typedef t_fv_stat::t_zero_func_body t_zero_func_body;
          typedef t_fv_stat::t_delete_func_body t_delete_func_body;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_impl_func_body*p)
            {
              ptr=get(p);
            } void Do(t_zero_func_body*p)
            {
              ptr=get(p);
            } void Do(t_delete_func_body*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_body*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_fv_body_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
        //===<<===i_fv_body_visitor
        //class t_visitor:public t_fv_stat::i_fv_body_visitor{
        //public:
        //  class t_dev{
        //  public:
        //  };
        //  t_dev&dev;
        //  t_visitor(t_dev&dev):dev(dev){}
        //public:
        //  void Do(t_impl_func_body*p){}
        //  void Do(t_zero_func_body*p){}
        //  void Do(t_delete_func_body*p){}
        //};
      public:
        class i_fv_body
        {
          //=====+>>>>>i_fv_body
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_fv_stat OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef i_fv_body SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
          }
          //==Declaration Constructors==//
        public:
          i_fv_body(const i_fv_body&)=delete;
          i_fv_body()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          i_fv_body(i_fv_body&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(i_fv_body&&_Right)
          {
            if (&_Right==this)return;
            {
            }
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="i_fv_body";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "i_fv_body";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====i_fv_body
        public:
          typedef i_fv_body_visitor i_visitor;
          virtual void Use(i_visitor&A)
          {
            QapDebugMsg("no way.");/*A.Do(this);*/
          }
        public:
          virtual bool go(i_dev&dev)
          {
            QapDebugMsg("no way.");
            return false;
          };
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            template<int>
            bool load()
            {
              //[Line](=>)
              go_for<t_impl_func_body>();
              //[Line](<=)
              //[Line](=>)
              go_for<t_zero_func_body>();
              //[Line](<=)
              //[Line](=>)
              go_for<t_delete_func_body>();
              //[Line](<=)
              (void)count;
              (void)first_id;
              (void)out_arr;
              (void)this;
              main();
              return scope.ok;
            }
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
              vector<t_out_rec> out_arr;
              static int out_arr_size=0;
              out_arr.reserve(out_arr_size);
              t_fallback scope(dev,__FUNCTION__);
              int count=0;
              int first_id=-1;
              auto&Env=dev.getEnv();
              static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
              t_poly_tool::go_poly<SelfClass> solver_impl=
              {
                out_arr,dev,ref,scope,count,first_id,strbasetype,Env
              };
              t_poly_impl&solver=(t_poly_impl&)solver_impl;
              solver.load<0>();
              out_arr_size=out_arr.size();
              return scope.ok;
            }
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              t_fallback scope(dev,__FUNCTION__);
              bool&ok=scope.ok;
              if (!std::is_polymorphic<SelfClass>::value)if (!ref)
                {
                  return false;
                }
              if (!ref)return false;
              QapAssert(ref);
              auto*p=ref.get();
              ok=p->go(dev);
              return ok;
            }
          };
        };
      public:
        //===>>===i_fv_end_visitor
        class i_fv_end;
        class t_func_fv_end;
        class t_var_fv_end;
        class i_fv_end_visitor
        {
        public:
          typedef t_fv_stat::i_fv_end i_fv_end;
        public:
          virtual void Do(t_func_fv_end*p)=0;
          virtual void Do(t_var_fv_end*p)=0;
        public:
          typedef t_fv_stat::t_func_fv_end t_func_fv_end;
          typedef t_fv_stat::t_var_fv_end t_var_fv_end;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor
          {
            TYPE*ptr;
            Is():ptr(nullptr) {}
public:
            template<class U>static TYPE*get(U*p)
            {
              return nullptr;
            }
            template<>static TYPE*get<TYPE>(TYPE*p)
            {
              return p;
            }
public:
            void Do(t_func_fv_end*p)
            {
              ptr=get(p);
            } void Do(t_var_fv_end*p)
            {
              ptr=get(p);
            }
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_end*p)
          {
            if (!p)return nullptr;
            Is<TYPE,i_fv_end_visitor> IS;
            p->Use(IS);
            return IS.ptr;
          }
        };
        //===<<===i_fv_end_visitor
        //class t_visitor:public t_fv_stat::i_fv_end_visitor{
        //public:
        //  class t_dev{
        //  public:
        //  };
        //  t_dev&dev;
        //  t_visitor(t_dev&dev):dev(dev){}
        //public:
        //  void Do(t_func_fv_end*p){}
        //  void Do(t_var_fv_end*p){}
        //};
      public:
        class i_fv_end
        {
          //=====+>>>>>i_fv_end
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_fv_stat OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef i_fv_end SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
          }
          //==Declaration Constructors==//
        public:
          i_fv_end(const i_fv_end&)=delete;
          i_fv_end()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          i_fv_end(i_fv_end&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(i_fv_end&&_Right)
          {
            if (&_Right==this)return;
            {
            }
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="i_fv_end";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "i_fv_end";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====i_fv_end
        public:
          typedef i_fv_end_visitor i_visitor;
          virtual void Use(i_visitor&A)
          {
            QapDebugMsg("no way.");/*A.Do(this);*/
          }
        public:
          virtual bool go(i_dev&dev)
          {
            QapDebugMsg("no way.");
            return false;
          };
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            template<int>
            bool load()
            {
              //[Line](=>)
              go_for<t_func_fv_end>();
              //[Line](<=)
              //[Line](=>)
              go_for<t_var_fv_end>();
              //[Line](<=)
              (void)count;
              (void)first_id;
              (void)out_arr;
              (void)this;
              main();
              return scope.ok;
            }
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
              vector<t_out_rec> out_arr;
              static int out_arr_size=0;
              out_arr.reserve(out_arr_size);
              t_fallback scope(dev,__FUNCTION__);
              int count=0;
              int first_id=-1;
              auto&Env=dev.getEnv();
              static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
              t_poly_tool::go_poly<SelfClass> solver_impl=
              {
                out_arr,dev,ref,scope,count,first_id,strbasetype,Env
              };
              t_poly_impl&solver=(t_poly_impl&)solver_impl;
              solver.load<0>();
              out_arr_size=out_arr.size();
              return scope.ok;
            }
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
            {
              t_fallback scope(dev,__FUNCTION__);
              bool&ok=scope.ok;
              if (!std::is_polymorphic<SelfClass>::value)if (!ref)
                {
                  return false;
                }
              if (!ref)return false;
              QapAssert(ref);
              auto*p=ref.get();
              ok=p->go(dev);
              return ok;
            }
          };
        };
        class t_impl_func_body:public i_fv_body
        {
          //=====+>>>>>t_impl_func_body
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_fv_stat OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_impl_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          t_sep sep;
          t_raw_func_body body;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
            detail::FieldTryDoReset(this->sep);
            detail::FieldTryDoReset(this->body);
          }
          //==Declaration Constructors==//
        public:
          t_impl_func_body(const t_impl_func_body&)=delete;
          t_impl_func_body()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_impl_func_body(t_impl_func_body&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_impl_func_body&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_fv_body(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_fv_body::operator=(std::move(_Right));
              //[Line](<=)
            }
            //[Line](=>)
            this->sep=std::move(_Right.sep);
            this->body=std::move(_Right.body);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_impl_func_body";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
              Info->AddMemberDEF(Sys$$<t_raw_func_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_impl_func_body";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_impl_func_body
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            O+=dev.go_auto(sep);
            if (!ok)return ok;
            M+=dev.go_auto(body);
            if (!ok)return ok;
            return ok;
          }
        };
        class t_zero_func_body:public i_fv_body
        {
          //=====+>>>>>t_zero_func_body
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_fv_stat OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_zero_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
          }
          //==Declaration Constructors==//
        public:
          t_zero_func_body(const t_zero_func_body&)=delete;
          t_zero_func_body()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_zero_func_body(t_zero_func_body&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_zero_func_body&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_fv_body(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_fv_body::operator=(std::move(_Right));
              //[Line](<=)
            }
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_zero_func_body";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_zero_func_body";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_zero_func_body
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_const("=0;");
            if (!ok)return ok;
            return ok;
          }
        };
        class t_delete_func_body:public i_fv_body
        {
          //=====+>>>>>t_delete_func_body
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_fv_stat OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_delete_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
          }
          //==Declaration Constructors==//
        public:
          t_delete_func_body(const t_delete_func_body&)=delete;
          t_delete_func_body()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_delete_func_body(t_delete_func_body&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_delete_func_body&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_fv_body(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_fv_body::operator=(std::move(_Right));
              //[Line](<=)
            }
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_delete_func_body";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_delete_func_body";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_delete_func_body
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_const("=delete;");
            if (!ok)return ok;
            return ok;
          }
        };
        class t_func_fv_end:public i_fv_end
        {
          //=====+>>>>>t_func_fv_end
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_fv_stat OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_func_fv_end SelfClass;
        public:
          typedef i_fv_end ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          TAutoPtr<t_func_params> params;
          TAutoPtr<t_const_with_sep> cv1;
          t_sep sep1;
          TAutoPtr<i_fv_body> body;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
            detail::FieldTryDoReset(this->params);
            detail::FieldTryDoReset(this->cv1);
            detail::FieldTryDoReset(this->sep1);
            detail::FieldTryDoReset(this->body);
          }
          //==Declaration Constructors==//
        public:
          t_func_fv_end(const t_func_fv_end&)=delete;
          t_func_fv_end()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_func_fv_end(t_func_fv_end&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_func_fv_end&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_fv_end(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_fv_end::operator=(std::move(_Right));
              //[Line](<=)
            }
            //[Line](=>)
            this->params=std::move(_Right.params);
            this->cv1=std::move(_Right.cv1);
            this->sep1=std::move(_Right.sep1);
            this->body=std::move(_Right.body);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_func_fv_end";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
              Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");
              Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
              Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_func_fv_end";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_func_fv_end
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_auto(params);
            if (!ok)return ok;
            O+=dev.go_auto(cv1);
            if (!ok)return ok;
            O+=dev.go_auto(sep1);
            if (!ok)return ok;
            M+=dev.go_auto(body);
            if (!ok)return ok;
            return ok;
          }
        };
        class t_var_fv_end:public i_fv_end
        {
        public:
          //===>>===i_fv_item_visitor
          class i_fv_item;
          class t_func_fv_item;
          class t_var_fv_item;
          class i_fv_item_visitor
          {
          public:
            typedef t_var_fv_end::i_fv_item i_fv_item;
          public:
            virtual void Do(t_func_fv_item*p)=0;
            virtual void Do(t_var_fv_item*p)=0;
          public:
            typedef t_var_fv_end::t_func_fv_item t_func_fv_item;
            typedef t_var_fv_end::t_var_fv_item t_var_fv_item;
          public:
            template<class TYPE,class Visitor>
            struct Is:public Visitor
            {
              TYPE*ptr;
              Is():ptr(nullptr) {}
public:
              template<class U>static TYPE*get(U*p)
              {
                return nullptr;
              }
              template<>static TYPE*get<TYPE>(TYPE*p)
              {
                return p;
              }
public:
              void Do(t_func_fv_item*p)
              {
                ptr=get(p);
              } void Do(t_var_fv_item*p)
              {
                ptr=get(p);
              }
            };
            template<class TYPE>
            static TYPE*UberCast(i_fv_item*p)
            {
              if (!p)return nullptr;
              Is<TYPE,i_fv_item_visitor> IS;
              p->Use(IS);
              return IS.ptr;
            }
          };
          //===<<===i_fv_item_visitor
          //class t_visitor:public t_var_fv_end::i_fv_item_visitor{
          //public:
          //  class t_dev{
          //  public:
          //  };
          //  t_dev&dev;
          //  t_visitor(t_dev&dev):dev(dev){}
          //public:
          //  void Do(t_func_fv_item*p){}
          //  void Do(t_var_fv_item*p){}
          //};
        public:
          class i_fv_item
          {
            //=====+>>>>>i_fv_item
            //==Declaration SelfClass,ParentClass,OwnerClass==//
            //[Line](=>)
          public:
            typedef t_var_fv_end OwnerClass;
            //[Line](<=)
            //[Line](=>)
          public:
            typedef i_fv_item SelfClass;
            //[Line](<=)
            //==Declaration Members==//
          public:
            //==Declaration DoReset==//
          public:
            void DoReset()
            {
              {
              }
            }
            //==Declaration Constructors==//
          public:
            i_fv_item(const i_fv_item&)=delete;
            i_fv_item()
            {
              DoReset();
            };
            //==Declaration Equal Operator==//
            //==Declaration Copy Constructor==//
          public:
            i_fv_item(i_fv_item&&_Right)
            {
              operator=(std::move(_Right));
            }
            void operator=(i_fv_item&&_Right)
            {
              if (&_Right==this)return;
              {
              }
            }
            //==Declaration GetRTTI==//
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              template<class QAP_RTTI>
              static metatype*GetRTTI(QAP_RTTI&RTTI)
              {
                //[Line](=>)
                static const string Name="i_fv_item";
                //[Line](<=)
                TTypeStruct*Info=nullptr;
                if (RTTI.Register<SelfClass>(Info,Name))
                {
                  return Info;
                }
                else
                {
                  Info->SubType=nullptr;
                  Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
                }
                {
                  RTTI.OnRegEnd(Info);
                }
                {
                }
                Info->SelfTesting();
                return Info;
              }
              static string GetFullName()
              {
                //[Line](=>)
                return "i_fv_item";
                //[Line](<=)
              }
            };
          public:
            //<<<<<+=====i_fv_item
          public:
            typedef i_fv_item_visitor i_visitor;
            virtual void Use(i_visitor&A)
            {
              QapDebugMsg("no way.");/*A.Do(this);*/
            }
          public:
            virtual bool go(i_dev&dev)
            {
              QapDebugMsg("no way.");
              return false;
            };
            struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
            {
              typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
              template<int>
              bool load()
              {
                //[Line](=>)
                go_for<t_func_fv_item>();
                //[Line](<=)
                //[Line](=>)
                go_for<t_var_fv_item>();
                //[Line](<=)
                (void)count;
                (void)first_id;
                (void)out_arr;
                (void)this;
                main();
                return scope.ok;
              }
              static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
              {
                typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
                vector<t_out_rec> out_arr;
                static int out_arr_size=0;
                out_arr.reserve(out_arr_size);
                t_fallback scope(dev,__FUNCTION__);
                int count=0;
                int first_id=-1;
                auto&Env=dev.getEnv();
                static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
                t_poly_tool::go_poly<SelfClass> solver_impl=
                {
                  out_arr,dev,ref,scope,count,first_id,strbasetype,Env
                };
                t_poly_impl&solver=(t_poly_impl&)solver_impl;
                solver.load<0>();
                out_arr_size=out_arr.size();
                return scope.ok;
              }
              static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
              {
                t_fallback scope(dev,__FUNCTION__);
                bool&ok=scope.ok;
                if (!std::is_polymorphic<SelfClass>::value)if (!ref)
                  {
                    return false;
                  }
                if (!ref)return false;
                QapAssert(ref);
                auto*p=ref.get();
                ok=p->go(dev);
                return ok;
              }
            };
          };
          class t_func_fv_item:public i_fv_item
          {
            //=====+>>>>>t_func_fv_item
            //==Declaration SelfClass,ParentClass,OwnerClass==//
            //[Line](=>)
          public:
            typedef t_var_fv_end OwnerClass;
            //[Line](<=)
            //[Line](=>)
          public:
            typedef t_func_fv_item SelfClass;
          public:
            typedef i_fv_item ParentClass;
            //[Line](<=)
            //==Declaration Members==//
          public:
            //[Line](=>)
            TAutoPtr<t_func_params> params;
            TAutoPtr<t_const_with_sep> cv1;
            //[Line](<=)
            //==Declaration DoReset==//
          public:
            void DoReset()
            {
              {
                //[Line](=>)
                detail::TryDoReset<SelfClass>(this);
                //[Line](<=)
              }
              detail::FieldTryDoReset(this->params);
              detail::FieldTryDoReset(this->cv1);
            }
            //==Declaration Constructors==//
          public:
            t_func_fv_item(const t_func_fv_item&)=delete;
            t_func_fv_item()
            {
              DoReset();
            };
            //==Declaration Equal Operator==//
            //==Declaration Copy Constructor==//
          public:
            t_func_fv_item(t_func_fv_item&&_Right)
            {
              operator=(std::move(_Right));
            }
            void operator=(t_func_fv_item&&_Right)
            {
              //[Line](=>)
              struct hidden
              {
                static void foo(i_fv_item(*)=(SelfClass*)nullptr) {}};
              //[Line](<=)
              if (&_Right==this)return;
              {
                //[Line](=>)
                i_fv_item::operator=(std::move(_Right));
                //[Line](<=)
              }
              //[Line](=>)
              this->params=std::move(_Right.params);
              this->cv1=std::move(_Right.cv1);
              //[Line](<=)
            }
            //==Declaration GetRTTI==//
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              template<class QAP_RTTI>
              static metatype*GetRTTI(QAP_RTTI&RTTI)
              {
                //[Line](=>)
                static const string Name="t_func_fv_item";
                //[Line](<=)
                TTypeStruct*Info=nullptr;
                if (RTTI.Register<SelfClass>(Info,Name))
                {
                  return Info;
                }
                else
                {
                  Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                  Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
                }
                //[Line](=>)
                Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
                Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");
                //[Line](<=)
                {
                  RTTI.OnRegEnd(Info);
                }
                {
                }
                Info->SelfTesting();
                return Info;
              }
              static string GetFullName()
              {
                //[Line](=>)
                return "t_func_fv_item";
                //[Line](<=)
              }
            };
          public:
            //<<<<<+=====t_func_fv_item
          public:
            void Use(i_visitor&A)
            {
              A.Do(this);
            }
            static SelfClass*UberCast(ParentClass*ptr)
            {
              return i_visitor::UberCast<SelfClass>(ptr);
            }
          public:
            bool go(i_dev&dev)
            {
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              M+=dev.go_auto(params);
              if (!ok)return ok;
              O+=dev.go_auto(cv1);
              if (!ok)return ok;
              return ok;
            }
          };
          class t_var_fv_item:public i_fv_item
          {
            //=====+>>>>>t_var_fv_item
            //==Declaration SelfClass,ParentClass,OwnerClass==//
            //[Line](=>)
          public:
            typedef t_var_fv_end OwnerClass;
            //[Line](<=)
            //[Line](=>)
          public:
            typedef t_var_fv_item SelfClass;
          public:
            typedef i_fv_item ParentClass;
            //[Line](<=)
            //==Declaration Members==//
          public:
            //[Line](=>)
            TAutoPtr<t_arr_body> arrbody;
            TAutoPtr<t_func_param_value> value;
            //[Line](<=)
            //==Declaration DoReset==//
          public:
            void DoReset()
            {
              {
                //[Line](=>)
                detail::TryDoReset<SelfClass>(this);
                //[Line](<=)
              }
              detail::FieldTryDoReset(this->arrbody);
              detail::FieldTryDoReset(this->value);
            }
            //==Declaration Constructors==//
          public:
            t_var_fv_item(const t_var_fv_item&)=delete;
            t_var_fv_item()
            {
              DoReset();
            };
            //==Declaration Equal Operator==//
            //==Declaration Copy Constructor==//
          public:
            t_var_fv_item(t_var_fv_item&&_Right)
            {
              operator=(std::move(_Right));
            }
            void operator=(t_var_fv_item&&_Right)
            {
              //[Line](=>)
              struct hidden
              {
                static void foo(i_fv_item(*)=(SelfClass*)nullptr) {}};
              //[Line](<=)
              if (&_Right==this)return;
              {
                //[Line](=>)
                i_fv_item::operator=(std::move(_Right));
                //[Line](<=)
              }
              //[Line](=>)
              this->arrbody=std::move(_Right.arrbody);
              this->value=std::move(_Right.value);
              //[Line](<=)
            }
            //==Declaration GetRTTI==//
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              template<class QAP_RTTI>
              static metatype*GetRTTI(QAP_RTTI&RTTI)
              {
                //[Line](=>)
                static const string Name="t_var_fv_item";
                //[Line](<=)
                TTypeStruct*Info=nullptr;
                if (RTTI.Register<SelfClass>(Info,Name))
                {
                  return Info;
                }
                else
                {
                  Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                  Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
                }
                //[Line](=>)
                Info->AddMemberDEF(Sys$$<TAutoPtr<t_arr_body>>::GetRTTI(RTTI),"arrbody",int(&(((SelfClass*)nullptr)->*(&SelfClass::arrbody))),"DEF","$");
                Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
                //[Line](<=)
                {
                  RTTI.OnRegEnd(Info);
                }
                {
                }
                Info->SelfTesting();
                return Info;
              }
              static string GetFullName()
              {
                //[Line](=>)
                return "t_var_fv_item";
                //[Line](<=)
              }
            };
          public:
            //<<<<<+=====t_var_fv_item
          public:
            void Use(i_visitor&A)
            {
              A.Do(this);
            }
            static SelfClass*UberCast(ParentClass*ptr)
            {
              return i_visitor::UberCast<SelfClass>(ptr);
            }
          public:
            bool go(i_dev&dev)
            {
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              O+=dev.go_auto(arrbody);
              if (!ok)return ok;
              O+=dev.go_auto(value);
              if (!ok)return ok;
              return ok;
            }
          };
          class t_body
          {
            //=====+>>>>>t_body
            //==Declaration SelfClass,ParentClass,OwnerClass==//
            //[Line](=>)
          public:
            typedef t_var_fv_end OwnerClass;
            //[Line](<=)
            //[Line](=>)
          public:
            typedef t_body SelfClass;
            //[Line](<=)
            //==Declaration Members==//
          public:
            //[Line](=>)
            TAutoPtr<i_fv_item> body;
            //[Line](<=)
            //==Declaration DoReset==//
          public:
            void DoReset()
            {
              {
              }
              detail::FieldTryDoReset(this->body);
            }
            //==Declaration Constructors==//
          public:
            t_body(const t_body&)=delete;
            t_body()
            {
              DoReset();
            };
            //==Declaration Equal Operator==//
            //==Declaration Copy Constructor==//
          public:
            t_body(t_body&&_Right)
            {
              operator=(std::move(_Right));
            }
            void operator=(t_body&&_Right)
            {
              if (&_Right==this)return;
              {
              }
              //[Line](=>)
              this->body=std::move(_Right.body);
              //[Line](<=)
            }
            //==Declaration GetRTTI==//
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              template<class QAP_RTTI>
              static metatype*GetRTTI(QAP_RTTI&RTTI)
              {
                //[Line](=>)
                static const string Name="t_body";
                //[Line](<=)
                TTypeStruct*Info=nullptr;
                if (RTTI.Register<SelfClass>(Info,Name))
                {
                  return Info;
                }
                else
                {
                  Info->SubType=nullptr;
                  Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
                }
                //[Line](=>)
                Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_item>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
                //[Line](<=)
                {
                  RTTI.OnRegEnd(Info);
                }
                {
                }
                Info->SelfTesting();
                return Info;
              }
              static string GetFullName()
              {
                //[Line](=>)
                return "t_body";
                //[Line](<=)
              }
            };
          public:
            //<<<<<+=====t_body
          public:
            bool go(i_dev&dev)
            {
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              D+=dev.go_auto(body);
              if (!ok)return ok;
              return ok;
            }
          };
          class t_item
          {
            //=====+>>>>>t_item
            //==Declaration SelfClass,ParentClass,OwnerClass==//
            //[Line](=>)
          public:
            typedef t_var_fv_end OwnerClass;
            //[Line](<=)
            //[Line](=>)
          public:
            typedef t_item SelfClass;
            //[Line](<=)
            //==Declaration Members==//
          public:
            //[Line](=>)
            t_sep sep0;
            TAutoPtr<t_const_with_sep> cv;
            t_sep sep1;
            string name;
            t_sep sep2;
            t_body body;
            t_sep sep3;
            //[Line](<=)
            //==Declaration DoReset==//
          public:
            void DoReset()
            {
              {
              }
              detail::FieldTryDoReset(this->sep0);
              detail::FieldTryDoReset(this->cv);
              detail::FieldTryDoReset(this->sep1);
              detail::FieldTryDoReset(this->name);
              detail::FieldTryDoReset(this->sep2);
              detail::FieldTryDoReset(this->body);
              detail::FieldTryDoReset(this->sep3);
            }
            //==Declaration Constructors==//
          public:
            t_item(const t_item&)=delete;
            t_item()
            {
              DoReset();
            };
            //==Declaration Equal Operator==//
            //==Declaration Copy Constructor==//
          public:
            t_item(t_item&&_Right)
            {
              operator=(std::move(_Right));
            }
            void operator=(t_item&&_Right)
            {
              if (&_Right==this)return;
              {
              }
              //[Line](=>)
              this->sep0=std::move(_Right.sep0);
              this->cv=std::move(_Right.cv);
              this->sep1=std::move(_Right.sep1);
              this->name=std::move(_Right.name);
              this->sep2=std::move(_Right.sep2);
              this->body=std::move(_Right.body);
              this->sep3=std::move(_Right.sep3);
              //[Line](<=)
            }
            //==Declaration GetRTTI==//
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              template<class QAP_RTTI>
              static metatype*GetRTTI(QAP_RTTI&RTTI)
              {
                //[Line](=>)
                static const string Name="t_item";
                //[Line](<=)
                TTypeStruct*Info=nullptr;
                if (RTTI.Register<SelfClass>(Info,Name))
                {
                  return Info;
                }
                else
                {
                  Info->SubType=nullptr;
                  Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
                }
                //[Line](=>)
                Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
                Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
                Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
                Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
                Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
                Info->AddMemberDEF(Sys$$<t_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
                Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
                //[Line](<=)
                {
                  RTTI.OnRegEnd(Info);
                }
                {
                }
                Info->SelfTesting();
                return Info;
              }
              static string GetFullName()
              {
                //[Line](=>)
                return "t_item";
                //[Line](<=)
              }
            };
          public:
            //<<<<<+=====t_item
          public:
            bool go(i_dev&dev)
            {
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              M+=dev.go_const(",");
              if (!ok)return ok;
              O+=dev.go_auto(sep0);
              if (!ok)return ok;
              O+=dev.go_auto(cv);
              if (!ok)return ok;
              O+=dev.go_auto(sep1);
              if (!ok)return ok;
              M+=dev.go_str<t_name>(name);
              if (!ok)return ok;
              O+=dev.go_auto(sep2);
              if (!ok)return ok;
              M+=dev.go_auto(body);
              if (!ok)return ok;
              O+=dev.go_auto(sep3);
              if (!ok)return ok;
              return ok;
            }
          };
        public:
          //=====+>>>>>t_var_fv_end
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_fv_stat OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_var_fv_end SelfClass;
        public:
          typedef i_fv_end ParentClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          TAutoPtr<t_body> body;
          vector<t_item> arr;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
              //[Line](=>)
              detail::TryDoReset<SelfClass>(this);
              //[Line](<=)
            }
            detail::FieldTryDoReset(this->body);
            detail::FieldTryDoReset(this->arr);
          }
          //==Declaration Constructors==//
        public:
          t_var_fv_end(const t_var_fv_end&)=delete;
          t_var_fv_end()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_var_fv_end(t_var_fv_end&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_var_fv_end&&_Right)
          {
            //[Line](=>)
            struct hidden
            {
              static void foo(i_fv_end(*)=(SelfClass*)nullptr) {}};
            //[Line](<=)
            if (&_Right==this)return;
            {
              //[Line](=>)
              i_fv_end::operator=(std::move(_Right));
              //[Line](<=)
            }
            //[Line](=>)
            this->body=std::move(_Right.body);
            this->arr=std::move(_Right.arr);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_var_fv_end";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<TAutoPtr<t_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
              Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
                //[Line](=>)
                Info->AddNested(Sys$$<t_func_fv_item>::GetRTTI(RTTI));
                Info->AddNested(Sys$$<t_var_fv_item>::GetRTTI(RTTI));
                Info->AddNested(Sys$$<t_body>::GetRTTI(RTTI));
                Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
                //[Line](<=)
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_var_fv_end";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_var_fv_end
        public:
          void Use(i_visitor&A)
          {
            A.Do(this);
          }
          static SelfClass*UberCast(ParentClass*ptr)
          {
            return i_visitor::UberCast<SelfClass>(ptr);
          }
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            O+=dev.go_auto(body);
            if (!ok)return ok;
            O+=dev.go_auto(arr);
            if (!ok)return ok;
            M+=dev.go_const(";");
            if (!ok)return ok;
            return ok;
          }
        public:
          //class t_static_visitor{
          //public:
          //  #define F(TYPE)typedef t_var_fv_end::TYPE TYPE;
          //  F(i_fv_item);
          //  F(t_func_fv_item);
          //  F(t_var_fv_item);
          //  F(t_body);
          //  F(t_item);
          //  #undef F
          //public:
          //  void Do(t_func_fv_item&ref){}
          //  void Do(t_var_fv_item&ref){}
          //  void Do(t_body&ref){}
          //  void Do(t_item&ref){}
          //};
        };
      public:
        //=====+>>>>>t_fv_stat
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_type_expr OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_fv_stat SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep_wa;
        vector<t_keyword> keywords;
        TAutoPtr<t_type_expr> type;
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep0;
        TAutoPtr<t_func_path> path;
        t_name_part name;
        t_sep sep1;
        TAutoPtr<i_fv_end> way;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep_wa);
          detail::FieldTryDoReset(this->keywords);
          detail::FieldTryDoReset(this->type);
          detail::FieldTryDoReset(this->cv);
          detail::FieldTryDoReset(this->sep0);
          detail::FieldTryDoReset(this->path);
          detail::FieldTryDoReset(this->name);
          detail::FieldTryDoReset(this->sep1);
          detail::FieldTryDoReset(this->way);
        }
        //==Declaration Constructors==//
      public:
        t_fv_stat(const t_fv_stat&)=delete;
        t_fv_stat()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_fv_stat(t_fv_stat&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_fv_stat&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep_wa=std::move(_Right.sep_wa);
          this->keywords=std::move(_Right.keywords);
          this->type=std::move(_Right.type);
          this->cv=std::move(_Right.cv);
          this->sep0=std::move(_Right.sep0);
          this->path=std::move(_Right.path);
          this->name=std::move(_Right.name);
          this->sep1=std::move(_Right.sep1);
          this->way=std::move(_Right.way);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_fv_stat";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep_wa",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep_wa))),"DEF","$");
            Info->AddMemberDEF(Sys$$<vector<t_keyword>>::GetRTTI(RTTI),"keywords",int(&(((SelfClass*)nullptr)->*(&SelfClass::keywords))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_name_part>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
            Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_end>>::GetRTTI(RTTI),"way",int(&(((SelfClass*)nullptr)->*(&SelfClass::way))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
              //[Line](=>)
              Info->AddNested(Sys$$<t_impl_func_body>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_zero_func_body>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_delete_func_body>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_func_fv_end>::GetRTTI(RTTI));
              Info->AddNested(Sys$$<t_var_fv_end>::GetRTTI(RTTI));
              //[Line](<=)
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_fv_stat";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_fv_stat
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep_wa);
          if (!ok)return ok;
          O+=dev.go_auto(keywords);
          if (!ok)return ok;
          M+=dev.go_auto(type);
          if (!ok)return ok;
          O+=dev.go_auto(cv);
          if (!ok)return ok;
          O+=dev.go_auto(sep0);
          if (!ok)return ok;
          O+=dev.go_auto(path);
          if (!ok)return ok;
          M+=dev.go_auto(name);
          if (!ok)return ok;
          O+=dev.go_auto(sep1);
          if (!ok)return ok;
          M+=dev.go_auto(way);
          if (!ok)return ok;
          return ok;
        }
      public:
        //class t_static_visitor{
        //public:
        //  #define F(TYPE)typedef t_fv_stat::TYPE TYPE;
        //  F(i_fv_body);
        //  F(i_fv_end);
        //  F(t_impl_func_body);
        //  F(t_zero_func_body);
        //  F(t_delete_func_body);
        //  F(t_func_fv_end);
        //  F(t_var_fv_end);
        //  #undef F
        //public:
        //  void Do(t_impl_func_body&ref){}
        //  void Do(t_zero_func_body&ref){}
        //  void Do(t_delete_func_body&ref){}
        //  void Do(t_func_fv_end&ref){}
        //  void Do(t_var_fv_end&ref){}
        //};
      };
    public:
      //=====+>>>>>t_type_expr
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_fv_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_type_expr SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      TAutoPtr<t_first_scope> first;
      t_scopes scopes;
      vector<t_ptr> ptrs;
      TAutoPtr<t_ref> ref;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->first);
        detail::FieldTryDoReset(this->scopes);
        detail::FieldTryDoReset(this->ptrs);
        detail::FieldTryDoReset(this->ref);
      }
      //==Declaration Constructors==//
    public:
      t_type_expr(const t_type_expr&)=delete;
      t_type_expr()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_type_expr(t_type_expr&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_type_expr&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->first=std::move(_Right.first);
        this->scopes=std::move(_Right.scopes);
        this->ptrs=std::move(_Right.ptrs);
        this->ref=std::move(_Right.ref);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_type_expr";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_first_scope>>::GetRTTI(RTTI),"first",int(&(((SelfClass*)nullptr)->*(&SelfClass::first))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_scopes>::GetRTTI(RTTI),"scopes",int(&(((SelfClass*)nullptr)->*(&SelfClass::scopes))),"DEF","$");
          Info->AddMemberDEF(Sys$$<vector<t_ptr>>::GetRTTI(RTTI),"ptrs",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptrs))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_ref>>::GetRTTI(RTTI),"ref",int(&(((SelfClass*)nullptr)->*(&SelfClass::ref))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
            //[Line](=>)
            Info->AddNested(Sys$$<t_first_scope>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_const_with_sep>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_type_with_sep>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_scope_with_sep>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_scope>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_ptr>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_ref>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_scopes>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_keyword>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_name_part>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_arr_body>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_brackets_name_part>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_raw_name_part>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_pfunc_func_param>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_var_args_func_param>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_type_func_param>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_expr_func_param>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_expr_ext>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_func_ref_ext>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_func_param_value>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_func_param>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_func_params>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_fv_stat>::GetRTTI(RTTI));
            //[Line](<=)
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_type_expr";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_type_expr
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(first);
        if (!ok)return ok;
        M+=dev.go_auto(scopes);
        if (!ok)return ok;
        O+=dev.go_auto(ptrs);
        if (!ok)return ok;
        O+=dev.go_auto(ref);
        if (!ok)return ok;
        return ok;
      }
    public:
      //class t_static_visitor{
      //public:
      //  #define F(TYPE)typedef t_type_expr::TYPE TYPE;
      //  F(i_name_part);
      //  F(i_func_param);
      //  F(i_func_param_value);
      //  F(t_first_scope);
      //  F(t_const_with_sep);
      //  F(t_type_with_sep);
      //  F(t_scope_with_sep);
      //  F(t_scope);
      //  F(t_ptr);
      //  F(t_ref);
      //  F(t_scopes);
      //  F(t_keyword);
      //  F(t_type_expr_with_sep_and_cv);
      //  F(t_name_part);
      //  F(t_arr_body);
      //  F(t_brackets_name_part);
      //  F(t_raw_name_part);
      //  F(t_pfunc_func_param);
      //  F(t_var_args_func_param);
      //  F(t_type_func_param);
      //  F(t_expr_func_param);
      //  F(t_expr_ext);
      //  F(t_func_ref_ext);
      //  F(t_func_param_value);
      //  F(t_func_param);
      //  F(t_func_params);
      //  F(t_fv_stat);
      //  #undef F
      //public:
      //  void Do(t_first_scope&ref){}
      //  void Do(t_const_with_sep&ref){}
      //  void Do(t_type_with_sep&ref){}
      //  void Do(t_scope_with_sep&ref){}
      //  void Do(t_scope&ref){}
      //  void Do(t_ptr&ref){}
      //  void Do(t_ref&ref){}
      //  void Do(t_scopes&ref){}
      //  void Do(t_keyword&ref){}
      //  void Do(t_type_expr_with_sep_and_cv&ref){}
      //  void Do(t_name_part&ref){}
      //  void Do(t_arr_body&ref){}
      //  void Do(t_brackets_name_part&ref){}
      //  void Do(t_raw_name_part&ref){}
      //  void Do(t_pfunc_func_param&ref){}
      //  void Do(t_var_args_func_param&ref){}
      //  void Do(t_type_func_param&ref){}
      //  void Do(t_expr_func_param&ref){}
      //  void Do(t_expr_ext&ref){}
      //  void Do(t_func_ref_ext&ref){}
      //  void Do(t_func_param_value&ref){}
      //  void Do(t_func_param&ref){}
      //  void Do(t_func_params&ref){}
      //  void Do(t_fv_stat&ref){}
      //};
    };
  public:
    //=====+>>>>>t_fv_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_fv_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_type_expr::t_fv_stat body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_fv_class_stat(const t_fv_class_stat&)=delete;
    t_fv_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_fv_class_stat(t_fv_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_fv_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_fv_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_type_expr::t_fv_stat>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_type_expr>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_fv_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_fv_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_typedef_class_stat:public i_class_stat
  {
    //=====+>>>>>t_typedef_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_typedef_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    t_fv_class_stat::t_type_expr::t_fv_stat body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_typedef_class_stat(const t_typedef_class_stat&)=delete;
    t_typedef_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_typedef_class_stat(t_typedef_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_typedef_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_typedef_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_fv_stat>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_typedef_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_typedef_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("typedef");
      if (!ok)return ok;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      M+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_call_param
  {
    //=====+>>>>>t_call_param
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_call_param SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep0;
    t_expr expr;
    t_sep sep1;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->sep0);
      detail::FieldTryDoReset(this->expr);
      detail::FieldTryDoReset(this->sep1);
    }
    //==Declaration Constructors==//
  public:
    t_call_param(const t_call_param&)=delete;
    t_call_param()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_call_param(t_call_param&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_call_param&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->sep0=std::move(_Right.sep0);
      this->expr=std::move(_Right.expr);
      this->sep1=std::move(_Right.sep1);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_call_param";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_call_param";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_call_param
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if (!ok)return ok;
      M+=dev.go_auto(expr);
      if (!ok)return ok;
      O+=dev.go_auto(sep1);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_call_expr:public i_expr
  {
    //=====+>>>>>t_call_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_call_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string func;
    t_sep sep;
    vector<t_call_param> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->func);
      detail::FieldTryDoReset(this->sep);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_call_expr(const t_call_expr&)=delete;
    t_call_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_call_expr(t_call_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_call_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->func=std::move(_Right.func);
      this->sep=std::move(_Right.sep);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_call_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"func",int(&(((SelfClass*)nullptr)->*(&SelfClass::func))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_call_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_call_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_call_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_str<t_name>(func);
      if (!ok)return ok;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      M+=dev.go_const("(");
      if (!ok)return ok;
      O+=dev.go_vec(arr,",");
      if (!ok)return ok;
      M+=dev.go_const(")");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_real
  {
  public:
    class t_f
    {
      //=====+>>>>>t_f
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_real OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_f SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      char body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_f(const t_f&)=delete;
      t_f()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_f(t_f&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_f&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_f";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_f";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_f
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=CharMask::fromStr("fF");
        D+=dev.go_any_char(body,g_static_var_0);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_real
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_real SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string bef;
    string aft;
    TAutoPtr<t_f> ext;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->bef);
      detail::FieldTryDoReset(this->aft);
      detail::FieldTryDoReset(this->ext);
    }
    //==Declaration Constructors==//
  public:
    t_real(const t_real&)=delete;
    t_real()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_real(t_real&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_real&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->bef=std::move(_Right.bef);
      this->aft=std::move(_Right.aft);
      this->ext=std::move(_Right.ext);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_real";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_f>>::GetRTTI(RTTI),"ext",int(&(((SelfClass*)nullptr)->*(&SelfClass::ext))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_f>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_real";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_real
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      M+=dev.go_any(bef,g_static_var_0);
      if (!ok)return ok;
      M+=dev.go_const(".");
      if (!ok)return ok;
      static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
      O+=dev.go_any(aft,g_static_var_2);
      if (!ok)return ok;
      O+=dev.go_auto(ext);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_bool_expr:public i_expr
  {
    //=====+>>>>>t_bool_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_bool_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string value;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->value);
    }
    //==Declaration Constructors==//
  public:
    t_bool_expr(const t_bool_expr&)=delete;
    t_bool_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_bool_expr(t_bool_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_bool_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->value=std::move(_Right.value);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_bool_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_bool_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_bool_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_string_expr:public i_expr
  {
    //=====+>>>>>t_string_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_string_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string value;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->value);
    }
    //==Declaration Constructors==//
  public:
    t_string_expr(const t_string_expr&)=delete;
    t_string_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_string_expr(t_string_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_string_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->value=std::move(_Right.value);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_string_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_string_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_string_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_str_item::t_impl>(value);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_char_expr:public i_expr
  {
    //=====+>>>>>t_char_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_char_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string value;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->value);
    }
    //==Declaration Constructors==//
  public:
    t_char_expr(const t_char_expr&)=delete;
    t_char_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_char_expr(t_char_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_char_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->value=std::move(_Right.value);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_char_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_char_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_char_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_char_item::t_impl>(value);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_num_expr:public i_expr
  {
    //=====+>>>>>t_num_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_num_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string value;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->value);
    }
    //==Declaration Constructors==//
  public:
    t_num_expr(const t_num_expr&)=delete;
    t_num_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_num_expr(t_num_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_num_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->value=std::move(_Right.value);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_num_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_num_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_num_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      D+=dev.go_any(value,g_static_var_0);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_real_expr:public i_expr
  {
    //=====+>>>>>t_real_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_real_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string value;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->value);
    }
    //==Declaration Constructors==//
  public:
    t_real_expr(const t_real_expr&)=delete;
    t_real_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_real_expr(t_real_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_real_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->value=std::move(_Right.value);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_real_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_real_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_real_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_real>(value);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_nullptr_expr:public i_expr
  {
    //=====+>>>>>t_nullptr_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_nullptr_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
    }
    //==Declaration Constructors==//
  public:
    t_nullptr_expr(const t_nullptr_expr&)=delete;
    t_nullptr_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_nullptr_expr(t_nullptr_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_nullptr_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_nullptr_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_nullptr_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_nullptr_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("nullptr");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_or_expr:public i_expr
  {
    //=====+>>>>>t_or_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_or_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    vector<t_name> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_or_expr(const t_or_expr&)=delete;
    t_or_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_or_expr(t_or_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_or_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_or_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<vector<t_name>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_or_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_or_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_bin_oper(arr,"|");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_hex_expr:public i_expr
  {
  public:
    class t_impl
    {
      //=====+>>>>>t_impl
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_hex_expr OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_impl SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      char x;
      string value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->x);
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_impl(const t_impl&)=delete;
      t_impl()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_impl(t_impl&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_impl&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->x=std::move(_Right.x);
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_impl";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<char>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_impl";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("0");
        if (!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("xX");
        D+=dev.go_any_char(x,g_static_var_1);
        if (!ok)return ok;
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09afAF"));
        D+=dev.go_any(value,g_static_var_2);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_hex_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_hex_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string value;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->value);
    }
    //==Declaration Constructors==//
  public:
    t_hex_expr(const t_hex_expr&)=delete;
    t_hex_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_hex_expr(t_hex_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_hex_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->value=std::move(_Right.value);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_hex_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_hex_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_hex_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_impl>(value);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_var_expr:public i_expr
  {
  public:
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_var_expr OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_fv_class_stat::t_type_expr::t_type_with_sep body;
      t_sep sep;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->body);
        detail::FieldTryDoReset(this->sep);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->body=std::move(_Right.body);
        this->sep=std::move(_Right.sep);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_type_with_sep>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_auto(body);
        if (!ok)return ok;
        O+=dev.go_auto(sep);
        if (!ok)return ok;
        M+=dev.go_const("::");
        if (!ok)return ok;
        return ok;
      }
    };
    class t_field
    {
      //=====+>>>>>t_field
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_var_expr OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_field SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep bef;
      string name;
      t_sep aft;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->bef);
        detail::FieldTryDoReset(this->name);
        detail::FieldTryDoReset(this->aft);
      }
      //==Declaration Constructors==//
    public:
      t_field(const t_field&)=delete;
      t_field()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_field(t_field&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_field&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->bef=std::move(_Right.bef);
        this->name=std::move(_Right.name);
        this->aft=std::move(_Right.aft);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_field";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_field";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_field
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(bef);
        if (!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if (!ok)return ok;
        O+=dev.go_auto(aft);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_impl
    {
      //=====+>>>>>t_impl
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_var_expr OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_impl SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      vector<t_item> items;
      t_sep sep;
      vector<t_field> arr;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->items);
        detail::FieldTryDoReset(this->sep);
        detail::FieldTryDoReset(this->arr);
      }
      //==Declaration Constructors==//
    public:
      t_impl(const t_impl&)=delete;
      t_impl()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_impl(t_impl&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_impl&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->items=std::move(_Right.items);
        this->sep=std::move(_Right.sep);
        this->arr=std::move(_Right.arr);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_impl";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"items",int(&(((SelfClass*)nullptr)->*(&SelfClass::items))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
          Info->AddMemberDEF(Sys$$<vector<t_field>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_impl";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(items);
        if (!ok)return ok;
        O+=dev.go_auto(sep);
        if (!ok)return ok;
        M+=dev.go_vec(arr,".");
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_var_expr
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_var_expr SelfClass;
  public:
    typedef i_expr ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string name;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->name);
    }
    //==Declaration Constructors==//
  public:
    t_var_expr(const t_var_expr&)=delete;
    t_var_expr()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_var_expr(t_var_expr&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_var_expr&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_expr::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->name=std::move(_Right.name);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_var_expr";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_field>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_var_expr";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_var_expr
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_impl>(name);
      if (!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_var_expr::TYPE TYPE;
    //  F(t_item);
    //  F(t_field);
    //  F(t_impl);
    //  #undef F
    //public:
    //  void Do(t_item&ref){}
    //  void Do(t_field&ref){}
    //  void Do(t_impl&ref){}
    //};
  };
  class t_ctor_init_list
  {
  public:
    class t_init_param
    {
      //=====+>>>>>t_init_param
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_ctor_init_list OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_init_param SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep0;
      string name;
      vector<t_call_param> arr;
      t_sep sep1;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->name);
        detail::FieldTryDoReset(this->arr);
        detail::FieldTryDoReset(this->sep1);
      }
      //==Declaration Constructors==//
    public:
      t_init_param(const t_init_param&)=delete;
      t_init_param()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_init_param(t_init_param&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_init_param&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->sep0=std::move(_Right.sep0);
        this->name=std::move(_Right.name);
        this->arr=std::move(_Right.arr);
        this->sep1=std::move(_Right.sep1);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_init_param";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          Info->AddMemberDEF(Sys$$<vector<t_call_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_init_param";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_init_param
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if (!ok)return ok;
        M+=dev.go_const("(");
        if (!ok)return ok;
        O+=dev.go_vec(arr,",");
        if (!ok)return ok;
        M+=dev.go_const(")");
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_ctor_init_list
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_ctor_init_list SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    vector<t_init_param> params;
    t_sep sep;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->params);
      detail::FieldTryDoReset(this->sep);
    }
    //==Declaration Constructors==//
  public:
    t_ctor_init_list(const t_ctor_init_list&)=delete;
    t_ctor_init_list()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_ctor_init_list(t_ctor_init_list&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_ctor_init_list&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->params=std::move(_Right.params);
      this->sep=std::move(_Right.sep);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_ctor_init_list";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<vector<t_init_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_init_param>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_ctor_init_list";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_ctor_init_list
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const(":");
      if (!ok)return ok;
      M+=dev.go_vec(params,",");
      if (!ok)return ok;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_zero_func_body:public i_func_body
  {
    //=====+>>>>>t_zero_func_body
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_zero_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
    }
    //==Declaration Constructors==//
  public:
    t_zero_func_body(const t_zero_func_body&)=delete;
    t_zero_func_body()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_zero_func_body(t_zero_func_body&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_zero_func_body&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_func_body::operator=(std::move(_Right));
        //[Line](<=)
      }
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_zero_func_body";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_zero_func_body";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_zero_func_body
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("=0;");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_null_func_body:public i_func_body
  {
    //=====+>>>>>t_null_func_body
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_null_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep);
    }
    //==Declaration Constructors==//
  public:
    t_null_func_body(const t_null_func_body&)=delete;
    t_null_func_body()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_null_func_body(t_null_func_body&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_null_func_body&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_func_body::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_null_func_body";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_null_func_body";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_null_func_body
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      M+=dev.go_const(";");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_delete_func_body:public i_func_body
  {
    //=====+>>>>>t_delete_func_body
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_delete_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
    }
    //==Declaration Constructors==//
  public:
    t_delete_func_body(const t_delete_func_body&)=delete;
    t_delete_func_body()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_delete_func_body(t_delete_func_body&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_delete_func_body&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_func_body::operator=(std::move(_Right));
        //[Line](<=)
      }
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_delete_func_body";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_delete_func_body";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_delete_func_body
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("=delete;");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_impl_func_body:public i_func_body
  {
    //=====+>>>>>t_impl_func_body
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_impl_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    TAutoPtr<t_ctor_init_list> init_list;
    t_raw_func_body body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep);
      detail::FieldTryDoReset(this->init_list);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_impl_func_body(const t_impl_func_body&)=delete;
    t_impl_func_body()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_impl_func_body(t_impl_func_body&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_impl_func_body&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_func_body::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      this->init_list=std::move(_Right.init_list);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_impl_func_body";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_ctor_init_list>>::GetRTTI(RTTI),"init_list",int(&(((SelfClass*)nullptr)->*(&SelfClass::init_list))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_raw_func_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_impl_func_body";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_impl_func_body
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      O+=dev.go_auto(init_list);
      if (!ok)return ok;
      M+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_dtor_class_stat:public i_class_stat
  {
    //=====+>>>>>t_dtor_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_dtor_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep0;
    TAutoPtr<t_func_path> path;
    string name;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<i_func_body> body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep0);
      detail::FieldTryDoReset(this->path);
      detail::FieldTryDoReset(this->name);
      detail::FieldTryDoReset(this->sep1);
      detail::FieldTryDoReset(this->params);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_dtor_class_stat(const t_dtor_class_stat&)=delete;
    t_dtor_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_dtor_class_stat(t_dtor_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_dtor_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep0=std::move(_Right.sep0);
      this->path=std::move(_Right.path);
      this->name=std::move(_Right.name);
      this->sep1=std::move(_Right.sep1);
      this->params=std::move(_Right.params);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_dtor_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_dtor_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_dtor_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(path);
      if (!ok)return ok;
      M+=dev.go_const("~");
      if (!ok)return ok;
      O+=dev.go_auto(sep0);
      if (!ok)return ok;
      M+=dev.go_str<t_name>(name);
      if (!ok)return ok;
      O+=dev.go_auto(sep1);
      if (!ok)return ok;
      M+=dev.go_auto(params);
      if (!ok)return ok;
      M+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_ctor_class_stat:public i_class_stat
  {
  public:
    class t_impl
    {
    public:
      class t_explicit
      {
        //=====+>>>>>t_explicit
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_impl OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_explicit SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep);
        }
        //==Declaration Constructors==//
      public:
        t_explicit(const t_explicit&)=delete;
        t_explicit()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_explicit(t_explicit&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_explicit&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_explicit";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_explicit";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_explicit
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("explicit");
          if (!ok)return ok;
          M+=dev.go_auto(sep);
          if (!ok)return ok;
          return ok;
        }
      };
    public:
      //=====+>>>>>t_impl
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_ctor_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_impl SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      TAutoPtr<t_explicit> prefix;
      TAutoPtr<t_func_path> path;
      string name;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<i_func_body> body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->prefix);
        detail::FieldTryDoReset(this->path);
        detail::FieldTryDoReset(this->name);
        detail::FieldTryDoReset(this->params);
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_impl(const t_impl&)=delete;
      t_impl()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_impl(t_impl&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_impl&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->prefix=std::move(_Right.prefix);
        this->path=std::move(_Right.path);
        this->name=std::move(_Right.name);
        this->params=std::move(_Right.params);
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_impl";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_explicit>>::GetRTTI(RTTI),"prefix",int(&(((SelfClass*)nullptr)->*(&SelfClass::prefix))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
            //[Line](=>)
            Info->AddNested(Sys$$<t_explicit>::GetRTTI(RTTI));
            //[Line](<=)
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_impl";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(prefix);
        if (!ok)return ok;
        O+=dev.go_auto(path);
        if (!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if (!ok)return ok;
        M+=dev.go_auto(params);
        if (!ok)return ok;
        M+=dev.go_auto(body);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_ctor_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_ctor_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_impl body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_ctor_class_stat(const t_ctor_class_stat&)=delete;
    t_ctor_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_ctor_class_stat(t_ctor_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_ctor_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_ctor_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_ctor_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_ctor_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_oper_cast_class_stat:public i_class_stat
  {
    //=====+>>>>>t_oper_cast_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_oper_cast_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    TAutoPtr<t_func_path> path;
    t_sep sep0;
    t_fv_class_stat::t_type_expr type;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv;
    TAutoPtr<i_func_body> body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->path);
      detail::FieldTryDoReset(this->sep0);
      detail::FieldTryDoReset(this->type);
      detail::FieldTryDoReset(this->sep1);
      detail::FieldTryDoReset(this->params);
      detail::FieldTryDoReset(this->cv);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_oper_cast_class_stat(const t_oper_cast_class_stat&)=delete;
    t_oper_cast_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_oper_cast_class_stat(t_oper_cast_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_oper_cast_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->path=std::move(_Right.path);
      this->sep0=std::move(_Right.sep0);
      this->type=std::move(_Right.type);
      this->sep1=std::move(_Right.sep1);
      this->params=std::move(_Right.params);
      this->cv=std::move(_Right.cv);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_oper_cast_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_oper_cast_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_oper_cast_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(path);
      if (!ok)return ok;
      M+=dev.go_const("operator");
      if (!ok)return ok;
      O+=dev.go_auto(sep0);
      if (!ok)return ok;
      M+=dev.go_auto(type);
      if (!ok)return ok;
      O+=dev.go_auto(sep1);
      if (!ok)return ok;
      M+=dev.go_auto(params);
      if (!ok)return ok;
      O+=dev.go_auto(cv);
      if (!ok)return ok;
      M+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_common_oper_class_stat:public i_class_stat
  {
  public:
    class t_impl
    {
      //=====+>>>>>t_impl
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_common_oper_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_impl SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      vector<t_fv_class_stat::t_type_expr::t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv0;
      t_sep sep0;
      TAutoPtr<t_func_path> path;
      t_sep sep1;
      string oper;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->keywords);
        detail::FieldTryDoReset(this->type);
        detail::FieldTryDoReset(this->cv0);
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->path);
        detail::FieldTryDoReset(this->sep1);
        detail::FieldTryDoReset(this->oper);
        detail::FieldTryDoReset(this->params);
        detail::FieldTryDoReset(this->cv1);
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_impl(const t_impl&)=delete;
      t_impl()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_impl(t_impl&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_impl&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->keywords=std::move(_Right.keywords);
        this->type=std::move(_Right.type);
        this->cv0=std::move(_Right.cv0);
        this->sep0=std::move(_Right.sep0);
        this->path=std::move(_Right.path);
        this->sep1=std::move(_Right.sep1);
        this->oper=std::move(_Right.oper);
        this->params=std::move(_Right.params);
        this->cv1=std::move(_Right.cv1);
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_impl";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<vector<t_fv_class_stat::t_type_expr::t_keyword>>::GetRTTI(RTTI),"keywords",int(&(((SelfClass*)nullptr)->*(&SelfClass::keywords))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep>>::GetRTTI(RTTI),"cv0",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_impl";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(keywords);
        if (!ok)return ok;
        M+=dev.go_auto(type);
        if (!ok)return ok;
        O+=dev.go_auto(cv0);
        if (!ok)return ok;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        O+=dev.go_auto(path);
        if (!ok)return ok;
        M+=dev.go_const("operator");
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        static const auto g_static_var_7=QapStrFinder::fromArr(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[]",","));
        M+=dev.go_any_str_from_vec(oper,g_static_var_7);
        if (!ok)return ok;
        M+=dev.go_auto(params);
        if (!ok)return ok;
        O+=dev.go_auto(cv1);
        if (!ok)return ok;
        M+=dev.go_auto(body);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_common_oper_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_common_oper_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_impl body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_common_oper_class_stat(const t_common_oper_class_stat&)=delete;
    t_common_oper_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_common_oper_class_stat(t_common_oper_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_common_oper_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_common_oper_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_common_oper_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_common_oper_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_parents
  {
  public:
    class t_item
    {
    public:
      class t_pub
      {
        //=====+>>>>>t_pub
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_item OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_pub SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_access_mod mod;
        t_sep sep;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->mod);
          detail::FieldTryDoReset(this->sep);
        }
        //==Declaration Constructors==//
      public:
        t_pub(const t_pub&)=delete;
        t_pub()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_pub(t_pub&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_pub&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->mod=std::move(_Right.mod);
          this->sep=std::move(_Right.sep);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_pub";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_access_mod>::GetRTTI(RTTI),"mod",int(&(((SelfClass*)nullptr)->*(&SelfClass::mod))),"DEF","$");
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_pub";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_pub
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(mod);
          if (!ok)return ok;
          O+=dev.go_auto(sep);
          if (!ok)return ok;
          return ok;
        }
      };
    public:
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_parents OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep;
      TAutoPtr<t_pub> pub;
      string name;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->sep);
        detail::FieldTryDoReset(this->pub);
        detail::FieldTryDoReset(this->name);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->sep=std::move(_Right.sep);
        this->pub=std::move(_Right.pub);
        this->name=std::move(_Right.name);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_pub>>::GetRTTI(RTTI),"pub",int(&(((SelfClass*)nullptr)->*(&SelfClass::pub))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
            //[Line](=>)
            Info->AddNested(Sys$$<t_pub>::GetRTTI(RTTI));
            //[Line](<=)
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep);
        if (!ok)return ok;
        O+=dev.go_auto(pub);
        if (!ok)return ok;
        M+=dev.go_str<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>(name);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_parents
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_parents SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    vector<t_item> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->sep);
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_parents(const t_parents&)=delete;
    t_parents()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_parents(t_parents&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_parents&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_parents";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_parents";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_parents
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const(":");
      if (!ok)return ok;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      M+=dev.go_vec(arr,",");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_class_body
  {
    //=====+>>>>>t_class_body
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_class_body SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    vector<TAutoPtr<i_class_stat>> arr;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->arr);
    }
    //==Declaration Constructors==//
  public:
    t_class_body(const t_class_body&)=delete;
    t_class_body()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_class_body(t_class_body&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_class_body&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->arr=std::move(_Right.arr);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_class_body";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_class_stat>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_class_body";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_class_body
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{");
      if (!ok)return ok;
      O+=dev.go_auto(arr);
      if (!ok)return ok;
      M+=dev.go_const("}");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_class
  {
    //=====+>>>>>t_class
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_class SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string keyword;
    t_sep sep0;
    string name;
    t_sep sep1;
    TAutoPtr<t_parents> parents;
    t_sep sep2;
    TAutoPtr<t_class_body> body;
    t_sep sep3;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->keyword);
      detail::FieldTryDoReset(this->sep0);
      detail::FieldTryDoReset(this->name);
      detail::FieldTryDoReset(this->sep1);
      detail::FieldTryDoReset(this->parents);
      detail::FieldTryDoReset(this->sep2);
      detail::FieldTryDoReset(this->body);
      detail::FieldTryDoReset(this->sep3);
    }
    //==Declaration Constructors==//
  public:
    t_class(const t_class&)=delete;
    t_class()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_class(t_class&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_class&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->keyword=std::move(_Right.keyword);
      this->sep0=std::move(_Right.sep0);
      this->name=std::move(_Right.name);
      this->sep1=std::move(_Right.sep1);
      this->parents=std::move(_Right.parents);
      this->sep2=std::move(_Right.sep2);
      this->body=std::move(_Right.body);
      this->sep3=std::move(_Right.sep3);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_class";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_parents>>::GetRTTI(RTTI),"parents",int(&(((SelfClass*)nullptr)->*(&SelfClass::parents))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_class_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_class";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_class
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
      M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if (!ok)return ok;
      O+=dev.go_auto(sep0);
      if (!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if (!ok)return ok;
      O+=dev.go_auto(sep1);
      if (!ok)return ok;
      O+=dev.go_auto(parents);
      if (!ok)return ok;
      O+=dev.go_auto(sep2);
      if (!ok)return ok;
      O+=dev.go_auto(body);
      if (!ok)return ok;
      O+=dev.go_auto(sep3);
      if (!ok)return ok;
      M+=dev.go_const(";");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_namespace_class_stat:public i_class_stat
  {
    //=====+>>>>>t_namespace_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_namespace_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep0;
    string name;
    t_sep sep1;
    t_class_body body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep0);
      detail::FieldTryDoReset(this->name);
      detail::FieldTryDoReset(this->sep1);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_namespace_class_stat(const t_namespace_class_stat&)=delete;
    t_namespace_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_namespace_class_stat(t_namespace_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_namespace_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep0=std::move(_Right.sep0);
      this->name=std::move(_Right.name);
      this->sep1=std::move(_Right.sep1);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_namespace_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_class_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_namespace_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_namespace_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("namespace");
      if (!ok)return ok;
      O+=dev.go_auto(sep0);
      if (!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if (!ok)return ok;
      O+=dev.go_auto(sep1);
      if (!ok)return ok;
      M+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_template_class_stat:public i_class_stat
  {
  public:
    //===>>===i_template_body_visitor
    class i_template_body;
    class t_common_oper_template_body;
    class t_ctor_template_body;
    class t_func_template_body;
    class t_class_template_body;
    class i_template_body_visitor
    {
    public:
      typedef t_template_class_stat::i_template_body i_template_body;
    public:
      virtual void Do(t_common_oper_template_body*p)=0;
      virtual void Do(t_ctor_template_body*p)=0;
      virtual void Do(t_func_template_body*p)=0;
      virtual void Do(t_class_template_body*p)=0;
    public:
      typedef t_template_class_stat::t_common_oper_template_body t_common_oper_template_body;
      typedef t_template_class_stat::t_ctor_template_body t_ctor_template_body;
      typedef t_template_class_stat::t_func_template_body t_func_template_body;
      typedef t_template_class_stat::t_class_template_body t_class_template_body;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_common_oper_template_body*p)
        {
          ptr=get(p);
        } void Do(t_ctor_template_body*p)
        {
          ptr=get(p);
        } void Do(t_func_template_body*p)
        {
          ptr=get(p);
        } void Do(t_class_template_body*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_body*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_template_body_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
    //===<<===i_template_body_visitor
    //class t_visitor:public t_template_class_stat::i_template_body_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_common_oper_template_body*p){}
    //  void Do(t_ctor_template_body*p){}
    //  void Do(t_func_template_body*p){}
    //  void Do(t_class_template_body*p){}
    //};
  public:
    class i_template_body
    {
      //=====+>>>>>i_template_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef i_template_body SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
      }
      //==Declaration Constructors==//
    public:
      i_template_body(const i_template_body&)=delete;
      i_template_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      i_template_body(i_template_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(i_template_body&&_Right)
      {
        if (&_Right==this)return;
        {
        }
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="i_template_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "i_template_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====i_template_body
    public:
      typedef i_template_body_visitor i_visitor;
      virtual void Use(i_visitor&A)
      {
        QapDebugMsg("no way.");/*A.Do(this);*/
      }
    public:
      virtual bool go(i_dev&dev)
      {
        QapDebugMsg("no way.");
        return false;
      };
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        template<int>
        bool load()
        {
          //[Line](=>)
          go_for<t_common_oper_template_body>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_ctor_template_body>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_func_template_body>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_class_template_body>();
          //[Line](<=)
          (void)count;
          (void)first_id;
          (void)out_arr;
          (void)this;
          main();
          return scope.ok;
        }
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          vector<t_out_rec> out_arr;
          static int out_arr_size=0;
          out_arr.reserve(out_arr_size);
          t_fallback scope(dev,__FUNCTION__);
          int count=0;
          int first_id=-1;
          auto&Env=dev.getEnv();
          static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
          t_poly_tool::go_poly<SelfClass> solver_impl=
          {
            out_arr,dev,ref,scope,count,first_id,strbasetype,Env
          };
          t_poly_impl&solver=(t_poly_impl&)solver_impl;
          solver.load<0>();
          out_arr_size=out_arr.size();
          return scope.ok;
        }
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          t_fallback scope(dev,__FUNCTION__);
          bool&ok=scope.ok;
          if (!std::is_polymorphic<SelfClass>::value)if (!ref)
            {
              return false;
            }
          if (!ref)return false;
          QapAssert(ref);
          auto*p=ref.get();
          ok=p->go(dev);
          return ok;
        }
      };
    };
  public:
    //===>>===i_template_param_visitor
    class i_template_param;
    class t_name_template_param;
    class t_type_template_param;
    class i_template_param_visitor
    {
    public:
      typedef t_template_class_stat::i_template_param i_template_param;
    public:
      virtual void Do(t_name_template_param*p)=0;
      virtual void Do(t_type_template_param*p)=0;
    public:
      typedef t_template_class_stat::t_name_template_param t_name_template_param;
      typedef t_template_class_stat::t_type_template_param t_type_template_param;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_name_template_param*p)
        {
          ptr=get(p);
        } void Do(t_type_template_param*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_param*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_template_param_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
    //===<<===i_template_param_visitor
    //class t_visitor:public t_template_class_stat::i_template_param_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_name_template_param*p){}
    //  void Do(t_type_template_param*p){}
    //};
  public:
    class i_template_param
    {
      //=====+>>>>>i_template_param
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef i_template_param SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
      }
      //==Declaration Constructors==//
    public:
      i_template_param(const i_template_param&)=delete;
      i_template_param()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      i_template_param(i_template_param&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(i_template_param&&_Right)
      {
        if (&_Right==this)return;
        {
        }
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="i_template_param";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "i_template_param";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====i_template_param
    public:
      typedef i_template_param_visitor i_visitor;
      virtual void Use(i_visitor&A)
      {
        QapDebugMsg("no way.");/*A.Do(this);*/
      }
    public:
      virtual bool go(i_dev&dev)
      {
        QapDebugMsg("no way.");
        return false;
      };
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        template<int>
        bool load()
        {
          //[Line](=>)
          go_for<t_name_template_param>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_type_template_param>();
          //[Line](<=)
          (void)count;
          (void)first_id;
          (void)out_arr;
          (void)this;
          main();
          return scope.ok;
        }
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          vector<t_out_rec> out_arr;
          static int out_arr_size=0;
          out_arr.reserve(out_arr_size);
          t_fallback scope(dev,__FUNCTION__);
          int count=0;
          int first_id=-1;
          auto&Env=dev.getEnv();
          static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
          t_poly_tool::go_poly<SelfClass> solver_impl=
          {
            out_arr,dev,ref,scope,count,first_id,strbasetype,Env
          };
          t_poly_impl&solver=(t_poly_impl&)solver_impl;
          solver.load<0>();
          out_arr_size=out_arr.size();
          return scope.ok;
        }
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          t_fallback scope(dev,__FUNCTION__);
          bool&ok=scope.ok;
          if (!std::is_polymorphic<SelfClass>::value)if (!ref)
            {
              return false;
            }
          if (!ref)return false;
          QapAssert(ref);
          auto*p=ref.get();
          ok=p->go(dev);
          return ok;
        }
      };
    };
    class t_template_param
    {
      //=====+>>>>>t_template_param
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_template_param SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep bef;
      TAutoPtr<i_template_param> body;
      t_sep aft;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->bef);
        detail::FieldTryDoReset(this->body);
        detail::FieldTryDoReset(this->aft);
      }
      //==Declaration Constructors==//
    public:
      t_template_param(const t_template_param&)=delete;
      t_template_param()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_template_param(t_template_param&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_template_param&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->bef=std::move(_Right.bef);
        this->body=std::move(_Right.body);
        this->aft=std::move(_Right.aft);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_template_param";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_param>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_template_param";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_template_param
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(bef);
        if (!ok)return ok;
        M+=dev.go_auto(body);
        if (!ok)return ok;
        O+=dev.go_auto(aft);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_concrete_param
    {
    public:
      //===>>===i_body_visitor
      class i_body;
      class t_raw_expr;
      class t_template_expr;
      class i_body_visitor
      {
      public:
        typedef t_concrete_param::i_body i_body;
      public:
        virtual void Do(t_raw_expr*p)=0;
        virtual void Do(t_template_expr*p)=0;
      public:
        typedef t_concrete_param::t_raw_expr t_raw_expr;
        typedef t_concrete_param::t_template_expr t_template_expr;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor
        {
          TYPE*ptr;
          Is():ptr(nullptr) {}
public:
          template<class U>static TYPE*get(U*p)
          {
            return nullptr;
          }
          template<>static TYPE*get<TYPE>(TYPE*p)
          {
            return p;
          }
public:
          void Do(t_raw_expr*p)
          {
            ptr=get(p);
          } void Do(t_template_expr*p)
          {
            ptr=get(p);
          }
        };
        template<class TYPE>
        static TYPE*UberCast(i_body*p)
        {
          if (!p)return nullptr;
          Is<TYPE,i_body_visitor> IS;
          p->Use(IS);
          return IS.ptr;
        }
      };
      //===<<===i_body_visitor
      //class t_visitor:public t_concrete_param::i_body_visitor{
      //public:
      //  class t_dev{
      //  public:
      //  };
      //  t_dev&dev;
      //  t_visitor(t_dev&dev):dev(dev){}
      //public:
      //  void Do(t_raw_expr*p){}
      //  void Do(t_template_expr*p){}
      //};
    public:
      class i_body
      {
        //=====+>>>>>i_body
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_concrete_param OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef i_body SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
        }
        //==Declaration Constructors==//
      public:
        i_body(const i_body&)=delete;
        i_body()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        i_body(i_body&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(i_body&&_Right)
        {
          if (&_Right==this)return;
          {
          }
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="i_body";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "i_body";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====i_body
      public:
        typedef i_body_visitor i_visitor;
        virtual void Use(i_visitor&A)
        {
          QapDebugMsg("no way.");/*A.Do(this);*/
        }
      public:
        virtual bool go(i_dev&dev)
        {
          QapDebugMsg("no way.");
          return false;
        };
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          template<int>
          bool load()
          {
            //[Line](=>)
            go_for<t_raw_expr>();
            //[Line](<=)
            //[Line](=>)
            go_for<t_template_expr>();
            //[Line](<=)
            (void)count;
            (void)first_id;
            (void)out_arr;
            (void)this;
            main();
            return scope.ok;
          }
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            vector<t_out_rec> out_arr;
            static int out_arr_size=0;
            out_arr.reserve(out_arr_size);
            t_fallback scope(dev,__FUNCTION__);
            int count=0;
            int first_id=-1;
            auto&Env=dev.getEnv();
            static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
            t_poly_tool::go_poly<SelfClass> solver_impl=
            {
              out_arr,dev,ref,scope,count,first_id,strbasetype,Env
            };
            t_poly_impl&solver=(t_poly_impl&)solver_impl;
            solver.load<0>();
            out_arr_size=out_arr.size();
            return scope.ok;
          }
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
          {
            t_fallback scope(dev,__FUNCTION__);
            bool&ok=scope.ok;
            if (!std::is_polymorphic<SelfClass>::value)if (!ref)
              {
                return false;
              }
            if (!ref)return false;
            QapAssert(ref);
            auto*p=ref.get();
            ok=p->go(dev);
            return ok;
          }
        };
      };
      class t_raw_expr:public i_body
      {
        //=====+>>>>>t_raw_expr
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_concrete_param OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_raw_expr SelfClass;
      public:
        typedef i_body ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_expr body;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->body);
        }
        //==Declaration Constructors==//
      public:
        t_raw_expr(const t_raw_expr&)=delete;
        t_raw_expr()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_raw_expr(t_raw_expr&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_raw_expr&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_body(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_body::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->body=std::move(_Right.body);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_raw_expr";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_raw_expr";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_raw_expr
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_auto(body);
          if (!ok)return ok;
          return ok;
        }
      };
      class t_template_expr:public i_body
      {
      public:
        class t_main
        {
          //=====+>>>>>t_main
          //==Declaration SelfClass,ParentClass,OwnerClass==//
          //[Line](=>)
        public:
          typedef t_template_expr OwnerClass;
          //[Line](<=)
          //[Line](=>)
        public:
          typedef t_main SelfClass;
          //[Line](<=)
          //==Declaration Members==//
        public:
          //[Line](=>)
          vector<t_fv_class_stat::t_type_expr::t_type_with_sep> arr;
          //[Line](<=)
          //==Declaration DoReset==//
        public:
          void DoReset()
          {
            {
            }
            detail::FieldTryDoReset(this->arr);
          }
          //==Declaration Constructors==//
        public:
          t_main(const t_main&)=delete;
          t_main()
          {
            DoReset();
          };
          //==Declaration Equal Operator==//
          //==Declaration Copy Constructor==//
        public:
          t_main(t_main&&_Right)
          {
            operator=(std::move(_Right));
          }
          void operator=(t_main&&_Right)
          {
            if (&_Right==this)return;
            {
            }
            //[Line](=>)
            this->arr=std::move(_Right.arr);
            //[Line](<=)
          }
          //==Declaration GetRTTI==//
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            template<class QAP_RTTI>
            static metatype*GetRTTI(QAP_RTTI&RTTI)
            {
              //[Line](=>)
              static const string Name="t_main";
              //[Line](<=)
              TTypeStruct*Info=nullptr;
              if (RTTI.Register<SelfClass>(Info,Name))
              {
                return Info;
              }
              else
              {
                Info->SubType=nullptr;
                Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
              }
              //[Line](=>)
              Info->AddMemberDEF(Sys$$<vector<t_fv_class_stat::t_type_expr::t_type_with_sep>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
              //[Line](<=)
              {
                RTTI.OnRegEnd(Info);
              }
              {
              }
              Info->SelfTesting();
              return Info;
            }
            static string GetFullName()
            {
              //[Line](=>)
              return "t_main";
              //[Line](<=)
            }
          };
        public:
          //<<<<<+=====t_main
        public:
          bool go(i_dev&dev)
          {
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_vec(arr,"::");
            if (!ok)return ok;
            return ok;
          }
        };
      public:
        //=====+>>>>>t_template_expr
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_concrete_param OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_template_expr SelfClass;
      public:
        typedef i_body ParentClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_main body;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
            //[Line](=>)
            detail::TryDoReset<SelfClass>(this);
            //[Line](<=)
          }
          detail::FieldTryDoReset(this->body);
        }
        //==Declaration Constructors==//
      public:
        t_template_expr(const t_template_expr&)=delete;
        t_template_expr()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_template_expr(t_template_expr&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_template_expr&&_Right)
        {
          //[Line](=>)
          struct hidden
          {
            static void foo(i_body(*)=(SelfClass*)nullptr) {}};
          //[Line](<=)
          if (&_Right==this)return;
          {
            //[Line](=>)
            i_body::operator=(std::move(_Right));
            //[Line](<=)
          }
          //[Line](=>)
          this->body=std::move(_Right.body);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_template_expr";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_main>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
              //[Line](=>)
              Info->AddNested(Sys$$<t_main>::GetRTTI(RTTI));
              //[Line](<=)
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_template_expr";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_template_expr
      public:
        void Use(i_visitor&A)
        {
          A.Do(this);
        }
        static SelfClass*UberCast(ParentClass*ptr)
        {
          return i_visitor::UberCast<SelfClass>(ptr);
        }
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_diff<t_raw_expr>(body);
          if (!ok)return ok;
          return ok;
        }
      };
    public:
      //=====+>>>>>t_concrete_param
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_concrete_param SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep0;
      TAutoPtr<i_body> body;
      t_sep sep1;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->body);
        detail::FieldTryDoReset(this->sep1);
      }
      //==Declaration Constructors==//
    public:
      t_concrete_param(const t_concrete_param&)=delete;
      t_concrete_param()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_concrete_param(t_concrete_param&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_concrete_param&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->sep0=std::move(_Right.sep0);
        this->body=std::move(_Right.body);
        this->sep1=std::move(_Right.sep1);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_concrete_param";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<i_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
            //[Line](=>)
            Info->AddNested(Sys$$<t_raw_expr>::GetRTTI(RTTI));
            Info->AddNested(Sys$$<t_template_expr>::GetRTTI(RTTI));
            //[Line](<=)
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_concrete_param";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_concrete_param
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_auto(body);
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_concrete_params
    {
      //=====+>>>>>t_concrete_params
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_concrete_params SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      vector<t_concrete_param> arr;
      t_sep sep;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->arr);
        detail::FieldTryDoReset(this->sep);
      }
      //==Declaration Constructors==//
    public:
      t_concrete_params(const t_concrete_params&)=delete;
      t_concrete_params()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_concrete_params(t_concrete_params&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_concrete_params&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->arr=std::move(_Right.arr);
        this->sep=std::move(_Right.sep);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_concrete_params";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<vector<t_concrete_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_concrete_params";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_concrete_params
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("<");
        if (!ok)return ok;
        O+=dev.go_vec(arr,",");
        if (!ok)return ok;
        M+=dev.go_const(">");
        if (!ok)return ok;
        O+=dev.go_auto(sep);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_common_oper_template_body:public i_template_body
    {
      //=====+>>>>>t_common_oper_template_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_common_oper_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_common_oper_class_stat::t_impl body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_common_oper_template_body(const t_common_oper_template_body&)=delete;
      t_common_oper_template_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_common_oper_template_body(t_common_oper_template_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_common_oper_template_body&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_template_body::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_common_oper_template_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_common_oper_class_stat::t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_common_oper_template_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_common_oper_template_body
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_ctor_template_body:public i_template_body
    {
      //=====+>>>>>t_ctor_template_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_ctor_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_ctor_class_stat::t_impl body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_ctor_template_body(const t_ctor_template_body&)=delete;
      t_ctor_template_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_ctor_template_body(t_ctor_template_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_ctor_template_body&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_template_body::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_ctor_template_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_ctor_class_stat::t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_ctor_template_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_ctor_template_body
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_func_template_body:public i_template_body
    {
      //=====+>>>>>t_func_template_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_func_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      vector<t_fv_class_stat::t_type_expr::t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv0;
      t_sep sep0;
      string func_name;
      TAutoPtr<t_concrete_params> concrete_params;
      t_sep sep1;
      t_fv_class_stat::t_type_expr::t_func_params params;
      t_sep sep2;
      TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->keywords);
        detail::FieldTryDoReset(this->type);
        detail::FieldTryDoReset(this->cv0);
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->func_name);
        detail::FieldTryDoReset(this->concrete_params);
        detail::FieldTryDoReset(this->sep1);
        detail::FieldTryDoReset(this->params);
        detail::FieldTryDoReset(this->sep2);
        detail::FieldTryDoReset(this->cv1);
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_func_template_body(const t_func_template_body&)=delete;
      t_func_template_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_func_template_body(t_func_template_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_func_template_body&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_template_body::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->keywords=std::move(_Right.keywords);
        this->type=std::move(_Right.type);
        this->cv0=std::move(_Right.cv0);
        this->sep0=std::move(_Right.sep0);
        this->func_name=std::move(_Right.func_name);
        this->concrete_params=std::move(_Right.concrete_params);
        this->sep1=std::move(_Right.sep1);
        this->params=std::move(_Right.params);
        this->sep2=std::move(_Right.sep2);
        this->cv1=std::move(_Right.cv1);
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_func_template_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<vector<t_fv_class_stat::t_type_expr::t_keyword>>::GetRTTI(RTTI),"keywords",int(&(((SelfClass*)nullptr)->*(&SelfClass::keywords))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep>>::GetRTTI(RTTI),"cv0",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"func_name",int(&(((SelfClass*)nullptr)->*(&SelfClass::func_name))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"concrete_params",int(&(((SelfClass*)nullptr)->*(&SelfClass::concrete_params))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_func_template_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_func_template_body
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(keywords);
        if (!ok)return ok;
        M+=dev.go_auto(type);
        if (!ok)return ok;
        O+=dev.go_auto(cv0);
        if (!ok)return ok;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_str<t_name>(func_name);
        if (!ok)return ok;
        O+=dev.go_auto(concrete_params);
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        M+=dev.go_auto(params);
        if (!ok)return ok;
        O+=dev.go_auto(sep2);
        if (!ok)return ok;
        O+=dev.go_auto(cv1);
        if (!ok)return ok;
        M+=dev.go_auto(body);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_class_template_body:public i_template_body
    {
      //=====+>>>>>t_class_template_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_class_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string keyword;
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_concrete_params> params;
      TAutoPtr<t_parents> parents;
      t_sep sep2;
      TAutoPtr<t_class_body> body;
      t_sep sep3;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->keyword);
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->name);
        detail::FieldTryDoReset(this->sep1);
        detail::FieldTryDoReset(this->params);
        detail::FieldTryDoReset(this->parents);
        detail::FieldTryDoReset(this->sep2);
        detail::FieldTryDoReset(this->body);
        detail::FieldTryDoReset(this->sep3);
      }
      //==Declaration Constructors==//
    public:
      t_class_template_body(const t_class_template_body&)=delete;
      t_class_template_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_class_template_body(t_class_template_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_class_template_body&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_template_body::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->keyword=std::move(_Right.keyword);
        this->sep0=std::move(_Right.sep0);
        this->name=std::move(_Right.name);
        this->sep1=std::move(_Right.sep1);
        this->params=std::move(_Right.params);
        this->parents=std::move(_Right.parents);
        this->sep2=std::move(_Right.sep2);
        this->body=std::move(_Right.body);
        this->sep3=std::move(_Right.sep3);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_class_template_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_parents>>::GetRTTI(RTTI),"parents",int(&(((SelfClass*)nullptr)->*(&SelfClass::parents))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_class_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_class_template_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_class_template_body
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
        M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
        if (!ok)return ok;
        M+=dev.go_auto(sep0);
        if (!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        O+=dev.go_auto(params);
        if (!ok)return ok;
        O+=dev.go_auto(parents);
        if (!ok)return ok;
        O+=dev.go_auto(sep2);
        if (!ok)return ok;
        O+=dev.go_auto(body);
        if (!ok)return ok;
        O+=dev.go_auto(sep3);
        if (!ok)return ok;
        M+=dev.go_const(";");
        if (!ok)return ok;
        return ok;
      }
    };
    class t_head
    {
      //=====+>>>>>t_head
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_head SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep0;
      vector<t_template_param> params;
      t_sep sep1;
      TAutoPtr<i_template_body> body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->params);
        detail::FieldTryDoReset(this->sep1);
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_head(const t_head&)=delete;
      t_head()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_head(t_head&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_head&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->sep0=std::move(_Right.sep0);
        this->params=std::move(_Right.params);
        this->sep1=std::move(_Right.sep1);
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_head";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<vector<t_template_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_head";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_head
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("template");
        if (!ok)return ok;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_const("<");
        if (!ok)return ok;
        O+=dev.go_vec(params,",");
        if (!ok)return ok;
        M+=dev.go_const(">");
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_name_template_param:public i_template_param
    {
    public:
      class t_unsgnd
      {
        //=====+>>>>>t_unsgnd
        //==Declaration SelfClass,ParentClass,OwnerClass==//
        //[Line](=>)
      public:
        typedef t_name_template_param OwnerClass;
        //[Line](<=)
        //[Line](=>)
      public:
        typedef t_unsgnd SelfClass;
        //[Line](<=)
        //==Declaration Members==//
      public:
        //[Line](=>)
        t_sep sep;
        //[Line](<=)
        //==Declaration DoReset==//
      public:
        void DoReset()
        {
          {
          }
          detail::FieldTryDoReset(this->sep);
        }
        //==Declaration Constructors==//
      public:
        t_unsgnd(const t_unsgnd&)=delete;
        t_unsgnd()
        {
          DoReset();
        };
        //==Declaration Equal Operator==//
        //==Declaration Copy Constructor==//
      public:
        t_unsgnd(t_unsgnd&&_Right)
        {
          operator=(std::move(_Right));
        }
        void operator=(t_unsgnd&&_Right)
        {
          if (&_Right==this)return;
          {
          }
          //[Line](=>)
          this->sep=std::move(_Right.sep);
          //[Line](<=)
        }
        //==Declaration GetRTTI==//
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          template<class QAP_RTTI>
          static metatype*GetRTTI(QAP_RTTI&RTTI)
          {
            //[Line](=>)
            static const string Name="t_unsgnd";
            //[Line](<=)
            TTypeStruct*Info=nullptr;
            if (RTTI.Register<SelfClass>(Info,Name))
            {
              return Info;
            }
            else
            {
              Info->SubType=nullptr;
              Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
            }
            //[Line](=>)
            Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
            //[Line](<=)
            {
              RTTI.OnRegEnd(Info);
            }
            {
            }
            Info->SelfTesting();
            return Info;
          }
          static string GetFullName()
          {
            //[Line](=>)
            return "t_unsgnd";
            //[Line](<=)
          }
        };
      public:
        //<<<<<+=====t_unsgnd
      public:
        bool go(i_dev&dev)
        {
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("unsigned");
          if (!ok)return ok;
          return ok;
        }
      };
    public:
      //=====+>>>>>t_name_template_param
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_name_template_param SelfClass;
    public:
      typedef i_template_param ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      string unsgnd0;
      t_sep sep0;
      string type;
      t_sep sep1;
      string unsgnd1;
      t_sep sep2;
      string name;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->unsgnd0);
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->type);
        detail::FieldTryDoReset(this->sep1);
        detail::FieldTryDoReset(this->unsgnd1);
        detail::FieldTryDoReset(this->sep2);
        detail::FieldTryDoReset(this->name);
      }
      //==Declaration Constructors==//
    public:
      t_name_template_param(const t_name_template_param&)=delete;
      t_name_template_param()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_name_template_param(t_name_template_param&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_name_template_param&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_template_param(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_template_param::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->unsgnd0=std::move(_Right.unsgnd0);
        this->sep0=std::move(_Right.sep0);
        this->type=std::move(_Right.type);
        this->sep1=std::move(_Right.sep1);
        this->unsgnd1=std::move(_Right.unsgnd1);
        this->sep2=std::move(_Right.sep2);
        this->name=std::move(_Right.name);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_name_template_param";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"unsgnd0",int(&(((SelfClass*)nullptr)->*(&SelfClass::unsgnd0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"unsgnd1",int(&(((SelfClass*)nullptr)->*(&SelfClass::unsgnd1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
            //[Line](=>)
            Info->AddNested(Sys$$<t_unsgnd>::GetRTTI(RTTI));
            //[Line](<=)
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_name_template_param";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_name_template_param
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_str<t_unsgnd>(unsgnd0);
        if (!ok)return ok;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_str<t_name>(type);
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        O+=dev.go_str<t_unsgnd>(unsgnd1);
        if (!ok)return ok;
        O+=dev.go_auto(sep2);
        if (!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_type_template_param:public i_template_param
    {
      //=====+>>>>>t_type_template_param
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_template_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_type_template_param SelfClass;
    public:
      typedef i_template_param ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      TAutoPtr<t_head> head;
      string type;
      t_sep sep;
      string name;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->head);
        detail::FieldTryDoReset(this->type);
        detail::FieldTryDoReset(this->sep);
        detail::FieldTryDoReset(this->name);
      }
      //==Declaration Constructors==//
    public:
      t_type_template_param(const t_type_template_param&)=delete;
      t_type_template_param()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_type_template_param(t_type_template_param&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_type_template_param&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_template_param(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_template_param::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->head=std::move(_Right.head);
        this->type=std::move(_Right.type);
        this->sep=std::move(_Right.sep);
        this->name=std::move(_Right.name);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_type_template_param";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_head>>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_type_template_param";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_type_template_param
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(head);
        if (!ok)return ok;
        static const auto g_static_var_1=QapStrFinder::fromArr(split("class,typename",","));
        M+=dev.go_any_str_from_vec(type,g_static_var_1);
        if (!ok)return ok;
        O+=dev.go_auto(sep);
        if (!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_template_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_template_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_head head;
    vector<t_template_param> params;
    TAutoPtr<i_template_body> body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->head);
      detail::FieldTryDoReset(this->params);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_template_class_stat(const t_template_class_stat&)=delete;
    t_template_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_template_class_stat(t_template_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_template_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->head=std::move(_Right.head);
      this->params=std::move(_Right.params);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_template_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_head>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");
        Info->AddMemberDEF(Sys$$<vector<t_template_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_template_param>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_concrete_param>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_concrete_params>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_common_oper_template_body>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_ctor_template_body>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_func_template_body>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_class_template_body>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_head>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_name_template_param>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_type_template_param>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_template_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_template_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(head);
      if (!ok)return ok;
      M+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_template_class_stat::TYPE TYPE;
    //  F(i_template_body);
    //  F(i_template_param);
    //  F(t_template_param);
    //  F(t_concrete_param);
    //  F(t_concrete_params);
    //  F(t_common_oper_template_body);
    //  F(t_ctor_template_body);
    //  F(t_func_template_body);
    //  F(t_class_template_body);
    //  F(t_head);
    //  F(t_name_template_param);
    //  F(t_type_template_param);
    //  #undef F
    //public:
    //  void Do(t_template_param&ref){}
    //  void Do(t_concrete_param&ref){}
    //  void Do(t_concrete_params&ref){}
    //  void Do(t_common_oper_template_body&ref){}
    //  void Do(t_ctor_template_body&ref){}
    //  void Do(t_func_template_body&ref){}
    //  void Do(t_class_template_body&ref){}
    //  void Do(t_head&ref){}
    //  void Do(t_name_template_param&ref){}
    //  void Do(t_type_template_param&ref){}
    //};
  };
  class t_enum_class_stat:public i_class_stat
  {
  public:
    //===>>===i_body_visitor
    class i_body;
    class t_impl_body;
    class t_empty_body;
    class i_body_visitor
    {
    public:
      typedef t_enum_class_stat::i_body i_body;
    public:
      virtual void Do(t_impl_body*p)=0;
      virtual void Do(t_empty_body*p)=0;
    public:
      typedef t_enum_class_stat::t_impl_body t_impl_body;
      typedef t_enum_class_stat::t_empty_body t_empty_body;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor
      {
        TYPE*ptr;
        Is():ptr(nullptr) {}
public:
        template<class U>static TYPE*get(U*p)
        {
          return nullptr;
        }
        template<>static TYPE*get<TYPE>(TYPE*p)
        {
          return p;
        }
public:
        void Do(t_impl_body*p)
        {
          ptr=get(p);
        } void Do(t_empty_body*p)
        {
          ptr=get(p);
        }
      };
      template<class TYPE>
      static TYPE*UberCast(i_body*p)
      {
        if (!p)return nullptr;
        Is<TYPE,i_body_visitor> IS;
        p->Use(IS);
        return IS.ptr;
      }
    };
    //===<<===i_body_visitor
    //class t_visitor:public t_enum_class_stat::i_body_visitor{
    //public:
    //  class t_dev{
    //  public:
    //  };
    //  t_dev&dev;
    //  t_visitor(t_dev&dev):dev(dev){}
    //public:
    //  void Do(t_impl_body*p){}
    //  void Do(t_empty_body*p){}
    //};
  public:
    class i_body
    {
      //=====+>>>>>i_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_enum_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef i_body SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
      }
      //==Declaration Constructors==//
    public:
      i_body(const i_body&)=delete;
      i_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      i_body(i_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(i_body&&_Right)
      {
        if (&_Right==this)return;
        {
        }
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="i_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "i_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====i_body
    public:
      typedef i_body_visitor i_visitor;
      virtual void Use(i_visitor&A)
      {
        QapDebugMsg("no way.");/*A.Do(this);*/
      }
    public:
      virtual bool go(i_dev&dev)
      {
        QapDebugMsg("no way.");
        return false;
      };
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        template<int>
        bool load()
        {
          //[Line](=>)
          go_for<t_impl_body>();
          //[Line](<=)
          //[Line](=>)
          go_for<t_empty_body>();
          //[Line](<=)
          (void)count;
          (void)first_id;
          (void)out_arr;
          (void)this;
          main();
          return scope.ok;
        }
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          vector<t_out_rec> out_arr;
          static int out_arr_size=0;
          out_arr.reserve(out_arr_size);
          t_fallback scope(dev,__FUNCTION__);
          int count=0;
          int first_id=-1;
          auto&Env=dev.getEnv();
          static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
          t_poly_tool::go_poly<SelfClass> solver_impl=
          {
            out_arr,dev,ref,scope,count,first_id,strbasetype,Env
          };
          t_poly_impl&solver=(t_poly_impl&)solver_impl;
          solver.load<0>();
          out_arr_size=out_arr.size();
          return scope.ok;
        }
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
        {
          t_fallback scope(dev,__FUNCTION__);
          bool&ok=scope.ok;
          if (!std::is_polymorphic<SelfClass>::value)if (!ref)
            {
              return false;
            }
          if (!ref)return false;
          QapAssert(ref);
          auto*p=ref.get();
          ok=p->go(dev);
          return ok;
        }
      };
    };
    class t_value
    {
      //=====+>>>>>t_value
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_enum_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_value SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep0;
      t_expr expr;
      t_sep sep1;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->expr);
        detail::FieldTryDoReset(this->sep1);
      }
      //==Declaration Constructors==//
    public:
      t_value(const t_value&)=delete;
      t_value()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_value(t_value&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_value&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->sep0=std::move(_Right.sep0);
        this->expr=std::move(_Right.expr);
        this->sep1=std::move(_Right.sep1);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_value";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_value";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_value
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("=");
        if (!ok)return ok;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_auto(expr);
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_item
    {
      //=====+>>>>>t_item
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_enum_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_item SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_value> value;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->sep0);
        detail::FieldTryDoReset(this->name);
        detail::FieldTryDoReset(this->sep1);
        detail::FieldTryDoReset(this->value);
      }
      //==Declaration Constructors==//
    public:
      t_item(const t_item&)=delete;
      t_item()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_item(t_item&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_item&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->sep0=std::move(_Right.sep0);
        this->name=std::move(_Right.name);
        this->sep1=std::move(_Right.sep1);
        this->value=std::move(_Right.value);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_item";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
          Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_item";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_item
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if (!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if (!ok)return ok;
        O+=dev.go_auto(sep1);
        if (!ok)return ok;
        O+=dev.go_auto(value);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_comma_with_sep
    {
      //=====+>>>>>t_comma_with_sep
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_enum_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_comma_with_sep SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      t_sep sep;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->sep);
      }
      //==Declaration Constructors==//
    public:
      t_comma_with_sep(const t_comma_with_sep&)=delete;
      t_comma_with_sep()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_comma_with_sep(t_comma_with_sep&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_comma_with_sep&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->sep=std::move(_Right.sep);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_comma_with_sep";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_comma_with_sep";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_comma_with_sep
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const(",");
        if (!ok)return ok;
        O+=dev.go_auto(sep);
        if (!ok)return ok;
        return ok;
      }
    };
    class t_impl_body:public i_body
    {
      //=====+>>>>>t_impl_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_enum_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_impl_body SelfClass;
    public:
      typedef i_body ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      vector<t_item> arr;
      TAutoPtr<t_comma_with_sep> comma;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
        detail::FieldTryDoReset(this->arr);
        detail::FieldTryDoReset(this->comma);
      }
      //==Declaration Constructors==//
    public:
      t_impl_body(const t_impl_body&)=delete;
      t_impl_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_impl_body(t_impl_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_impl_body&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_body(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_body::operator=(std::move(_Right));
          //[Line](<=)
        }
        //[Line](=>)
        this->arr=std::move(_Right.arr);
        this->comma=std::move(_Right.comma);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_impl_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
          Info->AddMemberDEF(Sys$$<TAutoPtr<t_comma_with_sep>>::GetRTTI(RTTI),"comma",int(&(((SelfClass*)nullptr)->*(&SelfClass::comma))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_impl_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_impl_body
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("{");
        if (!ok)return ok;
        O+=dev.go_vec(arr,",");
        if (!ok)return ok;
        O+=dev.go_auto(comma);
        if (!ok)return ok;
        M+=dev.go_const("}");
        if (!ok)return ok;
        return ok;
      }
    };
    class t_empty_body:public i_body
    {
      //=====+>>>>>t_empty_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_enum_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_empty_body SelfClass;
    public:
      typedef i_body ParentClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
          //[Line](=>)
          detail::TryDoReset<SelfClass>(this);
          //[Line](<=)
        }
      }
      //==Declaration Constructors==//
    public:
      t_empty_body(const t_empty_body&)=delete;
      t_empty_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_empty_body(t_empty_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_empty_body&&_Right)
      {
        //[Line](=>)
        struct hidden
        {
          static void foo(i_body(*)=(SelfClass*)nullptr) {}};
        //[Line](<=)
        if (&_Right==this)return;
        {
          //[Line](=>)
          i_body::operator=(std::move(_Right));
          //[Line](<=)
        }
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_empty_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_empty_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_empty_body
    public:
      void Use(i_visitor&A)
      {
        A.Do(this);
      }
      static SelfClass*UberCast(ParentClass*ptr)
      {
        return i_visitor::UberCast<SelfClass>(ptr);
      }
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const(";");
        if (!ok)return ok;
        return ok;
      }
    };
    class t_body
    {
      //=====+>>>>>t_body
      //==Declaration SelfClass,ParentClass,OwnerClass==//
      //[Line](=>)
    public:
      typedef t_enum_class_stat OwnerClass;
      //[Line](<=)
      //[Line](=>)
    public:
      typedef t_body SelfClass;
      //[Line](<=)
      //==Declaration Members==//
    public:
      //[Line](=>)
      TAutoPtr<i_body> body;
      //[Line](<=)
      //==Declaration DoReset==//
    public:
      void DoReset()
      {
        {
        }
        detail::FieldTryDoReset(this->body);
      }
      //==Declaration Constructors==//
    public:
      t_body(const t_body&)=delete;
      t_body()
      {
        DoReset();
      };
      //==Declaration Equal Operator==//
      //==Declaration Copy Constructor==//
    public:
      t_body(t_body&&_Right)
      {
        operator=(std::move(_Right));
      }
      void operator=(t_body&&_Right)
      {
        if (&_Right==this)return;
        {
        }
        //[Line](=>)
        this->body=std::move(_Right.body);
        //[Line](<=)
      }
      //==Declaration GetRTTI==//
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        template<class QAP_RTTI>
        static metatype*GetRTTI(QAP_RTTI&RTTI)
        {
          //[Line](=>)
          static const string Name="t_body";
          //[Line](<=)
          TTypeStruct*Info=nullptr;
          if (RTTI.Register<SelfClass>(Info,Name))
          {
            return Info;
          }
          else
          {
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
          }
          //[Line](=>)
          Info->AddMemberDEF(Sys$$<TAutoPtr<i_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
          //[Line](<=)
          {
            RTTI.OnRegEnd(Info);
          }
          {
          }
          Info->SelfTesting();
          return Info;
        }
        static string GetFullName()
        {
          //[Line](=>)
          return "t_body";
          //[Line](<=)
        }
      };
    public:
      //<<<<<+=====t_body
    public:
      bool go(i_dev&dev)
      {
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if (!ok)return ok;
        return ok;
      }
    };
  public:
    //=====+>>>>>t_enum_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_enum_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep0;
    string name;
    t_sep sep1;
    t_body body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep0);
      detail::FieldTryDoReset(this->name);
      detail::FieldTryDoReset(this->sep1);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_enum_class_stat(const t_enum_class_stat&)=delete;
    t_enum_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_enum_class_stat(t_enum_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_enum_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep0=std::move(_Right.sep0);
      this->name=std::move(_Right.name);
      this->sep1=std::move(_Right.sep1);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_enum_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
          //[Line](=>)
          Info->AddNested(Sys$$<t_value>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_comma_with_sep>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_impl_body>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_empty_body>::GetRTTI(RTTI));
          Info->AddNested(Sys$$<t_body>::GetRTTI(RTTI));
          //[Line](<=)
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_enum_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_enum_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("enum");
      if (!ok)return ok;
      O+=dev.go_auto(sep0);
      if (!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if (!ok)return ok;
      O+=dev.go_auto(sep1);
      if (!ok)return ok;
      O+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  public:
    //class t_static_visitor{
    //public:
    //  #define F(TYPE)typedef t_enum_class_stat::TYPE TYPE;
    //  F(i_body);
    //  F(t_value);
    //  F(t_item);
    //  F(t_comma_with_sep);
    //  F(t_impl_body);
    //  F(t_empty_body);
    //  F(t_body);
    //  #undef F
    //public:
    //  void Do(t_value&ref){}
    //  void Do(t_item&ref){}
    //  void Do(t_comma_with_sep&ref){}
    //  void Do(t_impl_body&ref){}
    //  void Do(t_empty_body&ref){}
    //  void Do(t_body&ref){}
    //};
  };
  class t_using_class_stat:public i_class_stat
  {
    //=====+>>>>>t_using_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_using_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    t_fv_class_stat::t_type_expr type;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep);
      detail::FieldTryDoReset(this->type);
    }
    //==Declaration Constructors==//
  public:
    t_using_class_stat(const t_using_class_stat&)=delete;
    t_using_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_using_class_stat(t_using_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_using_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      this->type=std::move(_Right.type);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_using_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_using_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_using_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("using");
      if (!ok)return ok;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      M+=dev.go_auto(type);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_pragma_class_stat:public i_class_stat
  {
    //=====+>>>>>t_pragma_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_pragma_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_pragma_class_stat(const t_pragma_class_stat&)=delete;
    t_pragma_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_pragma_class_stat(t_pragma_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_pragma_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_pragma_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_pragma_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_pragma_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#pragma");
      if (!ok)return ok;
      D+=dev.go_end(body,"\n");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_include_class_stat:public i_class_stat
  {
    //=====+>>>>>t_include_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_include_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_include_class_stat(const t_include_class_stat&)=delete;
    t_include_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_include_class_stat(t_include_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_include_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_include_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_include_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_include_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#include");
      if (!ok)return ok;
      D+=dev.go_end(body,"\n");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_preproc_if_class_stat:public i_class_stat
  {
    //=====+>>>>>t_preproc_if_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_preproc_if_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_preproc_if_class_stat(const t_preproc_if_class_stat&)=delete;
    t_preproc_if_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_preproc_if_class_stat(t_preproc_if_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_preproc_if_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_preproc_if_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_preproc_if_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_preproc_if_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#if");
      if (!ok)return ok;
      D+=dev.go_end(body,"\n");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_preproc_else_class_stat:public i_class_stat
  {
    //=====+>>>>>t_preproc_else_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_preproc_else_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_preproc_else_class_stat(const t_preproc_else_class_stat&)=delete;
    t_preproc_else_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_preproc_else_class_stat(t_preproc_else_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_preproc_else_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_preproc_else_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_preproc_else_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_preproc_else_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#else");
      if (!ok)return ok;
      D+=dev.go_end(body,"\n");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_preproc_endif_class_stat:public i_class_stat
  {
    //=====+>>>>>t_preproc_endif_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_preproc_endif_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_preproc_endif_class_stat(const t_preproc_endif_class_stat&)=delete;
    t_preproc_endif_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_preproc_endif_class_stat(t_preproc_endif_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_preproc_endif_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_preproc_endif_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_preproc_endif_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_preproc_endif_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#endif");
      if (!ok)return ok;
      D+=dev.go_end(body,"\n");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_define_class_stat:public i_class_stat
  {
    //=====+>>>>>t_define_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_define_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_define_class_stat(const t_define_class_stat&)=delete;
    t_define_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_define_class_stat(t_define_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_define_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_define_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_define_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_define_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#define");
      if (!ok)return ok;
      D+=dev.go_end(body,"\n");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_undef_class_stat:public i_class_stat
  {
    //=====+>>>>>t_undef_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_undef_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    string body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_undef_class_stat(const t_undef_class_stat&)=delete;
    t_undef_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_undef_class_stat(t_undef_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_undef_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_undef_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_undef_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_undef_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#undef");
      if (!ok)return ok;
      D+=dev.go_end(body,"\n");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_sep_class_stat:public i_class_stat
  {
    //=====+>>>>>t_sep_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_sep_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->sep);
    }
    //==Declaration Constructors==//
  public:
    t_sep_class_stat(const t_sep_class_stat&)=delete;
    t_sep_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_sep_class_stat(t_sep_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_sep_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_sep_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_sep_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_sep_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(sep);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_null_class_stat:public i_class_stat
  {
    //=====+>>>>>t_null_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_null_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
    }
    //==Declaration Constructors==//
  public:
    t_null_class_stat(const t_null_class_stat&)=delete;
    t_null_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_null_class_stat(t_null_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_null_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_null_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_null_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_null_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(";");
      if (!ok)return ok;
      return ok;
    }
  };
  class t_class_class_stat:public i_class_stat
  {
    //=====+>>>>>t_class_class_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_class_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_class body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
        //[Line](=>)
        detail::TryDoReset<SelfClass>(this);
        //[Line](<=)
      }
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_class_class_stat(const t_class_class_stat&)=delete;
    t_class_class_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_class_class_stat(t_class_class_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_class_class_stat&&_Right)
    {
      //[Line](=>)
      struct hidden
      {
        static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
      //[Line](<=)
      if (&_Right==this)return;
      {
        //[Line](=>)
        i_class_stat::operator=(std::move(_Right));
        //[Line](<=)
      }
      //[Line](=>)
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_class_class_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_class>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_class_class_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_class_class_stat
  public:
    void Use(i_visitor&A)
    {
      A.Do(this);
    }
    static SelfClass*UberCast(ParentClass*ptr)
    {
      return i_visitor::UberCast<SelfClass>(ptr);
    }
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
  class t_inl_file_stat
  {
    //=====+>>>>>t_inl_file_stat
    //==Declaration SelfClass,ParentClass,OwnerClass==//
    //[Line](=>)
  public:
    typedef t_inl_file OwnerClass;
    //[Line](<=)
    //[Line](=>)
  public:
    typedef t_inl_file_stat SelfClass;
    //[Line](<=)
    //==Declaration Members==//
  public:
    //[Line](=>)
    t_sep sep;
    TAutoPtr<t_class> body;
    //[Line](<=)
    //==Declaration DoReset==//
  public:
    void DoReset()
    {
      {
      }
      detail::FieldTryDoReset(this->sep);
      detail::FieldTryDoReset(this->body);
    }
    //==Declaration Constructors==//
  public:
    t_inl_file_stat(const t_inl_file_stat&)=delete;
    t_inl_file_stat()
    {
      DoReset();
    };
    //==Declaration Equal Operator==//
    //==Declaration Copy Constructor==//
  public:
    t_inl_file_stat(t_inl_file_stat&&_Right)
    {
      operator=(std::move(_Right));
    }
    void operator=(t_inl_file_stat&&_Right)
    {
      if (&_Right==this)return;
      {
      }
      //[Line](=>)
      this->sep=std::move(_Right.sep);
      this->body=std::move(_Right.body);
      //[Line](<=)
    }
    //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      {
        //[Line](=>)
        static const string Name="t_inl_file_stat";
        //[Line](<=)
        TTypeStruct*Info=nullptr;
        if (RTTI.Register<SelfClass>(Info,Name))
        {
          return Info;
        }
        else
        {
          Info->SubType=nullptr;
          Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
        //[Line](=>)
        Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
        Info->AddMemberDEF(Sys$$<TAutoPtr<t_class>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
        //[Line](<=)
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
      static string GetFullName()
      {
        //[Line](=>)
        return "t_inl_file_stat";
        //[Line](<=)
      }
    };
  public:
    //<<<<<+=====t_inl_file_stat
  public:
    bool go(i_dev&dev)
    {
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if (!ok)return ok;
      M+=dev.go_auto(body);
      if (!ok)return ok;
      return ok;
    }
  };
public:
//=====+>>>>>t_inl_file
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  //[Line](=>)
public:
  typedef t_inl_file SelfClass;
  //[Line](<=)
  //==Declaration Members==//
public:
  //[Line](=>)
  vector<TAutoPtr<i_class_stat>> arr;
  //[Line](<=)
  //==Declaration DoReset==//
public:
  void DoReset()
  {
    {
    }
    detail::FieldTryDoReset(this->arr);
  }
  //==Declaration Constructors==//
public:
  t_inl_file(const t_inl_file&)=delete;
  t_inl_file()
  {
    DoReset();
  };
  //==Declaration Equal Operator==//
  //==Declaration Copy Constructor==//
public:
  t_inl_file(t_inl_file&&_Right)
  {
    operator=(std::move(_Right));
  }
  void operator=(t_inl_file&&_Right)
  {
    if (&_Right==this)return;
    {
    }
    //[Line](=>)
    this->arr=std::move(_Right.arr);
    //[Line](<=)
  }
  //==Declaration GetRTTI==//
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      //[Line](=>)
      static const string Name="t_inl_file";
      //[Line](<=)
      TTypeStruct*Info=nullptr;
      if (RTTI.Register<SelfClass>(Info,Name))
      {
        return Info;
      }
      else
      {
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      //[Line](=>)
      Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_class_stat>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
      //[Line](<=)
      {
        RTTI.OnRegEnd(Info);
      }
      {
        //[Line](=>)
        Info->AddNested(Sys$$<t_lev03>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev05>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev06>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev07>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev08>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev09>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev10>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev11>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev12>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev13>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_lev14>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_access_mod>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_access_mod_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_raw_func_body>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_func_path>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_fv_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_typedef_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_call_param>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_call_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_real>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_bool_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_string_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_char_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_num_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_real_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_nullptr_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_or_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_hex_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_var_expr>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_ctor_init_list>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_zero_func_body>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_null_func_body>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_delete_func_body>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_impl_func_body>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_dtor_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_ctor_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_oper_cast_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_common_oper_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_parents>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_class_body>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_class>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_namespace_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_template_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_enum_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_using_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_pragma_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_include_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_preproc_if_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_preproc_else_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_preproc_endif_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_define_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_undef_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_sep_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_null_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_class_class_stat>::GetRTTI(RTTI));
        Info->AddNested(Sys$$<t_inl_file_stat>::GetRTTI(RTTI));
        //[Line](<=)
      }
      Info->SelfTesting();
      return Info;
    }
    static string GetFullName()
    {
      //[Line](=>)
      return "t_inl_file";
      //[Line](<=)
    }
  };
public:
//<<<<<+=====t_inl_file
public:
  bool go(i_dev&dev)
  {
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(arr);
    if (!ok)return ok;
    return ok;
  }
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_inl_file::TYPE TYPE;
  //  F(i_class_stat);
  //  F(i_expr);
  //  F(i_func_body);
  //  F(t_lev03);
  //  F(t_lev05);
  //  F(t_lev06);
  //  F(t_lev07);
  //  F(t_lev08);
  //  F(t_lev09);
  //  F(t_lev10);
  //  F(t_lev11);
  //  F(t_lev12);
  //  F(t_lev13);
  //  F(t_lev14);
  //  F(t_expr);
  //  F(t_access_mod);
  //  F(t_access_mod_class_stat);
  //  F(t_raw_func_body);
  //  F(t_func_path);
  //  F(t_fv_class_stat);
  //  F(t_typedef_class_stat);
  //  F(t_call_param);
  //  F(t_call_expr);
  //  F(t_real);
  //  F(t_bool_expr);
  //  F(t_string_expr);
  //  F(t_char_expr);
  //  F(t_num_expr);
  //  F(t_real_expr);
  //  F(t_nullptr_expr);
  //  F(t_or_expr);
  //  F(t_hex_expr);
  //  F(t_var_expr);
  //  F(t_ctor_init_list);
  //  F(t_zero_func_body);
  //  F(t_null_func_body);
  //  F(t_delete_func_body);
  //  F(t_impl_func_body);
  //  F(t_dtor_class_stat);
  //  F(t_ctor_class_stat);
  //  F(t_oper_cast_class_stat);
  //  F(t_common_oper_class_stat);
  //  F(t_parents);
  //  F(t_class_body);
  //  F(t_class);
  //  F(t_namespace_class_stat);
  //  F(t_template_class_stat);
  //  F(t_enum_class_stat);
  //  F(t_using_class_stat);
  //  F(t_pragma_class_stat);
  //  F(t_include_class_stat);
  //  F(t_preproc_if_class_stat);
  //  F(t_preproc_else_class_stat);
  //  F(t_preproc_endif_class_stat);
  //  F(t_define_class_stat);
  //  F(t_undef_class_stat);
  //  F(t_sep_class_stat);
  //  F(t_null_class_stat);
  //  F(t_class_class_stat);
  //  F(t_inl_file_stat);
  //  #undef F
  //public:
  //  void Do(t_lev03&ref){}
  //  void Do(t_lev05&ref){}
  //  void Do(t_lev06&ref){}
  //  void Do(t_lev07&ref){}
  //  void Do(t_lev08&ref){}
  //  void Do(t_lev09&ref){}
  //  void Do(t_lev10&ref){}
  //  void Do(t_lev11&ref){}
  //  void Do(t_lev12&ref){}
  //  void Do(t_lev13&ref){}
  //  void Do(t_lev14&ref){}
  //  void Do(t_expr&ref){}
  //  void Do(t_access_mod&ref){}
  //  void Do(t_access_mod_class_stat&ref){}
  //  void Do(t_raw_func_body&ref){}
  //  void Do(t_func_path&ref){}
  //  void Do(t_fv_class_stat&ref){}
  //  void Do(t_typedef_class_stat&ref){}
  //  void Do(t_call_param&ref){}
  //  void Do(t_call_expr&ref){}
  //  void Do(t_real&ref){}
  //  void Do(t_bool_expr&ref){}
  //  void Do(t_string_expr&ref){}
  //  void Do(t_char_expr&ref){}
  //  void Do(t_num_expr&ref){}
  //  void Do(t_real_expr&ref){}
  //  void Do(t_nullptr_expr&ref){}
  //  void Do(t_or_expr&ref){}
  //  void Do(t_hex_expr&ref){}
  //  void Do(t_var_expr&ref){}
  //  void Do(t_ctor_init_list&ref){}
  //  void Do(t_zero_func_body&ref){}
  //  void Do(t_null_func_body&ref){}
  //  void Do(t_delete_func_body&ref){}
  //  void Do(t_impl_func_body&ref){}
  //  void Do(t_dtor_class_stat&ref){}
  //  void Do(t_ctor_class_stat&ref){}
  //  void Do(t_oper_cast_class_stat&ref){}
  //  void Do(t_common_oper_class_stat&ref){}
  //  void Do(t_parents&ref){}
  //  void Do(t_class_body&ref){}
  //  void Do(t_class&ref){}
  //  void Do(t_namespace_class_stat&ref){}
  //  void Do(t_template_class_stat&ref){}
  //  void Do(t_enum_class_stat&ref){}
  //  void Do(t_using_class_stat&ref){}
  //  void Do(t_pragma_class_stat&ref){}
  //  void Do(t_include_class_stat&ref){}
  //  void Do(t_preproc_if_class_stat&ref){}
  //  void Do(t_preproc_else_class_stat&ref){}
  //  void Do(t_preproc_endif_class_stat&ref){}
  //  void Do(t_define_class_stat&ref){}
  //  void Do(t_undef_class_stat&ref){}
  //  void Do(t_sep_class_stat&ref){}
  //  void Do(t_null_class_stat&ref){}
  //  void Do(t_class_class_stat&ref){}
  //  void Do(t_inl_file_stat&ref){}
  //};
};
/*
//list of types:
F(t_inl_file)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Finl%5Ffile%7B%0D%0A%20%20t%5Flev03%7B%0D%0A%20%20%20%20string%20oper%3B%0D%0
A%20%20%20%20TAutoPtr%3Ci%5Fexpr%3E%20expr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%2
0%20%20%20O%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%2B%2C%2D%2C%21
%2C%7E%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29
%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev05%7B%0D%0A%20%20%20%2
0t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B
%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%
2A%2C%2F%2C%25%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20
%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D
%0A%20%20%20%20%20%20t%5Flev03%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%
20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%2
8expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5
Flev03%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%2
0%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%2
0O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5
Flev06%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%
0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5F
vec%28value%2Csplit%28%22%2B%2C%2D%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%
20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t
%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev05%20expr%3B%0D%0A%20%20%20%20%2
0%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20
%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%
0D%0A%20%20%20%20t%5Flev05%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr
%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D
%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%
20%7D%0D%0A%20%20t%5Flev07%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%
20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5
Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3C%3C%2C%3E%3E%22%2C%22%2C%22%29%2
9%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7
B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev06%20e
xpr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%
29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%2
0%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev06%20expr%3B%0D%0A%20%20%20%20
vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3
Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0
A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev08%7B%0D%0A%20%20%20%20t%5Fope
r%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%2
0%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%3C%2C%3C
%3D%2C%3E%2C%3E%3D%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%2
0%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3
B%0D%0A%20%20%20%20%20%20t%5Flev07%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20
%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fau
to%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%2
0t%5Flev07%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%
20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%
20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%2
0t%5Flev09%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value
%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffro
m%5Fvec%28value%2Csplit%28%22%3D%3D%2C%21%3D%22%2C%22%2C%22%29%29%3B%0D%0A%20%20
%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20
%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev08%20expr%3B%0D%0A%20%
20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%2
0%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20
%20%20%7D%0D%0A%20%20%20%20t%5Flev08%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fite
m%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28exp
r%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D
%0D%0A%20%20%7D%0D%0A%20%20t%5Flev10%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20
%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20
%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%26%22%2C%22%2C%22%29%29%
3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%
0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev09%20exp
r%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29
%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%
7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev09%20expr%3B%0D%0A%20%20%20%20ve
ctor%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dg
o%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%
20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev11%7B%0D%0A%20%20%20%20t%5Foper%
7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%
20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22%5E%22%2C%2
2%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%
20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t
%5Flev10%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5F
auto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%2
0%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev10%20expr%3B%0D%0A
%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20
%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28ar
r%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev12%7B%0D%0A%20%20%
20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20%20%20%20%20%2
0%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28
%22%7C%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0
D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20oper%3B%0D%0A%20%2
0%20%20%20%20t%5Flev11%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20
%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29
%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Flev11%2
0expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%
0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20O%2B%3D
go%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Flev13%7
B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20value%3B%0D%0A%20
%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5Fvec%28va
lue%2Csplit%28%22%26%26%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A
%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Foper%20o
per%3B%0D%0A%20%20%20%20%20%20t%5Flev12%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%
0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20%20%20%20%20%20go
%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20
%20%20t%5Flev12%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%2
0%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A
%20%20t%5Flev14%7B%0D%0A%20%20%20%20t%5Foper%7B%0D%0A%20%20%20%20%20%20string%20
value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%
5Ffrom%5Fvec%28value%2Csplit%28%22%7C%7C%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%
20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%
20%20t%5Foper%20oper%3B%0D%0A%20%20%20%20%20%20t%5Flev13%20expr%3B%0D%0A%20%20%2
0%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fauto%28oper%29%3B%0D%0A%20%20%20
%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%
20%7D%0D%0A%20%20%20%20t%5Flev13%20expr%3B%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E
%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29
%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%
0A%20%20%7D%0D%0A%20%20t%5Fexpr%7Bt%5Flev14%20body%3B%7Bgo%5Fauto%28body%29%3B%7
D%7D%0D%0A%20%20t%5Faccess%5Fmod%7Bstring%20keyword%3B%7Bgo%5Fany%5Fstr%5Ffrom%5
Fvec%28keyword%2Csplit%28%22public%2Cprotected%2Cprivate%22%2C%22%2C%22%29%29%3B
%7D%7D%0D%0A%20%20t%5Faccess%5Fmod%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A
%20%20%20%20t%5Faccess%5Fmod%20mod%3B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20
%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28mod%29%3B%0D%0A%20%20%20%
20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28
%22%3A%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fraw%5Ffunc%5F
body%7B%0D%0A%20%20%20%20t%5Fsep%5Fitem%3D%3Ei%5Fitem%7Bt%5Fsep%20sep%3B%7Bgo%5F
auto%28sep%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fs%5Fitem%3D%3Ei%5Fitem%7Bstring%20va
lue%3B%7Bgo%5Fstr%3Ct%5Fstr%5Fitem%3A%3At%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20
%20%20%20t%5Fc%5Fitem%3D%3Ei%5Fitem%7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fchar%5F
item%3A%3At%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fcode%5Fitem%3D%3E
i%5Fitem%7Bstring%20code%3B%7Bgo%5Fany%28code%2Cgen%5Fdips%28%22AZaz09%22%29%2B%
22%2B%2D%2A%3F%3C%3E%5B%5D%28%29%2C%2E%3A%3B%7E%21%40%23%24%5F%3D%25%5E%26%5C%5C
%7C%22%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fdiv%5Fitem%3D%3Ei%5Fitem%7B%7Bgo%5Fconst
%28%22%2F%22%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fblock%5Fitem%3D%3Ei%5Fitem%7BTAuto
Ptr%3Ct%5Fraw%5Ffunc%5Fbody%3E%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20
%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20vector%3CTAutoPtr%3Ci%5Fitem%3E%3E%20
arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22
%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%
20%20t%5Ffunc%5Fpath%7B%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20%20%
20string%20value%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%2
0%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%
2B%3Dgo%5Fstr%3Ct%5Fname%3E%28value%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo
%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3A%3A%
22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%
20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20vector%3Ct%5Fitem%3E%20arr%
3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fauto%28arr%29%3B%0D%0A%20%20
%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ffv%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%
7B%0D%0A%20%20%20%20t%5Ftype%5Fexpr%7B%0D%0A%20%20%20%20%20%20t%5Ffirst%5Fscope%
7B%0D%0A%20%20%20%20%20%20%20%20string%20body%3B%0D%0A%20%20%20%20%20%20%20%20t%
5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20
%20M%2B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%
20%7D%0D%0A%20%20%20%20%20%20t%5Fconst%5Fwith%5Fsep%7Bt%5Fsep%20sep%3Bstring%20k
eyword%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28key
word%2Csplit%28%22typename%2Cconst%2Cunsigned%22%2C%22%2C%22%29%29%3B%7D%7D%0D%0
A%20%20%20%20%20%20t%5Ftype%5Fwith%5Fsep%7B%0D%0A%20%20%20%20%20%20%20%20t%5Ftyp
e%5Fparam%3D%3Ei%5Fparam%7B%0D%0A%20%20%20%20%20%20%20%20%20%20vector%3Ct%5Fcons
t%5Fwith%5Fsep%3E%20cvs%3B%0D%0A%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ftyp
e%5Fexpr%3E%20body%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%2
0%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cvs%29%3B%0D%0A%20%20%20%20%20%20%20%20
%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7D
%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fnum%5Fparam%3
D%3Ei%5Fparam%7Bstring%20body%3B%7Bgo%5Fany%28body%2Cgen%5Fdips%28%2209%22%29%29
%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fparams%7B%0D%0A%20%20%20%20%20%20%20%
20%20%20t%5Ftype%5Fexpr%5Fwith%5Fsep%7Bt%5Fsep%20sep%5Fbef%3BTAutoPtr%3Ci%5Fpara
m%3E%20param%3Bt%5Fsep%20sep%5Faft%3B%7BO%2B%3Dgo%5Fauto%28sep%5Fbef%29%3BM%2B%3
Dgo%5Fauto%28param%29%3BO%2B%3Dgo%5Fauto%28sep%5Faft%29%3B%7D%7D%0D%0A%20%20%20%
20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%20%20%20vector%3
Ct%5Ftype%5Fexpr%5Fwith%5Fsep%3E%20arr%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7B
%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%
20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3C%22%29%3B%0D%0A%20%20%
20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%20
%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3E%22%29%3B%0D%0A%20%20%20
%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%2
0%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%20string%20name%3B%0D%0A%20%2
0%20%20%20%20%20%20TAutoPtr%3Ct%5Fparams%3E%20params%3B%0D%0A%20%20%20%20%20%20%
20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%2
0%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%
20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%2
0%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fscope%5Fwith%5F
sep%7Bt%5Fsep%20sep%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo%5Fconst%28%22%3A%
3A%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fscope%7B%7Bgo%5Fconst%28%22%3A%3A%2
2%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fptr%7B%0D%0A%20%20%20%20%20%20%20%20TAu
toPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%2
0sep%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28se
p%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%2A%22%29%3B%0
D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%
20t%5Fref%7B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%2
0cv%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%
20string%20ref%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20
%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5
Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffro
m%5Fvec%28ref%2Csplit%28%22%26%26%2C%26%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%2
0%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fscopes%7B
%0D%0A%20%20%20%20%20%20%20%20t%5Fitem%7Bt%5Fscope%5Fwith%5Fsep%20sws%3Bt%5Ftype
%5Fwith%5Fsep%20body%3B%7Bgo%5Fauto%28sws%29%3Bgo%5Fauto%28body%29%3B%7D%7D%0D%0
A%20%20%20%20%20%20%20%20t%5Ftype%5Fwith%5Fsep%20first%3B%0D%0A%20%20%20%20%20%2
0%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%2
0%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28first%29%3B%0D%0A%20%20%20%20%20%20%
20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%2
0%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fkeyword%7B%0D%0A%20%20%20%20%20%2
0%20%20string%20keyword%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%2
0%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fs
tr%5Ffrom%5Fvec%28keyword%2Csplit%28%22friend%2Ctypename%2Cextern%2Cexplicit%2Cc
onstexpr%2Cvirtual%2Cconst%2Cstatic%2Cinline%2Cunsigned%22%2C%22%2C%22%29%29%3B%
0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%2
0%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Ftype%5Fex
pr%5Fwith%5Fsep%5Fand%5Fcv%7B%0D%0A%20%20%20%20%20%20%20%20vector%3Ct%5Fconst%5F
with%5Fsep%3E%20cvs%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ftype%5Fexpr%3
E%20body%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28cvs%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto
%28body%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%
20%20%20%20%20%20t%5Fname%5Fpart%7BTAutoPtr%3Ci%5Fname%5Fpart%3E%20body%3B%7Bgo%
5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Farr%5Fbody%7B%0D%0A%20%20%2
0%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep1%3B
%0D%0A%20%20%20%20%20%20%20%20t%5Fexpr%20expr%3B%0D%0A%20%20%20%20%20%20%20%20t%
5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep3%3B%0D%0A%20%20%20%20
%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B
%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5B%22%29%3B%0D%0A%20
%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20
%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%
28%22%5D%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%
3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20
%20%20t%5Fbrackets%5Fname%5Fpart%3D%3Ei%5Fname%5Fpart%7B%0D%0A%20%20%20%20%20%20
%20%20t%5Famp%7Bstring%20body%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28body%2Csplit%28
%22%26%2C%26%26%22%2C%22%2C%22%29%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fa
mp%5Fpart%3D%3Ei%5Fpart%7Bt%5Famp%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A
%20%20%20%20%20%20%20%20t%5Fstar%5Fpart%3D%3Ei%5Fpart%7Bstring%20stars%3BTAutoPt
r%3Ct%5Famp%3E%20amp%3B%7BM%2B%3Dgo%5Fany%28stars%2C%22%2A%22%29%3BO%2B%3Dgo%5Fa
uto%28amp%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ci%5Fpart%3E%20stam
p%5Fpart%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%2
0%20%20TAutoPtr%3Ct%5Fname%5Fpart%3E%20namepart%3B%0D%0A%20%20%20%20%20%20%20%20
TAutoPtr%3Ct%5Farr%5Fbody%3E%20arrbody%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A
%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0A%20%20%20
%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28stamp%5Fpart%29%3B%0D%0A%20%20%20%20%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%
2B%3Dgo%5Fauto%28namepart%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fc
onst%28%22%29%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr
body%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%
20%20%20%20%20t%5Fraw%5Fname%5Fpart%3D%3Ei%5Fname%5Fpart%7Bstring%20name%3B%7Bgo
%5Fstr%3Ct%5Fname%3E%28name%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fpfunc%5Ffunc%
5Fparam%3D%3Ei%5Ffunc%5Fparam%7B%0D%0A%20%20%20%20%20%20%20%20t%5Faddr%7B%0D%0A%
20%20%20%20%20%20%20%20%20%20t%5Ftype%5Fexpr%5Fwith%5Fsep%5Fand%5Fcv%20type%3B%0
D%0A%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20M
%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%
5Fconst%28%22%3A%3A%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%
20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20t%5Ftype%5Fexpr%5Fwith%5Fsep%5
Fand%5Fcv%20type%3B%0D%0A%20%20%20%20%20%20%20%20t%5Faddr%20addr%3B%0D%0A%20%20%
20%20%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%2
0%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%20%20%20%20%2
0%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%
2B%3Dgo%5Fauto%28addr%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst
%28%22%2A%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname
%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%2
2%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%29%22%29%3
B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%
20%20t%5Fvar%5Fargs%5Ffunc%5Fparam%3D%3Ei%5Ffunc%5Fparam%7B%7Bgo%5Fconst%28%22%2
E%2E%2E%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Ftype%5Ffunc%5Fparam%3D%3Ei%5Ff
unc%5Fparam%7B%0D%0A%20%20%20%20%20%20%20%20t%5Ftype%5Fexpr%5Fwith%5Fsep%5Fand%5
Fcv%20type%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20
%20%20%20TAutoPtr%3Ct%5Fname%5Fpart%3E%20namepart%3B%0D%0A%20%20%20%20%20%20%20%
20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%
20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%2
0%20%20%20O%2B%3Dgo%5Fauto%28namepart%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%
0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fexpr%5Ffunc%5Fparam%3D%3Ei%5F
func%5Fparam%7Bt%5Fexpr%20body%3B%7Bgo%5Fminor%3Ct%5Ftype%5Ffunc%5Fparam%3E%28bo
dy%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fexpr%5Fext%3D%3Ei%5Ffunc%5Fparam%5Fval
ue%7Bt%5Fexpr%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%
5Ffunc%5Fref%5Fext%3D%3Ei%5Ffunc%5Fparam%5Fvalue%7B%0D%0A%20%20%20%20%20%20%20%2
0t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%20t%5Ftype%5Fexpr%5Fwith%5Fsep%5Fan
d%5Fcv%20type%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%
20%20M%2B%3Dgo%5Fconst%28%22%26%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28t
ype%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%2
0%20%20%20%20t%5Ffunc%5Fparam%5Fvalue%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20
sep%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fparam%5Fvalue%3E%20val
ue%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3
Dgo%5Fconst%28%22%3D%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28value%29%3B%
0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20
%20t%5Ffunc%5Fparam%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%2
0%20%20%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fparam%3E%20body%3B%0D%0A%20%20%20%20%20
%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpa
ram%5Fvalue%3E%20value%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%2
0%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28
sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0
A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%2
0%20%20%20%20%20O%2B%3Dgo%5Fauto%28value%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%
20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%
20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Ffunc%5Fparams%7B%0D%0A%20%20%20%20%20%20%
20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%20%20vector%3Ct%5Ffunc%5Fparam%3E%
20arr%3B%0D%0A%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%2
8%22%28%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%
2C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%
3B%0D%0A%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20
%20%20t%5Ffv%5Fstat%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fimpl%5Ffunc%5Fbody%3D%3E
i%5Ffv%5Fbody%7Bt%5Fsep%20sep%3Bt%5Fraw%5Ffunc%5Fbody%20body%3B%7BO%2B%3Dgo%5Fau
to%28sep%29%3BM%2B%3Dgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20t
%5Fzero%5Ffunc%5Fbody%3D%3Ei%5Ffv%5Fbody%7B%7Bgo%5Fconst%28%22%3D0%3B%22%29%3B%7
D%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fdelete%5Ffunc%5Fbody%3D%3Ei%5Ffv%5Fbody%7B
%7Bgo%5Fconst%28%22%3Ddelete%3B%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%20%20t%5F
func%5Ffv%5Fend%3D%3Ei%5Ffv%5Fend%7B%0D%0A%20%20%20%20%20%20%20%20%20%20TAutoPtr
%3Ct%5Ffunc%5Fparams%3E%20params%3B%0D%0A%20%20%20%20%20%20%20%20%20%20TAutoPtr%
3Ct%5Fconst%5Fwith%5Fsep%3E%20cv1%3B%0D%0A%20%20%20%20%20%20%20%20%20%20t%5Fsep%
20sep1%3B%0D%0A%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ci%5Ffv%5Fbody%3E%20body%
3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20
%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28cv1%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fau
to%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body
%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%7D%0
D%0A%20%20%20%20%20%20%20%20t%5Fvar%5Ffv%5Fend%3D%3Ei%5Ffv%5Fend%7B%0D%0A%20%20%
20%20%20%20%20%20%20%20t%5Ffunc%5Ffv%5Fitem%3D%3Ei%5Ffv%5Fitem%7B%0D%0A%20%20%20
%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fparams%3E%20params%3B%0D%0A%20%
20%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%20cv1%3B%0D
%0A%20%20%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%2
0%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20
%20%20%20O%2B%3Dgo%5Fauto%28cv1%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%
7D%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%20%20t%5
Fvar%5Ffv%5Fitem%3D%3Ei%5Ffv%5Fitem%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20
TAutoPtr%3Ct%5Farr%5Fbody%3E%20arrbody%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20
%20TAutoPtr%3Ct%5Ffunc%5Fparam%5Fvalue%3E%20value%3B%0D%0A%20%20%20%20%20%20%20%
20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28arrbody%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Faut
o%28value%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%2
0%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%20%20t%5Fbody%7BTAutoPtr%3Ci%5
Ffv%5Fitem%3E%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%2
0%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20t%5Fsep%20sep0%3B
%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fconst%5Fwith%5Fsep%3E%2
0cv%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20
%20%20%20%20%20%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%
20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20t%5Fbody%20body%
3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20t%5Fsep%20sep3%3B%0D%0A%20%20%20%20%
20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3
Dgo%5Fconst%28%22%2C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3
Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5
Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fst
r%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3D
go%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%
5Fauto%28sep3%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%
20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fbody%3
E%20body%3B%0D%0A%20%20%20%20%20%20%20%20%20%20vector%3Ct%5Fitem%3E%20arr%3B%0D%
0A%20%20%20%20%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20O%2
B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28arr%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%2
2%3B%22%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20%20%
20%7D%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep%5Fwa%3B%0D%0A%20%20%20%20%20%20
%20%20vector%3Ct%5Fkeyword%3E%20keywords%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPt
r%3Ct%5Ftype%5Fexpr%3E%20type%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Fcon
st%5Fwith%5Fsep%3E%20cv%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%
20%20%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpath%3E%20path%3B%0D%0A%20%20%20%20
%20%20%20%20t%5Fname%5Fpart%20name%3B%0D%0A%20%20%20%20%20%20%20%20t%5Fsep%20sep
1%3B%0D%0A%20%20%20%20%20%20%20%20TAutoPtr%3Ci%5Ffv%5Fend%3E%20way%3B%0D%0A%20%2
0%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep
%5Fwa%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28keywords%29%3B
%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20
%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20%20%20%20%2
0%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5
Fauto%28path%29%3B%0D%0A%20%20%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28name%29
%3B%0D%0A%20%20%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20
%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28way%29%3B%0D%0A%20%20%20%20%20%20%20%
20%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ffirst%5Fs
cope%3E%20first%3B%0D%0A%20%20%20%20%20%20t%5Fscopes%20scopes%3B%0D%0A%20%20%20%
20%20%20vector%3Ct%5Fptr%3E%20ptrs%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fref%
3E%20ref%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28first%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28scopes%29%3B%
0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28ptrs%29%3B%0D%0A%20%20%20%20%20%
20%20%20O%2B%3Dgo%5Fauto%28ref%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%2
0%7D%0D%0A%20%20%20%20t%5Ftype%5Fexpr%3A%3At%5Ffv%5Fstat%20body%3B%0D%0A%20%20%2
0%20%7Bgo%5Fauto%28body%29%3B%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftypedef%5Fclass%5
Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%
20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ffv%5Fstat%20body%3B%0D%0A%
20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22typedef%22%29%3B%0D
%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3D
go%5Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fcall%5
Fparam%7B%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20t%5Fexpr%20expr%3B
%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28expr%29%
3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%7D%0D%
0A%20%20%7D%0D%0A%20%20t%5Fcall%5Fexpr%3D%3Ei%5Fexpr%7B%0D%0A%20%20%20%20string%
20func%3B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20vector%3Ct%5Fcall%5
Fparam%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3
Ct%5Fname%3E%28func%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D
%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0D%0A%20%20%20%20%20%20
O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst
%28%22%29%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Freal%7B%0D
%0A%20%20%20%20t%5Ff%7Bchar%20body%3B%7Bgo%5Fany%5Fchar%28body%2C%22fF%22%29%3B%
7D%7D%0D%0A%20%20%20%20string%20bef%3B%0D%0A%20%20%20%20string%20aft%3B%0D%0A%20
%20%20%20TAutoPtr%3Ct%5Ff%3E%20ext%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%
20M%2B%3Dgo%5Fany%28bef%2Cgen%5Fdips%28%2209%22%29%29%3B%0D%0A%20%20%20%20%20%20
M%2B%3Dgo%5Fconst%28%22%2E%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fany%28aft
%2Cgen%5Fdips%28%2209%22%29%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28ext%
29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fbool%5Fexpr%3D%3Ei%5Fex
pr%7Bstring%20value%3B%7Bgo%5Fany%5Fstr%5Ffrom%5Fvec%28value%2Csplit%28%22false%
2Ctrue%22%2C%22%2C%22%29%29%3B%7D%7D%0D%0A%20%20t%5Fstring%5Fexpr%3D%3Ei%5Fexpr%
7Bstring%20value%3B%7Bgo%5Fstr%3Ct%5Fstr%5Fitem%3A%3At%5Fimpl%3E%28value%29%3B%7
D%7D%0D%0A%20%20t%5Fchar%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fstr%3Ct
%5Fchar%5Fitem%3A%3At%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20%20t%5Fnum%5Fexpr%3D
%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fany%28value%2Cgen%5Fdips%28%2209%22%29%29
%3B%7D%7D%0D%0A%20%20t%5Freal%5Fexpr%3D%3Ei%5Fexpr%7Bstring%20value%3B%7Bgo%5Fst
r%3Ct%5Freal%3E%28value%29%3B%7D%7D%0D%0A%20%20t%5Fnullptr%5Fexpr%3D%3Ei%5Fexpr%
7B%7Bgo%5Fconst%28%22nullptr%22%29%3B%7D%7D%0D%0A%20%20t%5For%5Fexpr%3D%3Ei%5Fex
pr%7Bvector%3Ct%5Fname%3E%20arr%3B%7Bgo%5Fbin%5Foper%28arr%2C%22%7C%22%29%3B%7D%
7D%0D%0A%20%20t%5Fhex%5Fexpr%3D%3Ei%5Fexpr%7Bt%5Fimpl%7Bchar%20x%3Bstring%20valu
e%3B%7Bgo%5Fconst%28%220%22%29%3Bgo%5Fany%5Fchar%28x%2C%22xX%22%29%3Bgo%5Fany%28
value%2Cgen%5Fdips%28%2209afAF%22%29%29%3B%7D%7Dstring%20value%3B%7Bgo%5Fstr%3Ct
%5Fimpl%3E%28value%29%3B%7D%7D%0D%0A%20%20t%5Fvar%5Fexpr%3D%3Ei%5Fexpr%7B%0D%0A%
20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftyp
e%5Fexpr%3A%3At%5Ftype%5Fwith%5Fsep%20body%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20s
ep%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%2
8body%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%2
0%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3A%3A%22%29%3B%0D%0A%20%20%20%20%20%2
0%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Ffield%7Bt%5Fsep%20bef%3Bstring%20
name%3Bt%5Fsep%20aft%3B%7BO%2B%3Dgo%5Fauto%28bef%29%3BM%2B%3Dgo%5Fstr%3Ct%5Fname
%3E%28name%29%3BO%2B%3Dgo%5Fauto%28aft%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fimpl%7B%
0D%0A%20%20%20%20%20%20vector%3Ct%5Fitem%3E%20items%3B%0D%0A%20%20%20%20%20%20t%
5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20vector%3Ct%5Ffield%3E%20arr%3B%0D%0A%20%20
%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28items%29%3B%0D%0
A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20
%20M%2B%3Dgo%5Fvec%28arr%2C%22%2E%22%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%2
0%20%20%7D%0D%0A%20%20%20%20string%20name%3B%7Bgo%5Fstr%3Ct%5Fimpl%3E%28name%29%
3B%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fctor%5Finit%5Flist%7B%0D%0A%20%20%20%20t%5Fi
nit%5Fparam%7B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20s
tring%20name%3B%0D%0A%20%20%20%20%20%20vector%3Ct%5Fcall%5Fparam%3E%20arr%3B%0D%
0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%
20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3D
go%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fcon
st%28%22%28%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C
%22%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0D%0A
%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%7D
%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20vector%3Ct%5Finit%5Fparam%3E%20params%3B%
0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%
2B%3Dgo%5Fconst%28%22%3A%22%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fvec%28param
s%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20
%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fzero%5Ffunc%5Fbody%3D%3Ei%5Ffunc%5Fbo
dy%7B%7Bgo%5Fconst%28%22%3D0%3B%22%29%3B%7D%7D%0D%0A%20%20t%5Fnull%5Ffunc%5Fbody
%3D%3Ei%5Ffunc%5Fbody%7Bt%5Fsep%20sep%3B%7BO%2B%3Dgo%5Fauto%28sep%29%3BM%2B%3Dgo
%5Fconst%28%22%3B%22%29%3B%7D%7D%0D%0A%20%20t%5Fdelete%5Ffunc%5Fbody%3D%3Ei%5Ffu
nc%5Fbody%7B%7Bgo%5Fconst%28%22%3Ddelete%3B%22%29%3B%7D%7D%0D%0A%20%20t%5Fimpl%5
Ffunc%5Fbody%3D%3Ei%5Ffunc%5Fbody%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%
20%20%20TAutoPtr%3Ct%5Fctor%5Finit%5Flist%3E%20init%5Flist%3B%0D%0A%20%20%20%20t
%5Fraw%5Ffunc%5Fbody%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20O%2B%
3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28init%5Flist%29
%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D
%0A%20%20%7D%0D%0A%20%20t%5Fdtor%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%2
0%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpath%3E%20pat
h%3B%0D%0A%20%20%20%20string%20name%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%
20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ffunc%5Fparams%20p
arams%3B%0D%0A%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fbody%3E%20body%3B%0D%0A%20%20%20
%20%7B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28path%29%3B%0D%0A%20%20%20%20%20
%20M%2B%3Dgo%5Fconst%28%22%7E%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8sep0%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D
%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20M%2B%3
Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0
D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fctor%5Fclass%5Fstat%3D%3Ei%5Fc
lass%5Fstat%7B%0D%0A%20%20%20%20t%5Fimpl%7B%0D%0A%20%20%20%20%20%20t%5Fexplicit%
7Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fconst%28%22explicit%22%29%3BM%2B%3Dgo%5Fauto%28
sep%29%3B%7D%7D%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fexplicit%3E%20prefix%3B%0D
%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpath%3E%20path%3B%0D%0A%20%20%20%20%2
0%20string%20name%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%
5Fexpr%3A%3At%5Ffunc%5Fparams%20params%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5F
func%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%2
0O%2B%3Dgo%5Fauto%28prefix%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8path%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29
%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%
20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%
20%20%20%7D%0D%0A%20%20%20%20t%5Fimpl%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%0D%0
A%20%20%7D%0D%0A%20%20t%5Foper%5Fcast%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D
%0A%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpath%3E%20path%3B%0D%0A%20%20%20%20t%5Fsep%
20sep0%3B%0D%0A%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%20type%3B%
0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At
%5Ftype%5Fexpr%3A%3At%5Ffunc%5Fparams%20params%3B%0D%0A%20%20%20%20TAutoPtr%3Ct%
5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Fconst%5Fwith%5Fsep%3E%20cv%3B%
0D%0A%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%7B%0D
%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28path%29%3B%0D%0A%20%20%20%20%20%20M%2B%3
Dgo%5Fconst%28%22operator%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep
0%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%20%2
0%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28para
ms%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv%29%3B%0D%0A%20%20%20%20%20
%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20
t%5Fcommon%5Foper%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fi
mpl%7B%0D%0A%20%20%20%20%20%20vector%3Ct%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexp
r%3A%3At%5Fkeyword%3E%20keywords%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat
%3A%3At%5Ftype%5Fexpr%20type%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ffv%5Fclass
%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Fconst%5Fwith%5Fsep%3E%20cv0%3B%0D%0A%20%20
%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ffunc%5Fpath%
3E%20path%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20str
ing%20oper%3B%0D%0A%20%20%20%20%20%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%
3A%3At%5Ffunc%5Fparams%20params%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Ffv%5Fcl
ass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Fconst%5Fwith%5Fsep%3E%20cv1%3B%0D%0A%20
%20%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%20%7
B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28keywords%29%3B%0D%0A%20%20%20%
20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3D
go%5Fauto%28cv0%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B
%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28path%29%3B%0D%0A%20%20%20%20%20
%20%20%20M%2B%3Dgo%5Fconst%28%22operator%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O
%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%
5Ffrom%5Fvec%28oper%2Csplit%28%22%3D%2C%2B%3D%2C%2D%3D%2C%2A%3D%2C%2F%3D%2C%25%3
D%2C%7C%3D%2C%26%3D%2C%5E%3D%2C%3C%3C%3D%2C%3E%3E%3D%2C%7C%7C%2C%26%26%2C%7C%2C%
5E%2C%26%2C%3D%3D%2C%21%3D%2C%3C%2C%3C%3D%2C%3E%2C%3E%3D%2C%3C%3C%2C%3E%3E%2C%2B
%2C%2D%2C%2A%2C%2F%2C%25%2C%2B%2B%2C%2D%2D%2C%7E%2C%21%2C%28%29%2C%5B%5D%22%2C%2
2%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D
%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv1%29%3B%0D%0A%20%20%20%20%20%20%
20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%
7D%0D%0A%20%20%20%20t%5Fimpl%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%0D%0A%20%20%7
D%0D%0A%20%20t%5Fparents%7B%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%20%20%20%20%20
t%5Fpub%7Bt%5Faccess%5Fmod%20mod%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fauto%28mod%29%
3BO%2B%3Dgo%5Fauto%28sep%29%3B%7D%7D%0D%0A%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%
0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fpub%3E%20pub%3B%0D%0A%20%20%20%20%20%20string
%20name%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fa
uto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28pub%29%3B%0D%0A%
20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fe
xpr%3A%3At%5Ftype%5Fexpr%5Fwith%5Fsep%5Fand%5Fcv%3E%28name%29%3B%0D%0A%20%20%20%
20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%2
0%20vector%3Ct%5Fitem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%
2B%3Dgo%5Fconst%28%22%3A%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%
29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3B%0D%0A%20%20
%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fclass%5Fbody%7B%0D%0A%20%20%20%20vector%
3CTAutoPtr%3Ci%5Fclass%5Fstat%3E%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20
%20%20%20M%2B%3Dgo%5Fconst%28%22%7B%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28arr%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0D%0
A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fclass%7B%0D%0A%20%20%20%20string%
20keyword%3B%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20string%20name%3
B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20TAutoPtr%3Ct%5Fparents%3E%
20parents%3B%0D%0A%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20TAutoPtr%3Ct%5F
class%5Fbody%3E%20body%3B%0D%0A%20%20%20%20t%5Fsep%20sep3%3B%0D%0A%20%20%20%20%7
B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28keyword%2Csplit%28
%22struct%2Cclass%2Cunion%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20O%2B%3D
go%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28na
me%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%
20%20O%2B%3Dgo%5Fauto%28parents%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28
sep2%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%2
0%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28
%22%3B%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fnamespace%5Fc
lass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20
%20%20%20string%20name%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20t%
5Fclass%5Fbody%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5
Fconst%28%22namespace%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29
%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%2
0%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fau
to%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Ftemplate%5Fcl
ass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Ftemplate%5Fparam%7B%0D%
0A%20%20%20%20%20%20t%5Fsep%20bef%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Ftempl
ate%5Fparam%3E%20body%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20aft%3B%0D%0A%20%20%20%
20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28bef%29%3B%0D%0A%20%2
0%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%20%20O%
2B%3Dgo%5Fauto%28aft%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A
%20%20%20%20t%5Fconcrete%5Fparam%7B%0D%0A%20%20%20%20%20%20t%5Fraw%5Fexpr%3D%3Ei
%5Fbody%7Bt%5Fexpr%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20%20
%20t%5Ftemplate%5Fexpr%3D%3Ei%5Fbody%7B%0D%0A%20%20%20%20%20%20%20%20t%5Fmain%7B
vector%3Ct%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ftype%5Fwith%5Fsep%3
E%20arr%3B%7Bgo%5Fvec%28arr%2C%22%3A%3A%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20%2
0%20t%5Fmain%20body%3B%0D%0A%20%20%20%20%20%20%20%20%7Bgo%5Fdiff%3Ct%5Fraw%5Fexp
r%3E%28body%29%3B%7D%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%20%20t%5Fsep%2
0sep0%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Fbody%3E%20body%3B%0D%0A%20%20%20%
20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%
20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28
body%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%2
0%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fconcrete%5Fparams%7B%
0D%0A%20%20%20%20%20%20vector%3Ct%5Fconcrete%5Fparam%3E%20arr%3B%0D%0A%20%20%20%
20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%2
0M%2B%3Dgo%5Fconst%28%22%3C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fve
c%28arr%2C%22%2C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3
E%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20
%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fcommon%5Foper%5Ftempla
te%5Fbody%3D%3Ei%5Ftemplate%5Fbody%7Bt%5Fcommon%5Foper%5Fclass%5Fstat%3A%3At%5Fi
mpl%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fctor%5Ftemplat
e%5Fbody%3D%3Ei%5Ftemplate%5Fbody%7Bt%5Fctor%5Fclass%5Fstat%3A%3At%5Fimpl%20body
%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Ffunc%5Ftemplate%5Fbody%3
D%3Ei%5Ftemplate%5Fbody%7B%0D%0A%20%20%20%20%20%20vector%3Ct%5Ffv%5Fclass%5Fstat
%3A%3At%5Ftype%5Fexpr%3A%3At%5Fkeyword%3E%20keywords%3B%0D%0A%20%20%20%20%20%20t
%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%20type%3B%0D%0A%20%20%20%20%20%20TAuto
Ptr%3Ct%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Fconst%5Fwith%5Fsep%3E%
20cv0%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20string%
20func%5Fname%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconcrete%5Fparams%3E%20co
ncrete%5Fparams%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20
%20t%5Ffv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Ffunc%5Fparams%20params%3B
%0D%0A%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5F
fv%5Fclass%5Fstat%3A%3At%5Ftype%5Fexpr%3A%3At%5Fconst%5Fwith%5Fsep%3E%20cv1%3B%0
D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5Ffunc%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%
20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28keywords%29%3B%0D%0A%20
%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28cv0%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep
0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28func%5Fname
%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28concrete%5Fparams%29%3B%0
D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%2
0%20%20M%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5F
auto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28cv1%29%3B%0D%0
A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%20%20%7
D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fclass%5Ftemplate%5Fbody%3D%3Ei%5Ftem
plate%5Fbody%7B%0D%0A%20%20%20%20%20%20string%20keyword%3B%0D%0A%20%20%20%20%20%
20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20string%20name%3B%0D%0A%20%20%20%20%20
%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fconcrete%5Fparams%3E%
20params%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fparents%3E%20parents%3B%0D%0A%
20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fclass%5
Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep3%3B%0D%0A%20%20%20%20%20
%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28keyword
%2Csplit%28%22struct%2Cclass%2Cunion%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%2
0%20%20%20M%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5
Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28
sep1%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28params%29%3B%0D%0A%20
%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28parents%29%3B%0D%0A%20%20%20%20%20%20%20
%20O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%2
8body%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep3%29%3B%0D%0A%20%
20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3B%22%29%3B%0D%0A%20%20%20%20%20%20%
7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fhead%7B%0D%0A%20%20%20%20%20%20t%5F
sep%20sep0%3B%0D%0A%20%20%20%20%20%20vector%3Ct%5Ftemplate%5Fparam%3E%20params%3
B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ci%5
Ftemplate%5Fbody%3E%20body%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20
%20%20M%2B%3Dgo%5Fconst%28%22template%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B
%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3
C%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28params%2C%22%2C%22%29%
3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3E%22%29%3B%0D%0A%20%20%
20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%
20%20%20%20%7D%0D%0A%20%20%20%20t%5Fname%5Ftemplate%5Fparam%3D%3Ei%5Ftemplate%5F
param%7B%0D%0A%20%20%20%20%20%20t%5Funsgnd%7Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fcons
t%28%22unsigned%22%29%3B%7D%7D%0D%0A%20%20%20%20%20%20string%20unsgnd0%3B%0D%0A%
20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20string%20type%3B%0D%0A
%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20string%20unsgnd1%3B%0
D%0A%20%20%20%20%20%20t%5Fsep%20sep2%3B%0D%0A%20%20%20%20%20%20string%20name%3B%
0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fun
sgnd%3E%28unsgnd0%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%
3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28type%29%3B%0D%0A
%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20%20
%20O%2B%3Dgo%5Fstr%3Ct%5Funsgnd%3E%28unsgnd1%29%3B%0D%0A%20%20%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28sep2%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5
Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%2
0%20%20t%5Ftype%5Ftemplate%5Fparam%3D%3Ei%5Ftemplate%5Fparam%7B%0D%0A%20%20%20%2
0%20%20TAutoPtr%3Ct%5Fhead%3E%20head%3B%0D%0A%20%20%20%20%20%20string%20type%3B%
0D%0A%20%20%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20%20%20string%20name%3B%
0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28head%
29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%5Fstr%5Ffrom%5Fvec%28type%2Cs
plit%28%22class%2Ctypename%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%20%20%20
O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5F
name%3E%28name%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20
%20%20t%5Fhead%20head%3B%0D%0A%20%20%20%20vector%3Ct%5Ftemplate%5Fparam%3E%20par
ams%3B%0D%0A%20%20%20%20TAutoPtr%3Ci%5Ftemplate%5Fbody%3E%20body%3B%0D%0A%20%20%
20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28head%29%3B%0D%0A%20%20%20%20%
20%20M%2B%3Dgo%5Fauto%28body%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%
20t%5Fenum%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fvalue%7B
%0D%0A%20%20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20t%5Fexpr%20expr
%3B%0D%0A%20%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20
%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22%3D%22%29%3B%0D%0A%20%20%20%20%20%20
%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Faut
o%28expr%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%
20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fitem%7B%0D%0A%20%
20%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%20%20%20%20%20string%20name%3B%0D%0A%20
%20%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fvalue%3E%
20value%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fa
uto%28sep0%29%3B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28na
me%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%
20%20%20%20%20%20O%2B%3Dgo%5Fauto%28value%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A
%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fcomma%5Fwith%5Fsep%7Bt%5Fsep%20sep%3B%7BM%2
B%3Dgo%5Fconst%28%22%2C%22%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%7D%7D%0D%0A%20%20%2
0%20t%5Fimpl%5Fbody%3D%3Ei%5Fbody%7B%0D%0A%20%20%20%20%20%20vector%3Ct%5Fitem%3E
%20arr%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fcomma%5Fwith%5Fsep%3E%20comma%3B
%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%22
%7B%22%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fvec%28arr%2C%22%2C%22%29%3
B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28comma%29%3B%0D%0A%20%20%20%20%
20%20%20%20M%2B%3Dgo%5Fconst%28%22%7D%22%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%
20%20%20%20%7D%0D%0A%20%20%20%20t%5Fempty%5Fbody%3D%3Ei%5Fbody%7B%7Bgo%5Fconst%2
8%22%3B%22%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fbody%7BTAutoPtr%3Ci%5Fbody%3E%20body
%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0D%0A%20%20%20%20t%5Fsep%20sep0%3B%0D%0A%20%2
0%20%20string%20name%3B%0D%0A%20%20%20%20t%5Fsep%20sep1%3B%0D%0A%20%20%20%20t%5F
body%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fconst%28%
22enum%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28sep0%29%3B%0D%0A%20%20
%20%20%20%20O%2B%3Dgo%5Fstr%3Ct%5Fname%3E%28name%29%3B%0D%0A%20%20%20%20%20%20O%
2B%3Dgo%5Fauto%28sep1%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28body%29%3B
%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fusing%5Fclass%5Fstat%3D%3Ei%
5Fclass%5Fstat%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20%20%20t%5Ffv%5Fcl
ass%5Fstat%3A%3At%5Ftype%5Fexpr%20type%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20
%20%20M%2B%3Dgo%5Fconst%28%22using%22%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fa
uto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28type%29%3B%0D%0A%20%20
%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fpragma%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fs
tat%7Bstring%20body%3B%7Bgo%5Fconst%28%22%23pragma%22%29%3Bgo%5Fend%28body%2C%22
%5Cn%22%29%3B%7D%7D%0D%0A%20%20t%5Finclude%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%
7Bstring%20body%3B%7Bgo%5Fconst%28%22%23include%22%29%3Bgo%5Fend%28body%2C%22%5C
n%22%29%3B%7D%7D%0D%0A%20%20t%5Fpreproc%5Fif%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fsta
t%7Bstring%20body%3B%7Bgo%5Fconst%28%22%23if%22%29%3Bgo%5Fend%28body%2C%22%5Cn%2
2%29%3B%7D%7D%0D%0A%20%20t%5Fpreproc%5Felse%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat
%7Bstring%20body%3B%7Bgo%5Fconst%28%22%23else%22%29%3Bgo%5Fend%28body%2C%22%5Cn%
22%29%3B%7D%7D%0D%0A%20%20t%5Fpreproc%5Fendif%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fst
at%7Bstring%20body%3B%7Bgo%5Fconst%28%22%23endif%22%29%3Bgo%5Fend%28body%2C%22%5
Cn%22%29%3B%7D%7D%0D%0A%20%20t%5Fdefine%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bs
tring%20body%3B%7Bgo%5Fconst%28%22%23define%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22
%29%3B%7D%7D%0D%0A%20%20t%5Fundef%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bstring%
20body%3B%7Bgo%5Fconst%28%22%23undef%22%29%3Bgo%5Fend%28body%2C%22%5Cn%22%29%3B%
7D%7D%0D%0A%20%20t%5Fsep%5Fclass%5Fstat%3D%3Ei%5Fclass%5Fstat%7Bt%5Fsep%20sep%3B
%7Bgo%5Fauto%28sep%29%3B%7D%7D%0D%0A%20%20t%5Fnull%5Fclass%5Fstat%3D%3Ei%5Fclass
%5Fstat%7B%7Bgo%5Fconst%28%22%3B%22%29%3B%7D%7D%0D%0A%20%20t%5Fclass%5Fclass%5Fs
tat%3D%3Ei%5Fclass%5Fstat%7Bt%5Fclass%20body%3B%7Bgo%5Fauto%28body%29%3B%7D%7D%0
D%0A%20%20t%5Finl%5Ffile%5Fstat%7B%0D%0A%20%20%20%20t%5Fsep%20sep%3B%0D%0A%20%20
%20%20TAutoPtr%3Ct%5Fclass%3E%20body%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%2
0%20O%2B%3Dgo%5Fauto%28sep%29%3B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28body%
29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20vector%3CTAutoPtr%3Ci%5Fcla
ss%5Fstat%3E%3E%20arr%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fauto%28arr%29%3B%0
D%0A%20%20%7D%0D%0A%7D
*/

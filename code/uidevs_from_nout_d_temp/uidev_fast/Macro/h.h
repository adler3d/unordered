class t_inl_file
{
public:
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
public:
  class i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef i_class_stat SelfClass;
  public:
  public:
    void DoReset();
  public:
    i_class_stat(const i_class_stat&)=delete;
    i_class_stat();;
  public:
    i_class_stat(i_class_stat&&_Right);
    void operator=(i_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    typedef i_class_stat_visitor i_visitor;
    virtual void Use(i_visitor&A);
  public:
    virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
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
public:
  class i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef i_expr SelfClass;
  public:
  public:
    void DoReset();
  public:
    i_expr(const i_expr&)=delete;
    i_expr();;
  public:
    i_expr(i_expr&&_Right);
    void operator=(i_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A);
  public:
    virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
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
public:
  class i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef i_func_body SelfClass;
  public:
  public:
    void DoReset();
  public:
    i_func_body(const i_func_body&)=delete;
    i_func_body();;
  public:
    i_func_body(i_func_body&&_Right);
    void operator=(i_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    typedef i_func_body_visitor i_visitor;
    virtual void Use(i_visitor&A);
  public:
    virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
  class t_lev03
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev03 SelfClass;
  public:
    string oper;
    TAutoPtr<i_expr> expr;
  public:
    void DoReset();
  public:
    t_lev03(const t_lev03&)=delete;
    t_lev03();;
  public:
    t_lev03(t_lev03&&_Right);
    void operator=(t_lev03&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev05
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev05 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev05 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev03 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev05 SelfClass;
  public:
    t_lev03 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev05(const t_lev05&)=delete;
    t_lev05();;
  public:
    t_lev05(t_lev05&&_Right);
    void operator=(t_lev05&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev06
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev06 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev06 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev05 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev06 SelfClass;
  public:
    t_lev05 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev06(const t_lev06&)=delete;
    t_lev06();;
  public:
    t_lev06(t_lev06&&_Right);
    void operator=(t_lev06&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev07
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev07 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev07 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev06 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev07 SelfClass;
  public:
    t_lev06 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev07(const t_lev07&)=delete;
    t_lev07();;
  public:
    t_lev07(t_lev07&&_Right);
    void operator=(t_lev07&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev08
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev08 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev08 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev07 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev08 SelfClass;
  public:
    t_lev07 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev08(const t_lev08&)=delete;
    t_lev08();;
  public:
    t_lev08(t_lev08&&_Right);
    void operator=(t_lev08&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev09
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev09 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev09 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev08 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev09 SelfClass;
  public:
    t_lev08 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev09(const t_lev09&)=delete;
    t_lev09();;
  public:
    t_lev09(t_lev09&&_Right);
    void operator=(t_lev09&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev10
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev10 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev10 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev09 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev10 SelfClass;
  public:
    t_lev09 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev10(const t_lev10&)=delete;
    t_lev10();;
  public:
    t_lev10(t_lev10&&_Right);
    void operator=(t_lev10&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev11
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev11 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev11 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev10 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev11 SelfClass;
  public:
    t_lev10 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev11(const t_lev11&)=delete;
    t_lev11();;
  public:
    t_lev11(t_lev11&&_Right);
    void operator=(t_lev11&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev12
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev12 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev12 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev11 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev12 SelfClass;
  public:
    t_lev11 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev12(const t_lev12&)=delete;
    t_lev12();;
  public:
    t_lev12(t_lev12&&_Right);
    void operator=(t_lev12&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev13
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev13 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev13 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev12 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev13 SelfClass;
  public:
    t_lev12 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev13(const t_lev13&)=delete;
    t_lev13();;
  public:
    t_lev13(t_lev13&&_Right);
    void operator=(t_lev13&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_lev14
  {
  public:
    class t_oper
    {
    public:
      typedef t_lev14 OwnerClass;
    public:
      typedef t_oper SelfClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_oper(const t_oper&)=delete;
      t_oper();;
    public:
      t_oper(t_oper&&_Right);
      void operator=(t_oper&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_lev14 OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_oper oper;
      t_lev13 expr;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_lev14 SelfClass;
  public:
    t_lev13 expr;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_lev14(const t_lev14&)=delete;
    t_lev14();;
  public:
    t_lev14(t_lev14&&_Right);
    void operator=(t_lev14&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_expr SelfClass;
  public:
    t_lev14 body;
  public:
    void DoReset();
  public:
    t_expr(const t_expr&)=delete;
    t_expr();;
  public:
    t_expr(t_expr&&_Right);
    void operator=(t_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_access_mod
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_access_mod SelfClass;
  public:
    string keyword;
  public:
    void DoReset();
  public:
    t_access_mod(const t_access_mod&)=delete;
    t_access_mod();;
  public:
    t_access_mod(t_access_mod&&_Right);
    void operator=(t_access_mod&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_access_mod_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_access_mod_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_access_mod mod;
    t_sep sep;
  public:
    void DoReset();
  public:
    t_access_mod_class_stat(const t_access_mod_class_stat&)=delete;
    t_access_mod_class_stat();;
  public:
    t_access_mod_class_stat(t_access_mod_class_stat&&_Right);
    void operator=(t_access_mod_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_raw_func_body
  {
  public:
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
  public:
    class i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef i_item SelfClass;
    public:
    public:
      void DoReset();
    public:
      i_item(const i_item&)=delete;
      i_item();;
    public:
      i_item(i_item&&_Right);
      void operator=(i_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      typedef i_item_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_sep_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_sep_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      t_sep sep;
    public:
      void DoReset();
    public:
      t_sep_item(const t_sep_item&)=delete;
      t_sep_item();;
    public:
      t_sep_item(t_sep_item&&_Right);
      void operator=(t_sep_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_s_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_s_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_s_item(const t_s_item&)=delete;
      t_s_item();;
    public:
      t_s_item(t_s_item&&_Right);
      void operator=(t_s_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_c_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_c_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      string value;
    public:
      void DoReset();
    public:
      t_c_item(const t_c_item&)=delete;
      t_c_item();;
    public:
      t_c_item(t_c_item&&_Right);
      void operator=(t_c_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_code_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_code_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      string code;
    public:
      void DoReset();
    public:
      t_code_item(const t_code_item&)=delete;
      t_code_item();;
    public:
      t_code_item(t_code_item&&_Right);
      void operator=(t_code_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_div_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_div_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
    public:
      void DoReset();
    public:
      t_div_item(const t_div_item&)=delete;
      t_div_item();;
    public:
      t_div_item(t_div_item&&_Right);
      void operator=(t_div_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_block_item:public i_item
    {
    public:
      typedef t_raw_func_body OwnerClass;
    public:
      typedef t_block_item SelfClass;
    public:
      typedef i_item ParentClass;
    public:
      TAutoPtr<t_raw_func_body> body;
    public:
      void DoReset();
    public:
      t_block_item(const t_block_item&)=delete;
      t_block_item();;
    public:
      t_block_item(t_block_item&&_Right);
      void operator=(t_block_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_raw_func_body SelfClass;
  public:
    t_sep sep;
    vector<TAutoPtr<i_item>> arr;
  public:
    void DoReset();
  public:
    t_raw_func_body(const t_raw_func_body&)=delete;
    t_raw_func_body();;
  public:
    t_raw_func_body(t_raw_func_body&&_Right);
    void operator=(t_raw_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_func_path
  {
  public:
    class t_item
    {
    public:
      typedef t_func_path OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      string value;
      t_sep sep0;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_func_path SelfClass;
  public:
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_func_path(const t_func_path&)=delete;
    t_func_path();;
  public:
    t_func_path(t_func_path&&_Right);
    void operator=(t_func_path&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_fv_class_stat:public i_class_stat
  {
  public:
    class t_type_expr
    {
    public:
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
    public:
      class i_name_part
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef i_name_part SelfClass;
      public:
      public:
        void DoReset();
      public:
        i_name_part(const i_name_part&)=delete;
        i_name_part();;
      public:
        i_name_part(i_name_part&&_Right);
        void operator=(i_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        typedef i_name_part_visitor i_visitor;
        virtual void Use(i_visitor&A);
      public:
        virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          bool load();
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    public:
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
    public:
      class i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef i_func_param SelfClass;
      public:
      public:
        void DoReset();
      public:
        i_func_param(const i_func_param&)=delete;
        i_func_param();;
      public:
        i_func_param(i_func_param&&_Right);
        void operator=(i_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        typedef i_func_param_visitor i_visitor;
        virtual void Use(i_visitor&A);
      public:
        virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          bool load();
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    public:
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
    public:
      class i_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef i_func_param_value SelfClass;
      public:
      public:
        void DoReset();
      public:
        i_func_param_value(const i_func_param_value&)=delete;
        i_func_param_value();;
      public:
        i_func_param_value(i_func_param_value&&_Right);
        void operator=(i_func_param_value&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        typedef i_func_param_value_visitor i_visitor;
        virtual void Use(i_visitor&A);
      public:
        virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          bool load();
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
      class t_first_scope
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_first_scope SelfClass;
      public:
        string body;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_first_scope(const t_first_scope&)=delete;
        t_first_scope();;
      public:
        t_first_scope(t_first_scope&&_Right);
        void operator=(t_first_scope&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_const_with_sep
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_const_with_sep SelfClass;
      public:
        t_sep sep;
        string keyword;
      public:
        void DoReset();
      public:
        t_const_with_sep(const t_const_with_sep&)=delete;
        t_const_with_sep();;
      public:
        t_const_with_sep(t_const_with_sep&&_Right);
        void operator=(t_const_with_sep&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_type_with_sep
      {
      public:
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
      public:
        class i_param
        {
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef i_param SelfClass;
        public:
        public:
          void DoReset();
        public:
          i_param(const i_param&)=delete;
          i_param();;
        public:
          i_param(i_param&&_Right);
          void operator=(i_param&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          typedef i_param_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_type_param:public i_param
        {
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef t_type_param SelfClass;
        public:
          typedef i_param ParentClass;
        public:
          vector<t_const_with_sep> cvs;
          TAutoPtr<t_type_expr> body;
        public:
          void DoReset();
        public:
          t_type_param(const t_type_param&)=delete;
          t_type_param();;
        public:
          t_type_param(t_type_param&&_Right);
          void operator=(t_type_param&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_num_param:public i_param
        {
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef t_num_param SelfClass;
        public:
          typedef i_param ParentClass;
        public:
          string body;
        public:
          void DoReset();
        public:
          t_num_param(const t_num_param&)=delete;
          t_num_param();;
        public:
          t_num_param(t_num_param&&_Right);
          void operator=(t_num_param&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_params
        {
        public:
          class t_type_expr_with_sep
          {
          public:
            typedef t_params OwnerClass;
          public:
            typedef t_type_expr_with_sep SelfClass;
          public:
            t_sep sep_bef;
            TAutoPtr<i_param> param;
            t_sep sep_aft;
          public:
            void DoReset();
          public:
            t_type_expr_with_sep(const t_type_expr_with_sep&)=delete;
            t_type_expr_with_sep();;
          public:
            t_type_expr_with_sep(t_type_expr_with_sep&&_Right);
            void operator=(t_type_expr_with_sep&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnv&RTTI);
              static string GetFullName();
            };
          public:
          public:
            bool go(i_dev&dev);
          };
        public:
        public:
          typedef t_type_with_sep OwnerClass;
        public:
          typedef t_params SelfClass;
        public:
          t_sep sep;
          vector<t_type_expr_with_sep> arr;
        public:
          void DoReset();
        public:
          t_params(const t_params&)=delete;
          t_params();;
        public:
          t_params(t_params&&_Right);
          void operator=(t_params&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          bool go(i_dev&dev);
        };
      public:
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_type_with_sep SelfClass;
      public:
        t_sep sep;
        string name;
        TAutoPtr<t_params> params;
      public:
        void DoReset();
      public:
        t_type_with_sep(const t_type_with_sep&)=delete;
        t_type_with_sep();;
      public:
        t_type_with_sep(t_type_with_sep&&_Right);
        void operator=(t_type_with_sep&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      public:
      };
      class t_scope_with_sep
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_scope_with_sep SelfClass;
      public:
        t_sep sep;
      public:
        void DoReset();
      public:
        t_scope_with_sep(const t_scope_with_sep&)=delete;
        t_scope_with_sep();;
      public:
        t_scope_with_sep(t_scope_with_sep&&_Right);
        void operator=(t_scope_with_sep&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_scope
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_scope SelfClass;
      public:
      public:
        void DoReset();
      public:
        t_scope(const t_scope&)=delete;
        t_scope();;
      public:
        t_scope(t_scope&&_Right);
        void operator=(t_scope&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_ptr
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_ptr SelfClass;
      public:
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_ptr(const t_ptr&)=delete;
        t_ptr();;
      public:
        t_ptr(t_ptr&&_Right);
        void operator=(t_ptr&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_ref
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_ref SelfClass;
      public:
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep;
        string ref;
      public:
        void DoReset();
      public:
        t_ref(const t_ref&)=delete;
        t_ref();;
      public:
        t_ref(t_ref&&_Right);
        void operator=(t_ref&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_scopes
      {
      public:
        class t_item
        {
        public:
          typedef t_scopes OwnerClass;
        public:
          typedef t_item SelfClass;
        public:
          t_scope_with_sep sws;
          t_type_with_sep body;
        public:
          void DoReset();
        public:
          t_item(const t_item&)=delete;
          t_item();;
        public:
          t_item(t_item&&_Right);
          void operator=(t_item&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          bool go(i_dev&dev);
        };
      public:
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_scopes SelfClass;
      public:
        t_type_with_sep first;
        vector<t_item> arr;
      public:
        void DoReset();
      public:
        t_scopes(const t_scopes&)=delete;
        t_scopes();;
      public:
        t_scopes(t_scopes&&_Right);
        void operator=(t_scopes&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_keyword
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_keyword SelfClass;
      public:
        string keyword;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_keyword(const t_keyword&)=delete;
        t_keyword();;
      public:
        t_keyword(t_keyword&&_Right);
        void operator=(t_keyword&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_type_expr_with_sep_and_cv
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_type_expr_with_sep_and_cv SelfClass;
      public:
        vector<t_const_with_sep> cvs;
        TAutoPtr<t_type_expr> body;
      public:
        void DoReset();
      public:
        t_type_expr_with_sep_and_cv(const t_type_expr_with_sep_and_cv&)=delete;
        t_type_expr_with_sep_and_cv();;
      public:
        t_type_expr_with_sep_and_cv(t_type_expr_with_sep_and_cv&&_Right);
        void operator=(t_type_expr_with_sep_and_cv&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_name_part
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_name_part SelfClass;
      public:
        TAutoPtr<i_name_part> body;
      public:
        void DoReset();
      public:
        t_name_part(const t_name_part&)=delete;
        t_name_part();;
      public:
        t_name_part(t_name_part&&_Right);
        void operator=(t_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_arr_body
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_arr_body SelfClass;
      public:
        t_sep sep0;
        t_sep sep1;
        t_expr expr;
        t_sep sep2;
        t_sep sep3;
      public:
        void DoReset();
      public:
        t_arr_body(const t_arr_body&)=delete;
        t_arr_body();;
      public:
        t_arr_body(t_arr_body&&_Right);
        void operator=(t_arr_body&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_brackets_name_part:public i_name_part
      {
      public:
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
      public:
        class i_part
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef i_part SelfClass;
        public:
        public:
          void DoReset();
        public:
          i_part(const i_part&)=delete;
          i_part();;
        public:
          i_part(i_part&&_Right);
          void operator=(i_part&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          typedef i_part_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_amp
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef t_amp SelfClass;
        public:
          string body;
        public:
          void DoReset();
        public:
          t_amp(const t_amp&)=delete;
          t_amp();;
        public:
          t_amp(t_amp&&_Right);
          void operator=(t_amp&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          bool go(i_dev&dev);
        };
        class t_amp_part:public i_part
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef t_amp_part SelfClass;
        public:
          typedef i_part ParentClass;
        public:
          t_amp body;
        public:
          void DoReset();
        public:
          t_amp_part(const t_amp_part&)=delete;
          t_amp_part();;
        public:
          t_amp_part(t_amp_part&&_Right);
          void operator=(t_amp_part&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_star_part:public i_part
        {
        public:
          typedef t_brackets_name_part OwnerClass;
        public:
          typedef t_star_part SelfClass;
        public:
          typedef i_part ParentClass;
        public:
          string stars;
          TAutoPtr<t_amp> amp;
        public:
          void DoReset();
        public:
          t_star_part(const t_star_part&)=delete;
          t_star_part();;
        public:
          t_star_part(t_star_part&&_Right);
          void operator=(t_star_part&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
      public:
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_brackets_name_part SelfClass;
      public:
        typedef i_name_part ParentClass;
      public:
        TAutoPtr<i_part> stamp_part;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
        TAutoPtr<t_arr_body> arrbody;
      public:
        void DoReset();
      public:
        t_brackets_name_part(const t_brackets_name_part&)=delete;
        t_brackets_name_part();;
      public:
        t_brackets_name_part(t_brackets_name_part&&_Right);
        void operator=(t_brackets_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      public:
      };
      class t_raw_name_part:public i_name_part
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_raw_name_part SelfClass;
      public:
        typedef i_name_part ParentClass;
      public:
        string name;
      public:
        void DoReset();
      public:
        t_raw_name_part(const t_raw_name_part&)=delete;
        t_raw_name_part();;
      public:
        t_raw_name_part(t_raw_name_part&&_Right);
        void operator=(t_raw_name_part&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_pfunc_func_param:public i_func_param
      {
      public:
        class t_addr
        {
        public:
          typedef t_pfunc_func_param OwnerClass;
        public:
          typedef t_addr SelfClass;
        public:
          t_type_expr_with_sep_and_cv type;
        public:
          void DoReset();
        public:
          t_addr(const t_addr&)=delete;
          t_addr();;
        public:
          t_addr(t_addr&&_Right);
          void operator=(t_addr&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          bool go(i_dev&dev);
        };
      public:
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_pfunc_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
        t_type_expr_with_sep_and_cv type;
        t_addr addr;
        string name;
      public:
        void DoReset();
      public:
        t_pfunc_func_param(const t_pfunc_func_param&)=delete;
        t_pfunc_func_param();;
      public:
        t_pfunc_func_param(t_pfunc_func_param&&_Right);
        void operator=(t_pfunc_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_var_args_func_param:public i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_var_args_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
      public:
        void DoReset();
      public:
        t_var_args_func_param(const t_var_args_func_param&)=delete;
        t_var_args_func_param();;
      public:
        t_var_args_func_param(t_var_args_func_param&&_Right);
        void operator=(t_var_args_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_type_func_param:public i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_type_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
        t_type_expr_with_sep_and_cv type;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
      public:
        void DoReset();
      public:
        t_type_func_param(const t_type_func_param&)=delete;
        t_type_func_param();;
      public:
        t_type_func_param(t_type_func_param&&_Right);
        void operator=(t_type_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_expr_func_param:public i_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_expr_func_param SelfClass;
      public:
        typedef i_func_param ParentClass;
      public:
        t_expr body;
      public:
        void DoReset();
      public:
        t_expr_func_param(const t_expr_func_param&)=delete;
        t_expr_func_param();;
      public:
        t_expr_func_param(t_expr_func_param&&_Right);
        void operator=(t_expr_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_expr_ext:public i_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_expr_ext SelfClass;
      public:
        typedef i_func_param_value ParentClass;
      public:
        t_expr body;
      public:
        void DoReset();
      public:
        t_expr_ext(const t_expr_ext&)=delete;
        t_expr_ext();;
      public:
        t_expr_ext(t_expr_ext&&_Right);
        void operator=(t_expr_ext&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_func_ref_ext:public i_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_func_ref_ext SelfClass;
      public:
        typedef i_func_param_value ParentClass;
      public:
        t_sep sep;
        t_type_expr_with_sep_and_cv type;
      public:
        void DoReset();
      public:
        t_func_ref_ext(const t_func_ref_ext&)=delete;
        t_func_ref_ext();;
      public:
        t_func_ref_ext(t_func_ref_ext&&_Right);
        void operator=(t_func_ref_ext&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_func_param_value
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_func_param_value SelfClass;
      public:
        t_sep sep;
        TAutoPtr<i_func_param_value> value;
      public:
        void DoReset();
      public:
        t_func_param_value(const t_func_param_value&)=delete;
        t_func_param_value();;
      public:
        t_func_param_value(t_func_param_value&&_Right);
        void operator=(t_func_param_value&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_func_param
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_func_param SelfClass;
      public:
        t_sep sep0;
        TAutoPtr<i_func_param> body;
        t_sep sep1;
        TAutoPtr<t_func_param_value> value;
        t_sep sep2;
      public:
        void DoReset();
      public:
        t_func_param(const t_func_param&)=delete;
        t_func_param();;
      public:
        t_func_param(t_func_param&&_Right);
        void operator=(t_func_param&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_func_params
      {
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_func_params SelfClass;
      public:
        t_sep sep;
        vector<t_func_param> arr;
      public:
        void DoReset();
      public:
        t_func_params(const t_func_params&)=delete;
        t_func_params();;
      public:
        t_func_params(t_func_params&&_Right);
        void operator=(t_func_params&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
      class t_fv_stat
      {
      public:
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
      public:
        class i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef i_fv_body SelfClass;
        public:
        public:
          void DoReset();
        public:
          i_fv_body(const i_fv_body&)=delete;
          i_fv_body();;
        public:
          i_fv_body(i_fv_body&&_Right);
          void operator=(i_fv_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          typedef i_fv_body_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
      public:
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
      public:
        class i_fv_end
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef i_fv_end SelfClass;
        public:
        public:
          void DoReset();
        public:
          i_fv_end(const i_fv_end&)=delete;
          i_fv_end();;
        public:
          i_fv_end(i_fv_end&&_Right);
          void operator=(i_fv_end&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          typedef i_fv_end_visitor i_visitor;
          virtual void Use(i_visitor&A);
        public:
          virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
            bool load();
            static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
            static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_impl_func_body:public i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_impl_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
        public:
          t_sep sep;
          t_raw_func_body body;
        public:
          void DoReset();
        public:
          t_impl_func_body(const t_impl_func_body&)=delete;
          t_impl_func_body();;
        public:
          t_impl_func_body(t_impl_func_body&&_Right);
          void operator=(t_impl_func_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_zero_func_body:public i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_zero_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
        public:
        public:
          void DoReset();
        public:
          t_zero_func_body(const t_zero_func_body&)=delete;
          t_zero_func_body();;
        public:
          t_zero_func_body(t_zero_func_body&&_Right);
          void operator=(t_zero_func_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_delete_func_body:public i_fv_body
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_delete_func_body SelfClass;
        public:
          typedef i_fv_body ParentClass;
        public:
        public:
          void DoReset();
        public:
          t_delete_func_body(const t_delete_func_body&)=delete;
          t_delete_func_body();;
        public:
          t_delete_func_body(t_delete_func_body&&_Right);
          void operator=(t_delete_func_body&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_func_fv_end:public i_fv_end
        {
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_func_fv_end SelfClass;
        public:
          typedef i_fv_end ParentClass;
        public:
          TAutoPtr<t_func_params> params;
          TAutoPtr<t_const_with_sep> cv1;
          t_sep sep1;
          TAutoPtr<i_fv_body> body;
        public:
          void DoReset();
        public:
          t_func_fv_end(const t_func_fv_end&)=delete;
          t_func_fv_end();;
        public:
          t_func_fv_end(t_func_fv_end&&_Right);
          void operator=(t_func_fv_end&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        };
        class t_var_fv_end:public i_fv_end
        {
        public:
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
        public:
          class i_fv_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef i_fv_item SelfClass;
          public:
          public:
            void DoReset();
          public:
            i_fv_item(const i_fv_item&)=delete;
            i_fv_item();;
          public:
            i_fv_item(i_fv_item&&_Right);
            void operator=(i_fv_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnv&RTTI);
              static string GetFullName();
            };
          public:
          public:
            typedef i_fv_item_visitor i_visitor;
            virtual void Use(i_visitor&A);
          public:
            virtual bool go(i_dev&dev);;
            struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
            {
              typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
              bool load();
              static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
              static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
            };
          };
          class t_func_fv_item:public i_fv_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_func_fv_item SelfClass;
          public:
            typedef i_fv_item ParentClass;
          public:
            TAutoPtr<t_func_params> params;
            TAutoPtr<t_const_with_sep> cv1;
          public:
            void DoReset();
          public:
            t_func_fv_item(const t_func_fv_item&)=delete;
            t_func_fv_item();;
          public:
            t_func_fv_item(t_func_fv_item&&_Right);
            void operator=(t_func_fv_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnv&RTTI);
              static string GetFullName();
            };
          public:
          public:
            void Use(i_visitor&A);
            static SelfClass*UberCast(ParentClass*ptr);
          public:
            bool go(i_dev&dev);
          };
          class t_var_fv_item:public i_fv_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_var_fv_item SelfClass;
          public:
            typedef i_fv_item ParentClass;
          public:
            TAutoPtr<t_arr_body> arrbody;
            TAutoPtr<t_func_param_value> value;
          public:
            void DoReset();
          public:
            t_var_fv_item(const t_var_fv_item&)=delete;
            t_var_fv_item();;
          public:
            t_var_fv_item(t_var_fv_item&&_Right);
            void operator=(t_var_fv_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnv&RTTI);
              static string GetFullName();
            };
          public:
          public:
            void Use(i_visitor&A);
            static SelfClass*UberCast(ParentClass*ptr);
          public:
            bool go(i_dev&dev);
          };
          class t_body
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_body SelfClass;
          public:
            TAutoPtr<i_fv_item> body;
          public:
            void DoReset();
          public:
            t_body(const t_body&)=delete;
            t_body();;
          public:
            t_body(t_body&&_Right);
            void operator=(t_body&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnv&RTTI);
              static string GetFullName();
            };
          public:
          public:
            bool go(i_dev&dev);
          };
          class t_item
          {
          public:
            typedef t_var_fv_end OwnerClass;
          public:
            typedef t_item SelfClass;
          public:
            t_sep sep0;
            TAutoPtr<t_const_with_sep> cv;
            t_sep sep1;
            string name;
            t_sep sep2;
            t_body body;
            t_sep sep3;
          public:
            void DoReset();
          public:
            t_item(const t_item&)=delete;
            t_item();;
          public:
            t_item(t_item&&_Right);
            void operator=(t_item&&_Right);
          public:
            struct ProxySys$$
            {
              typedef TTypeStruct metatype;
              static metatype*GetRTTI(IEnv&RTTI);
              static string GetFullName();
            };
          public:
          public:
            bool go(i_dev&dev);
          };
        public:
        public:
          typedef t_fv_stat OwnerClass;
        public:
          typedef t_var_fv_end SelfClass;
        public:
          typedef i_fv_end ParentClass;
        public:
          TAutoPtr<t_body> body;
          vector<t_item> arr;
        public:
          void DoReset();
        public:
          t_var_fv_end(const t_var_fv_end&)=delete;
          t_var_fv_end();;
        public:
          t_var_fv_end(t_var_fv_end&&_Right);
          void operator=(t_var_fv_end&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          void Use(i_visitor&A);
          static SelfClass*UberCast(ParentClass*ptr);
        public:
          bool go(i_dev&dev);
        public:
        };
      public:
      public:
        typedef t_type_expr OwnerClass;
      public:
        typedef t_fv_stat SelfClass;
      public:
        t_sep sep_wa;
        vector<t_keyword> keywords;
        TAutoPtr<t_type_expr> type;
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep0;
        TAutoPtr<t_func_path> path;
        t_name_part name;
        t_sep sep1;
        TAutoPtr<i_fv_end> way;
      public:
        void DoReset();
      public:
        t_fv_stat(const t_fv_stat&)=delete;
        t_fv_stat();;
      public:
        t_fv_stat(t_fv_stat&&_Right);
        void operator=(t_fv_stat&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      public:
      };
    public:
    public:
      typedef t_fv_class_stat OwnerClass;
    public:
      typedef t_type_expr SelfClass;
    public:
      TAutoPtr<t_first_scope> first;
      t_scopes scopes;
      vector<t_ptr> ptrs;
      TAutoPtr<t_ref> ref;
    public:
      void DoReset();
    public:
      t_type_expr(const t_type_expr&)=delete;
      t_type_expr();;
    public:
      t_type_expr(t_type_expr&&_Right);
      void operator=(t_type_expr&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    public:
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_fv_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_type_expr::t_fv_stat body;
  public:
    void DoReset();
  public:
    t_fv_class_stat(const t_fv_class_stat&)=delete;
    t_fv_class_stat();;
  public:
    t_fv_class_stat(t_fv_class_stat&&_Right);
    void operator=(t_fv_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_typedef_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_typedef_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep;
    t_fv_class_stat::t_type_expr::t_fv_stat body;
  public:
    void DoReset();
  public:
    t_typedef_class_stat(const t_typedef_class_stat&)=delete;
    t_typedef_class_stat();;
  public:
    t_typedef_class_stat(t_typedef_class_stat&&_Right);
    void operator=(t_typedef_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_call_param
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_call_param SelfClass;
  public:
    t_sep sep0;
    t_expr expr;
    t_sep sep1;
  public:
    void DoReset();
  public:
    t_call_param(const t_call_param&)=delete;
    t_call_param();;
  public:
    t_call_param(t_call_param&&_Right);
    void operator=(t_call_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_call_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_call_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string func;
    t_sep sep;
    vector<t_call_param> arr;
  public:
    void DoReset();
  public:
    t_call_expr(const t_call_expr&)=delete;
    t_call_expr();;
  public:
    t_call_expr(t_call_expr&&_Right);
    void operator=(t_call_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_real
  {
  public:
    class t_f
    {
    public:
      typedef t_real OwnerClass;
    public:
      typedef t_f SelfClass;
    public:
      char body;
    public:
      void DoReset();
    public:
      t_f(const t_f&)=delete;
      t_f();;
    public:
      t_f(t_f&&_Right);
      void operator=(t_f&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_real SelfClass;
  public:
    string bef;
    string aft;
    TAutoPtr<t_f> ext;
  public:
    void DoReset();
  public:
    t_real(const t_real&)=delete;
    t_real();;
  public:
    t_real(t_real&&_Right);
    void operator=(t_real&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_bool_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_bool_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_bool_expr(const t_bool_expr&)=delete;
    t_bool_expr();;
  public:
    t_bool_expr(t_bool_expr&&_Right);
    void operator=(t_bool_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_string_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_string_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_string_expr(const t_string_expr&)=delete;
    t_string_expr();;
  public:
    t_string_expr(t_string_expr&&_Right);
    void operator=(t_string_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_char_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_char_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_char_expr(const t_char_expr&)=delete;
    t_char_expr();;
  public:
    t_char_expr(t_char_expr&&_Right);
    void operator=(t_char_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_num_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_num_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_num_expr(const t_num_expr&)=delete;
    t_num_expr();;
  public:
    t_num_expr(t_num_expr&&_Right);
    void operator=(t_num_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_real_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_real_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_real_expr(const t_real_expr&)=delete;
    t_real_expr();;
  public:
    t_real_expr(t_real_expr&&_Right);
    void operator=(t_real_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_nullptr_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_nullptr_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
  public:
    void DoReset();
  public:
    t_nullptr_expr(const t_nullptr_expr&)=delete;
    t_nullptr_expr();;
  public:
    t_nullptr_expr(t_nullptr_expr&&_Right);
    void operator=(t_nullptr_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_or_expr:public i_expr
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_or_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    vector<t_name> arr;
  public:
    void DoReset();
  public:
    t_or_expr(const t_or_expr&)=delete;
    t_or_expr();;
  public:
    t_or_expr(t_or_expr&&_Right);
    void operator=(t_or_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_hex_expr:public i_expr
  {
  public:
    class t_impl
    {
    public:
      typedef t_hex_expr OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      char x;
      string value;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();;
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_hex_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string value;
  public:
    void DoReset();
  public:
    t_hex_expr(const t_hex_expr&)=delete;
    t_hex_expr();;
  public:
    t_hex_expr(t_hex_expr&&_Right);
    void operator=(t_hex_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_var_expr:public i_expr
  {
  public:
    class t_item
    {
    public:
      typedef t_var_expr OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_fv_class_stat::t_type_expr::t_type_with_sep body;
      t_sep sep;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_field
    {
    public:
      typedef t_var_expr OwnerClass;
    public:
      typedef t_field SelfClass;
    public:
      t_sep bef;
      string name;
      t_sep aft;
    public:
      void DoReset();
    public:
      t_field(const t_field&)=delete;
      t_field();;
    public:
      t_field(t_field&&_Right);
      void operator=(t_field&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_impl
    {
    public:
      typedef t_var_expr OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      vector<t_item> items;
      t_sep sep;
      vector<t_field> arr;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();;
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_var_expr SelfClass;
  public:
    typedef i_expr ParentClass;
  public:
    string name;
  public:
    void DoReset();
  public:
    t_var_expr(const t_var_expr&)=delete;
    t_var_expr();;
  public:
    t_var_expr(t_var_expr&&_Right);
    void operator=(t_var_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_ctor_init_list
  {
  public:
    class t_init_param
    {
    public:
      typedef t_ctor_init_list OwnerClass;
    public:
      typedef t_init_param SelfClass;
    public:
      t_sep sep0;
      string name;
      vector<t_call_param> arr;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_init_param(const t_init_param&)=delete;
      t_init_param();;
    public:
      t_init_param(t_init_param&&_Right);
      void operator=(t_init_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_ctor_init_list SelfClass;
  public:
    vector<t_init_param> params;
    t_sep sep;
  public:
    void DoReset();
  public:
    t_ctor_init_list(const t_ctor_init_list&)=delete;
    t_ctor_init_list();;
  public:
    t_ctor_init_list(t_ctor_init_list&&_Right);
    void operator=(t_ctor_init_list&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_zero_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_zero_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
  public:
    void DoReset();
  public:
    t_zero_func_body(const t_zero_func_body&)=delete;
    t_zero_func_body();;
  public:
    t_zero_func_body(t_zero_func_body&&_Right);
    void operator=(t_zero_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_null_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_null_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
    t_sep sep;
  public:
    void DoReset();
  public:
    t_null_func_body(const t_null_func_body&)=delete;
    t_null_func_body();;
  public:
    t_null_func_body(t_null_func_body&&_Right);
    void operator=(t_null_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_delete_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_delete_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
  public:
    void DoReset();
  public:
    t_delete_func_body(const t_delete_func_body&)=delete;
    t_delete_func_body();;
  public:
    t_delete_func_body(t_delete_func_body&&_Right);
    void operator=(t_delete_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_impl_func_body:public i_func_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_impl_func_body SelfClass;
  public:
    typedef i_func_body ParentClass;
  public:
    t_sep sep;
    TAutoPtr<t_ctor_init_list> init_list;
    t_raw_func_body body;
  public:
    void DoReset();
  public:
    t_impl_func_body(const t_impl_func_body&)=delete;
    t_impl_func_body();;
  public:
    t_impl_func_body(t_impl_func_body&&_Right);
    void operator=(t_impl_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_dtor_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_dtor_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep0;
    TAutoPtr<t_func_path> path;
    string name;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<i_func_body> body;
  public:
    void DoReset();
  public:
    t_dtor_class_stat(const t_dtor_class_stat&)=delete;
    t_dtor_class_stat();;
  public:
    t_dtor_class_stat(t_dtor_class_stat&&_Right);
    void operator=(t_dtor_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_ctor_class_stat:public i_class_stat
  {
  public:
    class t_impl
    {
    public:
      class t_explicit
      {
      public:
        typedef t_impl OwnerClass;
      public:
        typedef t_explicit SelfClass;
      public:
        t_sep sep;
      public:
        void DoReset();
      public:
        t_explicit(const t_explicit&)=delete;
        t_explicit();;
      public:
        t_explicit(t_explicit&&_Right);
        void operator=(t_explicit&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
    public:
    public:
      typedef t_ctor_class_stat OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
      TAutoPtr<t_explicit> prefix;
      TAutoPtr<t_func_path> path;
      string name;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<i_func_body> body;
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();;
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_ctor_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_impl body;
  public:
    void DoReset();
  public:
    t_ctor_class_stat(const t_ctor_class_stat&)=delete;
    t_ctor_class_stat();;
  public:
    t_ctor_class_stat(t_ctor_class_stat&&_Right);
    void operator=(t_ctor_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_oper_cast_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_oper_cast_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    TAutoPtr<t_func_path> path;
    t_sep sep0;
    t_fv_class_stat::t_type_expr type;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep> cv;
    TAutoPtr<i_func_body> body;
  public:
    void DoReset();
  public:
    t_oper_cast_class_stat(const t_oper_cast_class_stat&)=delete;
    t_oper_cast_class_stat();;
  public:
    t_oper_cast_class_stat(t_oper_cast_class_stat&&_Right);
    void operator=(t_oper_cast_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_common_oper_class_stat:public i_class_stat
  {
  public:
    class t_impl
    {
    public:
      typedef t_common_oper_class_stat OwnerClass;
    public:
      typedef t_impl SelfClass;
    public:
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
    public:
      void DoReset();
    public:
      t_impl(const t_impl&)=delete;
      t_impl();;
    public:
      t_impl(t_impl&&_Right);
      void operator=(t_impl&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_common_oper_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_impl body;
  public:
    void DoReset();
  public:
    t_common_oper_class_stat(const t_common_oper_class_stat&)=delete;
    t_common_oper_class_stat();;
  public:
    t_common_oper_class_stat(t_common_oper_class_stat&&_Right);
    void operator=(t_common_oper_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_parents
  {
  public:
    class t_item
    {
    public:
      class t_pub
      {
      public:
        typedef t_item OwnerClass;
      public:
        typedef t_pub SelfClass;
      public:
        t_access_mod mod;
        t_sep sep;
      public:
        void DoReset();
      public:
        t_pub(const t_pub&)=delete;
        t_pub();;
      public:
        t_pub(t_pub&&_Right);
        void operator=(t_pub&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
    public:
    public:
      typedef t_parents OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_sep sep;
      TAutoPtr<t_pub> pub;
      string name;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_parents SelfClass;
  public:
    t_sep sep;
    vector<t_item> arr;
  public:
    void DoReset();
  public:
    t_parents(const t_parents&)=delete;
    t_parents();;
  public:
    t_parents(t_parents&&_Right);
    void operator=(t_parents&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_class_body
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_class_body SelfClass;
  public:
    vector<TAutoPtr<i_class_stat>> arr;
  public:
    void DoReset();
  public:
    t_class_body(const t_class_body&)=delete;
    t_class_body();;
  public:
    t_class_body(t_class_body&&_Right);
    void operator=(t_class_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_class
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_class SelfClass;
  public:
    string keyword;
    t_sep sep0;
    string name;
    t_sep sep1;
    TAutoPtr<t_parents> parents;
    t_sep sep2;
    TAutoPtr<t_class_body> body;
    t_sep sep3;
  public:
    void DoReset();
  public:
    t_class(const t_class&)=delete;
    t_class();;
  public:
    t_class(t_class&&_Right);
    void operator=(t_class&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
  class t_namespace_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_namespace_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep0;
    string name;
    t_sep sep1;
    t_class_body body;
  public:
    void DoReset();
  public:
    t_namespace_class_stat(const t_namespace_class_stat&)=delete;
    t_namespace_class_stat();;
  public:
    t_namespace_class_stat(t_namespace_class_stat&&_Right);
    void operator=(t_namespace_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_template_class_stat:public i_class_stat
  {
  public:
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
  public:
    class i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef i_template_body SelfClass;
    public:
    public:
      void DoReset();
    public:
      i_template_body(const i_template_body&)=delete;
      i_template_body();;
    public:
      i_template_body(i_template_body&&_Right);
      void operator=(i_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      typedef i_template_body_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
  public:
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
  public:
    class i_template_param
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef i_template_param SelfClass;
    public:
    public:
      void DoReset();
    public:
      i_template_param(const i_template_param&)=delete;
      i_template_param();;
    public:
      i_template_param(i_template_param&&_Right);
      void operator=(i_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      typedef i_template_param_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_template_param
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_template_param SelfClass;
    public:
      t_sep bef;
      TAutoPtr<i_template_param> body;
      t_sep aft;
    public:
      void DoReset();
    public:
      t_template_param(const t_template_param&)=delete;
      t_template_param();;
    public:
      t_template_param(t_template_param&&_Right);
      void operator=(t_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_concrete_param
    {
    public:
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
    public:
      class i_body
      {
      public:
        typedef t_concrete_param OwnerClass;
      public:
        typedef i_body SelfClass;
      public:
      public:
        void DoReset();
      public:
        i_body(const i_body&)=delete;
        i_body();;
      public:
        i_body(i_body&&_Right);
        void operator=(i_body&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        typedef i_body_visitor i_visitor;
        virtual void Use(i_visitor&A);
      public:
        virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
          bool load();
          static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
          static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
      class t_raw_expr:public i_body
      {
      public:
        typedef t_concrete_param OwnerClass;
      public:
        typedef t_raw_expr SelfClass;
      public:
        typedef i_body ParentClass;
      public:
        t_expr body;
      public:
        void DoReset();
      public:
        t_raw_expr(const t_raw_expr&)=delete;
        t_raw_expr();;
      public:
        t_raw_expr(t_raw_expr&&_Right);
        void operator=(t_raw_expr&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
      class t_template_expr:public i_body
      {
      public:
        class t_main
        {
        public:
          typedef t_template_expr OwnerClass;
        public:
          typedef t_main SelfClass;
        public:
          vector<t_fv_class_stat::t_type_expr::t_type_with_sep> arr;
        public:
          void DoReset();
        public:
          t_main(const t_main&)=delete;
          t_main();;
        public:
          t_main(t_main&&_Right);
          void operator=(t_main&&_Right);
        public:
          struct ProxySys$$
          {
            typedef TTypeStruct metatype;
            static metatype*GetRTTI(IEnv&RTTI);
            static string GetFullName();
          };
        public:
        public:
          bool go(i_dev&dev);
        };
      public:
      public:
        typedef t_concrete_param OwnerClass;
      public:
        typedef t_template_expr SelfClass;
      public:
        typedef i_body ParentClass;
      public:
        t_main body;
      public:
        void DoReset();
      public:
        t_template_expr(const t_template_expr&)=delete;
        t_template_expr();;
      public:
        t_template_expr(t_template_expr&&_Right);
        void operator=(t_template_expr&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        void Use(i_visitor&A);
        static SelfClass*UberCast(ParentClass*ptr);
      public:
        bool go(i_dev&dev);
      };
    public:
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_concrete_param SelfClass;
    public:
      t_sep sep0;
      TAutoPtr<i_body> body;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_concrete_param(const t_concrete_param&)=delete;
      t_concrete_param();;
    public:
      t_concrete_param(t_concrete_param&&_Right);
      void operator=(t_concrete_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_concrete_params
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_concrete_params SelfClass;
    public:
      vector<t_concrete_param> arr;
      t_sep sep;
    public:
      void DoReset();
    public:
      t_concrete_params(const t_concrete_params&)=delete;
      t_concrete_params();;
    public:
      t_concrete_params(t_concrete_params&&_Right);
      void operator=(t_concrete_params&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_common_oper_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_common_oper_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
      t_common_oper_class_stat::t_impl body;
    public:
      void DoReset();
    public:
      t_common_oper_template_body(const t_common_oper_template_body&)=delete;
      t_common_oper_template_body();;
    public:
      t_common_oper_template_body(t_common_oper_template_body&&_Right);
      void operator=(t_common_oper_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_ctor_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_ctor_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
      t_ctor_class_stat::t_impl body;
    public:
      void DoReset();
    public:
      t_ctor_template_body(const t_ctor_template_body&)=delete;
      t_ctor_template_body();;
    public:
      t_ctor_template_body(t_ctor_template_body&&_Right);
      void operator=(t_ctor_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_func_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_func_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
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
    public:
      void DoReset();
    public:
      t_func_template_body(const t_func_template_body&)=delete;
      t_func_template_body();;
    public:
      t_func_template_body(t_func_template_body&&_Right);
      void operator=(t_func_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_class_template_body:public i_template_body
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_class_template_body SelfClass;
    public:
      typedef i_template_body ParentClass;
    public:
      string keyword;
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_concrete_params> params;
      TAutoPtr<t_parents> parents;
      t_sep sep2;
      TAutoPtr<t_class_body> body;
      t_sep sep3;
    public:
      void DoReset();
    public:
      t_class_template_body(const t_class_template_body&)=delete;
      t_class_template_body();;
    public:
      t_class_template_body(t_class_template_body&&_Right);
      void operator=(t_class_template_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_head
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_head SelfClass;
    public:
      t_sep sep0;
      vector<t_template_param> params;
      t_sep sep1;
      TAutoPtr<i_template_body> body;
    public:
      void DoReset();
    public:
      t_head(const t_head&)=delete;
      t_head();;
    public:
      t_head(t_head&&_Right);
      void operator=(t_head&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_name_template_param:public i_template_param
    {
    public:
      class t_unsgnd
      {
      public:
        typedef t_name_template_param OwnerClass;
      public:
        typedef t_unsgnd SelfClass;
      public:
        t_sep sep;
      public:
        void DoReset();
      public:
        t_unsgnd(const t_unsgnd&)=delete;
        t_unsgnd();;
      public:
        t_unsgnd(t_unsgnd&&_Right);
        void operator=(t_unsgnd&&_Right);
      public:
        struct ProxySys$$
        {
          typedef TTypeStruct metatype;
          static metatype*GetRTTI(IEnv&RTTI);
          static string GetFullName();
        };
      public:
      public:
        bool go(i_dev&dev);
      };
    public:
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_name_template_param SelfClass;
    public:
      typedef i_template_param ParentClass;
    public:
      string unsgnd0;
      t_sep sep0;
      string type;
      t_sep sep1;
      string unsgnd1;
      t_sep sep2;
      string name;
    public:
      void DoReset();
    public:
      t_name_template_param(const t_name_template_param&)=delete;
      t_name_template_param();;
    public:
      t_name_template_param(t_name_template_param&&_Right);
      void operator=(t_name_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_type_template_param:public i_template_param
    {
    public:
      typedef t_template_class_stat OwnerClass;
    public:
      typedef t_type_template_param SelfClass;
    public:
      typedef i_template_param ParentClass;
    public:
      TAutoPtr<t_head> head;
      string type;
      t_sep sep;
      string name;
    public:
      void DoReset();
    public:
      t_type_template_param(const t_type_template_param&)=delete;
      t_type_template_param();;
    public:
      t_type_template_param(t_type_template_param&&_Right);
      void operator=(t_type_template_param&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_template_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_head head;
    vector<t_template_param> params;
    TAutoPtr<i_template_body> body;
  public:
    void DoReset();
  public:
    t_template_class_stat(const t_template_class_stat&)=delete;
    t_template_class_stat();;
  public:
    t_template_class_stat(t_template_class_stat&&_Right);
    void operator=(t_template_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_enum_class_stat:public i_class_stat
  {
  public:
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
  public:
    class i_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef i_body SelfClass;
    public:
    public:
      void DoReset();
    public:
      i_body(const i_body&)=delete;
      i_body();;
    public:
      i_body(i_body&&_Right);
      void operator=(i_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      typedef i_body_visitor i_visitor;
      virtual void Use(i_visitor&A);
    public:
      virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
        bool load();
        static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
        static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_value
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_value SelfClass;
    public:
      t_sep sep0;
      t_expr expr;
      t_sep sep1;
    public:
      void DoReset();
    public:
      t_value(const t_value&)=delete;
      t_value();;
    public:
      t_value(t_value&&_Right);
      void operator=(t_value&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_item
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_item SelfClass;
    public:
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_value> value;
    public:
      void DoReset();
    public:
      t_item(const t_item&)=delete;
      t_item();;
    public:
      t_item(t_item&&_Right);
      void operator=(t_item&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_comma_with_sep
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_comma_with_sep SelfClass;
    public:
      t_sep sep;
    public:
      void DoReset();
    public:
      t_comma_with_sep(const t_comma_with_sep&)=delete;
      t_comma_with_sep();;
    public:
      t_comma_with_sep(t_comma_with_sep&&_Right);
      void operator=(t_comma_with_sep&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
    class t_impl_body:public i_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_impl_body SelfClass;
    public:
      typedef i_body ParentClass;
    public:
      vector<t_item> arr;
      TAutoPtr<t_comma_with_sep> comma;
    public:
      void DoReset();
    public:
      t_impl_body(const t_impl_body&)=delete;
      t_impl_body();;
    public:
      t_impl_body(t_impl_body&&_Right);
      void operator=(t_impl_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_empty_body:public i_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_empty_body SelfClass;
    public:
      typedef i_body ParentClass;
    public:
    public:
      void DoReset();
    public:
      t_empty_body(const t_empty_body&)=delete;
      t_empty_body();;
    public:
      t_empty_body(t_empty_body&&_Right);
      void operator=(t_empty_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      void Use(i_visitor&A);
      static SelfClass*UberCast(ParentClass*ptr);
    public:
      bool go(i_dev&dev);
    };
    class t_body
    {
    public:
      typedef t_enum_class_stat OwnerClass;
    public:
      typedef t_body SelfClass;
    public:
      TAutoPtr<i_body> body;
    public:
      void DoReset();
    public:
      t_body(const t_body&)=delete;
      t_body();;
    public:
      t_body(t_body&&_Right);
      void operator=(t_body&&_Right);
    public:
      struct ProxySys$$
      {
        typedef TTypeStruct metatype;
        static metatype*GetRTTI(IEnv&RTTI);
        static string GetFullName();
      };
    public:
    public:
      bool go(i_dev&dev);
    };
  public:
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_enum_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep0;
    string name;
    t_sep sep1;
    t_body body;
  public:
    void DoReset();
  public:
    t_enum_class_stat(const t_enum_class_stat&)=delete;
    t_enum_class_stat();;
  public:
    t_enum_class_stat(t_enum_class_stat&&_Right);
    void operator=(t_enum_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  public:
  };
  class t_using_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_using_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep;
    t_fv_class_stat::t_type_expr type;
  public:
    void DoReset();
  public:
    t_using_class_stat(const t_using_class_stat&)=delete;
    t_using_class_stat();;
  public:
    t_using_class_stat(t_using_class_stat&&_Right);
    void operator=(t_using_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_pragma_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_pragma_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_pragma_class_stat(const t_pragma_class_stat&)=delete;
    t_pragma_class_stat();;
  public:
    t_pragma_class_stat(t_pragma_class_stat&&_Right);
    void operator=(t_pragma_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_include_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_include_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_include_class_stat(const t_include_class_stat&)=delete;
    t_include_class_stat();;
  public:
    t_include_class_stat(t_include_class_stat&&_Right);
    void operator=(t_include_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_preproc_if_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_preproc_if_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_preproc_if_class_stat(const t_preproc_if_class_stat&)=delete;
    t_preproc_if_class_stat();;
  public:
    t_preproc_if_class_stat(t_preproc_if_class_stat&&_Right);
    void operator=(t_preproc_if_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_preproc_else_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_preproc_else_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_preproc_else_class_stat(const t_preproc_else_class_stat&)=delete;
    t_preproc_else_class_stat();;
  public:
    t_preproc_else_class_stat(t_preproc_else_class_stat&&_Right);
    void operator=(t_preproc_else_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_preproc_endif_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_preproc_endif_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_preproc_endif_class_stat(const t_preproc_endif_class_stat&)=delete;
    t_preproc_endif_class_stat();;
  public:
    t_preproc_endif_class_stat(t_preproc_endif_class_stat&&_Right);
    void operator=(t_preproc_endif_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_define_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_define_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_define_class_stat(const t_define_class_stat&)=delete;
    t_define_class_stat();;
  public:
    t_define_class_stat(t_define_class_stat&&_Right);
    void operator=(t_define_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_undef_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_undef_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    string body;
  public:
    void DoReset();
  public:
    t_undef_class_stat(const t_undef_class_stat&)=delete;
    t_undef_class_stat();;
  public:
    t_undef_class_stat(t_undef_class_stat&&_Right);
    void operator=(t_undef_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_sep_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_sep_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_sep sep;
  public:
    void DoReset();
  public:
    t_sep_class_stat(const t_sep_class_stat&)=delete;
    t_sep_class_stat();;
  public:
    t_sep_class_stat(t_sep_class_stat&&_Right);
    void operator=(t_sep_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_null_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_null_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
  public:
    void DoReset();
  public:
    t_null_class_stat(const t_null_class_stat&)=delete;
    t_null_class_stat();;
  public:
    t_null_class_stat(t_null_class_stat&&_Right);
    void operator=(t_null_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_class_class_stat:public i_class_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_class_class_stat SelfClass;
  public:
    typedef i_class_stat ParentClass;
  public:
    t_class body;
  public:
    void DoReset();
  public:
    t_class_class_stat(const t_class_class_stat&)=delete;
    t_class_class_stat();;
  public:
    t_class_class_stat(t_class_class_stat&&_Right);
    void operator=(t_class_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    void Use(i_visitor&A);
    static SelfClass*UberCast(ParentClass*ptr);
  public:
    bool go(i_dev&dev);
  };
  class t_inl_file_stat
  {
  public:
    typedef t_inl_file OwnerClass;
  public:
    typedef t_inl_file_stat SelfClass;
  public:
    t_sep sep;
    TAutoPtr<t_class> body;
  public:
    void DoReset();
  public:
    t_inl_file_stat(const t_inl_file_stat&)=delete;
    t_inl_file_stat();;
  public:
    t_inl_file_stat(t_inl_file_stat&&_Right);
    void operator=(t_inl_file_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnv&RTTI);
      static string GetFullName();
    };
  public:
  public:
    bool go(i_dev&dev);
  };
public:
public:
  typedef t_inl_file SelfClass;
public:
  vector<TAutoPtr<i_class_stat>> arr;
public:
  void DoReset();
public:
  t_inl_file(const t_inl_file&)=delete;
  t_inl_file();;
public:
  t_inl_file(t_inl_file&&_Right);
  void operator=(t_inl_file&&_Right);
public:
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    static metatype*GetRTTI(IEnv&RTTI);
    static string GetFullName();
  };
public:
public:
  bool go(i_dev&dev);
public:
};
//impl
void t_inl_file::i_class_stat::DoReset()
{
  {
  }
}
t_inl_file::i_class_stat::i_class_stat()
{
  DoReset();
}
t_inl_file::i_class_stat::i_class_stat(i_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::i_class_stat::operator=(i_class_stat&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::i_class_stat::ProxySys$$::metatype*t_inl_file::i_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_class_stat";
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
string t_inl_file::i_class_stat::ProxySys$$::GetFullName()
{
  return "i_class_stat";
}
void t_inl_file::i_class_stat::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::i_class_stat::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::i_class_stat::t_poly_impl::load()
{
  go_for<t_access_mod_class_stat>();
  go_for<t_fv_class_stat>();
  go_for<t_typedef_class_stat>();
  go_for<t_dtor_class_stat>();
  go_for<t_ctor_class_stat>();
  go_for<t_oper_cast_class_stat>();
  go_for<t_common_oper_class_stat>();
  go_for<t_namespace_class_stat>();
  go_for<t_template_class_stat>();
  go_for<t_enum_class_stat>();
  go_for<t_using_class_stat>();
  go_for<t_pragma_class_stat>();
  go_for<t_include_class_stat>();
  go_for<t_preproc_if_class_stat>();
  go_for<t_preproc_else_class_stat>();
  go_for<t_preproc_endif_class_stat>();
  go_for<t_define_class_stat>();
  go_for<t_undef_class_stat>();
  go_for<t_sep_class_stat>();
  go_for<t_null_class_stat>();
  go_for<t_class_class_stat>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::i_class_stat::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_class_stat::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::i_expr::DoReset()
{
  {
  }
}
t_inl_file::i_expr::i_expr()
{
  DoReset();
}
t_inl_file::i_expr::i_expr(i_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::i_expr::operator=(i_expr&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::i_expr::ProxySys$$::metatype*t_inl_file::i_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_expr";
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
string t_inl_file::i_expr::ProxySys$$::GetFullName()
{
  return "i_expr";
}
void t_inl_file::i_expr::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::i_expr::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::i_expr::t_poly_impl::load()
{
  go_for<t_call_expr>();
  go_for<t_bool_expr>();
  go_for<t_string_expr>();
  go_for<t_char_expr>();
  go_for<t_num_expr>();
  go_for<t_real_expr>();
  go_for<t_nullptr_expr>();
  go_for<t_or_expr>();
  go_for<t_hex_expr>();
  go_for<t_var_expr>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::i_expr::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_expr::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::i_func_body::DoReset()
{
  {
  }
}
t_inl_file::i_func_body::i_func_body()
{
  DoReset();
}
t_inl_file::i_func_body::i_func_body(i_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::i_func_body::operator=(i_func_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::i_func_body::ProxySys$$::metatype*t_inl_file::i_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_func_body";
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
string t_inl_file::i_func_body::ProxySys$$::GetFullName()
{
  return "i_func_body";
}
void t_inl_file::i_func_body::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::i_func_body::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::i_func_body::t_poly_impl::load()
{
  go_for<t_zero_func_body>();
  go_for<t_null_func_body>();
  go_for<t_delete_func_body>();
  go_for<t_impl_func_body>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::i_func_body::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_func_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_lev03::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev03::t_lev03()
{
  DoReset();
}
t_inl_file::t_lev03::t_lev03(t_lev03&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev03::operator=(t_lev03&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev03::ProxySys$$::metatype*t_inl_file::t_lev03::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev03";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_expr>>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev03::ProxySys$$::GetFullName()
{
  return "t_lev03";
}
bool t_inl_file::t_lev03::go(i_dev&dev)
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
void t_inl_file::t_lev05::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev05::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev05::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev05::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev05::t_oper::ProxySys$$::metatype*t_inl_file::t_lev05::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev05::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev05::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev05::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev05::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev05::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev05::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev05::t_item::ProxySys$$::metatype*t_inl_file::t_lev05::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev05::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev05::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev05::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev05::t_lev05()
{
  DoReset();
}
t_inl_file::t_lev05::t_lev05(t_lev05&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev05::operator=(t_lev05&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev05::ProxySys$$::metatype*t_inl_file::t_lev05::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev05";
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
  Info->AddMemberDEF(Sys$$<t_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev05::ProxySys$$::GetFullName()
{
  return "t_lev05";
}
bool t_inl_file::t_lev05::go(i_dev&dev)
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
void t_inl_file::t_lev06::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev06::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev06::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev06::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev06::t_oper::ProxySys$$::metatype*t_inl_file::t_lev06::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev06::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev06::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev06::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev06::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev06::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev06::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev06::t_item::ProxySys$$::metatype*t_inl_file::t_lev06::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev06::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev06::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev06::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev06::t_lev06()
{
  DoReset();
}
t_inl_file::t_lev06::t_lev06(t_lev06&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev06::operator=(t_lev06&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev06::ProxySys$$::metatype*t_inl_file::t_lev06::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev06";
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
  Info->AddMemberDEF(Sys$$<t_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev06::ProxySys$$::GetFullName()
{
  return "t_lev06";
}
bool t_inl_file::t_lev06::go(i_dev&dev)
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
void t_inl_file::t_lev07::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev07::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev07::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev07::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev07::t_oper::ProxySys$$::metatype*t_inl_file::t_lev07::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev07::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev07::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev07::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev07::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev07::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev07::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev07::t_item::ProxySys$$::metatype*t_inl_file::t_lev07::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev07::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev07::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev07::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev07::t_lev07()
{
  DoReset();
}
t_inl_file::t_lev07::t_lev07(t_lev07&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev07::operator=(t_lev07&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev07::ProxySys$$::metatype*t_inl_file::t_lev07::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev07";
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
  Info->AddMemberDEF(Sys$$<t_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev07::ProxySys$$::GetFullName()
{
  return "t_lev07";
}
bool t_inl_file::t_lev07::go(i_dev&dev)
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
void t_inl_file::t_lev08::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev08::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev08::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev08::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev08::t_oper::ProxySys$$::metatype*t_inl_file::t_lev08::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev08::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev08::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev08::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev08::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev08::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev08::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev08::t_item::ProxySys$$::metatype*t_inl_file::t_lev08::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev07>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev08::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev08::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev08::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev08::t_lev08()
{
  DoReset();
}
t_inl_file::t_lev08::t_lev08(t_lev08&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev08::operator=(t_lev08&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev08::ProxySys$$::metatype*t_inl_file::t_lev08::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev08";
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
  Info->AddMemberDEF(Sys$$<t_lev07>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev08::ProxySys$$::GetFullName()
{
  return "t_lev08";
}
bool t_inl_file::t_lev08::go(i_dev&dev)
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
void t_inl_file::t_lev09::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev09::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev09::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev09::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev09::t_oper::ProxySys$$::metatype*t_inl_file::t_lev09::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev09::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev09::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev09::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev09::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev09::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev09::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev09::t_item::ProxySys$$::metatype*t_inl_file::t_lev09::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev08>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev09::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev09::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev09::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev09::t_lev09()
{
  DoReset();
}
t_inl_file::t_lev09::t_lev09(t_lev09&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev09::operator=(t_lev09&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev09::ProxySys$$::metatype*t_inl_file::t_lev09::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev09";
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
  Info->AddMemberDEF(Sys$$<t_lev08>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev09::ProxySys$$::GetFullName()
{
  return "t_lev09";
}
bool t_inl_file::t_lev09::go(i_dev&dev)
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
void t_inl_file::t_lev10::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev10::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev10::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev10::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev10::t_oper::ProxySys$$::metatype*t_inl_file::t_lev10::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev10::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev10::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev10::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev10::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev10::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev10::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev10::t_item::ProxySys$$::metatype*t_inl_file::t_lev10::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev10::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev10::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev10::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev10::t_lev10()
{
  DoReset();
}
t_inl_file::t_lev10::t_lev10(t_lev10&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev10::operator=(t_lev10&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev10::ProxySys$$::metatype*t_inl_file::t_lev10::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev10";
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
  Info->AddMemberDEF(Sys$$<t_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev10::ProxySys$$::GetFullName()
{
  return "t_lev10";
}
bool t_inl_file::t_lev10::go(i_dev&dev)
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
void t_inl_file::t_lev11::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev11::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev11::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev11::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev11::t_oper::ProxySys$$::metatype*t_inl_file::t_lev11::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev11::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev11::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev11::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev11::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev11::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev11::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev11::t_item::ProxySys$$::metatype*t_inl_file::t_lev11::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev11::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev11::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev11::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev11::t_lev11()
{
  DoReset();
}
t_inl_file::t_lev11::t_lev11(t_lev11&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev11::operator=(t_lev11&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev11::ProxySys$$::metatype*t_inl_file::t_lev11::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev11";
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
  Info->AddMemberDEF(Sys$$<t_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev11::ProxySys$$::GetFullName()
{
  return "t_lev11";
}
bool t_inl_file::t_lev11::go(i_dev&dev)
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
void t_inl_file::t_lev12::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev12::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev12::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev12::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev12::t_oper::ProxySys$$::metatype*t_inl_file::t_lev12::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev12::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev12::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev12::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev12::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev12::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev12::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev12::t_item::ProxySys$$::metatype*t_inl_file::t_lev12::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev12::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev12::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev12::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev12::t_lev12()
{
  DoReset();
}
t_inl_file::t_lev12::t_lev12(t_lev12&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev12::operator=(t_lev12&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev12::ProxySys$$::metatype*t_inl_file::t_lev12::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev12";
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
  Info->AddMemberDEF(Sys$$<t_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev12::ProxySys$$::GetFullName()
{
  return "t_lev12";
}
bool t_inl_file::t_lev12::go(i_dev&dev)
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
void t_inl_file::t_lev13::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev13::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev13::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev13::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev13::t_oper::ProxySys$$::metatype*t_inl_file::t_lev13::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev13::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev13::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev13::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev13::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev13::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev13::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev13::t_item::ProxySys$$::metatype*t_inl_file::t_lev13::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev13::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev13::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev13::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev13::t_lev13()
{
  DoReset();
}
t_inl_file::t_lev13::t_lev13(t_lev13&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev13::operator=(t_lev13&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev13::ProxySys$$::metatype*t_inl_file::t_lev13::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev13";
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
  Info->AddMemberDEF(Sys$$<t_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev13::ProxySys$$::GetFullName()
{
  return "t_lev13";
}
bool t_inl_file::t_lev13::go(i_dev&dev)
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
void t_inl_file::t_lev14::t_oper::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_lev14::t_oper::t_oper()
{
  DoReset();
}
t_inl_file::t_lev14::t_oper::t_oper(t_oper&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev14::t_oper::operator=(t_oper&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_lev14::t_oper::ProxySys$$::metatype*t_inl_file::t_lev14::t_oper::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev14::t_oper::ProxySys$$::GetFullName()
{
  return "t_oper";
}
bool t_inl_file::t_lev14::t_oper::go(i_dev&dev)
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
void t_inl_file::t_lev14::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->oper);
  detail::FieldTryDoReset(this->expr);
}
t_inl_file::t_lev14::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_lev14::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev14::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->oper=std::move(_Right.oper);
  this->expr=std::move(_Right.expr);
}
t_inl_file::t_lev14::t_item::ProxySys$$::metatype*t_inl_file::t_lev14::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev14::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_lev14::t_item::go(i_dev&dev)
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
void t_inl_file::t_lev14::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_lev14::t_lev14()
{
  DoReset();
}
t_inl_file::t_lev14::t_lev14(t_lev14&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_lev14::operator=(t_lev14&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->expr=std::move(_Right.expr);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_lev14::ProxySys$$::metatype*t_inl_file::t_lev14::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_lev14";
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
  Info->AddMemberDEF(Sys$$<t_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_lev14::ProxySys$$::GetFullName()
{
  return "t_lev14";
}
bool t_inl_file::t_lev14::go(i_dev&dev)
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
void t_inl_file::t_expr::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_expr::t_expr()
{
  DoReset();
}
t_inl_file::t_expr::t_expr(t_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_expr::operator=(t_expr&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_expr::ProxySys$$::metatype*t_inl_file::t_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_expr";
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
  Info->AddMemberDEF(Sys$$<t_lev14>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_expr::ProxySys$$::GetFullName()
{
  return "t_expr";
}
bool t_inl_file::t_expr::go(i_dev&dev)
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
void t_inl_file::t_access_mod::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->keyword);
}
t_inl_file::t_access_mod::t_access_mod()
{
  DoReset();
}
t_inl_file::t_access_mod::t_access_mod(t_access_mod&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_access_mod::operator=(t_access_mod&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->keyword=std::move(_Right.keyword);
}
t_inl_file::t_access_mod::ProxySys$$::metatype*t_inl_file::t_access_mod::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_access_mod";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_access_mod::ProxySys$$::GetFullName()
{
  return "t_access_mod";
}
bool t_inl_file::t_access_mod::go(i_dev&dev)
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
void t_inl_file::t_access_mod_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->mod);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_access_mod_class_stat::t_access_mod_class_stat()
{
  DoReset();
}
t_inl_file::t_access_mod_class_stat::t_access_mod_class_stat(t_access_mod_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_access_mod_class_stat::operator=(t_access_mod_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->mod=std::move(_Right.mod);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_access_mod_class_stat::ProxySys$$::metatype*t_inl_file::t_access_mod_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_access_mod_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_access_mod>::GetRTTI(RTTI),"mod",int(&(((SelfClass*)nullptr)->*(&SelfClass::mod))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_access_mod_class_stat::ProxySys$$::GetFullName()
{
  return "t_access_mod_class_stat";
}
void t_inl_file::t_access_mod_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_access_mod_class_stat::SelfClass*t_inl_file::t_access_mod_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_access_mod_class_stat::go(i_dev&dev)
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
void t_inl_file::t_raw_func_body::i_item::DoReset()
{
  {
  }
}
t_inl_file::t_raw_func_body::i_item::i_item()
{
  DoReset();
}
t_inl_file::t_raw_func_body::i_item::i_item(i_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::i_item::operator=(i_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_raw_func_body::i_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::i_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_item";
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
string t_inl_file::t_raw_func_body::i_item::ProxySys$$::GetFullName()
{
  return "i_item";
}
void t_inl_file::t_raw_func_body::i_item::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_raw_func_body::i_item::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_raw_func_body::i_item::t_poly_impl::load()
{
  go_for<t_sep_item>();
  go_for<t_s_item>();
  go_for<t_c_item>();
  go_for<t_code_item>();
  go_for<t_div_item>();
  go_for<t_block_item>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_raw_func_body::i_item::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_raw_func_body::i_item::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_raw_func_body::t_sep_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_raw_func_body::t_sep_item::t_sep_item()
{
  DoReset();
}
t_inl_file::t_raw_func_body::t_sep_item::t_sep_item(t_sep_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::t_sep_item::operator=(t_sep_item&&_Right)
{
  struct hidden
  {
    static void foo(i_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_item::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_raw_func_body::t_sep_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_sep_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_sep_item";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_raw_func_body::t_sep_item::ProxySys$$::GetFullName()
{
  return "t_sep_item";
}
void t_inl_file::t_raw_func_body::t_sep_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_raw_func_body::t_sep_item::SelfClass*t_inl_file::t_raw_func_body::t_sep_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_raw_func_body::t_sep_item::go(i_dev&dev)
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
void t_inl_file::t_raw_func_body::t_s_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_raw_func_body::t_s_item::t_s_item()
{
  DoReset();
}
t_inl_file::t_raw_func_body::t_s_item::t_s_item(t_s_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::t_s_item::operator=(t_s_item&&_Right)
{
  struct hidden
  {
    static void foo(i_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_item::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_raw_func_body::t_s_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_s_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_s_item";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_raw_func_body::t_s_item::ProxySys$$::GetFullName()
{
  return "t_s_item";
}
void t_inl_file::t_raw_func_body::t_s_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_raw_func_body::t_s_item::SelfClass*t_inl_file::t_raw_func_body::t_s_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_raw_func_body::t_s_item::go(i_dev&dev)
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
void t_inl_file::t_raw_func_body::t_c_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_raw_func_body::t_c_item::t_c_item()
{
  DoReset();
}
t_inl_file::t_raw_func_body::t_c_item::t_c_item(t_c_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::t_c_item::operator=(t_c_item&&_Right)
{
  struct hidden
  {
    static void foo(i_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_item::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_raw_func_body::t_c_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_c_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_c_item";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_raw_func_body::t_c_item::ProxySys$$::GetFullName()
{
  return "t_c_item";
}
void t_inl_file::t_raw_func_body::t_c_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_raw_func_body::t_c_item::SelfClass*t_inl_file::t_raw_func_body::t_c_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_raw_func_body::t_c_item::go(i_dev&dev)
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
void t_inl_file::t_raw_func_body::t_code_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->code);
}
t_inl_file::t_raw_func_body::t_code_item::t_code_item()
{
  DoReset();
}
t_inl_file::t_raw_func_body::t_code_item::t_code_item(t_code_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::t_code_item::operator=(t_code_item&&_Right)
{
  struct hidden
  {
    static void foo(i_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_item::operator=(std::move(_Right));
  }
  this->code=std::move(_Right.code);
}
t_inl_file::t_raw_func_body::t_code_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_code_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_code_item";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"code",int(&(((SelfClass*)nullptr)->*(&SelfClass::code))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_raw_func_body::t_code_item::ProxySys$$::GetFullName()
{
  return "t_code_item";
}
void t_inl_file::t_raw_func_body::t_code_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_raw_func_body::t_code_item::SelfClass*t_inl_file::t_raw_func_body::t_code_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_raw_func_body::t_code_item::go(i_dev&dev)
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
void t_inl_file::t_raw_func_body::t_div_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_raw_func_body::t_div_item::t_div_item()
{
  DoReset();
}
t_inl_file::t_raw_func_body::t_div_item::t_div_item(t_div_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::t_div_item::operator=(t_div_item&&_Right)
{
  struct hidden
  {
    static void foo(i_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_item::operator=(std::move(_Right));
  }
}
t_inl_file::t_raw_func_body::t_div_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_div_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_div_item";
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
string t_inl_file::t_raw_func_body::t_div_item::ProxySys$$::GetFullName()
{
  return "t_div_item";
}
void t_inl_file::t_raw_func_body::t_div_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_raw_func_body::t_div_item::SelfClass*t_inl_file::t_raw_func_body::t_div_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_raw_func_body::t_div_item::go(i_dev&dev)
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
void t_inl_file::t_raw_func_body::t_block_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_raw_func_body::t_block_item::t_block_item()
{
  DoReset();
}
t_inl_file::t_raw_func_body::t_block_item::t_block_item(t_block_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::t_block_item::operator=(t_block_item&&_Right)
{
  struct hidden
  {
    static void foo(i_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_item::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_raw_func_body::t_block_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_block_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_block_item";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_raw_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_raw_func_body::t_block_item::ProxySys$$::GetFullName()
{
  return "t_block_item";
}
void t_inl_file::t_raw_func_body::t_block_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_raw_func_body::t_block_item::SelfClass*t_inl_file::t_raw_func_body::t_block_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_raw_func_body::t_block_item::go(i_dev&dev)
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
void t_inl_file::t_raw_func_body::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_raw_func_body::t_raw_func_body()
{
  DoReset();
}
t_inl_file::t_raw_func_body::t_raw_func_body(t_raw_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_raw_func_body::operator=(t_raw_func_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_raw_func_body::ProxySys$$::metatype*t_inl_file::t_raw_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_raw_func_body";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_item>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_sep_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_s_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_c_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_code_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_div_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_block_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_raw_func_body::ProxySys$$::GetFullName()
{
  return "t_raw_func_body";
}
bool t_inl_file::t_raw_func_body::go(i_dev&dev)
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
void t_inl_file::t_func_path::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->value);
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->sep1);
}
t_inl_file::t_func_path::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_func_path::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_func_path::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->value=std::move(_Right.value);
  this->sep0=std::move(_Right.sep0);
  this->sep1=std::move(_Right.sep1);
}
t_inl_file::t_func_path::t_item::ProxySys$$::metatype*t_inl_file::t_func_path::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_func_path::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_func_path::t_item::go(i_dev&dev)
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
void t_inl_file::t_func_path::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_func_path::t_func_path()
{
  DoReset();
}
t_inl_file::t_func_path::t_func_path(t_func_path&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_func_path::operator=(t_func_path&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_func_path::ProxySys$$::metatype*t_inl_file::t_func_path::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_path";
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
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_func_path::ProxySys$$::GetFullName()
{
  return "t_func_path";
}
bool t_inl_file::t_func_path::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::i_name_part()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::i_name_part(i_name_part&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::operator=(i_name_part&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_name_part";
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
string t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::ProxySys$$::GetFullName()
{
  return "i_name_part";
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::t_poly_impl::load()
{
  go_for<t_brackets_name_part>();
  go_for<t_raw_name_part>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::i_func_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::i_func_param(i_func_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::operator=(i_func_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_func_param";
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
string t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::ProxySys$$::GetFullName()
{
  return "i_func_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::t_poly_impl::load()
{
  go_for<t_pfunc_func_param>();
  go_for<t_var_args_func_param>();
  go_for<t_type_func_param>();
  go_for<t_expr_func_param>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::i_func_param_value()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::i_func_param_value(i_func_param_value&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::operator=(i_func_param_value&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_func_param_value";
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
string t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::ProxySys$$::GetFullName()
{
  return "i_func_param_value";
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::t_poly_impl::load()
{
  go_for<t_expr_ext>();
  go_for<t_func_ref_ext>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param_value::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::t_first_scope()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::t_first_scope(t_first_scope&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::operator=(t_first_scope&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_first_scope";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::ProxySys$$::GetFullName()
{
  return "t_first_scope";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_first_scope::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->keyword);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::t_const_with_sep()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::t_const_with_sep(t_const_with_sep&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::operator=(t_const_with_sep&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->keyword=std::move(_Right.keyword);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_const_with_sep";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::ProxySys$$::GetFullName()
{
  return "t_const_with_sep";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_const_with_sep::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::i_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::i_param(i_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::operator=(i_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_param";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::ProxySys$$::GetFullName()
{
  return "i_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::t_poly_impl::load()
{
  go_for<t_type_param>();
  go_for<t_num_param>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::i_param::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->cvs);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::t_type_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::t_type_param(t_type_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::operator=(t_type_param&&_Right)
{
  struct hidden
  {
    static void foo(i_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_param::operator=(std::move(_Right));
  }
  this->cvs=std::move(_Right.cvs);
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_type_param";
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
  Info->AddMemberDEF(Sys$$<vector<t_const_with_sep>>::GetRTTI(RTTI),"cvs",int(&(((SelfClass*)nullptr)->*(&SelfClass::cvs))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::ProxySys$$::GetFullName()
{
  return "t_type_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_param::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::t_num_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::t_num_param(t_num_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::operator=(t_num_param&&_Right)
{
  struct hidden
  {
    static void foo(i_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_param::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_num_param";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::ProxySys$$::GetFullName()
{
  return "t_num_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_num_param::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep_bef);
  detail::FieldTryDoReset(this->param);
  detail::FieldTryDoReset(this->sep_aft);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::t_type_expr_with_sep()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::t_type_expr_with_sep(t_type_expr_with_sep&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::operator=(t_type_expr_with_sep&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep_bef=std::move(_Right.sep_bef);
  this->param=std::move(_Right.param);
  this->sep_aft=std::move(_Right.sep_aft);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_type_expr_with_sep";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep_bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep_bef))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_param>>::GetRTTI(RTTI),"param",int(&(((SelfClass*)nullptr)->*(&SelfClass::param))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep_aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep_aft))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::ProxySys$$::GetFullName()
{
  return "t_type_expr_with_sep";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_type_expr_with_sep::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_params()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::t_params(t_params&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::operator=(t_params&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_params";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_type_expr_with_sep>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_type_expr_with_sep>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::ProxySys$$::GetFullName()
{
  return "t_params";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_params::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->params);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_with_sep()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::t_type_with_sep(t_type_with_sep&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::operator=(t_type_with_sep&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->name=std::move(_Right.name);
  this->params=std::move(_Right.params);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_type_with_sep";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_type_param>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_num_param>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_params>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::ProxySys$$::GetFullName()
{
  return "t_type_with_sep";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_with_sep::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::t_scope_with_sep()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::t_scope_with_sep(t_scope_with_sep&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::operator=(t_scope_with_sep&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_scope_with_sep";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::ProxySys$$::GetFullName()
{
  return "t_scope_with_sep";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_scope_with_sep::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_scope::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scope::t_scope()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scope::t_scope(t_scope&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_scope::operator=(t_scope&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scope::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_scope::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_scope";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_scope::ProxySys$$::GetFullName()
{
  return "t_scope";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_scope::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->cv);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::t_ptr()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::t_ptr(t_ptr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::operator=(t_ptr&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->cv=std::move(_Right.cv);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_ptr";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::ProxySys$$::GetFullName()
{
  return "t_ptr";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_ptr::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_ref::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->cv);
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->ref);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_ref::t_ref()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_ref::t_ref(t_ref&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_ref::operator=(t_ref&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->cv=std::move(_Right.cv);
  this->sep=std::move(_Right.sep);
  this->ref=std::move(_Right.ref);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_ref::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_ref::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_ref";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"ref",int(&(((SelfClass*)nullptr)->*(&SelfClass::ref))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_ref::ProxySys$$::GetFullName()
{
  return "t_ref";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_ref::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sws);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sws=std::move(_Right.sws);
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_scope_with_sep>::GetRTTI(RTTI),"sws",int(&(((SelfClass*)nullptr)->*(&SelfClass::sws))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_type_with_sep>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_item::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->first);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_scopes()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::t_scopes(t_scopes&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::operator=(t_scopes&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->first=std::move(_Right.first);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_scopes";
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
  Info->AddMemberDEF(Sys$$<t_type_with_sep>::GetRTTI(RTTI),"first",int(&(((SelfClass*)nullptr)->*(&SelfClass::first))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::ProxySys$$::GetFullName()
{
  return "t_scopes";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_scopes::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->keyword);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::t_keyword()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::t_keyword(t_keyword&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::operator=(t_keyword&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->keyword=std::move(_Right.keyword);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_keyword";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::ProxySys$$::GetFullName()
{
  return "t_keyword";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_keyword::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->cvs);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::t_type_expr_with_sep_and_cv()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::t_type_expr_with_sep_and_cv(t_type_expr_with_sep_and_cv&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::operator=(t_type_expr_with_sep_and_cv&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->cvs=std::move(_Right.cvs);
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_type_expr_with_sep_and_cv";
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
  Info->AddMemberDEF(Sys$$<vector<t_const_with_sep>>::GetRTTI(RTTI),"cvs",int(&(((SelfClass*)nullptr)->*(&SelfClass::cvs))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::ProxySys$$::GetFullName()
{
  return "t_type_expr_with_sep_and_cv";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::t_name_part()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::t_name_part(t_name_part&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::operator=(t_name_part&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_name_part";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_name_part>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::ProxySys$$::GetFullName()
{
  return "t_name_part";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->sep2);
  detail::FieldTryDoReset(this->sep3);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::t_arr_body()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::t_arr_body(t_arr_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::operator=(t_arr_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->sep1=std::move(_Right.sep1);
  this->expr=std::move(_Right.expr);
  this->sep2=std::move(_Right.sep2);
  this->sep3=std::move(_Right.sep3);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_arr_body";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::ProxySys$$::GetFullName()
{
  return "t_arr_body";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_arr_body::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::i_part()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::i_part(i_part&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::operator=(i_part&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_part";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::ProxySys$$::GetFullName()
{
  return "i_part";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::t_poly_impl::load()
{
  go_for<t_amp_part>();
  go_for<t_star_part>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::t_amp()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::t_amp(t_amp&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::operator=(t_amp&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_amp";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::ProxySys$$::GetFullName()
{
  return "t_amp";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::t_amp_part()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::t_amp_part(t_amp_part&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::operator=(t_amp_part&&_Right)
{
  struct hidden
  {
    static void foo(i_part(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_part::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_amp_part";
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
  Info->AddMemberDEF(Sys$$<t_amp>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::ProxySys$$::GetFullName()
{
  return "t_amp_part";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->stars);
  detail::FieldTryDoReset(this->amp);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::t_star_part()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::t_star_part(t_star_part&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::operator=(t_star_part&&_Right)
{
  struct hidden
  {
    static void foo(i_part(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_part::operator=(std::move(_Right));
  }
  this->stars=std::move(_Right.stars);
  this->amp=std::move(_Right.amp);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_star_part";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"stars",int(&(((SelfClass*)nullptr)->*(&SelfClass::stars))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_amp>>::GetRTTI(RTTI),"amp",int(&(((SelfClass*)nullptr)->*(&SelfClass::amp))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::ProxySys$$::GetFullName()
{
  return "t_star_part";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->stamp_part);
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->namepart);
  detail::FieldTryDoReset(this->arrbody);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_brackets_name_part()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_brackets_name_part(t_brackets_name_part&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::operator=(t_brackets_name_part&&_Right)
{
  struct hidden
  {
    static void foo(i_name_part(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_name_part::operator=(std::move(_Right));
  }
  this->stamp_part=std::move(_Right.stamp_part);
  this->sep=std::move(_Right.sep);
  this->namepart=std::move(_Right.namepart);
  this->arrbody=std::move(_Right.arrbody);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_brackets_name_part";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_part>>::GetRTTI(RTTI),"stamp_part",int(&(((SelfClass*)nullptr)->*(&SelfClass::stamp_part))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_name_part>>::GetRTTI(RTTI),"namepart",int(&(((SelfClass*)nullptr)->*(&SelfClass::namepart))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_arr_body>>::GetRTTI(RTTI),"arrbody",int(&(((SelfClass*)nullptr)->*(&SelfClass::arrbody))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_amp>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_amp_part>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_star_part>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::ProxySys$$::GetFullName()
{
  return "t_brackets_name_part";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->name);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::t_raw_name_part()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::t_raw_name_part(t_raw_name_part&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::operator=(t_raw_name_part&&_Right)
{
  struct hidden
  {
    static void foo(i_name_part(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_name_part::operator=(std::move(_Right));
  }
  this->name=std::move(_Right.name);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_raw_name_part";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::ProxySys$$::GetFullName()
{
  return "t_raw_name_part";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->type);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::t_addr()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::t_addr(t_addr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::operator=(t_addr&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->type=std::move(_Right.type);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_addr";
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
  Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::ProxySys$$::GetFullName()
{
  return "t_addr";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_addr::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->type);
  detail::FieldTryDoReset(this->addr);
  detail::FieldTryDoReset(this->name);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_pfunc_func_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_pfunc_func_param(t_pfunc_func_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::operator=(t_pfunc_func_param&&_Right)
{
  struct hidden
  {
    static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_param::operator=(std::move(_Right));
  }
  this->type=std::move(_Right.type);
  this->addr=std::move(_Right.addr);
  this->name=std::move(_Right.name);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_pfunc_func_param";
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
  Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_addr>::GetRTTI(RTTI),"addr",int(&(((SelfClass*)nullptr)->*(&SelfClass::addr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_addr>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::ProxySys$$::GetFullName()
{
  return "t_pfunc_func_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::t_var_args_func_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::t_var_args_func_param(t_var_args_func_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::operator=(t_var_args_func_param&&_Right)
{
  struct hidden
  {
    static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_param::operator=(std::move(_Right));
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_var_args_func_param";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::ProxySys$$::GetFullName()
{
  return "t_var_args_func_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->type);
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->namepart);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_type_func_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_type_func_param(t_type_func_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::operator=(t_type_func_param&&_Right)
{
  struct hidden
  {
    static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_param::operator=(std::move(_Right));
  }
  this->type=std::move(_Right.type);
  this->sep=std::move(_Right.sep);
  this->namepart=std::move(_Right.namepart);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_type_func_param";
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
  Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_name_part>>::GetRTTI(RTTI),"namepart",int(&(((SelfClass*)nullptr)->*(&SelfClass::namepart))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::ProxySys$$::GetFullName()
{
  return "t_type_func_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::t_expr_func_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::t_expr_func_param(t_expr_func_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::operator=(t_expr_func_param&&_Right)
{
  struct hidden
  {
    static void foo(i_func_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_param::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_expr_func_param";
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
  Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::ProxySys$$::GetFullName()
{
  return "t_expr_func_param";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::t_expr_ext()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::t_expr_ext(t_expr_ext&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::operator=(t_expr_ext&&_Right)
{
  struct hidden
  {
    static void foo(i_func_param_value(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_param_value::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_expr_ext";
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
  Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::ProxySys$$::GetFullName()
{
  return "t_expr_ext";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_expr_ext::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->type);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::t_func_ref_ext()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::t_func_ref_ext(t_func_ref_ext&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::operator=(t_func_ref_ext&&_Right)
{
  struct hidden
  {
    static void foo(i_func_param_value(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_param_value::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
  this->type=std::move(_Right.type);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_ref_ext";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::ProxySys$$::GetFullName()
{
  return "t_func_ref_ext";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_func_ref_ext::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::t_func_param_value()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::t_func_param_value(t_func_param_value&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::operator=(t_func_param_value&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->value=std::move(_Right.value);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_param_value";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::ProxySys$$::GetFullName()
{
  return "t_func_param_value";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->body);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->value);
  detail::FieldTryDoReset(this->sep2);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::t_func_param()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::t_func_param(t_func_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::operator=(t_func_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->body=std::move(_Right.body);
  this->sep1=std::move(_Right.sep1);
  this->value=std::move(_Right.value);
  this->sep2=std::move(_Right.sep2);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_param";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_param>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::ProxySys$$::GetFullName()
{
  return "t_func_param";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::t_func_params()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::t_func_params(t_func_params&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::operator=(t_func_params&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_params";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_func_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::ProxySys$$::GetFullName()
{
  return "t_func_params";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::i_fv_body()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::i_fv_body(i_fv_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::operator=(i_fv_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_fv_body";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::ProxySys$$::GetFullName()
{
  return "i_fv_body";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::t_poly_impl::load()
{
  go_for<t_impl_func_body>();
  go_for<t_zero_func_body>();
  go_for<t_delete_func_body>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::i_fv_end()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::i_fv_end(i_fv_end&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::operator=(i_fv_end&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_fv_end";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::ProxySys$$::GetFullName()
{
  return "i_fv_end";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::t_poly_impl::load()
{
  go_for<t_func_fv_end>();
  go_for<t_var_fv_end>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::t_impl_func_body()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::t_impl_func_body(t_impl_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::operator=(t_impl_func_body&&_Right)
{
  struct hidden
  {
    static void foo(i_fv_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_fv_body::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_impl_func_body";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_raw_func_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::ProxySys$$::GetFullName()
{
  return "t_impl_func_body";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::t_zero_func_body()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::t_zero_func_body(t_zero_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::operator=(t_zero_func_body&&_Right)
{
  struct hidden
  {
    static void foo(i_fv_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_fv_body::operator=(std::move(_Right));
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_zero_func_body";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::ProxySys$$::GetFullName()
{
  return "t_zero_func_body";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::t_delete_func_body()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::t_delete_func_body(t_delete_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::operator=(t_delete_func_body&&_Right)
{
  struct hidden
  {
    static void foo(i_fv_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_fv_body::operator=(std::move(_Right));
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_delete_func_body";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::ProxySys$$::GetFullName()
{
  return "t_delete_func_body";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->cv1);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::t_func_fv_end()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::t_func_fv_end(t_func_fv_end&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::operator=(t_func_fv_end&&_Right)
{
  struct hidden
  {
    static void foo(i_fv_end(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_fv_end::operator=(std::move(_Right));
  }
  this->params=std::move(_Right.params);
  this->cv1=std::move(_Right.cv1);
  this->sep1=std::move(_Right.sep1);
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_fv_end";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::ProxySys$$::GetFullName()
{
  return "t_func_fv_end";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::DoReset()
{
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::i_fv_item()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::i_fv_item(i_fv_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::operator=(i_fv_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_fv_item";
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::ProxySys$$::GetFullName()
{
  return "i_fv_item";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::t_poly_impl::load()
{
  go_for<t_func_fv_item>();
  go_for<t_var_fv_item>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->cv1);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::t_func_fv_item()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::t_func_fv_item(t_func_fv_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::operator=(t_func_fv_item&&_Right)
{
  struct hidden
  {
    static void foo(i_fv_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_fv_item::operator=(std::move(_Right));
  }
  this->params=std::move(_Right.params);
  this->cv1=std::move(_Right.cv1);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_fv_item";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::ProxySys$$::GetFullName()
{
  return "t_func_fv_item";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->arrbody);
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::t_var_fv_item()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::t_var_fv_item(t_var_fv_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::operator=(t_var_fv_item&&_Right)
{
  struct hidden
  {
    static void foo(i_fv_item(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_fv_item::operator=(std::move(_Right));
  }
  this->arrbody=std::move(_Right.arrbody);
  this->value=std::move(_Right.value);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_var_fv_item";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_arr_body>>::GetRTTI(RTTI),"arrbody",int(&(((SelfClass*)nullptr)->*(&SelfClass::arrbody))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::ProxySys$$::GetFullName()
{
  return "t_var_fv_item";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::t_body()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::t_body(t_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::operator=(t_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_body";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_item>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::ProxySys$$::GetFullName()
{
  return "t_body";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::DoReset()
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
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->cv=std::move(_Right.cv);
  this->sep1=std::move(_Right.sep1);
  this->name=std::move(_Right.name);
  this->sep2=std::move(_Right.sep2);
  this->body=std::move(_Right.body);
  this->sep3=std::move(_Right.sep3);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_end()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_end(t_var_fv_end&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::operator=(t_var_fv_end&&_Right)
{
  struct hidden
  {
    static void foo(i_fv_end(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_fv_end::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_var_fv_end";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_func_fv_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_var_fv_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_body>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::ProxySys$$::GetFullName()
{
  return "t_var_fv_end";
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::DoReset()
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
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_fv_stat()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_fv_stat(t_fv_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::operator=(t_fv_stat&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep_wa=std::move(_Right.sep_wa);
  this->keywords=std::move(_Right.keywords);
  this->type=std::move(_Right.type);
  this->cv=std::move(_Right.cv);
  this->sep0=std::move(_Right.sep0);
  this->path=std::move(_Right.path);
  this->name=std::move(_Right.name);
  this->sep1=std::move(_Right.sep1);
  this->way=std::move(_Right.way);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_fv_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep_wa",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep_wa))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_keyword>>::GetRTTI(RTTI),"keywords",int(&(((SelfClass*)nullptr)->*(&SelfClass::keywords))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_name_part>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_end>>::GetRTTI(RTTI),"way",int(&(((SelfClass*)nullptr)->*(&SelfClass::way))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_impl_func_body>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_zero_func_body>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_delete_func_body>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_func_fv_end>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_var_fv_end>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::ProxySys$$::GetFullName()
{
  return "t_fv_stat";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::t_type_expr::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->first);
  detail::FieldTryDoReset(this->scopes);
  detail::FieldTryDoReset(this->ptrs);
  detail::FieldTryDoReset(this->ref);
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr(t_type_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::t_type_expr::operator=(t_type_expr&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->first=std::move(_Right.first);
  this->scopes=std::move(_Right.scopes);
  this->ptrs=std::move(_Right.ptrs);
  this->ref=std::move(_Right.ref);
}
t_inl_file::t_fv_class_stat::t_type_expr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_type_expr";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_first_scope>>::GetRTTI(RTTI),"first",int(&(((SelfClass*)nullptr)->*(&SelfClass::first))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_scopes>::GetRTTI(RTTI),"scopes",int(&(((SelfClass*)nullptr)->*(&SelfClass::scopes))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_ptr>>::GetRTTI(RTTI),"ptrs",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptrs))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_ref>>::GetRTTI(RTTI),"ref",int(&(((SelfClass*)nullptr)->*(&SelfClass::ref))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
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
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::t_type_expr::ProxySys$$::GetFullName()
{
  return "t_type_expr";
}
bool t_inl_file::t_fv_class_stat::t_type_expr::go(i_dev&dev)
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
void t_inl_file::t_fv_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_fv_class_stat::t_fv_class_stat()
{
  DoReset();
}
t_inl_file::t_fv_class_stat::t_fv_class_stat(t_fv_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_fv_class_stat::operator=(t_fv_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_fv_class_stat::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_fv_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_type_expr::t_fv_stat>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_type_expr>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_fv_class_stat::ProxySys$$::GetFullName()
{
  return "t_fv_class_stat";
}
void t_inl_file::t_fv_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_fv_class_stat::SelfClass*t_inl_file::t_fv_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_fv_class_stat::go(i_dev&dev)
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
void t_inl_file::t_typedef_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_typedef_class_stat::t_typedef_class_stat()
{
  DoReset();
}
t_inl_file::t_typedef_class_stat::t_typedef_class_stat(t_typedef_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_typedef_class_stat::operator=(t_typedef_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
  this->body=std::move(_Right.body);
}
t_inl_file::t_typedef_class_stat::ProxySys$$::metatype*t_inl_file::t_typedef_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_typedef_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_fv_stat>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_typedef_class_stat::ProxySys$$::GetFullName()
{
  return "t_typedef_class_stat";
}
void t_inl_file::t_typedef_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_typedef_class_stat::SelfClass*t_inl_file::t_typedef_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_typedef_class_stat::go(i_dev&dev)
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
void t_inl_file::t_call_param::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->sep1);
}
t_inl_file::t_call_param::t_call_param()
{
  DoReset();
}
t_inl_file::t_call_param::t_call_param(t_call_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_call_param::operator=(t_call_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->expr=std::move(_Right.expr);
  this->sep1=std::move(_Right.sep1);
}
t_inl_file::t_call_param::ProxySys$$::metatype*t_inl_file::t_call_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_call_param";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_call_param::ProxySys$$::GetFullName()
{
  return "t_call_param";
}
bool t_inl_file::t_call_param::go(i_dev&dev)
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
void t_inl_file::t_call_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->func);
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_call_expr::t_call_expr()
{
  DoReset();
}
t_inl_file::t_call_expr::t_call_expr(t_call_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_call_expr::operator=(t_call_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->func=std::move(_Right.func);
  this->sep=std::move(_Right.sep);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_call_expr::ProxySys$$::metatype*t_inl_file::t_call_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_call_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"func",int(&(((SelfClass*)nullptr)->*(&SelfClass::func))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_call_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_call_expr::ProxySys$$::GetFullName()
{
  return "t_call_expr";
}
void t_inl_file::t_call_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_call_expr::SelfClass*t_inl_file::t_call_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_call_expr::go(i_dev&dev)
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
void t_inl_file::t_real::t_f::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_real::t_f::t_f()
{
  DoReset();
}
t_inl_file::t_real::t_f::t_f(t_f&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_real::t_f::operator=(t_f&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_real::t_f::ProxySys$$::metatype*t_inl_file::t_real::t_f::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_f";
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
  Info->AddMemberDEF(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_real::t_f::ProxySys$$::GetFullName()
{
  return "t_f";
}
bool t_inl_file::t_real::t_f::go(i_dev&dev)
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
void t_inl_file::t_real::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->bef);
  detail::FieldTryDoReset(this->aft);
  detail::FieldTryDoReset(this->ext);
}
t_inl_file::t_real::t_real()
{
  DoReset();
}
t_inl_file::t_real::t_real(t_real&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_real::operator=(t_real&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->bef=std::move(_Right.bef);
  this->aft=std::move(_Right.aft);
  this->ext=std::move(_Right.ext);
}
t_inl_file::t_real::ProxySys$$::metatype*t_inl_file::t_real::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_real";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_f>>::GetRTTI(RTTI),"ext",int(&(((SelfClass*)nullptr)->*(&SelfClass::ext))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_f>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_real::ProxySys$$::GetFullName()
{
  return "t_real";
}
bool t_inl_file::t_real::go(i_dev&dev)
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
void t_inl_file::t_bool_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_bool_expr::t_bool_expr()
{
  DoReset();
}
t_inl_file::t_bool_expr::t_bool_expr(t_bool_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_bool_expr::operator=(t_bool_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_bool_expr::ProxySys$$::metatype*t_inl_file::t_bool_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_bool_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_bool_expr::ProxySys$$::GetFullName()
{
  return "t_bool_expr";
}
void t_inl_file::t_bool_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_bool_expr::SelfClass*t_inl_file::t_bool_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_bool_expr::go(i_dev&dev)
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
void t_inl_file::t_string_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_string_expr::t_string_expr()
{
  DoReset();
}
t_inl_file::t_string_expr::t_string_expr(t_string_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_string_expr::operator=(t_string_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_string_expr::ProxySys$$::metatype*t_inl_file::t_string_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_string_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_string_expr::ProxySys$$::GetFullName()
{
  return "t_string_expr";
}
void t_inl_file::t_string_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_string_expr::SelfClass*t_inl_file::t_string_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_string_expr::go(i_dev&dev)
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
void t_inl_file::t_char_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_char_expr::t_char_expr()
{
  DoReset();
}
t_inl_file::t_char_expr::t_char_expr(t_char_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_char_expr::operator=(t_char_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_char_expr::ProxySys$$::metatype*t_inl_file::t_char_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_char_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_char_expr::ProxySys$$::GetFullName()
{
  return "t_char_expr";
}
void t_inl_file::t_char_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_char_expr::SelfClass*t_inl_file::t_char_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_char_expr::go(i_dev&dev)
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
void t_inl_file::t_num_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_num_expr::t_num_expr()
{
  DoReset();
}
t_inl_file::t_num_expr::t_num_expr(t_num_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_num_expr::operator=(t_num_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_num_expr::ProxySys$$::metatype*t_inl_file::t_num_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_num_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_num_expr::ProxySys$$::GetFullName()
{
  return "t_num_expr";
}
void t_inl_file::t_num_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_num_expr::SelfClass*t_inl_file::t_num_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_num_expr::go(i_dev&dev)
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
void t_inl_file::t_real_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_real_expr::t_real_expr()
{
  DoReset();
}
t_inl_file::t_real_expr::t_real_expr(t_real_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_real_expr::operator=(t_real_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_real_expr::ProxySys$$::metatype*t_inl_file::t_real_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_real_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_real_expr::ProxySys$$::GetFullName()
{
  return "t_real_expr";
}
void t_inl_file::t_real_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_real_expr::SelfClass*t_inl_file::t_real_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_real_expr::go(i_dev&dev)
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
void t_inl_file::t_nullptr_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_nullptr_expr::t_nullptr_expr()
{
  DoReset();
}
t_inl_file::t_nullptr_expr::t_nullptr_expr(t_nullptr_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_nullptr_expr::operator=(t_nullptr_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
}
t_inl_file::t_nullptr_expr::ProxySys$$::metatype*t_inl_file::t_nullptr_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_nullptr_expr";
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
string t_inl_file::t_nullptr_expr::ProxySys$$::GetFullName()
{
  return "t_nullptr_expr";
}
void t_inl_file::t_nullptr_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_nullptr_expr::SelfClass*t_inl_file::t_nullptr_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_nullptr_expr::go(i_dev&dev)
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
void t_inl_file::t_or_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_or_expr::t_or_expr()
{
  DoReset();
}
t_inl_file::t_or_expr::t_or_expr(t_or_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_or_expr::operator=(t_or_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_or_expr::ProxySys$$::metatype*t_inl_file::t_or_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_or_expr";
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
  Info->AddMemberDEF(Sys$$<vector<t_name>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_or_expr::ProxySys$$::GetFullName()
{
  return "t_or_expr";
}
void t_inl_file::t_or_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_or_expr::SelfClass*t_inl_file::t_or_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_or_expr::go(i_dev&dev)
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
void t_inl_file::t_hex_expr::t_impl::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->x);
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_hex_expr::t_impl::t_impl()
{
  DoReset();
}
t_inl_file::t_hex_expr::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_hex_expr::t_impl::operator=(t_impl&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->x=std::move(_Right.x);
  this->value=std::move(_Right.value);
}
t_inl_file::t_hex_expr::t_impl::ProxySys$$::metatype*t_inl_file::t_hex_expr::t_impl::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_impl";
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
  Info->AddMemberDEF(Sys$$<char>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_hex_expr::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_inl_file::t_hex_expr::t_impl::go(i_dev&dev)
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
void t_inl_file::t_hex_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_hex_expr::t_hex_expr()
{
  DoReset();
}
t_inl_file::t_hex_expr::t_hex_expr(t_hex_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_hex_expr::operator=(t_hex_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->value=std::move(_Right.value);
}
t_inl_file::t_hex_expr::ProxySys$$::metatype*t_inl_file::t_hex_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_hex_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_hex_expr::ProxySys$$::GetFullName()
{
  return "t_hex_expr";
}
void t_inl_file::t_hex_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_hex_expr::SelfClass*t_inl_file::t_hex_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_hex_expr::go(i_dev&dev)
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
void t_inl_file::t_var_expr::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_var_expr::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_var_expr::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_var_expr::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_var_expr::t_item::ProxySys$$::metatype*t_inl_file::t_var_expr::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_type_with_sep>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_var_expr::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_var_expr::t_item::go(i_dev&dev)
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
void t_inl_file::t_var_expr::t_field::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->bef);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->aft);
}
t_inl_file::t_var_expr::t_field::t_field()
{
  DoReset();
}
t_inl_file::t_var_expr::t_field::t_field(t_field&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_var_expr::t_field::operator=(t_field&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->bef=std::move(_Right.bef);
  this->name=std::move(_Right.name);
  this->aft=std::move(_Right.aft);
}
t_inl_file::t_var_expr::t_field::ProxySys$$::metatype*t_inl_file::t_var_expr::t_field::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_field";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_var_expr::t_field::ProxySys$$::GetFullName()
{
  return "t_field";
}
bool t_inl_file::t_var_expr::t_field::go(i_dev&dev)
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
void t_inl_file::t_var_expr::t_impl::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->items);
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_var_expr::t_impl::t_impl()
{
  DoReset();
}
t_inl_file::t_var_expr::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_var_expr::t_impl::operator=(t_impl&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->items=std::move(_Right.items);
  this->sep=std::move(_Right.sep);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_var_expr::t_impl::ProxySys$$::metatype*t_inl_file::t_var_expr::t_impl::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_impl";
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
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"items",int(&(((SelfClass*)nullptr)->*(&SelfClass::items))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_field>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_var_expr::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_inl_file::t_var_expr::t_impl::go(i_dev&dev)
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
void t_inl_file::t_var_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->name);
}
t_inl_file::t_var_expr::t_var_expr()
{
  DoReset();
}
t_inl_file::t_var_expr::t_var_expr(t_var_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_var_expr::operator=(t_var_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_expr(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_expr::operator=(std::move(_Right));
  }
  this->name=std::move(_Right.name);
}
t_inl_file::t_var_expr::ProxySys$$::metatype*t_inl_file::t_var_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_var_expr";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_field>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_var_expr::ProxySys$$::GetFullName()
{
  return "t_var_expr";
}
void t_inl_file::t_var_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_var_expr::SelfClass*t_inl_file::t_var_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_var_expr::go(i_dev&dev)
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
void t_inl_file::t_ctor_init_list::t_init_param::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->arr);
  detail::FieldTryDoReset(this->sep1);
}
t_inl_file::t_ctor_init_list::t_init_param::t_init_param()
{
  DoReset();
}
t_inl_file::t_ctor_init_list::t_init_param::t_init_param(t_init_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_ctor_init_list::t_init_param::operator=(t_init_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->name=std::move(_Right.name);
  this->arr=std::move(_Right.arr);
  this->sep1=std::move(_Right.sep1);
}
t_inl_file::t_ctor_init_list::t_init_param::ProxySys$$::metatype*t_inl_file::t_ctor_init_list::t_init_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_init_param";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_call_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_ctor_init_list::t_init_param::ProxySys$$::GetFullName()
{
  return "t_init_param";
}
bool t_inl_file::t_ctor_init_list::t_init_param::go(i_dev&dev)
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
void t_inl_file::t_ctor_init_list::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_ctor_init_list::t_ctor_init_list()
{
  DoReset();
}
t_inl_file::t_ctor_init_list::t_ctor_init_list(t_ctor_init_list&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_ctor_init_list::operator=(t_ctor_init_list&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->params=std::move(_Right.params);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_ctor_init_list::ProxySys$$::metatype*t_inl_file::t_ctor_init_list::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_ctor_init_list";
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
  Info->AddMemberDEF(Sys$$<vector<t_init_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_init_param>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_ctor_init_list::ProxySys$$::GetFullName()
{
  return "t_ctor_init_list";
}
bool t_inl_file::t_ctor_init_list::go(i_dev&dev)
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
void t_inl_file::t_zero_func_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_zero_func_body::t_zero_func_body()
{
  DoReset();
}
t_inl_file::t_zero_func_body::t_zero_func_body(t_zero_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_zero_func_body::operator=(t_zero_func_body&&_Right)
{
  struct hidden
  {
    static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_body::operator=(std::move(_Right));
  }
}
t_inl_file::t_zero_func_body::ProxySys$$::metatype*t_inl_file::t_zero_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_zero_func_body";
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
string t_inl_file::t_zero_func_body::ProxySys$$::GetFullName()
{
  return "t_zero_func_body";
}
void t_inl_file::t_zero_func_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_zero_func_body::SelfClass*t_inl_file::t_zero_func_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_zero_func_body::go(i_dev&dev)
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
void t_inl_file::t_null_func_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_null_func_body::t_null_func_body()
{
  DoReset();
}
t_inl_file::t_null_func_body::t_null_func_body(t_null_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_null_func_body::operator=(t_null_func_body&&_Right)
{
  struct hidden
  {
    static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_body::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_null_func_body::ProxySys$$::metatype*t_inl_file::t_null_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_null_func_body";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_null_func_body::ProxySys$$::GetFullName()
{
  return "t_null_func_body";
}
void t_inl_file::t_null_func_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_null_func_body::SelfClass*t_inl_file::t_null_func_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_null_func_body::go(i_dev&dev)
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
void t_inl_file::t_delete_func_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_delete_func_body::t_delete_func_body()
{
  DoReset();
}
t_inl_file::t_delete_func_body::t_delete_func_body(t_delete_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_delete_func_body::operator=(t_delete_func_body&&_Right)
{
  struct hidden
  {
    static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_body::operator=(std::move(_Right));
  }
}
t_inl_file::t_delete_func_body::ProxySys$$::metatype*t_inl_file::t_delete_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_delete_func_body";
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
string t_inl_file::t_delete_func_body::ProxySys$$::GetFullName()
{
  return "t_delete_func_body";
}
void t_inl_file::t_delete_func_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_delete_func_body::SelfClass*t_inl_file::t_delete_func_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_delete_func_body::go(i_dev&dev)
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
void t_inl_file::t_impl_func_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->init_list);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_impl_func_body::t_impl_func_body()
{
  DoReset();
}
t_inl_file::t_impl_func_body::t_impl_func_body(t_impl_func_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_impl_func_body::operator=(t_impl_func_body&&_Right)
{
  struct hidden
  {
    static void foo(i_func_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_func_body::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
  this->init_list=std::move(_Right.init_list);
  this->body=std::move(_Right.body);
}
t_inl_file::t_impl_func_body::ProxySys$$::metatype*t_inl_file::t_impl_func_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_impl_func_body";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_ctor_init_list>>::GetRTTI(RTTI),"init_list",int(&(((SelfClass*)nullptr)->*(&SelfClass::init_list))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_raw_func_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_impl_func_body::ProxySys$$::GetFullName()
{
  return "t_impl_func_body";
}
void t_inl_file::t_impl_func_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_impl_func_body::SelfClass*t_inl_file::t_impl_func_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_impl_func_body::go(i_dev&dev)
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
void t_inl_file::t_dtor_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->path);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_dtor_class_stat::t_dtor_class_stat()
{
  DoReset();
}
t_inl_file::t_dtor_class_stat::t_dtor_class_stat(t_dtor_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_dtor_class_stat::operator=(t_dtor_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->sep0=std::move(_Right.sep0);
  this->path=std::move(_Right.path);
  this->name=std::move(_Right.name);
  this->sep1=std::move(_Right.sep1);
  this->params=std::move(_Right.params);
  this->body=std::move(_Right.body);
}
t_inl_file::t_dtor_class_stat::ProxySys$$::metatype*t_inl_file::t_dtor_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_dtor_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_dtor_class_stat::ProxySys$$::GetFullName()
{
  return "t_dtor_class_stat";
}
void t_inl_file::t_dtor_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_dtor_class_stat::SelfClass*t_inl_file::t_dtor_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_dtor_class_stat::go(i_dev&dev)
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
void t_inl_file::t_ctor_class_stat::t_impl::t_explicit::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_ctor_class_stat::t_impl::t_explicit::t_explicit()
{
  DoReset();
}
t_inl_file::t_ctor_class_stat::t_impl::t_explicit::t_explicit(t_explicit&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_ctor_class_stat::t_impl::t_explicit::operator=(t_explicit&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_ctor_class_stat::t_impl::t_explicit::ProxySys$$::metatype*t_inl_file::t_ctor_class_stat::t_impl::t_explicit::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_explicit";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_ctor_class_stat::t_impl::t_explicit::ProxySys$$::GetFullName()
{
  return "t_explicit";
}
bool t_inl_file::t_ctor_class_stat::t_impl::t_explicit::go(i_dev&dev)
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
void t_inl_file::t_ctor_class_stat::t_impl::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->prefix);
  detail::FieldTryDoReset(this->path);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_ctor_class_stat::t_impl::t_impl()
{
  DoReset();
}
t_inl_file::t_ctor_class_stat::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_ctor_class_stat::t_impl::operator=(t_impl&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->prefix=std::move(_Right.prefix);
  this->path=std::move(_Right.path);
  this->name=std::move(_Right.name);
  this->params=std::move(_Right.params);
  this->body=std::move(_Right.body);
}
t_inl_file::t_ctor_class_stat::t_impl::ProxySys$$::metatype*t_inl_file::t_ctor_class_stat::t_impl::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_impl";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_explicit>>::GetRTTI(RTTI),"prefix",int(&(((SelfClass*)nullptr)->*(&SelfClass::prefix))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_explicit>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_ctor_class_stat::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_inl_file::t_ctor_class_stat::t_impl::go(i_dev&dev)
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
void t_inl_file::t_ctor_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_ctor_class_stat::t_ctor_class_stat()
{
  DoReset();
}
t_inl_file::t_ctor_class_stat::t_ctor_class_stat(t_ctor_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_ctor_class_stat::operator=(t_ctor_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_ctor_class_stat::ProxySys$$::metatype*t_inl_file::t_ctor_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_ctor_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_ctor_class_stat::ProxySys$$::GetFullName()
{
  return "t_ctor_class_stat";
}
void t_inl_file::t_ctor_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_ctor_class_stat::SelfClass*t_inl_file::t_ctor_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_ctor_class_stat::go(i_dev&dev)
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
void t_inl_file::t_oper_cast_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->path);
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->type);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->cv);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_oper_cast_class_stat::t_oper_cast_class_stat()
{
  DoReset();
}
t_inl_file::t_oper_cast_class_stat::t_oper_cast_class_stat(t_oper_cast_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_oper_cast_class_stat::operator=(t_oper_cast_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->path=std::move(_Right.path);
  this->sep0=std::move(_Right.sep0);
  this->type=std::move(_Right.type);
  this->sep1=std::move(_Right.sep1);
  this->params=std::move(_Right.params);
  this->cv=std::move(_Right.cv);
  this->body=std::move(_Right.body);
}
t_inl_file::t_oper_cast_class_stat::ProxySys$$::metatype*t_inl_file::t_oper_cast_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_oper_cast_class_stat";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_fv_class_stat::t_type_expr::t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_oper_cast_class_stat::ProxySys$$::GetFullName()
{
  return "t_oper_cast_class_stat";
}
void t_inl_file::t_oper_cast_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_oper_cast_class_stat::SelfClass*t_inl_file::t_oper_cast_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_oper_cast_class_stat::go(i_dev&dev)
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
void t_inl_file::t_common_oper_class_stat::t_impl::DoReset()
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
t_inl_file::t_common_oper_class_stat::t_impl::t_impl()
{
  DoReset();
}
t_inl_file::t_common_oper_class_stat::t_impl::t_impl(t_impl&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_common_oper_class_stat::t_impl::operator=(t_impl&&_Right)
{
  if (&_Right==this)return;
  {
  }
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
}
t_inl_file::t_common_oper_class_stat::t_impl::ProxySys$$::metatype*t_inl_file::t_common_oper_class_stat::t_impl::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_impl";
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
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_common_oper_class_stat::t_impl::ProxySys$$::GetFullName()
{
  return "t_impl";
}
bool t_inl_file::t_common_oper_class_stat::t_impl::go(i_dev&dev)
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
void t_inl_file::t_common_oper_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_common_oper_class_stat::t_common_oper_class_stat()
{
  DoReset();
}
t_inl_file::t_common_oper_class_stat::t_common_oper_class_stat(t_common_oper_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_common_oper_class_stat::operator=(t_common_oper_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_common_oper_class_stat::ProxySys$$::metatype*t_inl_file::t_common_oper_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_common_oper_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_common_oper_class_stat::ProxySys$$::GetFullName()
{
  return "t_common_oper_class_stat";
}
void t_inl_file::t_common_oper_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_common_oper_class_stat::SelfClass*t_inl_file::t_common_oper_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_common_oper_class_stat::go(i_dev&dev)
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
void t_inl_file::t_parents::t_item::t_pub::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->mod);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_parents::t_item::t_pub::t_pub()
{
  DoReset();
}
t_inl_file::t_parents::t_item::t_pub::t_pub(t_pub&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_parents::t_item::t_pub::operator=(t_pub&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->mod=std::move(_Right.mod);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_parents::t_item::t_pub::ProxySys$$::metatype*t_inl_file::t_parents::t_item::t_pub::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_pub";
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
  Info->AddMemberDEF(Sys$$<t_access_mod>::GetRTTI(RTTI),"mod",int(&(((SelfClass*)nullptr)->*(&SelfClass::mod))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_parents::t_item::t_pub::ProxySys$$::GetFullName()
{
  return "t_pub";
}
bool t_inl_file::t_parents::t_item::t_pub::go(i_dev&dev)
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
void t_inl_file::t_parents::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->pub);
  detail::FieldTryDoReset(this->name);
}
t_inl_file::t_parents::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_parents::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_parents::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->pub=std::move(_Right.pub);
  this->name=std::move(_Right.name);
}
t_inl_file::t_parents::t_item::ProxySys$$::metatype*t_inl_file::t_parents::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_pub>>::GetRTTI(RTTI),"pub",int(&(((SelfClass*)nullptr)->*(&SelfClass::pub))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_pub>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_parents::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_parents::t_item::go(i_dev&dev)
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
void t_inl_file::t_parents::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_parents::t_parents()
{
  DoReset();
}
t_inl_file::t_parents::t_parents(t_parents&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_parents::operator=(t_parents&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_parents::ProxySys$$::metatype*t_inl_file::t_parents::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_parents";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_parents::ProxySys$$::GetFullName()
{
  return "t_parents";
}
bool t_inl_file::t_parents::go(i_dev&dev)
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
void t_inl_file::t_class_body::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_class_body::t_class_body()
{
  DoReset();
}
t_inl_file::t_class_body::t_class_body(t_class_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_class_body::operator=(t_class_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_class_body::ProxySys$$::metatype*t_inl_file::t_class_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_class_body";
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
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_class_stat>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_class_body::ProxySys$$::GetFullName()
{
  return "t_class_body";
}
bool t_inl_file::t_class_body::go(i_dev&dev)
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
void t_inl_file::t_class::DoReset()
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
t_inl_file::t_class::t_class()
{
  DoReset();
}
t_inl_file::t_class::t_class(t_class&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_class::operator=(t_class&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->keyword=std::move(_Right.keyword);
  this->sep0=std::move(_Right.sep0);
  this->name=std::move(_Right.name);
  this->sep1=std::move(_Right.sep1);
  this->parents=std::move(_Right.parents);
  this->sep2=std::move(_Right.sep2);
  this->body=std::move(_Right.body);
  this->sep3=std::move(_Right.sep3);
}
t_inl_file::t_class::ProxySys$$::metatype*t_inl_file::t_class::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_class";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_parents>>::GetRTTI(RTTI),"parents",int(&(((SelfClass*)nullptr)->*(&SelfClass::parents))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_class_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_class::ProxySys$$::GetFullName()
{
  return "t_class";
}
bool t_inl_file::t_class::go(i_dev&dev)
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
void t_inl_file::t_namespace_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_namespace_class_stat::t_namespace_class_stat()
{
  DoReset();
}
t_inl_file::t_namespace_class_stat::t_namespace_class_stat(t_namespace_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_namespace_class_stat::operator=(t_namespace_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->sep0=std::move(_Right.sep0);
  this->name=std::move(_Right.name);
  this->sep1=std::move(_Right.sep1);
  this->body=std::move(_Right.body);
}
t_inl_file::t_namespace_class_stat::ProxySys$$::metatype*t_inl_file::t_namespace_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_namespace_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_class_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_namespace_class_stat::ProxySys$$::GetFullName()
{
  return "t_namespace_class_stat";
}
void t_inl_file::t_namespace_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_namespace_class_stat::SelfClass*t_inl_file::t_namespace_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_namespace_class_stat::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::i_template_body::DoReset()
{
  {
  }
}
t_inl_file::t_template_class_stat::i_template_body::i_template_body()
{
  DoReset();
}
t_inl_file::t_template_class_stat::i_template_body::i_template_body(i_template_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::i_template_body::operator=(i_template_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_template_class_stat::i_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::i_template_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_template_body";
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
string t_inl_file::t_template_class_stat::i_template_body::ProxySys$$::GetFullName()
{
  return "i_template_body";
}
void t_inl_file::t_template_class_stat::i_template_body::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_template_class_stat::i_template_body::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_template_class_stat::i_template_body::t_poly_impl::load()
{
  go_for<t_common_oper_template_body>();
  go_for<t_ctor_template_body>();
  go_for<t_func_template_body>();
  go_for<t_class_template_body>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::i_template_body::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::i_template_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_template_class_stat::i_template_param::DoReset()
{
  {
  }
}
t_inl_file::t_template_class_stat::i_template_param::i_template_param()
{
  DoReset();
}
t_inl_file::t_template_class_stat::i_template_param::i_template_param(i_template_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::i_template_param::operator=(i_template_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_template_class_stat::i_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::i_template_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_template_param";
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
string t_inl_file::t_template_class_stat::i_template_param::ProxySys$$::GetFullName()
{
  return "i_template_param";
}
void t_inl_file::t_template_class_stat::i_template_param::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_template_class_stat::i_template_param::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_template_class_stat::i_template_param::t_poly_impl::load()
{
  go_for<t_name_template_param>();
  go_for<t_type_template_param>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::i_template_param::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::i_template_param::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_template_class_stat::t_template_param::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->bef);
  detail::FieldTryDoReset(this->body);
  detail::FieldTryDoReset(this->aft);
}
t_inl_file::t_template_class_stat::t_template_param::t_template_param()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_template_param::t_template_param(t_template_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_template_param::operator=(t_template_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->bef=std::move(_Right.bef);
  this->body=std::move(_Right.body);
  this->aft=std::move(_Right.aft);
}
t_inl_file::t_template_class_stat::t_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_template_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_template_param";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_param>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_template_param::ProxySys$$::GetFullName()
{
  return "t_template_param";
}
bool t_inl_file::t_template_class_stat::t_template_param::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_concrete_param::i_body::DoReset()
{
  {
  }
}
t_inl_file::t_template_class_stat::t_concrete_param::i_body::i_body()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_concrete_param::i_body::i_body(i_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_concrete_param::i_body::operator=(i_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_template_class_stat::t_concrete_param::i_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_concrete_param::i_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_body";
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
string t_inl_file::t_template_class_stat::t_concrete_param::i_body::ProxySys$$::GetFullName()
{
  return "i_body";
}
void t_inl_file::t_template_class_stat::t_concrete_param::i_body::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_template_class_stat::t_concrete_param::i_body::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_template_class_stat::t_concrete_param::i_body::t_poly_impl::load()
{
  go_for<t_raw_expr>();
  go_for<t_template_expr>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::t_concrete_param::i_body::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::t_concrete_param::i_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::t_raw_expr()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::t_raw_expr(t_raw_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::operator=(t_raw_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_body::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_raw_expr";
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
  Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::ProxySys$$::GetFullName()
{
  return "t_raw_expr";
}
void t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::SelfClass*t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_concrete_param::t_raw_expr::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::t_main()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::t_main(t_main&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::operator=(t_main&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->arr=std::move(_Right.arr);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_main";
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
  Info->AddMemberDEF(Sys$$<vector<t_fv_class_stat::t_type_expr::t_type_with_sep>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::ProxySys$$::GetFullName()
{
  return "t_main";
}
bool t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_main::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_template_expr()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::t_template_expr(t_template_expr&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::operator=(t_template_expr&&_Right)
{
  struct hidden
  {
    static void foo(i_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_body::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_template_expr";
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
  Info->AddMemberDEF(Sys$$<t_main>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_main>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::ProxySys$$::GetFullName()
{
  return "t_template_expr";
}
void t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::SelfClass*t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_concrete_param::t_template_expr::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_concrete_param::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->body);
  detail::FieldTryDoReset(this->sep1);
}
t_inl_file::t_template_class_stat::t_concrete_param::t_concrete_param()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_concrete_param::t_concrete_param(t_concrete_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_concrete_param::operator=(t_concrete_param&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->body=std::move(_Right.body);
  this->sep1=std::move(_Right.sep1);
}
t_inl_file::t_template_class_stat::t_concrete_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_concrete_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_concrete_param";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_raw_expr>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_template_expr>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_concrete_param::ProxySys$$::GetFullName()
{
  return "t_concrete_param";
}
bool t_inl_file::t_template_class_stat::t_concrete_param::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_concrete_params::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->arr);
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_template_class_stat::t_concrete_params::t_concrete_params()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_concrete_params::t_concrete_params(t_concrete_params&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_concrete_params::operator=(t_concrete_params&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->arr=std::move(_Right.arr);
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_template_class_stat::t_concrete_params::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_concrete_params::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_concrete_params";
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
  Info->AddMemberDEF(Sys$$<vector<t_concrete_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_concrete_params::ProxySys$$::GetFullName()
{
  return "t_concrete_params";
}
bool t_inl_file::t_template_class_stat::t_concrete_params::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_common_oper_template_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_template_class_stat::t_common_oper_template_body::t_common_oper_template_body()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_common_oper_template_body::t_common_oper_template_body(t_common_oper_template_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_common_oper_template_body::operator=(t_common_oper_template_body&&_Right)
{
  struct hidden
  {
    static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_template_body::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_template_class_stat::t_common_oper_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_common_oper_template_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_common_oper_template_body";
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
  Info->AddMemberDEF(Sys$$<t_common_oper_class_stat::t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_common_oper_template_body::ProxySys$$::GetFullName()
{
  return "t_common_oper_template_body";
}
void t_inl_file::t_template_class_stat::t_common_oper_template_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_common_oper_template_body::SelfClass*t_inl_file::t_template_class_stat::t_common_oper_template_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_common_oper_template_body::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_ctor_template_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_template_class_stat::t_ctor_template_body::t_ctor_template_body()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_ctor_template_body::t_ctor_template_body(t_ctor_template_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_ctor_template_body::operator=(t_ctor_template_body&&_Right)
{
  struct hidden
  {
    static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_template_body::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_template_class_stat::t_ctor_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_ctor_template_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_ctor_template_body";
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
  Info->AddMemberDEF(Sys$$<t_ctor_class_stat::t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_ctor_template_body::ProxySys$$::GetFullName()
{
  return "t_ctor_template_body";
}
void t_inl_file::t_template_class_stat::t_ctor_template_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_ctor_template_body::SelfClass*t_inl_file::t_template_class_stat::t_ctor_template_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_ctor_template_body::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_func_template_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
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
t_inl_file::t_template_class_stat::t_func_template_body::t_func_template_body()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_func_template_body::t_func_template_body(t_func_template_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_func_template_body::operator=(t_func_template_body&&_Right)
{
  struct hidden
  {
    static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_template_body::operator=(std::move(_Right));
  }
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
}
t_inl_file::t_template_class_stat::t_func_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_func_template_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_func_template_body";
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
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_func_template_body::ProxySys$$::GetFullName()
{
  return "t_func_template_body";
}
void t_inl_file::t_template_class_stat::t_func_template_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_func_template_body::SelfClass*t_inl_file::t_template_class_stat::t_func_template_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_func_template_body::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_class_template_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
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
t_inl_file::t_template_class_stat::t_class_template_body::t_class_template_body()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_class_template_body::t_class_template_body(t_class_template_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_class_template_body::operator=(t_class_template_body&&_Right)
{
  struct hidden
  {
    static void foo(i_template_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_template_body::operator=(std::move(_Right));
  }
  this->keyword=std::move(_Right.keyword);
  this->sep0=std::move(_Right.sep0);
  this->name=std::move(_Right.name);
  this->sep1=std::move(_Right.sep1);
  this->params=std::move(_Right.params);
  this->parents=std::move(_Right.parents);
  this->sep2=std::move(_Right.sep2);
  this->body=std::move(_Right.body);
  this->sep3=std::move(_Right.sep3);
}
t_inl_file::t_template_class_stat::t_class_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_class_template_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_class_template_body";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_parents>>::GetRTTI(RTTI),"parents",int(&(((SelfClass*)nullptr)->*(&SelfClass::parents))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_class_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_class_template_body::ProxySys$$::GetFullName()
{
  return "t_class_template_body";
}
void t_inl_file::t_template_class_stat::t_class_template_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_class_template_body::SelfClass*t_inl_file::t_template_class_stat::t_class_template_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_class_template_body::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_head::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_template_class_stat::t_head::t_head()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_head::t_head(t_head&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_head::operator=(t_head&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->params=std::move(_Right.params);
  this->sep1=std::move(_Right.sep1);
  this->body=std::move(_Right.body);
}
t_inl_file::t_template_class_stat::t_head::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_head::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_head";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_template_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_head::ProxySys$$::GetFullName()
{
  return "t_head";
}
bool t_inl_file::t_template_class_stat::t_head::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::t_unsgnd()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::t_unsgnd(t_unsgnd&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::operator=(t_unsgnd&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_unsgnd";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::ProxySys$$::GetFullName()
{
  return "t_unsgnd";
}
bool t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_name_template_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->unsgnd0);
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->type);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->unsgnd1);
  detail::FieldTryDoReset(this->sep2);
  detail::FieldTryDoReset(this->name);
}
t_inl_file::t_template_class_stat::t_name_template_param::t_name_template_param()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_name_template_param::t_name_template_param(t_name_template_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_name_template_param::operator=(t_name_template_param&&_Right)
{
  struct hidden
  {
    static void foo(i_template_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_template_param::operator=(std::move(_Right));
  }
  this->unsgnd0=std::move(_Right.unsgnd0);
  this->sep0=std::move(_Right.sep0);
  this->type=std::move(_Right.type);
  this->sep1=std::move(_Right.sep1);
  this->unsgnd1=std::move(_Right.unsgnd1);
  this->sep2=std::move(_Right.sep2);
  this->name=std::move(_Right.name);
}
t_inl_file::t_template_class_stat::t_name_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_name_template_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_name_template_param";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"unsgnd0",int(&(((SelfClass*)nullptr)->*(&SelfClass::unsgnd0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"unsgnd1",int(&(((SelfClass*)nullptr)->*(&SelfClass::unsgnd1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_unsgnd>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_name_template_param::ProxySys$$::GetFullName()
{
  return "t_name_template_param";
}
void t_inl_file::t_template_class_stat::t_name_template_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_name_template_param::SelfClass*t_inl_file::t_template_class_stat::t_name_template_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_name_template_param::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::t_type_template_param::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->head);
  detail::FieldTryDoReset(this->type);
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->name);
}
t_inl_file::t_template_class_stat::t_type_template_param::t_type_template_param()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_type_template_param::t_type_template_param(t_type_template_param&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::t_type_template_param::operator=(t_type_template_param&&_Right)
{
  struct hidden
  {
    static void foo(i_template_param(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_template_param::operator=(std::move(_Right));
  }
  this->head=std::move(_Right.head);
  this->type=std::move(_Right.type);
  this->sep=std::move(_Right.sep);
  this->name=std::move(_Right.name);
}
t_inl_file::t_template_class_stat::t_type_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_type_template_param::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_type_template_param";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_head>>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::t_type_template_param::ProxySys$$::GetFullName()
{
  return "t_type_template_param";
}
void t_inl_file::t_template_class_stat::t_type_template_param::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::t_type_template_param::SelfClass*t_inl_file::t_template_class_stat::t_type_template_param::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::t_type_template_param::go(i_dev&dev)
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
void t_inl_file::t_template_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->head);
  detail::FieldTryDoReset(this->params);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_template_class_stat::t_template_class_stat()
{
  DoReset();
}
t_inl_file::t_template_class_stat::t_template_class_stat(t_template_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_template_class_stat::operator=(t_template_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->head=std::move(_Right.head);
  this->params=std::move(_Right.params);
  this->body=std::move(_Right.body);
}
t_inl_file::t_template_class_stat::ProxySys$$::metatype*t_inl_file::t_template_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_template_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_head>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");
  Info->AddMemberDEF(Sys$$<vector<t_template_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
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
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_template_class_stat::ProxySys$$::GetFullName()
{
  return "t_template_class_stat";
}
void t_inl_file::t_template_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_template_class_stat::SelfClass*t_inl_file::t_template_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_template_class_stat::go(i_dev&dev)
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
void t_inl_file::t_enum_class_stat::i_body::DoReset()
{
  {
  }
}
t_inl_file::t_enum_class_stat::i_body::i_body()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::i_body::i_body(i_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::i_body::operator=(i_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
}
t_inl_file::t_enum_class_stat::i_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::i_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="i_body";
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
string t_inl_file::t_enum_class_stat::i_body::ProxySys$$::GetFullName()
{
  return "i_body";
}
void t_inl_file::t_enum_class_stat::i_body::Use(i_visitor&A)
{
  QapDebugMsg("no way.");/*A.Do(this);*/
}
bool t_inl_file::t_enum_class_stat::i_body::go(i_dev&dev)
{
  QapDebugMsg("no way.");
  return false;
}
bool t_inl_file::t_enum_class_stat::i_body::t_poly_impl::load()
{
  go_for<t_impl_body>();
  go_for<t_empty_body>();
  (void)count;
  (void)first_id;
  (void)out_arr;
  (void)this;
  main();
  return scope.ok;
}
bool t_inl_file::t_enum_class_stat::i_body::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_enum_class_stat::i_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
void t_inl_file::t_enum_class_stat::t_value::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->expr);
  detail::FieldTryDoReset(this->sep1);
}
t_inl_file::t_enum_class_stat::t_value::t_value()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::t_value::t_value(t_value&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::t_value::operator=(t_value&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->expr=std::move(_Right.expr);
  this->sep1=std::move(_Right.sep1);
}
t_inl_file::t_enum_class_stat::t_value::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_value::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_value";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_enum_class_stat::t_value::ProxySys$$::GetFullName()
{
  return "t_value";
}
bool t_inl_file::t_enum_class_stat::t_value::go(i_dev&dev)
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
void t_inl_file::t_enum_class_stat::t_item::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->value);
}
t_inl_file::t_enum_class_stat::t_item::t_item()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::t_item::t_item(t_item&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::t_item::operator=(t_item&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep0=std::move(_Right.sep0);
  this->name=std::move(_Right.name);
  this->sep1=std::move(_Right.sep1);
  this->value=std::move(_Right.value);
}
t_inl_file::t_enum_class_stat::t_item::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_item::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_item";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_enum_class_stat::t_item::ProxySys$$::GetFullName()
{
  return "t_item";
}
bool t_inl_file::t_enum_class_stat::t_item::go(i_dev&dev)
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
void t_inl_file::t_enum_class_stat::t_comma_with_sep::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_enum_class_stat::t_comma_with_sep::t_comma_with_sep()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::t_comma_with_sep::t_comma_with_sep(t_comma_with_sep&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::t_comma_with_sep::operator=(t_comma_with_sep&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_enum_class_stat::t_comma_with_sep::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_comma_with_sep::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_comma_with_sep";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_enum_class_stat::t_comma_with_sep::ProxySys$$::GetFullName()
{
  return "t_comma_with_sep";
}
bool t_inl_file::t_enum_class_stat::t_comma_with_sep::go(i_dev&dev)
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
void t_inl_file::t_enum_class_stat::t_impl_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->arr);
  detail::FieldTryDoReset(this->comma);
}
t_inl_file::t_enum_class_stat::t_impl_body::t_impl_body()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::t_impl_body::t_impl_body(t_impl_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::t_impl_body::operator=(t_impl_body&&_Right)
{
  struct hidden
  {
    static void foo(i_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_body::operator=(std::move(_Right));
  }
  this->arr=std::move(_Right.arr);
  this->comma=std::move(_Right.comma);
}
t_inl_file::t_enum_class_stat::t_impl_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_impl_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_impl_body";
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
  Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_comma_with_sep>>::GetRTTI(RTTI),"comma",int(&(((SelfClass*)nullptr)->*(&SelfClass::comma))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_enum_class_stat::t_impl_body::ProxySys$$::GetFullName()
{
  return "t_impl_body";
}
void t_inl_file::t_enum_class_stat::t_impl_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_enum_class_stat::t_impl_body::SelfClass*t_inl_file::t_enum_class_stat::t_impl_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_enum_class_stat::t_impl_body::go(i_dev&dev)
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
void t_inl_file::t_enum_class_stat::t_empty_body::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_enum_class_stat::t_empty_body::t_empty_body()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::t_empty_body::t_empty_body(t_empty_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::t_empty_body::operator=(t_empty_body&&_Right)
{
  struct hidden
  {
    static void foo(i_body(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_body::operator=(std::move(_Right));
  }
}
t_inl_file::t_enum_class_stat::t_empty_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_empty_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_empty_body";
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
string t_inl_file::t_enum_class_stat::t_empty_body::ProxySys$$::GetFullName()
{
  return "t_empty_body";
}
void t_inl_file::t_enum_class_stat::t_empty_body::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_enum_class_stat::t_empty_body::SelfClass*t_inl_file::t_enum_class_stat::t_empty_body::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_enum_class_stat::t_empty_body::go(i_dev&dev)
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
void t_inl_file::t_enum_class_stat::t_body::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_enum_class_stat::t_body::t_body()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::t_body::t_body(t_body&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::t_body::operator=(t_body&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_enum_class_stat::t_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_body::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_body";
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
  Info->AddMemberDEF(Sys$$<TAutoPtr<i_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_enum_class_stat::t_body::ProxySys$$::GetFullName()
{
  return "t_body";
}
bool t_inl_file::t_enum_class_stat::t_body::go(i_dev&dev)
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
void t_inl_file::t_enum_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep0);
  detail::FieldTryDoReset(this->name);
  detail::FieldTryDoReset(this->sep1);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_enum_class_stat::t_enum_class_stat()
{
  DoReset();
}
t_inl_file::t_enum_class_stat::t_enum_class_stat(t_enum_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_enum_class_stat::operator=(t_enum_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->sep0=std::move(_Right.sep0);
  this->name=std::move(_Right.name);
  this->sep1=std::move(_Right.sep1);
  this->body=std::move(_Right.body);
}
t_inl_file::t_enum_class_stat::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_enum_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
    Info->AddNested(Sys$$<t_value>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_comma_with_sep>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_impl_body>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_empty_body>::GetRTTI(RTTI));
    Info->AddNested(Sys$$<t_body>::GetRTTI(RTTI));
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_enum_class_stat::ProxySys$$::GetFullName()
{
  return "t_enum_class_stat";
}
void t_inl_file::t_enum_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_enum_class_stat::SelfClass*t_inl_file::t_enum_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_enum_class_stat::go(i_dev&dev)
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
void t_inl_file::t_using_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->type);
}
t_inl_file::t_using_class_stat::t_using_class_stat()
{
  DoReset();
}
t_inl_file::t_using_class_stat::t_using_class_stat(t_using_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_using_class_stat::operator=(t_using_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
  this->type=std::move(_Right.type);
}
t_inl_file::t_using_class_stat::ProxySys$$::metatype*t_inl_file::t_using_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_using_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_using_class_stat::ProxySys$$::GetFullName()
{
  return "t_using_class_stat";
}
void t_inl_file::t_using_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_using_class_stat::SelfClass*t_inl_file::t_using_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_using_class_stat::go(i_dev&dev)
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
void t_inl_file::t_pragma_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_pragma_class_stat::t_pragma_class_stat()
{
  DoReset();
}
t_inl_file::t_pragma_class_stat::t_pragma_class_stat(t_pragma_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_pragma_class_stat::operator=(t_pragma_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_pragma_class_stat::ProxySys$$::metatype*t_inl_file::t_pragma_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_pragma_class_stat";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_pragma_class_stat::ProxySys$$::GetFullName()
{
  return "t_pragma_class_stat";
}
void t_inl_file::t_pragma_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_pragma_class_stat::SelfClass*t_inl_file::t_pragma_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_pragma_class_stat::go(i_dev&dev)
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
void t_inl_file::t_include_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_include_class_stat::t_include_class_stat()
{
  DoReset();
}
t_inl_file::t_include_class_stat::t_include_class_stat(t_include_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_include_class_stat::operator=(t_include_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_include_class_stat::ProxySys$$::metatype*t_inl_file::t_include_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_include_class_stat";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_include_class_stat::ProxySys$$::GetFullName()
{
  return "t_include_class_stat";
}
void t_inl_file::t_include_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_include_class_stat::SelfClass*t_inl_file::t_include_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_include_class_stat::go(i_dev&dev)
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
void t_inl_file::t_preproc_if_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_preproc_if_class_stat::t_preproc_if_class_stat()
{
  DoReset();
}
t_inl_file::t_preproc_if_class_stat::t_preproc_if_class_stat(t_preproc_if_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_preproc_if_class_stat::operator=(t_preproc_if_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_preproc_if_class_stat::ProxySys$$::metatype*t_inl_file::t_preproc_if_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_preproc_if_class_stat";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_preproc_if_class_stat::ProxySys$$::GetFullName()
{
  return "t_preproc_if_class_stat";
}
void t_inl_file::t_preproc_if_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_preproc_if_class_stat::SelfClass*t_inl_file::t_preproc_if_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_preproc_if_class_stat::go(i_dev&dev)
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
void t_inl_file::t_preproc_else_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_preproc_else_class_stat::t_preproc_else_class_stat()
{
  DoReset();
}
t_inl_file::t_preproc_else_class_stat::t_preproc_else_class_stat(t_preproc_else_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_preproc_else_class_stat::operator=(t_preproc_else_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_preproc_else_class_stat::ProxySys$$::metatype*t_inl_file::t_preproc_else_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_preproc_else_class_stat";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_preproc_else_class_stat::ProxySys$$::GetFullName()
{
  return "t_preproc_else_class_stat";
}
void t_inl_file::t_preproc_else_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_preproc_else_class_stat::SelfClass*t_inl_file::t_preproc_else_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_preproc_else_class_stat::go(i_dev&dev)
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
void t_inl_file::t_preproc_endif_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_preproc_endif_class_stat::t_preproc_endif_class_stat()
{
  DoReset();
}
t_inl_file::t_preproc_endif_class_stat::t_preproc_endif_class_stat(t_preproc_endif_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_preproc_endif_class_stat::operator=(t_preproc_endif_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_preproc_endif_class_stat::ProxySys$$::metatype*t_inl_file::t_preproc_endif_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_preproc_endif_class_stat";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_preproc_endif_class_stat::ProxySys$$::GetFullName()
{
  return "t_preproc_endif_class_stat";
}
void t_inl_file::t_preproc_endif_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_preproc_endif_class_stat::SelfClass*t_inl_file::t_preproc_endif_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_preproc_endif_class_stat::go(i_dev&dev)
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
void t_inl_file::t_define_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_define_class_stat::t_define_class_stat()
{
  DoReset();
}
t_inl_file::t_define_class_stat::t_define_class_stat(t_define_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_define_class_stat::operator=(t_define_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_define_class_stat::ProxySys$$::metatype*t_inl_file::t_define_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_define_class_stat";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_define_class_stat::ProxySys$$::GetFullName()
{
  return "t_define_class_stat";
}
void t_inl_file::t_define_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_define_class_stat::SelfClass*t_inl_file::t_define_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_define_class_stat::go(i_dev&dev)
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
void t_inl_file::t_undef_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_undef_class_stat::t_undef_class_stat()
{
  DoReset();
}
t_inl_file::t_undef_class_stat::t_undef_class_stat(t_undef_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_undef_class_stat::operator=(t_undef_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_undef_class_stat::ProxySys$$::metatype*t_inl_file::t_undef_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_undef_class_stat";
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
  Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_undef_class_stat::ProxySys$$::GetFullName()
{
  return "t_undef_class_stat";
}
void t_inl_file::t_undef_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_undef_class_stat::SelfClass*t_inl_file::t_undef_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_undef_class_stat::go(i_dev&dev)
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
void t_inl_file::t_sep_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->sep);
}
t_inl_file::t_sep_class_stat::t_sep_class_stat()
{
  DoReset();
}
t_inl_file::t_sep_class_stat::t_sep_class_stat(t_sep_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_sep_class_stat::operator=(t_sep_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->sep=std::move(_Right.sep);
}
t_inl_file::t_sep_class_stat::ProxySys$$::metatype*t_inl_file::t_sep_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_sep_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_sep_class_stat::ProxySys$$::GetFullName()
{
  return "t_sep_class_stat";
}
void t_inl_file::t_sep_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_sep_class_stat::SelfClass*t_inl_file::t_sep_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_sep_class_stat::go(i_dev&dev)
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
void t_inl_file::t_null_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
}
t_inl_file::t_null_class_stat::t_null_class_stat()
{
  DoReset();
}
t_inl_file::t_null_class_stat::t_null_class_stat(t_null_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_null_class_stat::operator=(t_null_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
}
t_inl_file::t_null_class_stat::ProxySys$$::metatype*t_inl_file::t_null_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_null_class_stat";
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
string t_inl_file::t_null_class_stat::ProxySys$$::GetFullName()
{
  return "t_null_class_stat";
}
void t_inl_file::t_null_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_null_class_stat::SelfClass*t_inl_file::t_null_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_null_class_stat::go(i_dev&dev)
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
void t_inl_file::t_class_class_stat::DoReset()
{
  {
    detail::TryDoReset<SelfClass>(this);
  }
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_class_class_stat::t_class_class_stat()
{
  DoReset();
}
t_inl_file::t_class_class_stat::t_class_class_stat(t_class_class_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_class_class_stat::operator=(t_class_class_stat&&_Right)
{
  struct hidden
  {
    static void foo(i_class_stat(*)=(SelfClass*)nullptr) {}};
  if (&_Right==this)return;
  {
    i_class_stat::operator=(std::move(_Right));
  }
  this->body=std::move(_Right.body);
}
t_inl_file::t_class_class_stat::ProxySys$$::metatype*t_inl_file::t_class_class_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_class_class_stat";
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
  Info->AddMemberDEF(Sys$$<t_class>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_class_class_stat::ProxySys$$::GetFullName()
{
  return "t_class_class_stat";
}
void t_inl_file::t_class_class_stat::Use(i_visitor&A)
{
  A.Do(this);
}
t_inl_file::t_class_class_stat::SelfClass*t_inl_file::t_class_class_stat::UberCast(ParentClass*ptr)
{
  return i_visitor::UberCast<SelfClass>(ptr);
}
bool t_inl_file::t_class_class_stat::go(i_dev&dev)
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
void t_inl_file::t_inl_file_stat::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->sep);
  detail::FieldTryDoReset(this->body);
}
t_inl_file::t_inl_file_stat::t_inl_file_stat()
{
  DoReset();
}
t_inl_file::t_inl_file_stat::t_inl_file_stat(t_inl_file_stat&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::t_inl_file_stat::operator=(t_inl_file_stat&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->sep=std::move(_Right.sep);
  this->body=std::move(_Right.body);
}
t_inl_file::t_inl_file_stat::ProxySys$$::metatype*t_inl_file::t_inl_file_stat::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_inl_file_stat";
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
  Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");
  Info->AddMemberDEF(Sys$$<TAutoPtr<t_class>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::t_inl_file_stat::ProxySys$$::GetFullName()
{
  return "t_inl_file_stat";
}
bool t_inl_file::t_inl_file_stat::go(i_dev&dev)
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
void t_inl_file::DoReset()
{
  {
  }
  detail::FieldTryDoReset(this->arr);
}
t_inl_file::t_inl_file()
{
  DoReset();
}
t_inl_file::t_inl_file(t_inl_file&&_Right)
{
  operator=(std::move(_Right));
}
void t_inl_file::operator=(t_inl_file&&_Right)
{
  if (&_Right==this)return;
  {
  }
  this->arr=std::move(_Right.arr);
}
t_inl_file::ProxySys$$::metatype*t_inl_file::ProxySys$$::GetRTTI(IEnv&RTTI)
{
  static const string Name="t_inl_file";
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
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_class_stat>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");
  {
    RTTI.OnRegEnd(Info);
  }
  {
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
  }
  Info->SelfTesting();
  return Info;
}
string t_inl_file::ProxySys$$::GetFullName()
{
  return "t_inl_file";
}
bool t_inl_file::go(i_dev&dev)
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
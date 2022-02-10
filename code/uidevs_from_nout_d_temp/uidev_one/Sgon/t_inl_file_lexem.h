struct t_inl_file{

  struct i_class_stat;
   struct t_access_mod_class_stat; struct t_fv_class_stat; struct t_typedef_class_stat; struct t_dtor_class_stat; struct t_ctor_class_stat; struct t_oper_cast_class_stat; struct t_common_oper_class_stat; struct t_namespace_class_stat; struct t_template_class_stat; struct t_enum_class_stat; struct t_using_class_stat; struct t_pragma_class_stat; struct t_include_class_stat; struct t_preproc_if_class_stat; struct t_preproc_else_class_stat; struct t_preproc_endif_class_stat; struct t_define_class_stat; struct t_undef_class_stat; struct t_sep_class_stat; struct t_null_class_stat; struct t_class_class_stat;
  struct i_class_stat_visitor{
  
    typedef t_inl_file::i_class_stat i_class_stat;
  
     virtual void Do(t_access_mod_class_stat*p)=0; virtual void Do(t_fv_class_stat*p)=0; virtual void Do(t_typedef_class_stat*p)=0; virtual void Do(t_dtor_class_stat*p)=0; virtual void Do(t_ctor_class_stat*p)=0; virtual void Do(t_oper_cast_class_stat*p)=0; virtual void Do(t_common_oper_class_stat*p)=0; virtual void Do(t_namespace_class_stat*p)=0; virtual void Do(t_template_class_stat*p)=0; virtual void Do(t_enum_class_stat*p)=0; virtual void Do(t_using_class_stat*p)=0; virtual void Do(t_pragma_class_stat*p)=0; virtual void Do(t_include_class_stat*p)=0; virtual void Do(t_preproc_if_class_stat*p)=0; virtual void Do(t_preproc_else_class_stat*p)=0; virtual void Do(t_preproc_endif_class_stat*p)=0; virtual void Do(t_define_class_stat*p)=0; virtual void Do(t_undef_class_stat*p)=0; virtual void Do(t_sep_class_stat*p)=0; virtual void Do(t_null_class_stat*p)=0; virtual void Do(t_class_class_stat*p)=0;
  
     typedef t_inl_file::t_access_mod_class_stat t_access_mod_class_stat; typedef t_inl_file::t_fv_class_stat t_fv_class_stat; typedef t_inl_file::t_typedef_class_stat t_typedef_class_stat; typedef t_inl_file::t_dtor_class_stat t_dtor_class_stat; typedef t_inl_file::t_ctor_class_stat t_ctor_class_stat; typedef t_inl_file::t_oper_cast_class_stat t_oper_cast_class_stat; typedef t_inl_file::t_common_oper_class_stat t_common_oper_class_stat; typedef t_inl_file::t_namespace_class_stat t_namespace_class_stat; typedef t_inl_file::t_template_class_stat t_template_class_stat; typedef t_inl_file::t_enum_class_stat t_enum_class_stat; typedef t_inl_file::t_using_class_stat t_using_class_stat; typedef t_inl_file::t_pragma_class_stat t_pragma_class_stat; typedef t_inl_file::t_include_class_stat t_include_class_stat; typedef t_inl_file::t_preproc_if_class_stat t_preproc_if_class_stat; typedef t_inl_file::t_preproc_else_class_stat t_preproc_else_class_stat; typedef t_inl_file::t_preproc_endif_class_stat t_preproc_endif_class_stat; typedef t_inl_file::t_define_class_stat t_define_class_stat; typedef t_inl_file::t_undef_class_stat t_undef_class_stat; typedef t_inl_file::t_sep_class_stat t_sep_class_stat; typedef t_inl_file::t_null_class_stat t_null_class_stat; typedef t_inl_file::t_class_class_stat t_class_class_stat;
  
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    
       void Do(t_access_mod_class_stat*p){ptr=get(p);} void Do(t_fv_class_stat*p){ptr=get(p);} void Do(t_typedef_class_stat*p){ptr=get(p);} void Do(t_dtor_class_stat*p){ptr=get(p);} void Do(t_ctor_class_stat*p){ptr=get(p);} void Do(t_oper_cast_class_stat*p){ptr=get(p);} void Do(t_common_oper_class_stat*p){ptr=get(p);} void Do(t_namespace_class_stat*p){ptr=get(p);} void Do(t_template_class_stat*p){ptr=get(p);} void Do(t_enum_class_stat*p){ptr=get(p);} void Do(t_using_class_stat*p){ptr=get(p);} void Do(t_pragma_class_stat*p){ptr=get(p);} void Do(t_include_class_stat*p){ptr=get(p);} void Do(t_preproc_if_class_stat*p){ptr=get(p);} void Do(t_preproc_else_class_stat*p){ptr=get(p);} void Do(t_preproc_endif_class_stat*p){ptr=get(p);} void Do(t_define_class_stat*p){ptr=get(p);} void Do(t_undef_class_stat*p){ptr=get(p);} void Do(t_sep_class_stat*p){ptr=get(p);} void Do(t_null_class_stat*p){ptr=get(p);} void Do(t_class_class_stat*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_class_stat*p){
      if(!p)return nullptr;Is<TYPE,i_class_stat_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };

  struct i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef i_class_stat SelfClass;;
  
    void DoReset();
  
    i_class_stat(const i_class_stat&)=delete;i_class_stat();;
  
    i_class_stat(i_class_stat&&_Right);
    void operator=(i_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  
    typedef i_class_stat_visitor i_visitor;virtual void Use(i_visitor&A);
  virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };

  struct i_expr;
   struct t_call_expr; struct t_block_expr; struct t_bool_expr; struct t_string_expr; struct t_char_expr; struct t_num_expr; struct t_real_expr; struct t_nullptr_expr; struct t_or_expr; struct t_hex_expr; struct t_var_expr;
  struct i_expr_visitor{
  
    typedef t_inl_file::i_expr i_expr;
  
     virtual void Do(t_call_expr*p)=0; virtual void Do(t_block_expr*p)=0; virtual void Do(t_bool_expr*p)=0; virtual void Do(t_string_expr*p)=0; virtual void Do(t_char_expr*p)=0; virtual void Do(t_num_expr*p)=0; virtual void Do(t_real_expr*p)=0; virtual void Do(t_nullptr_expr*p)=0; virtual void Do(t_or_expr*p)=0; virtual void Do(t_hex_expr*p)=0; virtual void Do(t_var_expr*p)=0;
  
     typedef t_inl_file::t_call_expr t_call_expr; typedef t_inl_file::t_block_expr t_block_expr; typedef t_inl_file::t_bool_expr t_bool_expr; typedef t_inl_file::t_string_expr t_string_expr; typedef t_inl_file::t_char_expr t_char_expr; typedef t_inl_file::t_num_expr t_num_expr; typedef t_inl_file::t_real_expr t_real_expr; typedef t_inl_file::t_nullptr_expr t_nullptr_expr; typedef t_inl_file::t_or_expr t_or_expr; typedef t_inl_file::t_hex_expr t_hex_expr; typedef t_inl_file::t_var_expr t_var_expr;
  
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    
       void Do(t_call_expr*p){ptr=get(p);} void Do(t_block_expr*p){ptr=get(p);} void Do(t_bool_expr*p){ptr=get(p);} void Do(t_string_expr*p){ptr=get(p);} void Do(t_char_expr*p){ptr=get(p);} void Do(t_num_expr*p){ptr=get(p);} void Do(t_real_expr*p){ptr=get(p);} void Do(t_nullptr_expr*p){ptr=get(p);} void Do(t_or_expr*p){ptr=get(p);} void Do(t_hex_expr*p){ptr=get(p);} void Do(t_var_expr*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){
      if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };

  struct i_expr{
  typedef t_inl_file OwnerClass;;
  typedef i_expr SelfClass;;
  
    void DoReset();
  
    i_expr(const i_expr&)=delete;i_expr();;
  
    i_expr(i_expr&&_Right);
    void operator=(i_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  
    typedef i_expr_visitor i_visitor;virtual void Use(i_visitor&A);
  virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };

  struct i_func_body;
   struct t_zero_func_body; struct t_null_func_body; struct t_delete_func_body; struct t_impl_func_body;
  struct i_func_body_visitor{
  
    typedef t_inl_file::i_func_body i_func_body;
  
     virtual void Do(t_zero_func_body*p)=0; virtual void Do(t_null_func_body*p)=0; virtual void Do(t_delete_func_body*p)=0; virtual void Do(t_impl_func_body*p)=0;
  
     typedef t_inl_file::t_zero_func_body t_zero_func_body; typedef t_inl_file::t_null_func_body t_null_func_body; typedef t_inl_file::t_delete_func_body t_delete_func_body; typedef t_inl_file::t_impl_func_body t_impl_func_body;
  
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    
       void Do(t_zero_func_body*p){ptr=get(p);} void Do(t_null_func_body*p){ptr=get(p);} void Do(t_delete_func_body*p){ptr=get(p);} void Do(t_impl_func_body*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_func_body*p){
      if(!p)return nullptr;Is<TYPE,i_func_body_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };

  struct i_func_body{
  typedef t_inl_file OwnerClass;;
  typedef i_func_body SelfClass;;
  
    void DoReset();
  
    i_func_body(const i_func_body&)=delete;i_func_body();;
  
    i_func_body(i_func_body&&_Right);
    void operator=(i_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  
    typedef i_func_body_visitor i_visitor;virtual void Use(i_visitor&A);
  virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };

  struct i_tmpl_expr;
   struct t_call_tmpl_expr; struct t_block_tmpl_expr; struct t_bool_tmpl_expr; struct t_string_tmpl_expr; struct t_char_tmpl_expr; struct t_num_tmpl_expr; struct t_real_tmpl_expr; struct t_nullptr_tmpl_expr; struct t_or_tmpl_expr; struct t_hex_tmpl_expr; struct t_var_tmpl_expr;
  struct i_tmpl_expr_visitor{
  
    typedef t_inl_file::i_tmpl_expr i_tmpl_expr;
  
     virtual void Do(t_call_tmpl_expr*p)=0; virtual void Do(t_block_tmpl_expr*p)=0; virtual void Do(t_bool_tmpl_expr*p)=0; virtual void Do(t_string_tmpl_expr*p)=0; virtual void Do(t_char_tmpl_expr*p)=0; virtual void Do(t_num_tmpl_expr*p)=0; virtual void Do(t_real_tmpl_expr*p)=0; virtual void Do(t_nullptr_tmpl_expr*p)=0; virtual void Do(t_or_tmpl_expr*p)=0; virtual void Do(t_hex_tmpl_expr*p)=0; virtual void Do(t_var_tmpl_expr*p)=0;
  
     typedef t_inl_file::t_call_tmpl_expr t_call_tmpl_expr; typedef t_inl_file::t_block_tmpl_expr t_block_tmpl_expr; typedef t_inl_file::t_bool_tmpl_expr t_bool_tmpl_expr; typedef t_inl_file::t_string_tmpl_expr t_string_tmpl_expr; typedef t_inl_file::t_char_tmpl_expr t_char_tmpl_expr; typedef t_inl_file::t_num_tmpl_expr t_num_tmpl_expr; typedef t_inl_file::t_real_tmpl_expr t_real_tmpl_expr; typedef t_inl_file::t_nullptr_tmpl_expr t_nullptr_tmpl_expr; typedef t_inl_file::t_or_tmpl_expr t_or_tmpl_expr; typedef t_inl_file::t_hex_tmpl_expr t_hex_tmpl_expr; typedef t_inl_file::t_var_tmpl_expr t_var_tmpl_expr;
  
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    
       void Do(t_call_tmpl_expr*p){ptr=get(p);} void Do(t_block_tmpl_expr*p){ptr=get(p);} void Do(t_bool_tmpl_expr*p){ptr=get(p);} void Do(t_string_tmpl_expr*p){ptr=get(p);} void Do(t_char_tmpl_expr*p){ptr=get(p);} void Do(t_num_tmpl_expr*p){ptr=get(p);} void Do(t_real_tmpl_expr*p){ptr=get(p);} void Do(t_nullptr_tmpl_expr*p){ptr=get(p);} void Do(t_or_tmpl_expr*p){ptr=get(p);} void Do(t_hex_tmpl_expr*p){ptr=get(p);} void Do(t_var_tmpl_expr*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_tmpl_expr*p){
      if(!p)return nullptr;Is<TYPE,i_tmpl_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };

  struct i_tmpl_expr{
    typedef t_inl_file OwnerClass;
    typedef i_tmpl_expr SelfClass;
    void DoReset();
    i_tmpl_expr(const i_tmpl_expr&)=delete;
    i_tmpl_expr();
    i_tmpl_expr(i_tmpl_expr&&_Right);
    void operator=(i_tmpl_expr&&_Right);
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI);
      static string GetFullName();
    };
    typedef i_tmpl_expr_visitor i_visitor;
    virtual void Use(i_visitor&A);
    virtual bool go(i_dev&dev);
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
      bool load();
      static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);
      static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };

  struct i_concrete_param_way;
  struct t_pfunc_concrete_param_way;
  struct t_type_concrete_param_way;
  struct t_expr_concrete_param_way;

  struct i_concrete_param_way_visitor{
  
    typedef t_inl_file::i_concrete_param_way i_concrete_param_way;
  
     virtual void Do(t_pfunc_concrete_param_way*p)=0; virtual void Do(t_type_concrete_param_way*p)=0; virtual void Do(t_expr_concrete_param_way*p)=0;
  
     typedef t_inl_file::t_pfunc_concrete_param_way t_pfunc_concrete_param_way; typedef t_inl_file::t_type_concrete_param_way t_type_concrete_param_way; typedef t_inl_file::t_expr_concrete_param_way t_expr_concrete_param_way;
  
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    
       void Do(t_pfunc_concrete_param_way*p){ptr=get(p);} void Do(t_type_concrete_param_way*p){ptr=get(p);} void Do(t_expr_concrete_param_way*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_concrete_param_way*p){
      if(!p)return nullptr;Is<TYPE,i_concrete_param_way_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };

  struct i_concrete_param_way{
  typedef t_inl_file OwnerClass;;
  typedef i_concrete_param_way SelfClass;;
  
    void DoReset();
  
    i_concrete_param_way(const i_concrete_param_way&)=delete;i_concrete_param_way();;
  
    i_concrete_param_way(i_concrete_param_way&&_Right);
    void operator=(i_concrete_param_way&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  
    typedef i_concrete_param_way_visitor i_visitor;virtual void Use(i_visitor&A);
  virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
  struct t_lev03{
  typedef t_inl_file OwnerClass;;
  typedef t_lev03 SelfClass;;
  
   string oper;; TAutoPtr<i_expr> expr;;
    void DoReset();
  
    t_lev03(const t_lev03&)=delete;t_lev03();;
  
    t_lev03(t_lev03&&_Right);
    void operator=(t_lev03&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev05{
  
    struct t_oper{
  typedef t_lev05 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev05 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev03 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev05 SelfClass;;
  
   t_lev03 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev05(const t_lev05&)=delete;t_lev05();;
  
    t_lev05(t_lev05&&_Right);
    void operator=(t_lev05&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev06{
  
    struct t_oper{
  typedef t_lev06 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev06 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev05 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev06 SelfClass;;
  
   t_lev05 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev06(const t_lev06&)=delete;t_lev06();;
  
    t_lev06(t_lev06&&_Right);
    void operator=(t_lev06&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev07{
  
    struct t_oper{
  typedef t_lev07 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev07 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev06 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev07 SelfClass;;
  
   t_lev06 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev07(const t_lev07&)=delete;t_lev07();;
  
    t_lev07(t_lev07&&_Right);
    void operator=(t_lev07&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev08{
  
    struct t_oper{
  typedef t_lev08 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev08 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev07 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev08 SelfClass;;
  
   t_lev07 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev08(const t_lev08&)=delete;t_lev08();;
  
    t_lev08(t_lev08&&_Right);
    void operator=(t_lev08&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev09{
  
    struct t_oper{
  typedef t_lev09 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev09 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev08 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev09 SelfClass;;
  
   t_lev08 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev09(const t_lev09&)=delete;t_lev09();;
  
    t_lev09(t_lev09&&_Right);
    void operator=(t_lev09&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev10{
  
    struct t_oper{
  typedef t_lev10 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev10 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev09 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev10 SelfClass;;
  
   t_lev09 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev10(const t_lev10&)=delete;t_lev10();;
  
    t_lev10(t_lev10&&_Right);
    void operator=(t_lev10&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev11{
  
    struct t_oper{
  typedef t_lev11 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev11 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev10 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev11 SelfClass;;
  
   t_lev10 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev11(const t_lev11&)=delete;t_lev11();;
  
    t_lev11(t_lev11&&_Right);
    void operator=(t_lev11&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev12{
  
    struct t_oper{
  typedef t_lev12 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev12 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev11 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev12 SelfClass;;
  
   t_lev11 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev12(const t_lev12&)=delete;t_lev12();;
  
    t_lev12(t_lev12&&_Right);
    void operator=(t_lev12&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev13{
  
    struct t_oper{
  typedef t_lev13 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev13 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev12 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev13 SelfClass;;
  
   t_lev12 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev13(const t_lev13&)=delete;t_lev13();;
  
    t_lev13(t_lev13&&_Right);
    void operator=(t_lev13&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_lev14{
  
    struct t_oper{
  typedef t_lev14 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_lev14 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_lev13 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_lev14 SelfClass;;
  
   t_lev13 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_lev14(const t_lev14&)=delete;t_lev14();;
  
    t_lev14(t_lev14&&_Right);
    void operator=(t_lev14&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_expr SelfClass;;
  
   t_lev14 body;;
    void DoReset();
  
    t_expr(const t_expr&)=delete;t_expr();;
  
    t_expr(t_expr&&_Right);
    void operator=(t_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev03{
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev03 SelfClass;;
  
   string oper;; TAutoPtr<i_tmpl_expr> expr;;
    void DoReset();
  
    t_tmpl_lev03(const t_tmpl_lev03&)=delete;t_tmpl_lev03();;
  
    t_tmpl_lev03(t_tmpl_lev03&&_Right);
    void operator=(t_tmpl_lev03&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev05{
  
    struct t_oper{
  typedef t_tmpl_lev05 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev05 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev03 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev05 SelfClass;;
  
   t_tmpl_lev03 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev05(const t_tmpl_lev05&)=delete;t_tmpl_lev05();;
  
    t_tmpl_lev05(t_tmpl_lev05&&_Right);
    void operator=(t_tmpl_lev05&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev06{
  
    struct t_oper{
  typedef t_tmpl_lev06 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev06 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev05 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev06 SelfClass;;
  
   t_tmpl_lev05 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev06(const t_tmpl_lev06&)=delete;t_tmpl_lev06();;
  
    t_tmpl_lev06(t_tmpl_lev06&&_Right);
    void operator=(t_tmpl_lev06&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev09{
  
    struct t_oper{
  typedef t_tmpl_lev09 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev09 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev06 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev09 SelfClass;;
  
   t_tmpl_lev06 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev09(const t_tmpl_lev09&)=delete;t_tmpl_lev09();;
  
    t_tmpl_lev09(t_tmpl_lev09&&_Right);
    void operator=(t_tmpl_lev09&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev10{
  
    struct t_oper{
  typedef t_tmpl_lev10 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev10 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev09 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev10 SelfClass;;
  
   t_tmpl_lev09 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev10(const t_tmpl_lev10&)=delete;t_tmpl_lev10();;
  
    t_tmpl_lev10(t_tmpl_lev10&&_Right);
    void operator=(t_tmpl_lev10&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev11{
  
    struct t_oper{
  typedef t_tmpl_lev11 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev11 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev10 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev11 SelfClass;;
  
   t_tmpl_lev10 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev11(const t_tmpl_lev11&)=delete;t_tmpl_lev11();;
  
    t_tmpl_lev11(t_tmpl_lev11&&_Right);
    void operator=(t_tmpl_lev11&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev12{
  
    struct t_oper{
  typedef t_tmpl_lev12 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev12 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev11 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev12 SelfClass;;
  
   t_tmpl_lev11 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev12(const t_tmpl_lev12&)=delete;t_tmpl_lev12();;
  
    t_tmpl_lev12(t_tmpl_lev12&&_Right);
    void operator=(t_tmpl_lev12&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev13{
  
    struct t_oper{
  typedef t_tmpl_lev13 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev13 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev12 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev13 SelfClass;;
  
   t_tmpl_lev12 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev13(const t_tmpl_lev13&)=delete;t_tmpl_lev13();;
  
    t_tmpl_lev13(t_tmpl_lev13&&_Right);
    void operator=(t_tmpl_lev13&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_lev14{
  
    struct t_oper{
  typedef t_tmpl_lev14 OwnerClass;;
  typedef t_oper SelfClass;;
  
   string value;;
    void DoReset();
  
    t_oper(const t_oper&)=delete;t_oper();;
  
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_tmpl_lev14 OwnerClass;;
  typedef t_item SelfClass;;
  
   t_oper oper;; t_tmpl_lev13 expr;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_lev14 SelfClass;;
  
   t_tmpl_lev13 expr;; vector<t_item> arr;;
    void DoReset();
  
    t_tmpl_lev14(const t_tmpl_lev14&)=delete;t_tmpl_lev14();;
  
    t_tmpl_lev14(t_tmpl_lev14&&_Right);
    void operator=(t_tmpl_lev14&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_expr SelfClass;;
  
   t_tmpl_lev14 body;;
    void DoReset();
  
    t_tmpl_expr(const t_tmpl_expr&)=delete;t_tmpl_expr();;
  
    t_tmpl_expr(t_tmpl_expr&&_Right);
    void operator=(t_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_concrete_param{
  typedef t_inl_file OwnerClass;;
  typedef t_concrete_param SelfClass;;
  
   t_sep sep0;; TAutoPtr<i_concrete_param_way> body;; t_sep sep1;;
    void DoReset();
  
    t_concrete_param(const t_concrete_param&)=delete;t_concrete_param();;
  
    t_concrete_param(t_concrete_param&&_Right);
    void operator=(t_concrete_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_concrete_params{
  typedef t_inl_file OwnerClass;;
  typedef t_concrete_params SelfClass;;
  
   vector<t_concrete_param> arr;; t_sep sep;;
    void DoReset();
  
    t_concrete_params(const t_concrete_params&)=delete;t_concrete_params();;
  
    t_concrete_params(t_concrete_params&&_Right);
    void operator=(t_concrete_params&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_access_mod{
  typedef t_inl_file OwnerClass;;
  typedef t_access_mod SelfClass;;
  
   string keyword;;
    void DoReset();
  
    t_access_mod(const t_access_mod&)=delete;t_access_mod();;
  
    t_access_mod(t_access_mod&&_Right);
    void operator=(t_access_mod&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_access_mod_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_access_mod_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_access_mod mod;; t_sep sep;;
    void DoReset();
  
    t_access_mod_class_stat(const t_access_mod_class_stat&)=delete;t_access_mod_class_stat();;
  
    t_access_mod_class_stat(t_access_mod_class_stat&&_Right);
    void operator=(t_access_mod_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_raw_func_body{
  
    struct i_item;
     struct t_sep_item; struct t_s_item; struct t_c_item; struct t_code_item; struct t_div_item; struct t_block_item;
    struct i_item_visitor{
    
      typedef t_raw_func_body::i_item i_item;
    
       virtual void Do(t_sep_item*p)=0; virtual void Do(t_s_item*p)=0; virtual void Do(t_c_item*p)=0; virtual void Do(t_code_item*p)=0; virtual void Do(t_div_item*p)=0; virtual void Do(t_block_item*p)=0;
    
       typedef t_raw_func_body::t_sep_item t_sep_item; typedef t_raw_func_body::t_s_item t_s_item; typedef t_raw_func_body::t_c_item t_c_item; typedef t_raw_func_body::t_code_item t_code_item; typedef t_raw_func_body::t_div_item t_div_item; typedef t_raw_func_body::t_block_item t_block_item;
    
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      
         void Do(t_sep_item*p){ptr=get(p);} void Do(t_s_item*p){ptr=get(p);} void Do(t_c_item*p){ptr=get(p);} void Do(t_code_item*p){ptr=get(p);} void Do(t_div_item*p){ptr=get(p);} void Do(t_block_item*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_item*p){
        if(!p)return nullptr;Is<TYPE,i_item_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  
    struct i_item{
  typedef t_raw_func_body OwnerClass;;
  typedef i_item SelfClass;;
  
    void DoReset();
  
    i_item(const i_item&)=delete;i_item();;
  
    i_item(i_item&&_Right);
    void operator=(i_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    
      typedef i_item_visitor i_visitor;virtual void Use(i_visitor&A);
    virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    struct t_sep_item:public i_item{
  typedef t_raw_func_body OwnerClass;;
  typedef t_sep_item SelfClass;typedef i_item ParentClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_sep_item(const t_sep_item&)=delete;t_sep_item();;
  
    t_sep_item(t_sep_item&&_Right);
    void operator=(t_sep_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_s_item:public i_item{
  typedef t_raw_func_body OwnerClass;;
  typedef t_s_item SelfClass;typedef i_item ParentClass;;
  
   string value;;
    void DoReset();
  
    t_s_item(const t_s_item&)=delete;t_s_item();;
  
    t_s_item(t_s_item&&_Right);
    void operator=(t_s_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_c_item:public i_item{
  typedef t_raw_func_body OwnerClass;;
  typedef t_c_item SelfClass;typedef i_item ParentClass;;
  
   string value;;
    void DoReset();
  
    t_c_item(const t_c_item&)=delete;t_c_item();;
  
    t_c_item(t_c_item&&_Right);
    void operator=(t_c_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_code_item:public i_item{
  typedef t_raw_func_body OwnerClass;;
  typedef t_code_item SelfClass;typedef i_item ParentClass;;
  
   string code;;
    void DoReset();
  
    t_code_item(const t_code_item&)=delete;t_code_item();;
  
    t_code_item(t_code_item&&_Right);
    void operator=(t_code_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_div_item:public i_item{
  typedef t_raw_func_body OwnerClass;;
  typedef t_div_item SelfClass;typedef i_item ParentClass;;
  
    void DoReset();
  
    t_div_item(const t_div_item&)=delete;t_div_item();;
  
    t_div_item(t_div_item&&_Right);
    void operator=(t_div_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_block_item:public i_item{
  typedef t_raw_func_body OwnerClass;;
  typedef t_block_item SelfClass;typedef i_item ParentClass;;
  
   TAutoPtr<t_raw_func_body> body;;
    void DoReset();
  
    t_block_item(const t_block_item&)=delete;t_block_item();;
  
    t_block_item(t_block_item&&_Right);
    void operator=(t_block_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_raw_func_body SelfClass;;
  
   t_sep sep;; vector<TAutoPtr<i_item>> arr;;
    void DoReset();
  
    t_raw_func_body(const t_raw_func_body&)=delete;t_raw_func_body();;
  
    t_raw_func_body(t_raw_func_body&&_Right);
    void operator=(t_raw_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  
  };
  struct t_func_path{
  
    struct t_item{
  typedef t_func_path OwnerClass;;
  typedef t_item SelfClass;;
  
   string value;; t_sep sep0;; t_sep sep1;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_func_path SelfClass;;
  
   vector<t_item> arr;;
    void DoReset();
  
    t_func_path(const t_func_path&)=delete;t_func_path();;
  
    t_func_path(t_func_path&&_Right);
    void operator=(t_func_path&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_const_with_sep{
  typedef t_inl_file OwnerClass;;
  typedef t_const_with_sep SelfClass;;
  
   t_sep sep;; string keyword;;
    void DoReset();
  
    t_const_with_sep(const t_const_with_sep&)=delete;t_const_with_sep();;
  
    t_const_with_sep(t_const_with_sep&&_Right);
    void operator=(t_const_with_sep&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_keyword{
  typedef t_inl_file OwnerClass;;
  typedef t_keyword SelfClass;;
  
   string keyword;; t_sep sep;;
    void DoReset();
  
    t_keyword(const t_keyword&)=delete;t_keyword();;
  
    t_keyword(t_keyword&&_Right);
    void operator=(t_keyword&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_ptr{
  typedef t_inl_file OwnerClass;;
  typedef t_ptr SelfClass;;
  
   TAutoPtr<t_const_with_sep> cv;; t_sep sep;;
    void DoReset();
  
    t_ptr(const t_ptr&)=delete;t_ptr();;
  
    t_ptr(t_ptr&&_Right);
    void operator=(t_ptr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_ref{
  typedef t_inl_file OwnerClass;;
  typedef t_ref SelfClass;;
  
   TAutoPtr<t_const_with_sep> cv;; t_sep sep;; string ref;;
    void DoReset();
  
    t_ref(const t_ref&)=delete;t_ref();;
  
    t_ref(t_ref&&_Right);
    void operator=(t_ref&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_type_with_sep{
  typedef t_inl_file OwnerClass;;
  typedef t_type_with_sep SelfClass;;
  
   t_sep sep;; string name;; TAutoPtr<t_concrete_params> concrete_params;;
    void DoReset();
  
    t_type_with_sep(const t_type_with_sep&)=delete;t_type_with_sep();;
  
    t_type_with_sep(t_type_with_sep&&_Right);
    void operator=(t_type_with_sep&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_scope_with_sep{
  typedef t_inl_file OwnerClass;;
  typedef t_scope_with_sep SelfClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_scope_with_sep(const t_scope_with_sep&)=delete;t_scope_with_sep();;
  
    t_scope_with_sep(t_scope_with_sep&&_Right);
    void operator=(t_scope_with_sep&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_scopes{
  
    struct t_item{
  typedef t_scopes OwnerClass;;
  typedef t_item SelfClass;;
  
   t_scope_with_sep sws;; t_type_with_sep body;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_scopes SelfClass;;
  
   t_type_with_sep first;; vector<t_item> arr;;
    void DoReset();
  
    t_scopes(const t_scopes&)=delete;t_scopes();;
  
    t_scopes(t_scopes&&_Right);
    void operator=(t_scopes&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_fv_class_stat:public i_class_stat{
  
    struct t_type_expr{
    
      struct i_name_part;
       struct t_raw_name_part; struct t_brackets_name_part;
      struct i_name_part_visitor{
      
        typedef t_type_expr::i_name_part i_name_part;
      
         virtual void Do(t_raw_name_part*p)=0; virtual void Do(t_brackets_name_part*p)=0;
      
         typedef t_type_expr::t_raw_name_part t_raw_name_part; typedef t_type_expr::t_brackets_name_part t_brackets_name_part;
      
        template<class TYPE,class Visitor>
        struct Is:public Visitor{
          TYPE*ptr;
          Is():ptr(nullptr){}
        
          template<class U>static TYPE*get(U*p){return nullptr;}
          template<>static TYPE*get<TYPE>(TYPE*p){return p;}
        
           void Do(t_raw_name_part*p){ptr=get(p);} void Do(t_brackets_name_part*p){ptr=get(p);}
        };
        template<class TYPE>
        static TYPE*UberCast(i_name_part*p){
          if(!p)return nullptr;Is<TYPE,i_name_part_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
    
      struct i_name_part{
  typedef t_type_expr OwnerClass;;
  typedef i_name_part SelfClass;;
  
    void DoReset();
  
    i_name_part(const i_name_part&)=delete;i_name_part();;
  
    i_name_part(i_name_part&&_Right);
    void operator=(i_name_part&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      
        typedef i_name_part_visitor i_visitor;virtual void Use(i_visitor&A);
      virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    
      struct i_func_param;
       struct t_pfunc_func_param; struct t_var_args_func_param; struct t_type_func_param; struct t_expr_func_param;
      struct i_func_param_visitor{
      
        typedef t_type_expr::i_func_param i_func_param;
      
         virtual void Do(t_pfunc_func_param*p)=0; virtual void Do(t_var_args_func_param*p)=0; virtual void Do(t_type_func_param*p)=0; virtual void Do(t_expr_func_param*p)=0;
      
         typedef t_type_expr::t_pfunc_func_param t_pfunc_func_param; typedef t_type_expr::t_var_args_func_param t_var_args_func_param; typedef t_type_expr::t_type_func_param t_type_func_param; typedef t_type_expr::t_expr_func_param t_expr_func_param;
      
        template<class TYPE,class Visitor>
        struct Is:public Visitor{
          TYPE*ptr;
          Is():ptr(nullptr){}
        
          template<class U>static TYPE*get(U*p){return nullptr;}
          template<>static TYPE*get<TYPE>(TYPE*p){return p;}
        
           void Do(t_pfunc_func_param*p){ptr=get(p);} void Do(t_var_args_func_param*p){ptr=get(p);} void Do(t_type_func_param*p){ptr=get(p);} void Do(t_expr_func_param*p){ptr=get(p);}
        };
        template<class TYPE>
        static TYPE*UberCast(i_func_param*p){
          if(!p)return nullptr;Is<TYPE,i_func_param_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
    
      struct i_func_param{
  typedef t_type_expr OwnerClass;;
  typedef i_func_param SelfClass;;
  
    void DoReset();
  
    i_func_param(const i_func_param&)=delete;i_func_param();;
  
    i_func_param(i_func_param&&_Right);
    void operator=(i_func_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      
        typedef i_func_param_visitor i_visitor;virtual void Use(i_visitor&A);
      virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    
      struct i_typeexpr;
       struct t_impl_typeexpr; struct t_decl_typeexpr;
      struct i_typeexpr_visitor{
      
        typedef t_type_expr::i_typeexpr i_typeexpr;
      
         virtual void Do(t_impl_typeexpr*p)=0; virtual void Do(t_decl_typeexpr*p)=0;
      
         typedef t_type_expr::t_impl_typeexpr t_impl_typeexpr; typedef t_type_expr::t_decl_typeexpr t_decl_typeexpr;
      
        template<class TYPE,class Visitor>
        struct Is:public Visitor{
          TYPE*ptr;
          Is():ptr(nullptr){}
        
          template<class U>static TYPE*get(U*p){return nullptr;}
          template<>static TYPE*get<TYPE>(TYPE*p){return p;}
        
           void Do(t_impl_typeexpr*p){ptr=get(p);} void Do(t_decl_typeexpr*p){ptr=get(p);}
        };
        template<class TYPE>
        static TYPE*UberCast(i_typeexpr*p){
          if(!p)return nullptr;Is<TYPE,i_typeexpr_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
    
      struct i_typeexpr{
  typedef t_type_expr OwnerClass;;
  typedef i_typeexpr SelfClass;;
  
    void DoReset();
  
    i_typeexpr(const i_typeexpr&)=delete;i_typeexpr();;
  
    i_typeexpr(i_typeexpr&&_Right);
    void operator=(i_typeexpr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      
        typedef i_typeexpr_visitor i_visitor;virtual void Use(i_visitor&A);
      virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
      struct t_type_expr_with_sep_and_cv{
  typedef t_type_expr OwnerClass;;
  typedef t_type_expr_with_sep_and_cv SelfClass;;
  
   vector<t_const_with_sep> cvs;; TAutoPtr<t_type_expr> body;;
    void DoReset();
  
    t_type_expr_with_sep_and_cv(const t_type_expr_with_sep_and_cv&)=delete;t_type_expr_with_sep_and_cv();;
  
    t_type_expr_with_sep_and_cv(t_type_expr_with_sep_and_cv&&_Right);
    void operator=(t_type_expr_with_sep_and_cv&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_name_part{
  typedef t_type_expr OwnerClass;;
  typedef t_name_part SelfClass;;
  
   TAutoPtr<i_name_part> body;;
    void DoReset();
  
    t_name_part(const t_name_part&)=delete;t_name_part();;
  
    t_name_part(t_name_part&&_Right);
    void operator=(t_name_part&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_arr_body{
  typedef t_type_expr OwnerClass;;
  typedef t_arr_body SelfClass;;
  
   t_sep sep0;; t_sep sep1;; t_expr expr;; t_sep sep2;; t_sep sep3;;
    void DoReset();
  
    t_arr_body(const t_arr_body&)=delete;t_arr_body();;
  
    t_arr_body(t_arr_body&&_Right);
    void operator=(t_arr_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_raw_name_part:public i_name_part{
  typedef t_type_expr OwnerClass;;
  typedef t_raw_name_part SelfClass;typedef i_name_part ParentClass;;
  
   string name;;
    void DoReset();
  
    t_raw_name_part(const t_raw_name_part&)=delete;t_raw_name_part();;
  
    t_raw_name_part(t_raw_name_part&&_Right);
    void operator=(t_raw_name_part&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      };
      struct t_brackets_name_part:public i_name_part{
      
        struct i_part;
         struct t_amp_part; struct t_star_part;
        struct i_part_visitor{
        
          typedef t_brackets_name_part::i_part i_part;
        
           virtual void Do(t_amp_part*p)=0; virtual void Do(t_star_part*p)=0;
        
           typedef t_brackets_name_part::t_amp_part t_amp_part; typedef t_brackets_name_part::t_star_part t_star_part;
        
          template<class TYPE,class Visitor>
          struct Is:public Visitor{
            TYPE*ptr;
            Is():ptr(nullptr){}
          
            template<class U>static TYPE*get(U*p){return nullptr;}
            template<>static TYPE*get<TYPE>(TYPE*p){return p;}
          
             void Do(t_amp_part*p){ptr=get(p);} void Do(t_star_part*p){ptr=get(p);}
          };
          template<class TYPE>
          static TYPE*UberCast(i_part*p){
            if(!p)return nullptr;Is<TYPE,i_part_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
      
        struct i_part{
  typedef t_brackets_name_part OwnerClass;;
  typedef i_part SelfClass;;
  
    void DoReset();
  
    i_part(const i_part&)=delete;i_part();;
  
    i_part(i_part&&_Right);
    void operator=(i_part&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        
          typedef i_part_visitor i_visitor;virtual void Use(i_visitor&A);
        virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        struct t_amp{
  typedef t_brackets_name_part OwnerClass;;
  typedef t_amp SelfClass;;
  
   string body;;
    void DoReset();
  
    t_amp(const t_amp&)=delete;t_amp();;
  
    t_amp(t_amp&&_Right);
    void operator=(t_amp&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        bool go(i_dev&dev);
        };
        struct t_amp_part:public i_part{
  typedef t_brackets_name_part OwnerClass;;
  typedef t_amp_part SelfClass;typedef i_part ParentClass;;
  
   t_amp body;;
    void DoReset();
  
    t_amp_part(const t_amp_part&)=delete;t_amp_part();;
  
    t_amp_part(t_amp_part&&_Right);
    void operator=(t_amp_part&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        bool go(i_dev&dev);
        };
        struct t_star_part:public i_part{
  typedef t_brackets_name_part OwnerClass;;
  typedef t_star_part SelfClass;typedef i_part ParentClass;;
  
   string stars;; TAutoPtr<t_amp> amp;;
    void DoReset();
  
    t_star_part(const t_star_part&)=delete;t_star_part();;
  
    t_star_part(t_star_part&&_Right);
    void operator=(t_star_part&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        bool go(i_dev&dev);
        };
      
  typedef t_type_expr OwnerClass;;
  typedef t_brackets_name_part SelfClass;typedef i_name_part ParentClass;;
  
   TAutoPtr<i_part> stamp_part;; t_sep sep;; TAutoPtr<t_name_part> namepart;; TAutoPtr<t_arr_body> arrbody;;
    void DoReset();
  
    t_brackets_name_part(const t_brackets_name_part&)=delete;t_brackets_name_part();;
  
    t_brackets_name_part(t_brackets_name_part&&_Right);
    void operator=(t_brackets_name_part&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      
      };
      struct t_func_param_value{
  typedef t_type_expr OwnerClass;;
  typedef t_func_param_value SelfClass;;
  
   t_sep sep;; t_expr value;;
    void DoReset();
  
    t_func_param_value(const t_func_param_value&)=delete;t_func_param_value();;
  
    t_func_param_value(t_func_param_value&&_Right);
    void operator=(t_func_param_value&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_func_param{
  typedef t_type_expr OwnerClass;;
  typedef t_func_param SelfClass;;
  
   t_sep sep0;; TAutoPtr<i_func_param> body;; t_sep sep1;; TAutoPtr<t_func_param_value> value;; t_sep sep2;;
    void DoReset();
  
    t_func_param(const t_func_param&)=delete;t_func_param();;
  
    t_func_param(t_func_param&&_Right);
    void operator=(t_func_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_func_params{
  typedef t_type_expr OwnerClass;;
  typedef t_func_params SelfClass;;
  
   t_sep sep;; vector<t_func_param> arr;;
    void DoReset();
  
    t_func_params(const t_func_params&)=delete;t_func_params();;
  
    t_func_params(t_func_params&&_Right);
    void operator=(t_func_params&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_pfunc{
      
        struct t_addr{
  typedef t_pfunc OwnerClass;;
  typedef t_addr SelfClass;;
  
   t_type_expr_with_sep_and_cv type;;
    void DoReset();
  
    t_addr(const t_addr&)=delete;t_addr();;
  
    t_addr(t_addr&&_Right);
    void operator=(t_addr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        bool go(i_dev&dev);
        };
      
  typedef t_type_expr OwnerClass;;
  typedef t_pfunc SelfClass;;
  
   t_type_expr_with_sep_and_cv type;; t_addr addr;; string name;; t_func_params params;;
    void DoReset();
  
    t_pfunc(const t_pfunc&)=delete;t_pfunc();;
  
    t_pfunc(t_pfunc&&_Right);
    void operator=(t_pfunc&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_pfunc_func_param:public i_func_param{
  typedef t_type_expr OwnerClass;;
  typedef t_pfunc_func_param SelfClass;typedef i_func_param ParentClass;;
  
   t_pfunc value;;
    void DoReset();
  
    t_pfunc_func_param(const t_pfunc_func_param&)=delete;t_pfunc_func_param();;
  
    t_pfunc_func_param(t_pfunc_func_param&&_Right);
    void operator=(t_pfunc_func_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      };
      struct t_var_args_func_param:public i_func_param{
  typedef t_type_expr OwnerClass;;
  typedef t_var_args_func_param SelfClass;typedef i_func_param ParentClass;;
  
    void DoReset();
  
    t_var_args_func_param(const t_var_args_func_param&)=delete;t_var_args_func_param();;
  
    t_var_args_func_param(t_var_args_func_param&&_Right);
    void operator=(t_var_args_func_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      };
      struct t_type_func_param:public i_func_param{
      
        struct t_const{
  typedef t_type_func_param OwnerClass;;
  typedef t_const SelfClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_const(const t_const&)=delete;t_const();;
  
    t_const(t_const&&_Right);
    void operator=(t_const&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        bool go(i_dev&dev);
        };
      
  typedef t_type_expr OwnerClass;;
  typedef t_type_func_param SelfClass;typedef i_func_param ParentClass;;
  
   t_type_expr_with_sep_and_cv type;; t_sep sep;; TAutoPtr<t_const> cv;; TAutoPtr<t_name_part> namepart;;
    void DoReset();
  
    t_type_func_param(const t_type_func_param&)=delete;t_type_func_param();;
  
    t_type_func_param(t_type_func_param&&_Right);
    void operator=(t_type_func_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      };
      struct t_expr_func_param:public i_func_param{
  typedef t_type_expr OwnerClass;;
  typedef t_expr_func_param SelfClass;typedef i_func_param ParentClass;;
  
   t_expr body;;
    void DoReset();
  
    t_expr_func_param(const t_expr_func_param&)=delete;t_expr_func_param();;
  
    t_expr_func_param(t_expr_func_param&&_Right);
    void operator=(t_expr_func_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      };
      struct t_fv_stat{
      
        struct i_fv_body;
         struct t_impl_func_body; struct t_zero_func_body; struct t_delete_func_body;
        struct i_fv_body_visitor{
        
          typedef t_fv_stat::i_fv_body i_fv_body;
        
           virtual void Do(t_impl_func_body*p)=0; virtual void Do(t_zero_func_body*p)=0; virtual void Do(t_delete_func_body*p)=0;
        
           typedef t_fv_stat::t_impl_func_body t_impl_func_body; typedef t_fv_stat::t_zero_func_body t_zero_func_body; typedef t_fv_stat::t_delete_func_body t_delete_func_body;
        
          template<class TYPE,class Visitor>
          struct Is:public Visitor{
            TYPE*ptr;
            Is():ptr(nullptr){}
          
            template<class U>static TYPE*get(U*p){return nullptr;}
            template<>static TYPE*get<TYPE>(TYPE*p){return p;}
          
             void Do(t_impl_func_body*p){ptr=get(p);} void Do(t_zero_func_body*p){ptr=get(p);} void Do(t_delete_func_body*p){ptr=get(p);}
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_body*p){
            if(!p)return nullptr;Is<TYPE,i_fv_body_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
      
        struct i_fv_body{
  typedef t_fv_stat OwnerClass;;
  typedef i_fv_body SelfClass;;
  
    void DoReset();
  
    i_fv_body(const i_fv_body&)=delete;i_fv_body();;
  
    i_fv_body(i_fv_body&&_Right);
    void operator=(i_fv_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        
          typedef i_fv_body_visitor i_visitor;virtual void Use(i_visitor&A);
        virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
      
        struct i_fv_end;
         struct t_func_fv_end; struct t_var_fv_end;
        struct i_fv_end_visitor{
        
          typedef t_fv_stat::i_fv_end i_fv_end;
        
           virtual void Do(t_func_fv_end*p)=0; virtual void Do(t_var_fv_end*p)=0;
        
           typedef t_fv_stat::t_func_fv_end t_func_fv_end; typedef t_fv_stat::t_var_fv_end t_var_fv_end;
        
          template<class TYPE,class Visitor>
          struct Is:public Visitor{
            TYPE*ptr;
            Is():ptr(nullptr){}
          
            template<class U>static TYPE*get(U*p){return nullptr;}
            template<>static TYPE*get<TYPE>(TYPE*p){return p;}
          
             void Do(t_func_fv_end*p){ptr=get(p);} void Do(t_var_fv_end*p){ptr=get(p);}
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_end*p){
            if(!p)return nullptr;Is<TYPE,i_fv_end_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
      
        struct i_fv_end{
  typedef t_fv_stat OwnerClass;;
  typedef i_fv_end SelfClass;;
  
    void DoReset();
  
    i_fv_end(const i_fv_end&)=delete;i_fv_end();;
  
    i_fv_end(i_fv_end&&_Right);
    void operator=(i_fv_end&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        
          typedef i_fv_end_visitor i_visitor;virtual void Use(i_visitor&A);
        virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        struct t_impl_func_body:public i_fv_body{
  typedef t_fv_stat OwnerClass;;
  typedef t_impl_func_body SelfClass;typedef i_fv_body ParentClass;;
  
   t_sep sep;; t_raw_func_body body;;
    void DoReset();
  
    t_impl_func_body(const t_impl_func_body&)=delete;t_impl_func_body();;
  
    t_impl_func_body(t_impl_func_body&&_Right);
    void operator=(t_impl_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        bool go(i_dev&dev);
        };
        struct t_zero_func_body:public i_fv_body{
  typedef t_fv_stat OwnerClass;;
  typedef t_zero_func_body SelfClass;typedef i_fv_body ParentClass;;
  
    void DoReset();
  
    t_zero_func_body(const t_zero_func_body&)=delete;t_zero_func_body();;
  
    t_zero_func_body(t_zero_func_body&&_Right);
    void operator=(t_zero_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        bool go(i_dev&dev);
        };
        struct t_delete_func_body:public i_fv_body{
  typedef t_fv_stat OwnerClass;;
  typedef t_delete_func_body SelfClass;typedef i_fv_body ParentClass;;
  
    void DoReset();
  
    t_delete_func_body(const t_delete_func_body&)=delete;t_delete_func_body();;
  
    t_delete_func_body(t_delete_func_body&&_Right);
    void operator=(t_delete_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        bool go(i_dev&dev);
        };
        struct t_func_fv_end:public i_fv_end{
  typedef t_fv_stat OwnerClass;;
  typedef t_func_fv_end SelfClass;typedef i_fv_end ParentClass;;
  
   TAutoPtr<t_func_params> params;; TAutoPtr<t_const_with_sep> cv1;; t_sep sep1;; TAutoPtr<i_fv_body> body;;
    void DoReset();
  
    t_func_fv_end(const t_func_fv_end&)=delete;t_func_fv_end();;
  
    t_func_fv_end(t_func_fv_end&&_Right);
    void operator=(t_func_fv_end&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        bool go(i_dev&dev);
        };
        struct t_var_fv_end:public i_fv_end{
        
          struct i_fv_item;
           struct t_func_fv_item; struct t_var_fv_item;
          struct i_fv_item_visitor{
          
            typedef t_var_fv_end::i_fv_item i_fv_item;
          
             virtual void Do(t_func_fv_item*p)=0; virtual void Do(t_var_fv_item*p)=0;
          
             typedef t_var_fv_end::t_func_fv_item t_func_fv_item; typedef t_var_fv_end::t_var_fv_item t_var_fv_item;
          
            template<class TYPE,class Visitor>
            struct Is:public Visitor{
              TYPE*ptr;
              Is():ptr(nullptr){}
            
              template<class U>static TYPE*get(U*p){return nullptr;}
              template<>static TYPE*get<TYPE>(TYPE*p){return p;}
            
               void Do(t_func_fv_item*p){ptr=get(p);} void Do(t_var_fv_item*p){ptr=get(p);}
            };
            template<class TYPE>
            static TYPE*UberCast(i_fv_item*p){
              if(!p)return nullptr;Is<TYPE,i_fv_item_visitor> IS;p->Use(IS);return IS.ptr;
            }
          };
        
          struct i_fv_item{
  typedef t_var_fv_end OwnerClass;;
  typedef i_fv_item SelfClass;;
  
    void DoReset();
  
    i_fv_item(const i_fv_item&)=delete;i_fv_item();;
  
    i_fv_item(i_fv_item&&_Right);
    void operator=(i_fv_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
          
            typedef i_fv_item_visitor i_visitor;virtual void Use(i_visitor&A);
          virtual bool go(i_dev&dev);;
            struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
            {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
            };
          };
          struct t_func_fv_item:public i_fv_item{
  typedef t_var_fv_end OwnerClass;;
  typedef t_func_fv_item SelfClass;typedef i_fv_item ParentClass;;
  
   TAutoPtr<t_func_params> params;; TAutoPtr<t_const_with_sep> cv1;;
    void DoReset();
  
    t_func_fv_item(const t_func_fv_item&)=delete;t_func_fv_item();;
  
    t_func_fv_item(t_func_fv_item&&_Right);
    void operator=(t_func_fv_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
          void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
          bool go(i_dev&dev);
          };
          struct t_var_fv_item:public i_fv_item{
  typedef t_var_fv_end OwnerClass;;
  typedef t_var_fv_item SelfClass;typedef i_fv_item ParentClass;;
  
   TAutoPtr<t_arr_body> arrbody;; TAutoPtr<t_func_param_value> value;;
    void DoReset();
  
    t_var_fv_item(const t_var_fv_item&)=delete;t_var_fv_item();;
  
    t_var_fv_item(t_var_fv_item&&_Right);
    void operator=(t_var_fv_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
          void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
          bool go(i_dev&dev);
          };
          struct t_body{
  typedef t_var_fv_end OwnerClass;;
  typedef t_body SelfClass;;
  
   TAutoPtr<i_fv_item> body;;
    void DoReset();
  
    t_body(const t_body&)=delete;t_body();;
  
    t_body(t_body&&_Right);
    void operator=(t_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
          bool go(i_dev&dev);
          };
          struct t_item{
  typedef t_var_fv_end OwnerClass;;
  typedef t_item SelfClass;;
  
   t_sep sep0;; TAutoPtr<t_const_with_sep> cv;; t_sep sep1;; string name;; t_sep sep2;; t_body body;; t_sep sep3;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
          bool go(i_dev&dev);
          };
        
  typedef t_fv_stat OwnerClass;;
  typedef t_var_fv_end SelfClass;typedef i_fv_end ParentClass;;
  
   TAutoPtr<t_body> body;; vector<t_item> arr;;
    void DoReset();
  
    t_var_fv_end(const t_var_fv_end&)=delete;t_var_fv_end();;
  
    t_var_fv_end(t_var_fv_end&&_Right);
    void operator=(t_var_fv_end&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        bool go(i_dev&dev);
        
        };
      
  typedef t_type_expr OwnerClass;;
  typedef t_fv_stat SelfClass;;
  
   t_sep sep_wa;; vector<t_keyword> keywords;; TAutoPtr<t_type_expr> type;; TAutoPtr<t_const_with_sep> cv;; t_sep sep0;; TAutoPtr<t_func_path> path;; t_name_part name;; t_sep sep1;; TAutoPtr<i_fv_end> way;;
    void DoReset();
  
    t_fv_stat(const t_fv_stat&)=delete;t_fv_stat();;
  
    t_fv_stat(t_fv_stat&&_Right);
    void operator=(t_fv_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      
      };
      struct t_impl_typeexpr:public i_typeexpr{
      
        struct t_global{
  typedef t_impl_typeexpr OwnerClass;;
  typedef t_global SelfClass;;
  
    void DoReset();
  
    t_global(const t_global&)=delete;t_global();;
  
    t_global(t_global&&_Right);
    void operator=(t_global&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
        bool go(i_dev&dev);
        };
      
  typedef t_type_expr OwnerClass;;
  typedef t_impl_typeexpr SelfClass;typedef i_typeexpr ParentClass;;
  
   TAutoPtr<t_global> global;; t_sep sep;; t_scopes scopes;; vector<t_ptr> ptrs;; TAutoPtr<t_ref> ref;;
    void DoReset();
  
    t_impl_typeexpr(const t_impl_typeexpr&)=delete;t_impl_typeexpr();;
  
    t_impl_typeexpr(t_impl_typeexpr&&_Right);
    void operator=(t_impl_typeexpr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      };
      struct t_decl_typeexpr:public i_typeexpr{
  typedef t_type_expr OwnerClass;;
  typedef t_decl_typeexpr SelfClass;typedef i_typeexpr ParentClass;;
  
   t_sep sep0;; t_sep sep1;; t_expr expr;; t_sep sep2;;
    void DoReset();
  
    t_decl_typeexpr(const t_decl_typeexpr&)=delete;t_decl_typeexpr();;
  
    t_decl_typeexpr(t_decl_typeexpr&&_Right);
    void operator=(t_decl_typeexpr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      bool go(i_dev&dev);
      };
    
  typedef t_fv_class_stat OwnerClass;;
  typedef t_type_expr SelfClass;;
  
   TAutoPtr<i_typeexpr> body;;
    void DoReset();
  
    t_type_expr(const t_type_expr&)=delete;t_type_expr();;
  
    t_type_expr(t_type_expr&&_Right);
    void operator=(t_type_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_fv_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_type_expr::t_fv_stat body;;
    void DoReset();
  
    t_fv_class_stat(const t_fv_class_stat&)=delete;t_fv_class_stat();;
  
    t_fv_class_stat(t_fv_class_stat&&_Right);
    void operator=(t_fv_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_typedef_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_typedef_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_sep sep;; t_fv_class_stat::t_type_expr::t_fv_stat body;;
    void DoReset();
  
    t_typedef_class_stat(const t_typedef_class_stat&)=delete;t_typedef_class_stat();;
  
    t_typedef_class_stat(t_typedef_class_stat&&_Right);
    void operator=(t_typedef_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_real{
  
    struct t_f{
  typedef t_real OwnerClass;;
  typedef t_f SelfClass;;
  
   char body;;
    void DoReset();
  
    t_f(const t_f&)=delete;t_f();;
  
    t_f(t_f&&_Right);
    void operator=(t_f&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_real SelfClass;;
  
   string bef;; string aft;; TAutoPtr<t_f> ext;;
    void DoReset();
  
    t_real(const t_real&)=delete;t_real();;
  
    t_real(t_real&&_Right);
    void operator=(t_real&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_call_param{
  typedef t_inl_file OwnerClass;;
  typedef t_call_param SelfClass;;
  
   t_sep sep0;; t_expr expr;; t_sep sep1;;
    void DoReset();
  
    t_call_param(const t_call_param&)=delete;t_call_param();;
  
    t_call_param(t_call_param&&_Right);
    void operator=(t_call_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_call_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_call_expr SelfClass;typedef i_expr ParentClass;;
  
   string func;; t_sep sep;; vector<t_call_param> arr;;
    void DoReset();
  
    t_call_expr(const t_call_expr&)=delete;t_call_expr();;
  
    t_call_expr(t_call_expr&&_Right);
    void operator=(t_call_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_block_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_block_expr SelfClass;typedef i_expr ParentClass;;
  
   t_sep sep0;; t_expr expr;; t_sep sep1;;
    void DoReset();
  
    t_block_expr(const t_block_expr&)=delete;t_block_expr();;
  
    t_block_expr(t_block_expr&&_Right);
    void operator=(t_block_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_bool_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_bool_expr SelfClass;typedef i_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_bool_expr(const t_bool_expr&)=delete;t_bool_expr();;
  
    t_bool_expr(t_bool_expr&&_Right);
    void operator=(t_bool_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_string_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_string_expr SelfClass;typedef i_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_string_expr(const t_string_expr&)=delete;t_string_expr();;
  
    t_string_expr(t_string_expr&&_Right);
    void operator=(t_string_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_char_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_char_expr SelfClass;typedef i_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_char_expr(const t_char_expr&)=delete;t_char_expr();;
  
    t_char_expr(t_char_expr&&_Right);
    void operator=(t_char_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_num_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_num_expr SelfClass;typedef i_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_num_expr(const t_num_expr&)=delete;t_num_expr();;
  
    t_num_expr(t_num_expr&&_Right);
    void operator=(t_num_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_real_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_real_expr SelfClass;typedef i_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_real_expr(const t_real_expr&)=delete;t_real_expr();;
  
    t_real_expr(t_real_expr&&_Right);
    void operator=(t_real_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_nullptr_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_nullptr_expr SelfClass;typedef i_expr ParentClass;;
  
    void DoReset();
  
    t_nullptr_expr(const t_nullptr_expr&)=delete;t_nullptr_expr();;
  
    t_nullptr_expr(t_nullptr_expr&&_Right);
    void operator=(t_nullptr_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_or_expr:public i_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_or_expr SelfClass;typedef i_expr ParentClass;;
  
   vector<t_name> arr;;
    void DoReset();
  
    t_or_expr(const t_or_expr&)=delete;t_or_expr();;
  
    t_or_expr(t_or_expr&&_Right);
    void operator=(t_or_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_hex_expr:public i_expr{
  
    struct t_impl{
  typedef t_hex_expr OwnerClass;;
  typedef t_impl SelfClass;;
  
   char x;; string value;;
    void DoReset();
  
    t_impl(const t_impl&)=delete;t_impl();;
  
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_hex_expr SelfClass;typedef i_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_hex_expr(const t_hex_expr&)=delete;t_hex_expr();;
  
    t_hex_expr(t_hex_expr&&_Right);
    void operator=(t_hex_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_var_expr:public i_expr{
  
    struct t_item{
  typedef t_var_expr OwnerClass;;
  typedef t_item SelfClass;;
  
   t_type_with_sep body;; t_sep sep;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_field{
  typedef t_var_expr OwnerClass;;
  typedef t_field SelfClass;;
  
   t_sep bef;; string name;; t_sep aft;;
    void DoReset();
  
    t_field(const t_field&)=delete;t_field();;
  
    t_field(t_field&&_Right);
    void operator=(t_field&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_impl{
  typedef t_var_expr OwnerClass;;
  typedef t_impl SelfClass;;
  
   vector<t_item> items;; t_sep sep;; vector<t_field> arr;;
    void DoReset();
  
    t_impl(const t_impl&)=delete;t_impl();;
  
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_var_expr SelfClass;typedef i_expr ParentClass;;
  
   string name;;
    void DoReset();
  
    t_var_expr(const t_var_expr&)=delete;t_var_expr();;
  
    t_var_expr(t_var_expr&&_Right);
    void operator=(t_var_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  
  };
  struct t_ctor_init_list{
  
    struct t_init_param{
  typedef t_ctor_init_list OwnerClass;;
  typedef t_init_param SelfClass;;
  
   t_sep sep0;; string name;; vector<t_call_param> arr;; t_sep sep1;;
    void DoReset();
  
    t_init_param(const t_init_param&)=delete;t_init_param();;
  
    t_init_param(t_init_param&&_Right);
    void operator=(t_init_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_ctor_init_list SelfClass;;
  
   vector<t_init_param> params;; t_sep sep;;
    void DoReset();
  
    t_ctor_init_list(const t_ctor_init_list&)=delete;t_ctor_init_list();;
  
    t_ctor_init_list(t_ctor_init_list&&_Right);
    void operator=(t_ctor_init_list&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_zero_func_body:public i_func_body{
  typedef t_inl_file OwnerClass;;
  typedef t_zero_func_body SelfClass;typedef i_func_body ParentClass;;
  
    void DoReset();
  
    t_zero_func_body(const t_zero_func_body&)=delete;t_zero_func_body();;
  
    t_zero_func_body(t_zero_func_body&&_Right);
    void operator=(t_zero_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_null_func_body:public i_func_body{
  typedef t_inl_file OwnerClass;;
  typedef t_null_func_body SelfClass;typedef i_func_body ParentClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_null_func_body(const t_null_func_body&)=delete;t_null_func_body();;
  
    t_null_func_body(t_null_func_body&&_Right);
    void operator=(t_null_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_delete_func_body:public i_func_body{
  typedef t_inl_file OwnerClass;;
  typedef t_delete_func_body SelfClass;typedef i_func_body ParentClass;;
  
    void DoReset();
  
    t_delete_func_body(const t_delete_func_body&)=delete;t_delete_func_body();;
  
    t_delete_func_body(t_delete_func_body&&_Right);
    void operator=(t_delete_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_impl_func_body:public i_func_body{
  typedef t_inl_file OwnerClass;;
  typedef t_impl_func_body SelfClass;typedef i_func_body ParentClass;;
  
   t_sep sep;; TAutoPtr<t_ctor_init_list> init_list;; t_raw_func_body body;;
    void DoReset();
  
    t_impl_func_body(const t_impl_func_body&)=delete;t_impl_func_body();;
  
    t_impl_func_body(t_impl_func_body&&_Right);
    void operator=(t_impl_func_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_dtor_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_dtor_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_sep sep0;; TAutoPtr<t_func_path> path;; string name;; t_sep sep1;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<i_func_body> body;;
    void DoReset();
  
    t_dtor_class_stat(const t_dtor_class_stat&)=delete;t_dtor_class_stat();;
  
    t_dtor_class_stat(t_dtor_class_stat&&_Right);
    void operator=(t_dtor_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_ctor_class_stat:public i_class_stat{
  
    struct t_impl{
    
      struct t_explicit{
  typedef t_impl OwnerClass;;
  typedef t_explicit SelfClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_explicit(const t_explicit&)=delete;t_explicit();;
  
    t_explicit(t_explicit&&_Right);
    void operator=(t_explicit&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
    
  typedef t_ctor_class_stat OwnerClass;;
  typedef t_impl SelfClass;;
  
   TAutoPtr<t_explicit> prefix;; TAutoPtr<t_func_path> path;; string name;; t_sep sep1;; TAutoPtr<t_concrete_params> concrete_params;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<i_func_body> body;;
    void DoReset();
  
    t_impl(const t_impl&)=delete;t_impl();;
  
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_ctor_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_impl body;;
    void DoReset();
  
    t_ctor_class_stat(const t_ctor_class_stat&)=delete;t_ctor_class_stat();;
  
    t_ctor_class_stat(t_ctor_class_stat&&_Right);
    void operator=(t_ctor_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_oper_cast_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_oper_cast_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   TAutoPtr<t_func_path> path;; t_sep sep0;; t_fv_class_stat::t_type_expr type;; t_sep sep1;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<t_const_with_sep> cv;; TAutoPtr<i_func_body> body;;
    void DoReset();
  
    t_oper_cast_class_stat(const t_oper_cast_class_stat&)=delete;t_oper_cast_class_stat();;
  
    t_oper_cast_class_stat(t_oper_cast_class_stat&&_Right);
    void operator=(t_oper_cast_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_common_oper_class_stat:public i_class_stat{
  
    struct t_impl{
  typedef t_common_oper_class_stat OwnerClass;;
  typedef t_impl SelfClass;;
  
   vector<t_keyword> keywords;; t_fv_class_stat::t_type_expr type;; TAutoPtr<t_const_with_sep> cv0;; t_sep sep0;; TAutoPtr<t_func_path> path;; t_sep sep1;; string oper;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<t_const_with_sep> cv1;; TAutoPtr<i_func_body> body;;
    void DoReset();
  
    t_impl(const t_impl&)=delete;t_impl();;
  
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_common_oper_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_impl body;;
    void DoReset();
  
    t_common_oper_class_stat(const t_common_oper_class_stat&)=delete;t_common_oper_class_stat();;
  
    t_common_oper_class_stat(t_common_oper_class_stat&&_Right);
    void operator=(t_common_oper_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_parents{
  
    struct t_item{
    
      struct t_pub{
  typedef t_item OwnerClass;;
  typedef t_pub SelfClass;;
  
   t_access_mod mod;; t_sep sep;;
    void DoReset();
  
    t_pub(const t_pub&)=delete;t_pub();;
  
    t_pub(t_pub&&_Right);
    void operator=(t_pub&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
    
  typedef t_parents OwnerClass;;
  typedef t_item SelfClass;;
  
   t_sep sep;; TAutoPtr<t_pub> pub;; string name;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_parents SelfClass;;
  
   t_sep sep;; vector<t_item> arr;;
    void DoReset();
  
    t_parents(const t_parents&)=delete;t_parents();;
  
    t_parents(t_parents&&_Right);
    void operator=(t_parents&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_class_body{
  typedef t_inl_file OwnerClass;;
  typedef t_class_body SelfClass;;
  
   vector<TAutoPtr<i_class_stat>> arr;;
    void DoReset();
  
    t_class_body(const t_class_body&)=delete;t_class_body();;
  
    t_class_body(t_class_body&&_Right);
    void operator=(t_class_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_class{
  typedef t_inl_file OwnerClass;;
  typedef t_class SelfClass;;
  
   string keyword;; t_sep sep0;; string name;; t_sep sep1;; TAutoPtr<t_parents> parents;; t_sep sep2;; TAutoPtr<t_class_body> body;; t_sep sep3;;
    void DoReset();
  
    t_class(const t_class&)=delete;t_class();;
  
    t_class(t_class&&_Right);
    void operator=(t_class&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_namespace_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_namespace_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_sep sep0;; string name;; t_sep sep1;; t_class_body body;;
    void DoReset();
  
    t_namespace_class_stat(const t_namespace_class_stat&)=delete;t_namespace_class_stat();;
  
    t_namespace_class_stat(t_namespace_class_stat&&_Right);
    void operator=(t_namespace_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_template_class_stat:public i_class_stat{
  
    struct i_template_body;
     struct t_common_oper_template_body; struct t_ctor_template_body; struct t_func_template_body; struct class_template_body;
    struct i_template_body_visitor{
    
      typedef t_template_class_stat::i_template_body i_template_body;
    
       virtual void Do(t_common_oper_template_body*p)=0; virtual void Do(t_ctor_template_body*p)=0; virtual void Do(t_func_template_body*p)=0; virtual void Do(class_template_body*p)=0;
    
       typedef t_template_class_stat::t_common_oper_template_body t_common_oper_template_body; typedef t_template_class_stat::t_ctor_template_body t_ctor_template_body; typedef t_template_class_stat::t_func_template_body t_func_template_body; typedef t_template_class_stat::class_template_body class_template_body;
    
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      
         void Do(t_common_oper_template_body*p){ptr=get(p);} void Do(t_ctor_template_body*p){ptr=get(p);} void Do(t_func_template_body*p){ptr=get(p);} void Do(class_template_body*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_body*p){
        if(!p)return nullptr;Is<TYPE,i_template_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  
    struct i_template_body{
  typedef t_template_class_stat OwnerClass;;
  typedef i_template_body SelfClass;;
  
    void DoReset();
  
    i_template_body(const i_template_body&)=delete;i_template_body();;
  
    i_template_body(i_template_body&&_Right);
    void operator=(i_template_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    
      typedef i_template_body_visitor i_visitor;virtual void Use(i_visitor&A);
    virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
  
    struct i_template_param;
     struct t_name_template_param; struct t_type_template_param;
    struct i_template_param_visitor{
    
      typedef t_template_class_stat::i_template_param i_template_param;
    
       virtual void Do(t_name_template_param*p)=0; virtual void Do(t_type_template_param*p)=0;
    
       typedef t_template_class_stat::t_name_template_param t_name_template_param; typedef t_template_class_stat::t_type_template_param t_type_template_param;
    
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      
         void Do(t_name_template_param*p){ptr=get(p);} void Do(t_type_template_param*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_param*p){
        if(!p)return nullptr;Is<TYPE,i_template_param_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  
    struct i_template_param{
  typedef t_template_class_stat OwnerClass;;
  typedef i_template_param SelfClass;;
  
    void DoReset();
  
    i_template_param(const i_template_param&)=delete;i_template_param();;
  
    i_template_param(i_template_param&&_Right);
    void operator=(i_template_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    
      typedef i_template_param_visitor i_visitor;virtual void Use(i_visitor&A);
    virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    struct t_template_param{
  typedef t_template_class_stat OwnerClass;;
  typedef t_template_param SelfClass;;
  
   t_sep bef;; TAutoPtr<i_template_param> body;; t_sep aft;;
    void DoReset();
  
    t_template_param(const t_template_param&)=delete;t_template_param();;
  
    t_template_param(t_template_param&&_Right);
    void operator=(t_template_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_common_oper_template_body:public i_template_body{
  typedef t_template_class_stat OwnerClass;;
  typedef t_common_oper_template_body SelfClass;typedef i_template_body ParentClass;;
  
   t_common_oper_class_stat::t_impl body;;
    void DoReset();
  
    t_common_oper_template_body(const t_common_oper_template_body&)=delete;t_common_oper_template_body();;
  
    t_common_oper_template_body(t_common_oper_template_body&&_Right);
    void operator=(t_common_oper_template_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_ctor_template_body:public i_template_body{
  typedef t_template_class_stat OwnerClass;;
  typedef t_ctor_template_body SelfClass;typedef i_template_body ParentClass;;
  
   t_ctor_class_stat::t_impl body;;
    void DoReset();
  
    t_ctor_template_body(const t_ctor_template_body&)=delete;t_ctor_template_body();;
  
    t_ctor_template_body(t_ctor_template_body&&_Right);
    void operator=(t_ctor_template_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_func_template_body:public i_template_body{
  typedef t_template_class_stat OwnerClass;;
  typedef t_func_template_body SelfClass;typedef i_template_body ParentClass;;
  
   vector<t_keyword> keywords;; t_fv_class_stat::t_type_expr type;; TAutoPtr<t_const_with_sep> cv0;; t_sep sep0;; string func_name;; TAutoPtr<t_concrete_params> concrete_params;; t_sep sep1;; t_fv_class_stat::t_type_expr::t_func_params params;; t_sep sep2;; TAutoPtr<t_const_with_sep> cv1;; TAutoPtr<i_func_body> body;;
    void DoReset();
  
    t_func_template_body(const t_func_template_body&)=delete;t_func_template_body();;
  
    t_func_template_body(t_func_template_body&&_Right);
    void operator=(t_func_template_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct class_template_body:public i_template_body{
  typedef t_template_class_stat OwnerClass;;
  typedef class_template_body SelfClass;typedef i_template_body ParentClass;;
  
   string keyword;; t_sep sep0;; string name;; t_sep sep1;; TAutoPtr<t_concrete_params> params;; TAutoPtr<t_parents> parents;; t_sep sep2;; TAutoPtr<t_class_body> body;; t_sep sep3;;
    void DoReset();
  
    class_template_body(const class_template_body&)=delete;class_template_body();;
  
    class_template_body(class_template_body&&_Right);
    void operator=(class_template_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_name_template_param:public i_template_param{
    
      struct t_unsgnd{
  typedef t_name_template_param OwnerClass;;
  typedef t_unsgnd SelfClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_unsgnd(const t_unsgnd&)=delete;t_unsgnd();;
  
    t_unsgnd(t_unsgnd&&_Right);
    void operator=(t_unsgnd&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
      struct t_value{
  typedef t_name_template_param OwnerClass;;
  typedef t_value SelfClass;;
  
   t_expr body;; t_sep sep;;
    void DoReset();
  
    t_value(const t_value&)=delete;t_value();;
  
    t_value(t_value&&_Right);
    void operator=(t_value&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
      bool go(i_dev&dev);
      };
    
  typedef t_template_class_stat OwnerClass;;
  typedef t_name_template_param SelfClass;typedef i_template_param ParentClass;;
  
   string unsgnd0;; t_sep sep0;; string type;; t_sep sep1;; string unsgnd1;; t_sep sep2;; string name;; t_sep sep3;; TAutoPtr<t_value> value;;
    void DoReset();
  
    t_name_template_param(const t_name_template_param&)=delete;t_name_template_param();;
  
    t_name_template_param(t_name_template_param&&_Right);
    void operator=(t_name_template_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_head{
  typedef t_template_class_stat OwnerClass;;
  typedef t_head SelfClass;;
  
   t_sep sep0;; vector<t_template_param> params;; t_sep sep1;;
    void DoReset();
  
    t_head(const t_head&)=delete;t_head();;
  
    t_head(t_head&&_Right);
    void operator=(t_head&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_type_template_param:public i_template_param{
  typedef t_template_class_stat OwnerClass;;
  typedef t_type_template_param SelfClass;typedef i_template_param ParentClass;;
  
   TAutoPtr<t_head> head;; string type;; t_sep sep;; string name;;
    void DoReset();
  
    t_type_template_param(const t_type_template_param&)=delete;t_type_template_param();;
  
    t_type_template_param(t_type_template_param&&_Right);
    void operator=(t_type_template_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_template_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_head head;; TAutoPtr<i_template_body> body;;
    void DoReset();
  
    t_template_class_stat(const t_template_class_stat&)=delete;t_template_class_stat();;
  
    t_template_class_stat(t_template_class_stat&&_Right);
    void operator=(t_template_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  
  };
  struct t_enum_class_stat:public i_class_stat{
  
    struct i_body;
     struct t_impl_body; struct t_empty_body;
    struct i_body_visitor{
    
      typedef t_enum_class_stat::i_body i_body;
    
       virtual void Do(t_impl_body*p)=0; virtual void Do(t_empty_body*p)=0;
    
       typedef t_enum_class_stat::t_impl_body t_impl_body; typedef t_enum_class_stat::t_empty_body t_empty_body;
    
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      
         void Do(t_impl_body*p){ptr=get(p);} void Do(t_empty_body*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_body*p){
        if(!p)return nullptr;Is<TYPE,i_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  
    struct i_body{
  typedef t_enum_class_stat OwnerClass;;
  typedef i_body SelfClass;;
  
    void DoReset();
  
    i_body(const i_body&)=delete;i_body();;
  
    i_body(i_body&&_Right);
    void operator=(i_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    
      typedef i_body_visitor i_visitor;virtual void Use(i_visitor&A);
    virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    struct t_value{
  typedef t_enum_class_stat OwnerClass;;
  typedef t_value SelfClass;;
  
   t_sep sep0;; t_expr expr;; t_sep sep1;;
    void DoReset();
  
    t_value(const t_value&)=delete;t_value();;
  
    t_value(t_value&&_Right);
    void operator=(t_value&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_item{
  typedef t_enum_class_stat OwnerClass;;
  typedef t_item SelfClass;;
  
   t_sep sep0;; string name;; t_sep sep1;; TAutoPtr<t_value> value;;
    void DoReset();
  
    t_item(const t_item&)=delete;t_item();;
  
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_comma_with_sep{
  typedef t_enum_class_stat OwnerClass;;
  typedef t_comma_with_sep SelfClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_comma_with_sep(const t_comma_with_sep&)=delete;t_comma_with_sep();;
  
    t_comma_with_sep(t_comma_with_sep&&_Right);
    void operator=(t_comma_with_sep&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
    struct t_impl_body:public i_body{
  typedef t_enum_class_stat OwnerClass;;
  typedef t_impl_body SelfClass;typedef i_body ParentClass;;
  
   vector<t_item> arr;; TAutoPtr<t_comma_with_sep> comma;;
    void DoReset();
  
    t_impl_body(const t_impl_body&)=delete;t_impl_body();;
  
    t_impl_body(t_impl_body&&_Right);
    void operator=(t_impl_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_empty_body:public i_body{
  typedef t_enum_class_stat OwnerClass;;
  typedef t_empty_body SelfClass;typedef i_body ParentClass;;
  
    void DoReset();
  
    t_empty_body(const t_empty_body&)=delete;t_empty_body();;
  
    t_empty_body(t_empty_body&&_Right);
    void operator=(t_empty_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    bool go(i_dev&dev);
    };
    struct t_body{
  typedef t_enum_class_stat OwnerClass;;
  typedef t_body SelfClass;;
  
   TAutoPtr<i_body> body;;
    void DoReset();
  
    t_body(const t_body&)=delete;t_body();;
  
    t_body(t_body&&_Right);
    void operator=(t_body&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_enum_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_sep sep0;; string name;; t_sep sep1;; t_body body;;
    void DoReset();
  
    t_enum_class_stat(const t_enum_class_stat&)=delete;t_enum_class_stat();;
  
    t_enum_class_stat(t_enum_class_stat&&_Right);
    void operator=(t_enum_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  
  };
  struct t_using_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_using_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_sep sep;; t_fv_class_stat::t_type_expr type;;
    void DoReset();
  
    t_using_class_stat(const t_using_class_stat&)=delete;t_using_class_stat();;
  
    t_using_class_stat(t_using_class_stat&&_Right);
    void operator=(t_using_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_tmpl_call_param{
  typedef t_inl_file OwnerClass;;
  typedef t_tmpl_call_param SelfClass;;
  
   t_sep sep0;; t_tmpl_expr expr;; t_sep sep1;;
    void DoReset();
  
    t_tmpl_call_param(const t_tmpl_call_param&)=delete;t_tmpl_call_param();;
  
    t_tmpl_call_param(t_tmpl_call_param&&_Right);
    void operator=(t_tmpl_call_param&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };
  struct t_call_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_call_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string func;; t_sep sep;; vector<t_tmpl_call_param> arr;;
    void DoReset();
  
    t_call_tmpl_expr(const t_call_tmpl_expr&)=delete;t_call_tmpl_expr();;
  
    t_call_tmpl_expr(t_call_tmpl_expr&&_Right);
    void operator=(t_call_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_block_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_block_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   t_sep sep0;; t_tmpl_expr expr;; t_sep sep1;;
    void DoReset();
  
    t_block_tmpl_expr(const t_block_tmpl_expr&)=delete;t_block_tmpl_expr();;
  
    t_block_tmpl_expr(t_block_tmpl_expr&&_Right);
    void operator=(t_block_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_pfunc_concrete_param_way:public i_concrete_param_way{
  typedef t_inl_file OwnerClass;;
  typedef t_pfunc_concrete_param_way SelfClass;typedef i_concrete_param_way ParentClass;;
  
   t_fv_class_stat::t_type_expr::t_pfunc value;;
    void DoReset();
  
    t_pfunc_concrete_param_way(const t_pfunc_concrete_param_way&)=delete;t_pfunc_concrete_param_way();;
  
    t_pfunc_concrete_param_way(t_pfunc_concrete_param_way&&_Right);
    void operator=(t_pfunc_concrete_param_way&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_type_concrete_param_way:public i_concrete_param_way{
  typedef t_inl_file OwnerClass;;
  typedef t_type_concrete_param_way SelfClass;typedef i_concrete_param_way ParentClass;;
  
   t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv value;;
    void DoReset();
  
    t_type_concrete_param_way(const t_type_concrete_param_way&)=delete;t_type_concrete_param_way();;
  
    t_type_concrete_param_way(t_type_concrete_param_way&&_Right);
    void operator=(t_type_concrete_param_way&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_expr_concrete_param_way:public i_concrete_param_way{
  typedef t_inl_file OwnerClass;;
  typedef t_expr_concrete_param_way SelfClass;typedef i_concrete_param_way ParentClass;;
  
   t_tmpl_expr value;;
    void DoReset();
  
    t_expr_concrete_param_way(const t_expr_concrete_param_way&)=delete;t_expr_concrete_param_way();;
  
    t_expr_concrete_param_way(t_expr_concrete_param_way&&_Right);
    void operator=(t_expr_concrete_param_way&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_bool_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_bool_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_bool_tmpl_expr(const t_bool_tmpl_expr&)=delete;t_bool_tmpl_expr();;
  
    t_bool_tmpl_expr(t_bool_tmpl_expr&&_Right);
    void operator=(t_bool_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_string_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_string_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_string_tmpl_expr(const t_string_tmpl_expr&)=delete;t_string_tmpl_expr();;
  
    t_string_tmpl_expr(t_string_tmpl_expr&&_Right);
    void operator=(t_string_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_char_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_char_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_char_tmpl_expr(const t_char_tmpl_expr&)=delete;t_char_tmpl_expr();;
  
    t_char_tmpl_expr(t_char_tmpl_expr&&_Right);
    void operator=(t_char_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_num_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_num_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_num_tmpl_expr(const t_num_tmpl_expr&)=delete;t_num_tmpl_expr();;
  
    t_num_tmpl_expr(t_num_tmpl_expr&&_Right);
    void operator=(t_num_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_real_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_real_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_real_tmpl_expr(const t_real_tmpl_expr&)=delete;t_real_tmpl_expr();;
  
    t_real_tmpl_expr(t_real_tmpl_expr&&_Right);
    void operator=(t_real_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_nullptr_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_nullptr_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
    void DoReset();
  
    t_nullptr_tmpl_expr(const t_nullptr_tmpl_expr&)=delete;t_nullptr_tmpl_expr();;
  
    t_nullptr_tmpl_expr(t_nullptr_tmpl_expr&&_Right);
    void operator=(t_nullptr_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_or_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_or_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   vector<t_name> arr;;
    void DoReset();
  
    t_or_tmpl_expr(const t_or_tmpl_expr&)=delete;t_or_tmpl_expr();;
  
    t_or_tmpl_expr(t_or_tmpl_expr&&_Right);
    void operator=(t_or_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_hex_tmpl_expr:public i_tmpl_expr{
  
    struct t_impl{
  typedef t_hex_tmpl_expr OwnerClass;;
  typedef t_impl SelfClass;;
  
   char x;; string value;;
    void DoReset();
  
    t_impl(const t_impl&)=delete;t_impl();;
  
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
    bool go(i_dev&dev);
    };
  
  typedef t_inl_file OwnerClass;;
  typedef t_hex_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string value;;
    void DoReset();
  
    t_hex_tmpl_expr(const t_hex_tmpl_expr&)=delete;t_hex_tmpl_expr();;
  
    t_hex_tmpl_expr(t_hex_tmpl_expr&&_Right);
    void operator=(t_hex_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_var_tmpl_expr:public i_tmpl_expr{
  typedef t_inl_file OwnerClass;;
  typedef t_var_tmpl_expr SelfClass;typedef i_tmpl_expr ParentClass;;
  
   string name;;
    void DoReset();
  
    t_var_tmpl_expr(const t_var_tmpl_expr&)=delete;t_var_tmpl_expr();;
  
    t_var_tmpl_expr(t_var_tmpl_expr&&_Right);
    void operator=(t_var_tmpl_expr&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_pragma_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_pragma_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   string body;;
    void DoReset();
  
    t_pragma_class_stat(const t_pragma_class_stat&)=delete;t_pragma_class_stat();;
  
    t_pragma_class_stat(t_pragma_class_stat&&_Right);
    void operator=(t_pragma_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_include_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_include_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   string body;;
    void DoReset();
  
    t_include_class_stat(const t_include_class_stat&)=delete;t_include_class_stat();;
  
    t_include_class_stat(t_include_class_stat&&_Right);
    void operator=(t_include_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_preproc_if_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_preproc_if_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   string body;;
    void DoReset();
  
    t_preproc_if_class_stat(const t_preproc_if_class_stat&)=delete;t_preproc_if_class_stat();;
  
    t_preproc_if_class_stat(t_preproc_if_class_stat&&_Right);
    void operator=(t_preproc_if_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_preproc_else_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_preproc_else_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   string body;;
    void DoReset();
  
    t_preproc_else_class_stat(const t_preproc_else_class_stat&)=delete;t_preproc_else_class_stat();;
  
    t_preproc_else_class_stat(t_preproc_else_class_stat&&_Right);
    void operator=(t_preproc_else_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_preproc_endif_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_preproc_endif_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   string body;;
    void DoReset();
  
    t_preproc_endif_class_stat(const t_preproc_endif_class_stat&)=delete;t_preproc_endif_class_stat();;
  
    t_preproc_endif_class_stat(t_preproc_endif_class_stat&&_Right);
    void operator=(t_preproc_endif_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_define_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_define_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   string body;;
    void DoReset();
  
    t_define_class_stat(const t_define_class_stat&)=delete;t_define_class_stat();;
  
    t_define_class_stat(t_define_class_stat&&_Right);
    void operator=(t_define_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_undef_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_undef_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   string body;;
    void DoReset();
  
    t_undef_class_stat(const t_undef_class_stat&)=delete;t_undef_class_stat();;
  
    t_undef_class_stat(t_undef_class_stat&&_Right);
    void operator=(t_undef_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_sep_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_sep_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_sep sep;;
    void DoReset();
  
    t_sep_class_stat(const t_sep_class_stat&)=delete;t_sep_class_stat();;
  
    t_sep_class_stat(t_sep_class_stat&&_Right);
    void operator=(t_sep_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_null_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_null_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
    void DoReset();
  
    t_null_class_stat(const t_null_class_stat&)=delete;t_null_class_stat();;
  
    t_null_class_stat(t_null_class_stat&&_Right);
    void operator=(t_null_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_class_class_stat:public i_class_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_class_class_stat SelfClass;typedef i_class_stat ParentClass;;
  
   t_class body;;
    void DoReset();
  
    t_class_class_stat(const t_class_class_stat&)=delete;t_class_class_stat();;
  
    t_class_class_stat(t_class_class_stat&&_Right);
    void operator=(t_class_class_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  bool go(i_dev&dev);
  };
  struct t_inl_file_stat{
  typedef t_inl_file OwnerClass;;
  typedef t_inl_file_stat SelfClass;;
  
   t_sep sep;; TAutoPtr<t_class> body;;
    void DoReset();
  
    t_inl_file_stat(const t_inl_file_stat&)=delete;t_inl_file_stat();;
  
    t_inl_file_stat(t_inl_file_stat&&_Right);
    void operator=(t_inl_file_stat&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
  bool go(i_dev&dev);
  };

  ;
  typedef t_inl_file SelfClass;;
  
  vector<TAutoPtr<i_class_stat>> arr;;
    void DoReset();
  
    t_inl_file(const t_inl_file&)=delete;t_inl_file();;
  
    t_inl_file(t_inl_file&&_Right);
    void operator=(t_inl_file&&_Right);
  
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  
bool go(i_dev&dev);

};
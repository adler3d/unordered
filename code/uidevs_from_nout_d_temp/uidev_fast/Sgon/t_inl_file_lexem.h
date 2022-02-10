class t_inl_file{
public:
  class i_class_stat;
   class t_access_mod_class_stat; class t_fv_class_stat; class t_typedef_class_stat; class t_dtor_class_stat; class t_ctor_class_stat; class t_oper_cast_class_stat; class t_common_oper_class_stat; class t_namespace_class_stat; class t_template_class_stat; class t_enum_class_stat; class t_using_class_stat; class t_pragma_class_stat; class t_include_class_stat; class t_preproc_if_class_stat; class t_preproc_else_class_stat; class t_preproc_endif_class_stat; class t_define_class_stat; class t_undef_class_stat; class t_sep_class_stat; class t_null_class_stat; class t_class_class_stat;
  class i_class_stat_visitor{
  public:
    typedef t_inl_file::i_class_stat i_class_stat;
  public:
     virtual void Do(t_access_mod_class_stat*p)=0; virtual void Do(t_fv_class_stat*p)=0; virtual void Do(t_typedef_class_stat*p)=0; virtual void Do(t_dtor_class_stat*p)=0; virtual void Do(t_ctor_class_stat*p)=0; virtual void Do(t_oper_cast_class_stat*p)=0; virtual void Do(t_common_oper_class_stat*p)=0; virtual void Do(t_namespace_class_stat*p)=0; virtual void Do(t_template_class_stat*p)=0; virtual void Do(t_enum_class_stat*p)=0; virtual void Do(t_using_class_stat*p)=0; virtual void Do(t_pragma_class_stat*p)=0; virtual void Do(t_include_class_stat*p)=0; virtual void Do(t_preproc_if_class_stat*p)=0; virtual void Do(t_preproc_else_class_stat*p)=0; virtual void Do(t_preproc_endif_class_stat*p)=0; virtual void Do(t_define_class_stat*p)=0; virtual void Do(t_undef_class_stat*p)=0; virtual void Do(t_sep_class_stat*p)=0; virtual void Do(t_null_class_stat*p)=0; virtual void Do(t_class_class_stat*p)=0;
  public:
     typedef t_inl_file::t_access_mod_class_stat t_access_mod_class_stat; typedef t_inl_file::t_fv_class_stat t_fv_class_stat; typedef t_inl_file::t_typedef_class_stat t_typedef_class_stat; typedef t_inl_file::t_dtor_class_stat t_dtor_class_stat; typedef t_inl_file::t_ctor_class_stat t_ctor_class_stat; typedef t_inl_file::t_oper_cast_class_stat t_oper_cast_class_stat; typedef t_inl_file::t_common_oper_class_stat t_common_oper_class_stat; typedef t_inl_file::t_namespace_class_stat t_namespace_class_stat; typedef t_inl_file::t_template_class_stat t_template_class_stat; typedef t_inl_file::t_enum_class_stat t_enum_class_stat; typedef t_inl_file::t_using_class_stat t_using_class_stat; typedef t_inl_file::t_pragma_class_stat t_pragma_class_stat; typedef t_inl_file::t_include_class_stat t_include_class_stat; typedef t_inl_file::t_preproc_if_class_stat t_preproc_if_class_stat; typedef t_inl_file::t_preproc_else_class_stat t_preproc_else_class_stat; typedef t_inl_file::t_preproc_endif_class_stat t_preproc_endif_class_stat; typedef t_inl_file::t_define_class_stat t_define_class_stat; typedef t_inl_file::t_undef_class_stat t_undef_class_stat; typedef t_inl_file::t_sep_class_stat t_sep_class_stat; typedef t_inl_file::t_null_class_stat t_null_class_stat; typedef t_inl_file::t_class_class_stat t_class_class_stat;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
       void Do(t_access_mod_class_stat*p){ptr=get(p);} void Do(t_fv_class_stat*p){ptr=get(p);} void Do(t_typedef_class_stat*p){ptr=get(p);} void Do(t_dtor_class_stat*p){ptr=get(p);} void Do(t_ctor_class_stat*p){ptr=get(p);} void Do(t_oper_cast_class_stat*p){ptr=get(p);} void Do(t_common_oper_class_stat*p){ptr=get(p);} void Do(t_namespace_class_stat*p){ptr=get(p);} void Do(t_template_class_stat*p){ptr=get(p);} void Do(t_enum_class_stat*p){ptr=get(p);} void Do(t_using_class_stat*p){ptr=get(p);} void Do(t_pragma_class_stat*p){ptr=get(p);} void Do(t_include_class_stat*p){ptr=get(p);} void Do(t_preproc_if_class_stat*p){ptr=get(p);} void Do(t_preproc_else_class_stat*p){ptr=get(p);} void Do(t_preproc_endif_class_stat*p){ptr=get(p);} void Do(t_define_class_stat*p){ptr=get(p);} void Do(t_undef_class_stat*p){ptr=get(p);} void Do(t_sep_class_stat*p){ptr=get(p);} void Do(t_null_class_stat*p){ptr=get(p);} void Do(t_class_class_stat*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_class_stat*p){
      if(!p)return nullptr;Is<TYPE,i_class_stat_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
public:
  class i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef i_class_stat SelfClass;;
  public:
    public:void DoReset();
  public:
    i_class_stat(const i_class_stat&)=delete;i_class_stat();;
  public:
    i_class_stat(i_class_stat&&_Right);
    void operator=(i_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:
    typedef i_class_stat_visitor i_visitor;virtual void Use(i_visitor&A);
  public:virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
  class i_expr;
   class t_call_expr; class t_block_expr; class t_bool_expr; class t_string_expr; class t_char_expr; class t_num_expr; class t_real_expr; class t_nullptr_expr; class t_or_expr; class t_hex_expr; class t_var_expr;
  class i_expr_visitor{
  public:
    typedef t_inl_file::i_expr i_expr;
  public:
     virtual void Do(t_call_expr*p)=0; virtual void Do(t_block_expr*p)=0; virtual void Do(t_bool_expr*p)=0; virtual void Do(t_string_expr*p)=0; virtual void Do(t_char_expr*p)=0; virtual void Do(t_num_expr*p)=0; virtual void Do(t_real_expr*p)=0; virtual void Do(t_nullptr_expr*p)=0; virtual void Do(t_or_expr*p)=0; virtual void Do(t_hex_expr*p)=0; virtual void Do(t_var_expr*p)=0;
  public:
     typedef t_inl_file::t_call_expr t_call_expr; typedef t_inl_file::t_block_expr t_block_expr; typedef t_inl_file::t_bool_expr t_bool_expr; typedef t_inl_file::t_string_expr t_string_expr; typedef t_inl_file::t_char_expr t_char_expr; typedef t_inl_file::t_num_expr t_num_expr; typedef t_inl_file::t_real_expr t_real_expr; typedef t_inl_file::t_nullptr_expr t_nullptr_expr; typedef t_inl_file::t_or_expr t_or_expr; typedef t_inl_file::t_hex_expr t_hex_expr; typedef t_inl_file::t_var_expr t_var_expr;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
       void Do(t_call_expr*p){ptr=get(p);} void Do(t_block_expr*p){ptr=get(p);} void Do(t_bool_expr*p){ptr=get(p);} void Do(t_string_expr*p){ptr=get(p);} void Do(t_char_expr*p){ptr=get(p);} void Do(t_num_expr*p){ptr=get(p);} void Do(t_real_expr*p){ptr=get(p);} void Do(t_nullptr_expr*p){ptr=get(p);} void Do(t_or_expr*p){ptr=get(p);} void Do(t_hex_expr*p){ptr=get(p);} void Do(t_var_expr*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){
      if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
public:
  class i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef i_expr SelfClass;;
  public:
    public:void DoReset();
  public:
    i_expr(const i_expr&)=delete;i_expr();;
  public:
    i_expr(i_expr&&_Right);
    void operator=(i_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:
    typedef i_expr_visitor i_visitor;virtual void Use(i_visitor&A);
  public:virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
  class i_func_body;
   class t_zero_func_body; class t_null_func_body; class t_delete_func_body; class t_impl_func_body;
  class i_func_body_visitor{
  public:
    typedef t_inl_file::i_func_body i_func_body;
  public:
     virtual void Do(t_zero_func_body*p)=0; virtual void Do(t_null_func_body*p)=0; virtual void Do(t_delete_func_body*p)=0; virtual void Do(t_impl_func_body*p)=0;
  public:
     typedef t_inl_file::t_zero_func_body t_zero_func_body; typedef t_inl_file::t_null_func_body t_null_func_body; typedef t_inl_file::t_delete_func_body t_delete_func_body; typedef t_inl_file::t_impl_func_body t_impl_func_body;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
       void Do(t_zero_func_body*p){ptr=get(p);} void Do(t_null_func_body*p){ptr=get(p);} void Do(t_delete_func_body*p){ptr=get(p);} void Do(t_impl_func_body*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_func_body*p){
      if(!p)return nullptr;Is<TYPE,i_func_body_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
public:
  class i_func_body{
  public:typedef t_inl_file OwnerClass;;
  public:typedef i_func_body SelfClass;;
  public:
    public:void DoReset();
  public:
    i_func_body(const i_func_body&)=delete;i_func_body();;
  public:
    i_func_body(i_func_body&&_Right);
    void operator=(i_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:
    typedef i_func_body_visitor i_visitor;virtual void Use(i_visitor&A);
  public:virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
  class i_tmpl_expr;
   class t_call_tmpl_expr; class t_block_tmpl_expr; class t_bool_tmpl_expr; class t_string_tmpl_expr; class t_char_tmpl_expr; class t_num_tmpl_expr; class t_real_tmpl_expr; class t_nullptr_tmpl_expr; class t_or_tmpl_expr; class t_hex_tmpl_expr; class t_var_tmpl_expr;
  class i_tmpl_expr_visitor{
  public:
    typedef t_inl_file::i_tmpl_expr i_tmpl_expr;
  public:
     virtual void Do(t_call_tmpl_expr*p)=0; virtual void Do(t_block_tmpl_expr*p)=0; virtual void Do(t_bool_tmpl_expr*p)=0; virtual void Do(t_string_tmpl_expr*p)=0; virtual void Do(t_char_tmpl_expr*p)=0; virtual void Do(t_num_tmpl_expr*p)=0; virtual void Do(t_real_tmpl_expr*p)=0; virtual void Do(t_nullptr_tmpl_expr*p)=0; virtual void Do(t_or_tmpl_expr*p)=0; virtual void Do(t_hex_tmpl_expr*p)=0; virtual void Do(t_var_tmpl_expr*p)=0;
  public:
     typedef t_inl_file::t_call_tmpl_expr t_call_tmpl_expr; typedef t_inl_file::t_block_tmpl_expr t_block_tmpl_expr; typedef t_inl_file::t_bool_tmpl_expr t_bool_tmpl_expr; typedef t_inl_file::t_string_tmpl_expr t_string_tmpl_expr; typedef t_inl_file::t_char_tmpl_expr t_char_tmpl_expr; typedef t_inl_file::t_num_tmpl_expr t_num_tmpl_expr; typedef t_inl_file::t_real_tmpl_expr t_real_tmpl_expr; typedef t_inl_file::t_nullptr_tmpl_expr t_nullptr_tmpl_expr; typedef t_inl_file::t_or_tmpl_expr t_or_tmpl_expr; typedef t_inl_file::t_hex_tmpl_expr t_hex_tmpl_expr; typedef t_inl_file::t_var_tmpl_expr t_var_tmpl_expr;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
       void Do(t_call_tmpl_expr*p){ptr=get(p);} void Do(t_block_tmpl_expr*p){ptr=get(p);} void Do(t_bool_tmpl_expr*p){ptr=get(p);} void Do(t_string_tmpl_expr*p){ptr=get(p);} void Do(t_char_tmpl_expr*p){ptr=get(p);} void Do(t_num_tmpl_expr*p){ptr=get(p);} void Do(t_real_tmpl_expr*p){ptr=get(p);} void Do(t_nullptr_tmpl_expr*p){ptr=get(p);} void Do(t_or_tmpl_expr*p){ptr=get(p);} void Do(t_hex_tmpl_expr*p){ptr=get(p);} void Do(t_var_tmpl_expr*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_tmpl_expr*p){
      if(!p)return nullptr;Is<TYPE,i_tmpl_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
public:
  class i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef i_tmpl_expr SelfClass;;
  public:
    public:void DoReset();
  public:
    i_tmpl_expr(const i_tmpl_expr&)=delete;i_tmpl_expr();;
  public:
    i_tmpl_expr(i_tmpl_expr&&_Right);
    void operator=(i_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:
    typedef i_tmpl_expr_visitor i_visitor;virtual void Use(i_visitor&A);
  public:virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
public:
  class i_concrete_param_way;
   class t_pfunc_concrete_param_way; class t_type_concrete_param_way; class t_expr_concrete_param_way;
  class i_concrete_param_way_visitor{
  public:
    typedef t_inl_file::i_concrete_param_way i_concrete_param_way;
  public:
     virtual void Do(t_pfunc_concrete_param_way*p)=0; virtual void Do(t_type_concrete_param_way*p)=0; virtual void Do(t_expr_concrete_param_way*p)=0;
  public:
     typedef t_inl_file::t_pfunc_concrete_param_way t_pfunc_concrete_param_way; typedef t_inl_file::t_type_concrete_param_way t_type_concrete_param_way; typedef t_inl_file::t_expr_concrete_param_way t_expr_concrete_param_way;
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
       void Do(t_pfunc_concrete_param_way*p){ptr=get(p);} void Do(t_type_concrete_param_way*p){ptr=get(p);} void Do(t_expr_concrete_param_way*p){ptr=get(p);}
    };
    template<class TYPE>
    static TYPE*UberCast(i_concrete_param_way*p){
      if(!p)return nullptr;Is<TYPE,i_concrete_param_way_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
public:
  class i_concrete_param_way{
  public:typedef t_inl_file OwnerClass;;
  public:typedef i_concrete_param_way SelfClass;;
  public:
    public:void DoReset();
  public:
    i_concrete_param_way(const i_concrete_param_way&)=delete;i_concrete_param_way();;
  public:
    i_concrete_param_way(i_concrete_param_way&&_Right);
    void operator=(i_concrete_param_way&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:
    typedef i_concrete_param_way_visitor i_visitor;virtual void Use(i_visitor&A);
  public:virtual bool go(i_dev&dev);;
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
    };
  };
  class t_lev03{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev03 SelfClass;;
  public:
   string oper;; TAutoPtr<i_expr> expr;;
    public:void DoReset();
  public:
    t_lev03(const t_lev03&)=delete;t_lev03();;
  public:
    t_lev03(t_lev03&&_Right);
    void operator=(t_lev03&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev05{
  public:
    class t_oper{
  public:typedef t_lev05 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev05 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev03 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev05 SelfClass;;
  public:
   t_lev03 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev05(const t_lev05&)=delete;t_lev05();;
  public:
    t_lev05(t_lev05&&_Right);
    void operator=(t_lev05&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev06{
  public:
    class t_oper{
  public:typedef t_lev06 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev06 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev05 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev06 SelfClass;;
  public:
   t_lev05 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev06(const t_lev06&)=delete;t_lev06();;
  public:
    t_lev06(t_lev06&&_Right);
    void operator=(t_lev06&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev07{
  public:
    class t_oper{
  public:typedef t_lev07 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev07 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev06 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev07 SelfClass;;
  public:
   t_lev06 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev07(const t_lev07&)=delete;t_lev07();;
  public:
    t_lev07(t_lev07&&_Right);
    void operator=(t_lev07&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev08{
  public:
    class t_oper{
  public:typedef t_lev08 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev08 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev07 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev08 SelfClass;;
  public:
   t_lev07 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev08(const t_lev08&)=delete;t_lev08();;
  public:
    t_lev08(t_lev08&&_Right);
    void operator=(t_lev08&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev09{
  public:
    class t_oper{
  public:typedef t_lev09 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev09 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev08 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev09 SelfClass;;
  public:
   t_lev08 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev09(const t_lev09&)=delete;t_lev09();;
  public:
    t_lev09(t_lev09&&_Right);
    void operator=(t_lev09&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev10{
  public:
    class t_oper{
  public:typedef t_lev10 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev10 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev09 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev10 SelfClass;;
  public:
   t_lev09 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev10(const t_lev10&)=delete;t_lev10();;
  public:
    t_lev10(t_lev10&&_Right);
    void operator=(t_lev10&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev11{
  public:
    class t_oper{
  public:typedef t_lev11 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev11 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev10 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev11 SelfClass;;
  public:
   t_lev10 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev11(const t_lev11&)=delete;t_lev11();;
  public:
    t_lev11(t_lev11&&_Right);
    void operator=(t_lev11&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev12{
  public:
    class t_oper{
  public:typedef t_lev12 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev12 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev11 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev12 SelfClass;;
  public:
   t_lev11 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev12(const t_lev12&)=delete;t_lev12();;
  public:
    t_lev12(t_lev12&&_Right);
    void operator=(t_lev12&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev13{
  public:
    class t_oper{
  public:typedef t_lev13 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev13 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev12 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev13 SelfClass;;
  public:
   t_lev12 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev13(const t_lev13&)=delete;t_lev13();;
  public:
    t_lev13(t_lev13&&_Right);
    void operator=(t_lev13&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_lev14{
  public:
    class t_oper{
  public:typedef t_lev14 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_lev14 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_lev13 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_lev14 SelfClass;;
  public:
   t_lev13 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_lev14(const t_lev14&)=delete;t_lev14();;
  public:
    t_lev14(t_lev14&&_Right);
    void operator=(t_lev14&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_expr SelfClass;;
  public:
   t_lev14 body;;
    public:void DoReset();
  public:
    t_expr(const t_expr&)=delete;t_expr();;
  public:
    t_expr(t_expr&&_Right);
    void operator=(t_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev03{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev03 SelfClass;;
  public:
   string oper;; TAutoPtr<i_tmpl_expr> expr;;
    public:void DoReset();
  public:
    t_tmpl_lev03(const t_tmpl_lev03&)=delete;t_tmpl_lev03();;
  public:
    t_tmpl_lev03(t_tmpl_lev03&&_Right);
    void operator=(t_tmpl_lev03&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev05{
  public:
    class t_oper{
  public:typedef t_tmpl_lev05 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev05 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev03 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev05 SelfClass;;
  public:
   t_tmpl_lev03 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev05(const t_tmpl_lev05&)=delete;t_tmpl_lev05();;
  public:
    t_tmpl_lev05(t_tmpl_lev05&&_Right);
    void operator=(t_tmpl_lev05&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev06{
  public:
    class t_oper{
  public:typedef t_tmpl_lev06 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev06 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev05 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev06 SelfClass;;
  public:
   t_tmpl_lev05 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev06(const t_tmpl_lev06&)=delete;t_tmpl_lev06();;
  public:
    t_tmpl_lev06(t_tmpl_lev06&&_Right);
    void operator=(t_tmpl_lev06&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev09{
  public:
    class t_oper{
  public:typedef t_tmpl_lev09 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev09 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev06 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev09 SelfClass;;
  public:
   t_tmpl_lev06 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev09(const t_tmpl_lev09&)=delete;t_tmpl_lev09();;
  public:
    t_tmpl_lev09(t_tmpl_lev09&&_Right);
    void operator=(t_tmpl_lev09&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev10{
  public:
    class t_oper{
  public:typedef t_tmpl_lev10 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev10 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev09 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev10 SelfClass;;
  public:
   t_tmpl_lev09 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev10(const t_tmpl_lev10&)=delete;t_tmpl_lev10();;
  public:
    t_tmpl_lev10(t_tmpl_lev10&&_Right);
    void operator=(t_tmpl_lev10&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev11{
  public:
    class t_oper{
  public:typedef t_tmpl_lev11 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev11 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev10 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev11 SelfClass;;
  public:
   t_tmpl_lev10 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev11(const t_tmpl_lev11&)=delete;t_tmpl_lev11();;
  public:
    t_tmpl_lev11(t_tmpl_lev11&&_Right);
    void operator=(t_tmpl_lev11&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev12{
  public:
    class t_oper{
  public:typedef t_tmpl_lev12 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev12 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev11 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev12 SelfClass;;
  public:
   t_tmpl_lev11 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev12(const t_tmpl_lev12&)=delete;t_tmpl_lev12();;
  public:
    t_tmpl_lev12(t_tmpl_lev12&&_Right);
    void operator=(t_tmpl_lev12&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev13{
  public:
    class t_oper{
  public:typedef t_tmpl_lev13 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev13 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev12 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev13 SelfClass;;
  public:
   t_tmpl_lev12 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev13(const t_tmpl_lev13&)=delete;t_tmpl_lev13();;
  public:
    t_tmpl_lev13(t_tmpl_lev13&&_Right);
    void operator=(t_tmpl_lev13&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_lev14{
  public:
    class t_oper{
  public:typedef t_tmpl_lev14 OwnerClass;;
  public:typedef t_oper SelfClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_oper(const t_oper&)=delete;t_oper();;
  public:
    t_oper(t_oper&&_Right);
    void operator=(t_oper&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_tmpl_lev14 OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_oper oper;; t_tmpl_lev13 expr;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_lev14 SelfClass;;
  public:
   t_tmpl_lev13 expr;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_tmpl_lev14(const t_tmpl_lev14&)=delete;t_tmpl_lev14();;
  public:
    t_tmpl_lev14(t_tmpl_lev14&&_Right);
    void operator=(t_tmpl_lev14&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_expr SelfClass;;
  public:
   t_tmpl_lev14 body;;
    public:void DoReset();
  public:
    t_tmpl_expr(const t_tmpl_expr&)=delete;t_tmpl_expr();;
  public:
    t_tmpl_expr(t_tmpl_expr&&_Right);
    void operator=(t_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_concrete_param{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_concrete_param SelfClass;;
  public:
   t_sep sep0;; TAutoPtr<i_concrete_param_way> body;; t_sep sep1;;
    public:void DoReset();
  public:
    t_concrete_param(const t_concrete_param&)=delete;t_concrete_param();;
  public:
    t_concrete_param(t_concrete_param&&_Right);
    void operator=(t_concrete_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_concrete_params{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_concrete_params SelfClass;;
  public:
   vector<t_concrete_param> arr;; t_sep sep;;
    public:void DoReset();
  public:
    t_concrete_params(const t_concrete_params&)=delete;t_concrete_params();;
  public:
    t_concrete_params(t_concrete_params&&_Right);
    void operator=(t_concrete_params&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_access_mod{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_access_mod SelfClass;;
  public:
   string keyword;;
    public:void DoReset();
  public:
    t_access_mod(const t_access_mod&)=delete;t_access_mod();;
  public:
    t_access_mod(t_access_mod&&_Right);
    void operator=(t_access_mod&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_access_mod_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_access_mod_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_access_mod mod;; t_sep sep;;
    public:void DoReset();
  public:
    t_access_mod_class_stat(const t_access_mod_class_stat&)=delete;t_access_mod_class_stat();;
  public:
    t_access_mod_class_stat(t_access_mod_class_stat&&_Right);
    void operator=(t_access_mod_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_raw_func_body{
  public:
    class i_item;
     class t_sep_item; class t_s_item; class t_c_item; class t_code_item; class t_div_item; class t_block_item;
    class i_item_visitor{
    public:
      typedef t_raw_func_body::i_item i_item;
    public:
       virtual void Do(t_sep_item*p)=0; virtual void Do(t_s_item*p)=0; virtual void Do(t_c_item*p)=0; virtual void Do(t_code_item*p)=0; virtual void Do(t_div_item*p)=0; virtual void Do(t_block_item*p)=0;
    public:
       typedef t_raw_func_body::t_sep_item t_sep_item; typedef t_raw_func_body::t_s_item t_s_item; typedef t_raw_func_body::t_c_item t_c_item; typedef t_raw_func_body::t_code_item t_code_item; typedef t_raw_func_body::t_div_item t_div_item; typedef t_raw_func_body::t_block_item t_block_item;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      public:
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      public:
         void Do(t_sep_item*p){ptr=get(p);} void Do(t_s_item*p){ptr=get(p);} void Do(t_c_item*p){ptr=get(p);} void Do(t_code_item*p){ptr=get(p);} void Do(t_div_item*p){ptr=get(p);} void Do(t_block_item*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_item*p){
        if(!p)return nullptr;Is<TYPE,i_item_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  public:
    class i_item{
  public:typedef t_raw_func_body OwnerClass;;
  public:typedef i_item SelfClass;;
  public:
    public:void DoReset();
  public:
    i_item(const i_item&)=delete;i_item();;
  public:
    i_item(i_item&&_Right);
    void operator=(i_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:
      typedef i_item_visitor i_visitor;virtual void Use(i_visitor&A);
    public:virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_sep_item:public i_item{
  public:typedef t_raw_func_body OwnerClass;;
  public:typedef t_sep_item SelfClass;public:typedef i_item ParentClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_sep_item(const t_sep_item&)=delete;t_sep_item();;
  public:
    t_sep_item(t_sep_item&&_Right);
    void operator=(t_sep_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_s_item:public i_item{
  public:typedef t_raw_func_body OwnerClass;;
  public:typedef t_s_item SelfClass;public:typedef i_item ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_s_item(const t_s_item&)=delete;t_s_item();;
  public:
    t_s_item(t_s_item&&_Right);
    void operator=(t_s_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_c_item:public i_item{
  public:typedef t_raw_func_body OwnerClass;;
  public:typedef t_c_item SelfClass;public:typedef i_item ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_c_item(const t_c_item&)=delete;t_c_item();;
  public:
    t_c_item(t_c_item&&_Right);
    void operator=(t_c_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_code_item:public i_item{
  public:typedef t_raw_func_body OwnerClass;;
  public:typedef t_code_item SelfClass;public:typedef i_item ParentClass;;
  public:
   string code;;
    public:void DoReset();
  public:
    t_code_item(const t_code_item&)=delete;t_code_item();;
  public:
    t_code_item(t_code_item&&_Right);
    void operator=(t_code_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_div_item:public i_item{
  public:typedef t_raw_func_body OwnerClass;;
  public:typedef t_div_item SelfClass;public:typedef i_item ParentClass;;
  public:
    public:void DoReset();
  public:
    t_div_item(const t_div_item&)=delete;t_div_item();;
  public:
    t_div_item(t_div_item&&_Right);
    void operator=(t_div_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_block_item:public i_item{
  public:typedef t_raw_func_body OwnerClass;;
  public:typedef t_block_item SelfClass;public:typedef i_item ParentClass;;
  public:
   TAutoPtr<t_raw_func_body> body;;
    public:void DoReset();
  public:
    t_block_item(const t_block_item&)=delete;t_block_item();;
  public:
    t_block_item(t_block_item&&_Right);
    void operator=(t_block_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_raw_func_body SelfClass;;
  public:
   t_sep sep;; vector<TAutoPtr<i_item>> arr;;
    public:void DoReset();
  public:
    t_raw_func_body(const t_raw_func_body&)=delete;t_raw_func_body();;
  public:
    t_raw_func_body(t_raw_func_body&&_Right);
    void operator=(t_raw_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  public:
  };
  class t_func_path{
  public:
    class t_item{
  public:typedef t_func_path OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   string value;; t_sep sep0;; t_sep sep1;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_func_path SelfClass;;
  public:
   vector<t_item> arr;;
    public:void DoReset();
  public:
    t_func_path(const t_func_path&)=delete;t_func_path();;
  public:
    t_func_path(t_func_path&&_Right);
    void operator=(t_func_path&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_const_with_sep{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_const_with_sep SelfClass;;
  public:
   t_sep sep;; string keyword;;
    public:void DoReset();
  public:
    t_const_with_sep(const t_const_with_sep&)=delete;t_const_with_sep();;
  public:
    t_const_with_sep(t_const_with_sep&&_Right);
    void operator=(t_const_with_sep&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_keyword{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_keyword SelfClass;;
  public:
   string keyword;; t_sep sep;;
    public:void DoReset();
  public:
    t_keyword(const t_keyword&)=delete;t_keyword();;
  public:
    t_keyword(t_keyword&&_Right);
    void operator=(t_keyword&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_ptr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_ptr SelfClass;;
  public:
   TAutoPtr<t_const_with_sep> cv;; t_sep sep;;
    public:void DoReset();
  public:
    t_ptr(const t_ptr&)=delete;t_ptr();;
  public:
    t_ptr(t_ptr&&_Right);
    void operator=(t_ptr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_ref{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_ref SelfClass;;
  public:
   TAutoPtr<t_const_with_sep> cv;; t_sep sep;; string ref;;
    public:void DoReset();
  public:
    t_ref(const t_ref&)=delete;t_ref();;
  public:
    t_ref(t_ref&&_Right);
    void operator=(t_ref&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_type_with_sep{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_type_with_sep SelfClass;;
  public:
   t_sep sep;; string name;; TAutoPtr<t_concrete_params> concrete_params;;
    public:void DoReset();
  public:
    t_type_with_sep(const t_type_with_sep&)=delete;t_type_with_sep();;
  public:
    t_type_with_sep(t_type_with_sep&&_Right);
    void operator=(t_type_with_sep&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_scope_with_sep{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_scope_with_sep SelfClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_scope_with_sep(const t_scope_with_sep&)=delete;t_scope_with_sep();;
  public:
    t_scope_with_sep(t_scope_with_sep&&_Right);
    void operator=(t_scope_with_sep&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_scopes{
  public:
    class t_item{
  public:typedef t_scopes OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_scope_with_sep sws;; t_type_with_sep body;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_scopes SelfClass;;
  public:
   t_type_with_sep first;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_scopes(const t_scopes&)=delete;t_scopes();;
  public:
    t_scopes(t_scopes&&_Right);
    void operator=(t_scopes&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_fv_class_stat:public i_class_stat{
  public:
    class t_type_expr{
    public:
      class i_name_part;
       class t_raw_name_part; class t_brackets_name_part;
      class i_name_part_visitor{
      public:
        typedef t_type_expr::i_name_part i_name_part;
      public:
         virtual void Do(t_raw_name_part*p)=0; virtual void Do(t_brackets_name_part*p)=0;
      public:
         typedef t_type_expr::t_raw_name_part t_raw_name_part; typedef t_type_expr::t_brackets_name_part t_brackets_name_part;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor{
          TYPE*ptr;
          Is():ptr(nullptr){}
        public:
          template<class U>static TYPE*get(U*p){return nullptr;}
          template<>static TYPE*get<TYPE>(TYPE*p){return p;}
        public:
           void Do(t_raw_name_part*p){ptr=get(p);} void Do(t_brackets_name_part*p){ptr=get(p);}
        };
        template<class TYPE>
        static TYPE*UberCast(i_name_part*p){
          if(!p)return nullptr;Is<TYPE,i_name_part_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
    public:
      class i_name_part{
  public:typedef t_type_expr OwnerClass;;
  public:typedef i_name_part SelfClass;;
  public:
    public:void DoReset();
  public:
    i_name_part(const i_name_part&)=delete;i_name_part();;
  public:
    i_name_part(i_name_part&&_Right);
    void operator=(i_name_part&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:
        typedef i_name_part_visitor i_visitor;virtual void Use(i_visitor&A);
      public:virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    public:
      class i_func_param;
       class t_pfunc_func_param; class t_var_args_func_param; class t_type_func_param; class t_expr_func_param;
      class i_func_param_visitor{
      public:
        typedef t_type_expr::i_func_param i_func_param;
      public:
         virtual void Do(t_pfunc_func_param*p)=0; virtual void Do(t_var_args_func_param*p)=0; virtual void Do(t_type_func_param*p)=0; virtual void Do(t_expr_func_param*p)=0;
      public:
         typedef t_type_expr::t_pfunc_func_param t_pfunc_func_param; typedef t_type_expr::t_var_args_func_param t_var_args_func_param; typedef t_type_expr::t_type_func_param t_type_func_param; typedef t_type_expr::t_expr_func_param t_expr_func_param;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor{
          TYPE*ptr;
          Is():ptr(nullptr){}
        public:
          template<class U>static TYPE*get(U*p){return nullptr;}
          template<>static TYPE*get<TYPE>(TYPE*p){return p;}
        public:
           void Do(t_pfunc_func_param*p){ptr=get(p);} void Do(t_var_args_func_param*p){ptr=get(p);} void Do(t_type_func_param*p){ptr=get(p);} void Do(t_expr_func_param*p){ptr=get(p);}
        };
        template<class TYPE>
        static TYPE*UberCast(i_func_param*p){
          if(!p)return nullptr;Is<TYPE,i_func_param_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
    public:
      class i_func_param{
  public:typedef t_type_expr OwnerClass;;
  public:typedef i_func_param SelfClass;;
  public:
    public:void DoReset();
  public:
    i_func_param(const i_func_param&)=delete;i_func_param();;
  public:
    i_func_param(i_func_param&&_Right);
    void operator=(i_func_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:
        typedef i_func_param_visitor i_visitor;virtual void Use(i_visitor&A);
      public:virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
    public:
      class i_typeexpr;
       class t_impl_typeexpr; class t_decl_typeexpr;
      class i_typeexpr_visitor{
      public:
        typedef t_type_expr::i_typeexpr i_typeexpr;
      public:
         virtual void Do(t_impl_typeexpr*p)=0; virtual void Do(t_decl_typeexpr*p)=0;
      public:
         typedef t_type_expr::t_impl_typeexpr t_impl_typeexpr; typedef t_type_expr::t_decl_typeexpr t_decl_typeexpr;
      public:
        template<class TYPE,class Visitor>
        struct Is:public Visitor{
          TYPE*ptr;
          Is():ptr(nullptr){}
        public:
          template<class U>static TYPE*get(U*p){return nullptr;}
          template<>static TYPE*get<TYPE>(TYPE*p){return p;}
        public:
           void Do(t_impl_typeexpr*p){ptr=get(p);} void Do(t_decl_typeexpr*p){ptr=get(p);}
        };
        template<class TYPE>
        static TYPE*UberCast(i_typeexpr*p){
          if(!p)return nullptr;Is<TYPE,i_typeexpr_visitor> IS;p->Use(IS);return IS.ptr;
        }
      };
    public:
      class i_typeexpr{
  public:typedef t_type_expr OwnerClass;;
  public:typedef i_typeexpr SelfClass;;
  public:
    public:void DoReset();
  public:
    i_typeexpr(const i_typeexpr&)=delete;i_typeexpr();;
  public:
    i_typeexpr(i_typeexpr&&_Right);
    void operator=(i_typeexpr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:
        typedef i_typeexpr_visitor i_visitor;virtual void Use(i_visitor&A);
      public:virtual bool go(i_dev&dev);;
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
        };
      };
      class t_type_expr_with_sep_and_cv{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_type_expr_with_sep_and_cv SelfClass;;
  public:
   vector<t_const_with_sep> cvs;; TAutoPtr<t_type_expr> body;;
    public:void DoReset();
  public:
    t_type_expr_with_sep_and_cv(const t_type_expr_with_sep_and_cv&)=delete;t_type_expr_with_sep_and_cv();;
  public:
    t_type_expr_with_sep_and_cv(t_type_expr_with_sep_and_cv&&_Right);
    void operator=(t_type_expr_with_sep_and_cv&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_name_part{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_name_part SelfClass;;
  public:
   TAutoPtr<i_name_part> body;;
    public:void DoReset();
  public:
    t_name_part(const t_name_part&)=delete;t_name_part();;
  public:
    t_name_part(t_name_part&&_Right);
    void operator=(t_name_part&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_arr_body{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_arr_body SelfClass;;
  public:
   t_sep sep0;; t_sep sep1;; t_expr expr;; t_sep sep2;; t_sep sep3;;
    public:void DoReset();
  public:
    t_arr_body(const t_arr_body&)=delete;t_arr_body();;
  public:
    t_arr_body(t_arr_body&&_Right);
    void operator=(t_arr_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_raw_name_part:public i_name_part{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_raw_name_part SelfClass;public:typedef i_name_part ParentClass;;
  public:
   string name;;
    public:void DoReset();
  public:
    t_raw_name_part(const t_raw_name_part&)=delete;t_raw_name_part();;
  public:
    t_raw_name_part(t_raw_name_part&&_Right);
    void operator=(t_raw_name_part&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      };
      class t_brackets_name_part:public i_name_part{
      public:
        class i_part;
         class t_amp_part; class t_star_part;
        class i_part_visitor{
        public:
          typedef t_brackets_name_part::i_part i_part;
        public:
           virtual void Do(t_amp_part*p)=0; virtual void Do(t_star_part*p)=0;
        public:
           typedef t_brackets_name_part::t_amp_part t_amp_part; typedef t_brackets_name_part::t_star_part t_star_part;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor{
            TYPE*ptr;
            Is():ptr(nullptr){}
          public:
            template<class U>static TYPE*get(U*p){return nullptr;}
            template<>static TYPE*get<TYPE>(TYPE*p){return p;}
          public:
             void Do(t_amp_part*p){ptr=get(p);} void Do(t_star_part*p){ptr=get(p);}
          };
          template<class TYPE>
          static TYPE*UberCast(i_part*p){
            if(!p)return nullptr;Is<TYPE,i_part_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
      public:
        class i_part{
  public:typedef t_brackets_name_part OwnerClass;;
  public:typedef i_part SelfClass;;
  public:
    public:void DoReset();
  public:
    i_part(const i_part&)=delete;i_part();;
  public:
    i_part(i_part&&_Right);
    void operator=(i_part&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:
          typedef i_part_visitor i_visitor;virtual void Use(i_visitor&A);
        public:virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_amp{
  public:typedef t_brackets_name_part OwnerClass;;
  public:typedef t_amp SelfClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_amp(const t_amp&)=delete;t_amp();;
  public:
    t_amp(t_amp&&_Right);
    void operator=(t_amp&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:bool go(i_dev&dev);
        };
        class t_amp_part:public i_part{
  public:typedef t_brackets_name_part OwnerClass;;
  public:typedef t_amp_part SelfClass;public:typedef i_part ParentClass;;
  public:
   t_amp body;;
    public:void DoReset();
  public:
    t_amp_part(const t_amp_part&)=delete;t_amp_part();;
  public:
    t_amp_part(t_amp_part&&_Right);
    void operator=(t_amp_part&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        public:bool go(i_dev&dev);
        };
        class t_star_part:public i_part{
  public:typedef t_brackets_name_part OwnerClass;;
  public:typedef t_star_part SelfClass;public:typedef i_part ParentClass;;
  public:
   string stars;; TAutoPtr<t_amp> amp;;
    public:void DoReset();
  public:
    t_star_part(const t_star_part&)=delete;t_star_part();;
  public:
    t_star_part(t_star_part&&_Right);
    void operator=(t_star_part&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        public:bool go(i_dev&dev);
        };
      public:
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_brackets_name_part SelfClass;public:typedef i_name_part ParentClass;;
  public:
   TAutoPtr<i_part> stamp_part;; t_sep sep;; TAutoPtr<t_name_part> namepart;; TAutoPtr<t_arr_body> arrbody;;
    public:void DoReset();
  public:
    t_brackets_name_part(const t_brackets_name_part&)=delete;t_brackets_name_part();;
  public:
    t_brackets_name_part(t_brackets_name_part&&_Right);
    void operator=(t_brackets_name_part&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      public:
      };
      class t_func_param_value{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_func_param_value SelfClass;;
  public:
   t_sep sep;; t_expr value;;
    public:void DoReset();
  public:
    t_func_param_value(const t_func_param_value&)=delete;t_func_param_value();;
  public:
    t_func_param_value(t_func_param_value&&_Right);
    void operator=(t_func_param_value&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_func_param{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_func_param SelfClass;;
  public:
   t_sep sep0;; TAutoPtr<i_func_param> body;; t_sep sep1;; TAutoPtr<t_func_param_value> value;; t_sep sep2;;
    public:void DoReset();
  public:
    t_func_param(const t_func_param&)=delete;t_func_param();;
  public:
    t_func_param(t_func_param&&_Right);
    void operator=(t_func_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_func_params{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_func_params SelfClass;;
  public:
   t_sep sep;; vector<t_func_param> arr;;
    public:void DoReset();
  public:
    t_func_params(const t_func_params&)=delete;t_func_params();;
  public:
    t_func_params(t_func_params&&_Right);
    void operator=(t_func_params&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_pfunc{
      public:
        class t_addr{
  public:typedef t_pfunc OwnerClass;;
  public:typedef t_addr SelfClass;;
  public:
   t_type_expr_with_sep_and_cv type;;
    public:void DoReset();
  public:
    t_addr(const t_addr&)=delete;t_addr();;
  public:
    t_addr(t_addr&&_Right);
    void operator=(t_addr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:bool go(i_dev&dev);
        };
      public:
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_pfunc SelfClass;;
  public:
   t_type_expr_with_sep_and_cv type;; t_addr addr;; string name;; t_func_params params;;
    public:void DoReset();
  public:
    t_pfunc(const t_pfunc&)=delete;t_pfunc();;
  public:
    t_pfunc(t_pfunc&&_Right);
    void operator=(t_pfunc&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_pfunc_func_param:public i_func_param{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_pfunc_func_param SelfClass;public:typedef i_func_param ParentClass;;
  public:
   t_pfunc value;;
    public:void DoReset();
  public:
    t_pfunc_func_param(const t_pfunc_func_param&)=delete;t_pfunc_func_param();;
  public:
    t_pfunc_func_param(t_pfunc_func_param&&_Right);
    void operator=(t_pfunc_func_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      };
      class t_var_args_func_param:public i_func_param{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_var_args_func_param SelfClass;public:typedef i_func_param ParentClass;;
  public:
    public:void DoReset();
  public:
    t_var_args_func_param(const t_var_args_func_param&)=delete;t_var_args_func_param();;
  public:
    t_var_args_func_param(t_var_args_func_param&&_Right);
    void operator=(t_var_args_func_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      };
      class t_type_func_param:public i_func_param{
      public:
        class t_const{
  public:typedef t_type_func_param OwnerClass;;
  public:typedef t_const SelfClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_const(const t_const&)=delete;t_const();;
  public:
    t_const(t_const&&_Right);
    void operator=(t_const&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:bool go(i_dev&dev);
        };
      public:
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_type_func_param SelfClass;public:typedef i_func_param ParentClass;;
  public:
   t_type_expr_with_sep_and_cv type;; t_sep sep;; TAutoPtr<t_const> cv;; TAutoPtr<t_name_part> namepart;;
    public:void DoReset();
  public:
    t_type_func_param(const t_type_func_param&)=delete;t_type_func_param();;
  public:
    t_type_func_param(t_type_func_param&&_Right);
    void operator=(t_type_func_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      };
      class t_expr_func_param:public i_func_param{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_expr_func_param SelfClass;public:typedef i_func_param ParentClass;;
  public:
   t_expr body;;
    public:void DoReset();
  public:
    t_expr_func_param(const t_expr_func_param&)=delete;t_expr_func_param();;
  public:
    t_expr_func_param(t_expr_func_param&&_Right);
    void operator=(t_expr_func_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      };
      class t_fv_stat{
      public:
        class i_fv_body;
         class t_impl_func_body; class t_zero_func_body; class t_delete_func_body;
        class i_fv_body_visitor{
        public:
          typedef t_fv_stat::i_fv_body i_fv_body;
        public:
           virtual void Do(t_impl_func_body*p)=0; virtual void Do(t_zero_func_body*p)=0; virtual void Do(t_delete_func_body*p)=0;
        public:
           typedef t_fv_stat::t_impl_func_body t_impl_func_body; typedef t_fv_stat::t_zero_func_body t_zero_func_body; typedef t_fv_stat::t_delete_func_body t_delete_func_body;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor{
            TYPE*ptr;
            Is():ptr(nullptr){}
          public:
            template<class U>static TYPE*get(U*p){return nullptr;}
            template<>static TYPE*get<TYPE>(TYPE*p){return p;}
          public:
             void Do(t_impl_func_body*p){ptr=get(p);} void Do(t_zero_func_body*p){ptr=get(p);} void Do(t_delete_func_body*p){ptr=get(p);}
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_body*p){
            if(!p)return nullptr;Is<TYPE,i_fv_body_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
      public:
        class i_fv_body{
  public:typedef t_fv_stat OwnerClass;;
  public:typedef i_fv_body SelfClass;;
  public:
    public:void DoReset();
  public:
    i_fv_body(const i_fv_body&)=delete;i_fv_body();;
  public:
    i_fv_body(i_fv_body&&_Right);
    void operator=(i_fv_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:
          typedef i_fv_body_visitor i_visitor;virtual void Use(i_visitor&A);
        public:virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
      public:
        class i_fv_end;
         class t_func_fv_end; class t_var_fv_end;
        class i_fv_end_visitor{
        public:
          typedef t_fv_stat::i_fv_end i_fv_end;
        public:
           virtual void Do(t_func_fv_end*p)=0; virtual void Do(t_var_fv_end*p)=0;
        public:
           typedef t_fv_stat::t_func_fv_end t_func_fv_end; typedef t_fv_stat::t_var_fv_end t_var_fv_end;
        public:
          template<class TYPE,class Visitor>
          struct Is:public Visitor{
            TYPE*ptr;
            Is():ptr(nullptr){}
          public:
            template<class U>static TYPE*get(U*p){return nullptr;}
            template<>static TYPE*get<TYPE>(TYPE*p){return p;}
          public:
             void Do(t_func_fv_end*p){ptr=get(p);} void Do(t_var_fv_end*p){ptr=get(p);}
          };
          template<class TYPE>
          static TYPE*UberCast(i_fv_end*p){
            if(!p)return nullptr;Is<TYPE,i_fv_end_visitor> IS;p->Use(IS);return IS.ptr;
          }
        };
      public:
        class i_fv_end{
  public:typedef t_fv_stat OwnerClass;;
  public:typedef i_fv_end SelfClass;;
  public:
    public:void DoReset();
  public:
    i_fv_end(const i_fv_end&)=delete;i_fv_end();;
  public:
    i_fv_end(i_fv_end&&_Right);
    void operator=(i_fv_end&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:
          typedef i_fv_end_visitor i_visitor;virtual void Use(i_visitor&A);
        public:virtual bool go(i_dev&dev);;
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
          };
        };
        class t_impl_func_body:public i_fv_body{
  public:typedef t_fv_stat OwnerClass;;
  public:typedef t_impl_func_body SelfClass;public:typedef i_fv_body ParentClass;;
  public:
   t_sep sep;; t_raw_func_body body;;
    public:void DoReset();
  public:
    t_impl_func_body(const t_impl_func_body&)=delete;t_impl_func_body();;
  public:
    t_impl_func_body(t_impl_func_body&&_Right);
    void operator=(t_impl_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        public:bool go(i_dev&dev);
        };
        class t_zero_func_body:public i_fv_body{
  public:typedef t_fv_stat OwnerClass;;
  public:typedef t_zero_func_body SelfClass;public:typedef i_fv_body ParentClass;;
  public:
    public:void DoReset();
  public:
    t_zero_func_body(const t_zero_func_body&)=delete;t_zero_func_body();;
  public:
    t_zero_func_body(t_zero_func_body&&_Right);
    void operator=(t_zero_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        public:bool go(i_dev&dev);
        };
        class t_delete_func_body:public i_fv_body{
  public:typedef t_fv_stat OwnerClass;;
  public:typedef t_delete_func_body SelfClass;public:typedef i_fv_body ParentClass;;
  public:
    public:void DoReset();
  public:
    t_delete_func_body(const t_delete_func_body&)=delete;t_delete_func_body();;
  public:
    t_delete_func_body(t_delete_func_body&&_Right);
    void operator=(t_delete_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        public:bool go(i_dev&dev);
        };
        class t_func_fv_end:public i_fv_end{
  public:typedef t_fv_stat OwnerClass;;
  public:typedef t_func_fv_end SelfClass;public:typedef i_fv_end ParentClass;;
  public:
   TAutoPtr<t_func_params> params;; TAutoPtr<t_const_with_sep> cv1;; t_sep sep1;; TAutoPtr<i_fv_body> body;;
    public:void DoReset();
  public:
    t_func_fv_end(const t_func_fv_end&)=delete;t_func_fv_end();;
  public:
    t_func_fv_end(t_func_fv_end&&_Right);
    void operator=(t_func_fv_end&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        public:bool go(i_dev&dev);
        };
        class t_var_fv_end:public i_fv_end{
        public:
          class i_fv_item;
           class t_func_fv_item; class t_var_fv_item;
          class i_fv_item_visitor{
          public:
            typedef t_var_fv_end::i_fv_item i_fv_item;
          public:
             virtual void Do(t_func_fv_item*p)=0; virtual void Do(t_var_fv_item*p)=0;
          public:
             typedef t_var_fv_end::t_func_fv_item t_func_fv_item; typedef t_var_fv_end::t_var_fv_item t_var_fv_item;
          public:
            template<class TYPE,class Visitor>
            struct Is:public Visitor{
              TYPE*ptr;
              Is():ptr(nullptr){}
            public:
              template<class U>static TYPE*get(U*p){return nullptr;}
              template<>static TYPE*get<TYPE>(TYPE*p){return p;}
            public:
               void Do(t_func_fv_item*p){ptr=get(p);} void Do(t_var_fv_item*p){ptr=get(p);}
            };
            template<class TYPE>
            static TYPE*UberCast(i_fv_item*p){
              if(!p)return nullptr;Is<TYPE,i_fv_item_visitor> IS;p->Use(IS);return IS.ptr;
            }
          };
        public:
          class i_fv_item{
  public:typedef t_var_fv_end OwnerClass;;
  public:typedef i_fv_item SelfClass;;
  public:
    public:void DoReset();
  public:
    i_fv_item(const i_fv_item&)=delete;i_fv_item();;
  public:
    i_fv_item(i_fv_item&&_Right);
    void operator=(i_fv_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
          public:
            typedef i_fv_item_visitor i_visitor;virtual void Use(i_visitor&A);
          public:virtual bool go(i_dev&dev);;
            struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
            {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
            };
          };
          class t_func_fv_item:public i_fv_item{
  public:typedef t_var_fv_end OwnerClass;;
  public:typedef t_func_fv_item SelfClass;public:typedef i_fv_item ParentClass;;
  public:
   TAutoPtr<t_func_params> params;; TAutoPtr<t_const_with_sep> cv1;;
    public:void DoReset();
  public:
    t_func_fv_item(const t_func_fv_item&)=delete;t_func_fv_item();;
  public:
    t_func_fv_item(t_func_fv_item&&_Right);
    void operator=(t_func_fv_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
          public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
          public:bool go(i_dev&dev);
          };
          class t_var_fv_item:public i_fv_item{
  public:typedef t_var_fv_end OwnerClass;;
  public:typedef t_var_fv_item SelfClass;public:typedef i_fv_item ParentClass;;
  public:
   TAutoPtr<t_arr_body> arrbody;; TAutoPtr<t_func_param_value> value;;
    public:void DoReset();
  public:
    t_var_fv_item(const t_var_fv_item&)=delete;t_var_fv_item();;
  public:
    t_var_fv_item(t_var_fv_item&&_Right);
    void operator=(t_var_fv_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
          public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
          public:bool go(i_dev&dev);
          };
          class t_body{
  public:typedef t_var_fv_end OwnerClass;;
  public:typedef t_body SelfClass;;
  public:
   TAutoPtr<i_fv_item> body;;
    public:void DoReset();
  public:
    t_body(const t_body&)=delete;t_body();;
  public:
    t_body(t_body&&_Right);
    void operator=(t_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
          public:bool go(i_dev&dev);
          };
          class t_item{
  public:typedef t_var_fv_end OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_sep sep0;; TAutoPtr<t_const_with_sep> cv;; t_sep sep1;; string name;; t_sep sep2;; t_body body;; t_sep sep3;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
          public:bool go(i_dev&dev);
          };
        public:
  public:typedef t_fv_stat OwnerClass;;
  public:typedef t_var_fv_end SelfClass;public:typedef i_fv_end ParentClass;;
  public:
   TAutoPtr<t_body> body;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_var_fv_end(const t_var_fv_end&)=delete;t_var_fv_end();;
  public:
    t_var_fv_end(t_var_fv_end&&_Right);
    void operator=(t_var_fv_end&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
        public:bool go(i_dev&dev);
        public:
        };
      public:
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_fv_stat SelfClass;;
  public:
   t_sep sep_wa;; vector<t_keyword> keywords;; TAutoPtr<t_type_expr> type;; TAutoPtr<t_const_with_sep> cv;; t_sep sep0;; TAutoPtr<t_func_path> path;; t_name_part name;; t_sep sep1;; TAutoPtr<i_fv_end> way;;
    public:void DoReset();
  public:
    t_fv_stat(const t_fv_stat&)=delete;t_fv_stat();;
  public:
    t_fv_stat(t_fv_stat&&_Right);
    void operator=(t_fv_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      public:
      };
      class t_impl_typeexpr:public i_typeexpr{
      public:
        class t_global{
  public:typedef t_impl_typeexpr OwnerClass;;
  public:typedef t_global SelfClass;;
  public:
    public:void DoReset();
  public:
    t_global(const t_global&)=delete;t_global();;
  public:
    t_global(t_global&&_Right);
    void operator=(t_global&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
        public:bool go(i_dev&dev);
        };
      public:
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_impl_typeexpr SelfClass;public:typedef i_typeexpr ParentClass;;
  public:
   TAutoPtr<t_global> global;; t_sep sep;; t_scopes scopes;; vector<t_ptr> ptrs;; TAutoPtr<t_ref> ref;;
    public:void DoReset();
  public:
    t_impl_typeexpr(const t_impl_typeexpr&)=delete;t_impl_typeexpr();;
  public:
    t_impl_typeexpr(t_impl_typeexpr&&_Right);
    void operator=(t_impl_typeexpr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      };
      class t_decl_typeexpr:public i_typeexpr{
  public:typedef t_type_expr OwnerClass;;
  public:typedef t_decl_typeexpr SelfClass;public:typedef i_typeexpr ParentClass;;
  public:
   t_sep sep0;; t_sep sep1;; t_expr expr;; t_sep sep2;;
    public:void DoReset();
  public:
    t_decl_typeexpr(const t_decl_typeexpr&)=delete;t_decl_typeexpr();;
  public:
    t_decl_typeexpr(t_decl_typeexpr&&_Right);
    void operator=(t_decl_typeexpr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
      public:bool go(i_dev&dev);
      };
    public:
  public:typedef t_fv_class_stat OwnerClass;;
  public:typedef t_type_expr SelfClass;;
  public:
   TAutoPtr<i_typeexpr> body;;
    public:void DoReset();
  public:
    t_type_expr(const t_type_expr&)=delete;t_type_expr();;
  public:
    t_type_expr(t_type_expr&&_Right);
    void operator=(t_type_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    public:
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_fv_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_type_expr::t_fv_stat body;;
    public:void DoReset();
  public:
    t_fv_class_stat(const t_fv_class_stat&)=delete;t_fv_class_stat();;
  public:
    t_fv_class_stat(t_fv_class_stat&&_Right);
    void operator=(t_fv_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_typedef_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_typedef_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_sep sep;; t_fv_class_stat::t_type_expr::t_fv_stat body;;
    public:void DoReset();
  public:
    t_typedef_class_stat(const t_typedef_class_stat&)=delete;t_typedef_class_stat();;
  public:
    t_typedef_class_stat(t_typedef_class_stat&&_Right);
    void operator=(t_typedef_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_real{
  public:
    class t_f{
  public:typedef t_real OwnerClass;;
  public:typedef t_f SelfClass;;
  public:
   char body;;
    public:void DoReset();
  public:
    t_f(const t_f&)=delete;t_f();;
  public:
    t_f(t_f&&_Right);
    void operator=(t_f&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_real SelfClass;;
  public:
   string bef;; string aft;; TAutoPtr<t_f> ext;;
    public:void DoReset();
  public:
    t_real(const t_real&)=delete;t_real();;
  public:
    t_real(t_real&&_Right);
    void operator=(t_real&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_call_param{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_call_param SelfClass;;
  public:
   t_sep sep0;; t_expr expr;; t_sep sep1;;
    public:void DoReset();
  public:
    t_call_param(const t_call_param&)=delete;t_call_param();;
  public:
    t_call_param(t_call_param&&_Right);
    void operator=(t_call_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_call_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_call_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string func;; t_sep sep;; vector<t_call_param> arr;;
    public:void DoReset();
  public:
    t_call_expr(const t_call_expr&)=delete;t_call_expr();;
  public:
    t_call_expr(t_call_expr&&_Right);
    void operator=(t_call_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_block_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_block_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   t_sep sep0;; t_expr expr;; t_sep sep1;;
    public:void DoReset();
  public:
    t_block_expr(const t_block_expr&)=delete;t_block_expr();;
  public:
    t_block_expr(t_block_expr&&_Right);
    void operator=(t_block_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_bool_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_bool_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_bool_expr(const t_bool_expr&)=delete;t_bool_expr();;
  public:
    t_bool_expr(t_bool_expr&&_Right);
    void operator=(t_bool_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_string_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_string_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_string_expr(const t_string_expr&)=delete;t_string_expr();;
  public:
    t_string_expr(t_string_expr&&_Right);
    void operator=(t_string_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_char_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_char_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_char_expr(const t_char_expr&)=delete;t_char_expr();;
  public:
    t_char_expr(t_char_expr&&_Right);
    void operator=(t_char_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_num_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_num_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_num_expr(const t_num_expr&)=delete;t_num_expr();;
  public:
    t_num_expr(t_num_expr&&_Right);
    void operator=(t_num_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_real_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_real_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_real_expr(const t_real_expr&)=delete;t_real_expr();;
  public:
    t_real_expr(t_real_expr&&_Right);
    void operator=(t_real_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_nullptr_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_nullptr_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
    public:void DoReset();
  public:
    t_nullptr_expr(const t_nullptr_expr&)=delete;t_nullptr_expr();;
  public:
    t_nullptr_expr(t_nullptr_expr&&_Right);
    void operator=(t_nullptr_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_or_expr:public i_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_or_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   vector<t_name> arr;;
    public:void DoReset();
  public:
    t_or_expr(const t_or_expr&)=delete;t_or_expr();;
  public:
    t_or_expr(t_or_expr&&_Right);
    void operator=(t_or_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_hex_expr:public i_expr{
  public:
    class t_impl{
  public:typedef t_hex_expr OwnerClass;;
  public:typedef t_impl SelfClass;;
  public:
   char x;; string value;;
    public:void DoReset();
  public:
    t_impl(const t_impl&)=delete;t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_hex_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_hex_expr(const t_hex_expr&)=delete;t_hex_expr();;
  public:
    t_hex_expr(t_hex_expr&&_Right);
    void operator=(t_hex_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_var_expr:public i_expr{
  public:
    class t_item{
  public:typedef t_var_expr OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_type_with_sep body;; t_sep sep;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_field{
  public:typedef t_var_expr OwnerClass;;
  public:typedef t_field SelfClass;;
  public:
   t_sep bef;; string name;; t_sep aft;;
    public:void DoReset();
  public:
    t_field(const t_field&)=delete;t_field();;
  public:
    t_field(t_field&&_Right);
    void operator=(t_field&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_impl{
  public:typedef t_var_expr OwnerClass;;
  public:typedef t_impl SelfClass;;
  public:
   vector<t_item> items;; t_sep sep;; vector<t_field> arr;;
    public:void DoReset();
  public:
    t_impl(const t_impl&)=delete;t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_var_expr SelfClass;public:typedef i_expr ParentClass;;
  public:
   string name;;
    public:void DoReset();
  public:
    t_var_expr(const t_var_expr&)=delete;t_var_expr();;
  public:
    t_var_expr(t_var_expr&&_Right);
    void operator=(t_var_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  public:
  };
  class t_ctor_init_list{
  public:
    class t_init_param{
  public:typedef t_ctor_init_list OwnerClass;;
  public:typedef t_init_param SelfClass;;
  public:
   t_sep sep0;; string name;; vector<t_call_param> arr;; t_sep sep1;;
    public:void DoReset();
  public:
    t_init_param(const t_init_param&)=delete;t_init_param();;
  public:
    t_init_param(t_init_param&&_Right);
    void operator=(t_init_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_ctor_init_list SelfClass;;
  public:
   vector<t_init_param> params;; t_sep sep;;
    public:void DoReset();
  public:
    t_ctor_init_list(const t_ctor_init_list&)=delete;t_ctor_init_list();;
  public:
    t_ctor_init_list(t_ctor_init_list&&_Right);
    void operator=(t_ctor_init_list&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_zero_func_body:public i_func_body{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_zero_func_body SelfClass;public:typedef i_func_body ParentClass;;
  public:
    public:void DoReset();
  public:
    t_zero_func_body(const t_zero_func_body&)=delete;t_zero_func_body();;
  public:
    t_zero_func_body(t_zero_func_body&&_Right);
    void operator=(t_zero_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_null_func_body:public i_func_body{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_null_func_body SelfClass;public:typedef i_func_body ParentClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_null_func_body(const t_null_func_body&)=delete;t_null_func_body();;
  public:
    t_null_func_body(t_null_func_body&&_Right);
    void operator=(t_null_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_delete_func_body:public i_func_body{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_delete_func_body SelfClass;public:typedef i_func_body ParentClass;;
  public:
    public:void DoReset();
  public:
    t_delete_func_body(const t_delete_func_body&)=delete;t_delete_func_body();;
  public:
    t_delete_func_body(t_delete_func_body&&_Right);
    void operator=(t_delete_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_impl_func_body:public i_func_body{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_impl_func_body SelfClass;public:typedef i_func_body ParentClass;;
  public:
   t_sep sep;; TAutoPtr<t_ctor_init_list> init_list;; t_raw_func_body body;;
    public:void DoReset();
  public:
    t_impl_func_body(const t_impl_func_body&)=delete;t_impl_func_body();;
  public:
    t_impl_func_body(t_impl_func_body&&_Right);
    void operator=(t_impl_func_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_dtor_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_dtor_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_sep sep0;; TAutoPtr<t_func_path> path;; string name;; t_sep sep1;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<i_func_body> body;;
    public:void DoReset();
  public:
    t_dtor_class_stat(const t_dtor_class_stat&)=delete;t_dtor_class_stat();;
  public:
    t_dtor_class_stat(t_dtor_class_stat&&_Right);
    void operator=(t_dtor_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_ctor_class_stat:public i_class_stat{
  public:
    class t_impl{
    public:
      class t_explicit{
  public:typedef t_impl OwnerClass;;
  public:typedef t_explicit SelfClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_explicit(const t_explicit&)=delete;t_explicit();;
  public:
    t_explicit(t_explicit&&_Right);
    void operator=(t_explicit&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
    public:
  public:typedef t_ctor_class_stat OwnerClass;;
  public:typedef t_impl SelfClass;;
  public:
   TAutoPtr<t_explicit> prefix;; TAutoPtr<t_func_path> path;; string name;; t_sep sep1;; TAutoPtr<t_concrete_params> concrete_params;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<i_func_body> body;;
    public:void DoReset();
  public:
    t_impl(const t_impl&)=delete;t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_ctor_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_impl body;;
    public:void DoReset();
  public:
    t_ctor_class_stat(const t_ctor_class_stat&)=delete;t_ctor_class_stat();;
  public:
    t_ctor_class_stat(t_ctor_class_stat&&_Right);
    void operator=(t_ctor_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_oper_cast_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_oper_cast_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   TAutoPtr<t_func_path> path;; t_sep sep0;; t_fv_class_stat::t_type_expr type;; t_sep sep1;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<t_const_with_sep> cv;; TAutoPtr<i_func_body> body;;
    public:void DoReset();
  public:
    t_oper_cast_class_stat(const t_oper_cast_class_stat&)=delete;t_oper_cast_class_stat();;
  public:
    t_oper_cast_class_stat(t_oper_cast_class_stat&&_Right);
    void operator=(t_oper_cast_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_common_oper_class_stat:public i_class_stat{
  public:
    class t_impl{
  public:typedef t_common_oper_class_stat OwnerClass;;
  public:typedef t_impl SelfClass;;
  public:
   vector<t_keyword> keywords;; t_fv_class_stat::t_type_expr type;; TAutoPtr<t_const_with_sep> cv0;; t_sep sep0;; TAutoPtr<t_func_path> path;; t_sep sep1;; string oper;; t_fv_class_stat::t_type_expr::t_func_params params;; TAutoPtr<t_const_with_sep> cv1;; TAutoPtr<i_func_body> body;;
    public:void DoReset();
  public:
    t_impl(const t_impl&)=delete;t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_common_oper_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_impl body;;
    public:void DoReset();
  public:
    t_common_oper_class_stat(const t_common_oper_class_stat&)=delete;t_common_oper_class_stat();;
  public:
    t_common_oper_class_stat(t_common_oper_class_stat&&_Right);
    void operator=(t_common_oper_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_parents{
  public:
    class t_item{
    public:
      class t_pub{
  public:typedef t_item OwnerClass;;
  public:typedef t_pub SelfClass;;
  public:
   t_access_mod mod;; t_sep sep;;
    public:void DoReset();
  public:
    t_pub(const t_pub&)=delete;t_pub();;
  public:
    t_pub(t_pub&&_Right);
    void operator=(t_pub&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
    public:
  public:typedef t_parents OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_sep sep;; TAutoPtr<t_pub> pub;; string name;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_parents SelfClass;;
  public:
   t_sep sep;; vector<t_item> arr;;
    public:void DoReset();
  public:
    t_parents(const t_parents&)=delete;t_parents();;
  public:
    t_parents(t_parents&&_Right);
    void operator=(t_parents&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_class_body{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_class_body SelfClass;;
  public:
   vector<TAutoPtr<i_class_stat>> arr;;
    public:void DoReset();
  public:
    t_class_body(const t_class_body&)=delete;t_class_body();;
  public:
    t_class_body(t_class_body&&_Right);
    void operator=(t_class_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_class{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_class SelfClass;;
  public:
   string keyword;; t_sep sep0;; string name;; t_sep sep1;; TAutoPtr<t_parents> parents;; t_sep sep2;; TAutoPtr<t_class_body> body;; t_sep sep3;;
    public:void DoReset();
  public:
    t_class(const t_class&)=delete;t_class();;
  public:
    t_class(t_class&&_Right);
    void operator=(t_class&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_namespace_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_namespace_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_sep sep0;; string name;; t_sep sep1;; t_class_body body;;
    public:void DoReset();
  public:
    t_namespace_class_stat(const t_namespace_class_stat&)=delete;t_namespace_class_stat();;
  public:
    t_namespace_class_stat(t_namespace_class_stat&&_Right);
    void operator=(t_namespace_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_template_class_stat:public i_class_stat{
  public:
    class i_template_body;
     class t_common_oper_template_body; class t_ctor_template_body; class t_func_template_body; class class_template_body;
    class i_template_body_visitor{
    public:
      typedef t_template_class_stat::i_template_body i_template_body;
    public:
       virtual void Do(t_common_oper_template_body*p)=0; virtual void Do(t_ctor_template_body*p)=0; virtual void Do(t_func_template_body*p)=0; virtual void Do(class_template_body*p)=0;
    public:
       typedef t_template_class_stat::t_common_oper_template_body t_common_oper_template_body; typedef t_template_class_stat::t_ctor_template_body t_ctor_template_body; typedef t_template_class_stat::t_func_template_body t_func_template_body; typedef t_template_class_stat::class_template_body class_template_body;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      public:
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      public:
         void Do(t_common_oper_template_body*p){ptr=get(p);} void Do(t_ctor_template_body*p){ptr=get(p);} void Do(t_func_template_body*p){ptr=get(p);} void Do(class_template_body*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_body*p){
        if(!p)return nullptr;Is<TYPE,i_template_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  public:
    class i_template_body{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef i_template_body SelfClass;;
  public:
    public:void DoReset();
  public:
    i_template_body(const i_template_body&)=delete;i_template_body();;
  public:
    i_template_body(i_template_body&&_Right);
    void operator=(i_template_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:
      typedef i_template_body_visitor i_visitor;virtual void Use(i_visitor&A);
    public:virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
  public:
    class i_template_param;
     class t_name_template_param; class t_type_template_param;
    class i_template_param_visitor{
    public:
      typedef t_template_class_stat::i_template_param i_template_param;
    public:
       virtual void Do(t_name_template_param*p)=0; virtual void Do(t_type_template_param*p)=0;
    public:
       typedef t_template_class_stat::t_name_template_param t_name_template_param; typedef t_template_class_stat::t_type_template_param t_type_template_param;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      public:
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      public:
         void Do(t_name_template_param*p){ptr=get(p);} void Do(t_type_template_param*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_template_param*p){
        if(!p)return nullptr;Is<TYPE,i_template_param_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  public:
    class i_template_param{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef i_template_param SelfClass;;
  public:
    public:void DoReset();
  public:
    i_template_param(const i_template_param&)=delete;i_template_param();;
  public:
    i_template_param(i_template_param&&_Right);
    void operator=(i_template_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:
      typedef i_template_param_visitor i_visitor;virtual void Use(i_visitor&A);
    public:virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_template_param{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef t_template_param SelfClass;;
  public:
   t_sep bef;; TAutoPtr<i_template_param> body;; t_sep aft;;
    public:void DoReset();
  public:
    t_template_param(const t_template_param&)=delete;t_template_param();;
  public:
    t_template_param(t_template_param&&_Right);
    void operator=(t_template_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_common_oper_template_body:public i_template_body{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef t_common_oper_template_body SelfClass;public:typedef i_template_body ParentClass;;
  public:
   t_common_oper_class_stat::t_impl body;;
    public:void DoReset();
  public:
    t_common_oper_template_body(const t_common_oper_template_body&)=delete;t_common_oper_template_body();;
  public:
    t_common_oper_template_body(t_common_oper_template_body&&_Right);
    void operator=(t_common_oper_template_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_ctor_template_body:public i_template_body{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef t_ctor_template_body SelfClass;public:typedef i_template_body ParentClass;;
  public:
   t_ctor_class_stat::t_impl body;;
    public:void DoReset();
  public:
    t_ctor_template_body(const t_ctor_template_body&)=delete;t_ctor_template_body();;
  public:
    t_ctor_template_body(t_ctor_template_body&&_Right);
    void operator=(t_ctor_template_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_func_template_body:public i_template_body{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef t_func_template_body SelfClass;public:typedef i_template_body ParentClass;;
  public:
   vector<t_keyword> keywords;; t_fv_class_stat::t_type_expr type;; TAutoPtr<t_const_with_sep> cv0;; t_sep sep0;; string func_name;; TAutoPtr<t_concrete_params> concrete_params;; t_sep sep1;; t_fv_class_stat::t_type_expr::t_func_params params;; t_sep sep2;; TAutoPtr<t_const_with_sep> cv1;; TAutoPtr<i_func_body> body;;
    public:void DoReset();
  public:
    t_func_template_body(const t_func_template_body&)=delete;t_func_template_body();;
  public:
    t_func_template_body(t_func_template_body&&_Right);
    void operator=(t_func_template_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class class_template_body:public i_template_body{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef class_template_body SelfClass;public:typedef i_template_body ParentClass;;
  public:
   string keyword;; t_sep sep0;; string name;; t_sep sep1;; TAutoPtr<t_concrete_params> params;; TAutoPtr<t_parents> parents;; t_sep sep2;; TAutoPtr<t_class_body> body;; t_sep sep3;;
    public:void DoReset();
  public:
    class_template_body(const class_template_body&)=delete;class_template_body();;
  public:
    class_template_body(class_template_body&&_Right);
    void operator=(class_template_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_name_template_param:public i_template_param{
    public:
      class t_unsgnd{
  public:typedef t_name_template_param OwnerClass;;
  public:typedef t_unsgnd SelfClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_unsgnd(const t_unsgnd&)=delete;t_unsgnd();;
  public:
    t_unsgnd(t_unsgnd&&_Right);
    void operator=(t_unsgnd&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
      class t_value{
  public:typedef t_name_template_param OwnerClass;;
  public:typedef t_value SelfClass;;
  public:
   t_expr body;; t_sep sep;;
    public:void DoReset();
  public:
    t_value(const t_value&)=delete;t_value();;
  public:
    t_value(t_value&&_Right);
    void operator=(t_value&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
      public:bool go(i_dev&dev);
      };
    public:
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef t_name_template_param SelfClass;public:typedef i_template_param ParentClass;;
  public:
   string unsgnd0;; t_sep sep0;; string type;; t_sep sep1;; string unsgnd1;; t_sep sep2;; string name;; t_sep sep3;; TAutoPtr<t_value> value;;
    public:void DoReset();
  public:
    t_name_template_param(const t_name_template_param&)=delete;t_name_template_param();;
  public:
    t_name_template_param(t_name_template_param&&_Right);
    void operator=(t_name_template_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_head{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef t_head SelfClass;;
  public:
   t_sep sep0;; vector<t_template_param> params;; t_sep sep1;;
    public:void DoReset();
  public:
    t_head(const t_head&)=delete;t_head();;
  public:
    t_head(t_head&&_Right);
    void operator=(t_head&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_type_template_param:public i_template_param{
  public:typedef t_template_class_stat OwnerClass;;
  public:typedef t_type_template_param SelfClass;public:typedef i_template_param ParentClass;;
  public:
   TAutoPtr<t_head> head;; string type;; t_sep sep;; string name;;
    public:void DoReset();
  public:
    t_type_template_param(const t_type_template_param&)=delete;t_type_template_param();;
  public:
    t_type_template_param(t_type_template_param&&_Right);
    void operator=(t_type_template_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_template_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_head head;; TAutoPtr<i_template_body> body;;
    public:void DoReset();
  public:
    t_template_class_stat(const t_template_class_stat&)=delete;t_template_class_stat();;
  public:
    t_template_class_stat(t_template_class_stat&&_Right);
    void operator=(t_template_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  public:
  };
  class t_enum_class_stat:public i_class_stat{
  public:
    class i_body;
     class t_impl_body; class t_empty_body;
    class i_body_visitor{
    public:
      typedef t_enum_class_stat::i_body i_body;
    public:
       virtual void Do(t_impl_body*p)=0; virtual void Do(t_empty_body*p)=0;
    public:
       typedef t_enum_class_stat::t_impl_body t_impl_body; typedef t_enum_class_stat::t_empty_body t_empty_body;
    public:
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr;
        Is():ptr(nullptr){}
      public:
        template<class U>static TYPE*get(U*p){return nullptr;}
        template<>static TYPE*get<TYPE>(TYPE*p){return p;}
      public:
         void Do(t_impl_body*p){ptr=get(p);} void Do(t_empty_body*p){ptr=get(p);}
      };
      template<class TYPE>
      static TYPE*UberCast(i_body*p){
        if(!p)return nullptr;Is<TYPE,i_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
    };
  public:
    class i_body{
  public:typedef t_enum_class_stat OwnerClass;;
  public:typedef i_body SelfClass;;
  public:
    public:void DoReset();
  public:
    i_body(const i_body&)=delete;i_body();;
  public:
    i_body(i_body&&_Right);
    void operator=(i_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:
      typedef i_body_visitor i_visitor;virtual void Use(i_visitor&A);
    public:virtual bool go(i_dev&dev);;
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;bool load();static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref);static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref);
      };
    };
    class t_value{
  public:typedef t_enum_class_stat OwnerClass;;
  public:typedef t_value SelfClass;;
  public:
   t_sep sep0;; t_expr expr;; t_sep sep1;;
    public:void DoReset();
  public:
    t_value(const t_value&)=delete;t_value();;
  public:
    t_value(t_value&&_Right);
    void operator=(t_value&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_item{
  public:typedef t_enum_class_stat OwnerClass;;
  public:typedef t_item SelfClass;;
  public:
   t_sep sep0;; string name;; t_sep sep1;; TAutoPtr<t_value> value;;
    public:void DoReset();
  public:
    t_item(const t_item&)=delete;t_item();;
  public:
    t_item(t_item&&_Right);
    void operator=(t_item&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_comma_with_sep{
  public:typedef t_enum_class_stat OwnerClass;;
  public:typedef t_comma_with_sep SelfClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_comma_with_sep(const t_comma_with_sep&)=delete;t_comma_with_sep();;
  public:
    t_comma_with_sep(t_comma_with_sep&&_Right);
    void operator=(t_comma_with_sep&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
    class t_impl_body:public i_body{
  public:typedef t_enum_class_stat OwnerClass;;
  public:typedef t_impl_body SelfClass;public:typedef i_body ParentClass;;
  public:
   vector<t_item> arr;; TAutoPtr<t_comma_with_sep> comma;;
    public:void DoReset();
  public:
    t_impl_body(const t_impl_body&)=delete;t_impl_body();;
  public:
    t_impl_body(t_impl_body&&_Right);
    void operator=(t_impl_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_empty_body:public i_body{
  public:typedef t_enum_class_stat OwnerClass;;
  public:typedef t_empty_body SelfClass;public:typedef i_body ParentClass;;
  public:
    public:void DoReset();
  public:
    t_empty_body(const t_empty_body&)=delete;t_empty_body();;
  public:
    t_empty_body(t_empty_body&&_Right);
    void operator=(t_empty_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
    public:bool go(i_dev&dev);
    };
    class t_body{
  public:typedef t_enum_class_stat OwnerClass;;
  public:typedef t_body SelfClass;;
  public:
   TAutoPtr<i_body> body;;
    public:void DoReset();
  public:
    t_body(const t_body&)=delete;t_body();;
  public:
    t_body(t_body&&_Right);
    void operator=(t_body&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_enum_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_sep sep0;; string name;; t_sep sep1;; t_body body;;
    public:void DoReset();
  public:
    t_enum_class_stat(const t_enum_class_stat&)=delete;t_enum_class_stat();;
  public:
    t_enum_class_stat(t_enum_class_stat&&_Right);
    void operator=(t_enum_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  public:
  };
  class t_using_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_using_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_sep sep;; t_fv_class_stat::t_type_expr type;;
    public:void DoReset();
  public:
    t_using_class_stat(const t_using_class_stat&)=delete;t_using_class_stat();;
  public:
    t_using_class_stat(t_using_class_stat&&_Right);
    void operator=(t_using_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_tmpl_call_param{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_tmpl_call_param SelfClass;;
  public:
   t_sep sep0;; t_tmpl_expr expr;; t_sep sep1;;
    public:void DoReset();
  public:
    t_tmpl_call_param(const t_tmpl_call_param&)=delete;t_tmpl_call_param();;
  public:
    t_tmpl_call_param(t_tmpl_call_param&&_Right);
    void operator=(t_tmpl_call_param&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
  class t_call_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_call_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string func;; t_sep sep;; vector<t_tmpl_call_param> arr;;
    public:void DoReset();
  public:
    t_call_tmpl_expr(const t_call_tmpl_expr&)=delete;t_call_tmpl_expr();;
  public:
    t_call_tmpl_expr(t_call_tmpl_expr&&_Right);
    void operator=(t_call_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_block_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_block_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   t_sep sep0;; t_tmpl_expr expr;; t_sep sep1;;
    public:void DoReset();
  public:
    t_block_tmpl_expr(const t_block_tmpl_expr&)=delete;t_block_tmpl_expr();;
  public:
    t_block_tmpl_expr(t_block_tmpl_expr&&_Right);
    void operator=(t_block_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_pfunc_concrete_param_way:public i_concrete_param_way{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_pfunc_concrete_param_way SelfClass;public:typedef i_concrete_param_way ParentClass;;
  public:
   t_fv_class_stat::t_type_expr::t_pfunc value;;
    public:void DoReset();
  public:
    t_pfunc_concrete_param_way(const t_pfunc_concrete_param_way&)=delete;t_pfunc_concrete_param_way();;
  public:
    t_pfunc_concrete_param_way(t_pfunc_concrete_param_way&&_Right);
    void operator=(t_pfunc_concrete_param_way&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_type_concrete_param_way:public i_concrete_param_way{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_type_concrete_param_way SelfClass;public:typedef i_concrete_param_way ParentClass;;
  public:
   t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv value;;
    public:void DoReset();
  public:
    t_type_concrete_param_way(const t_type_concrete_param_way&)=delete;t_type_concrete_param_way();;
  public:
    t_type_concrete_param_way(t_type_concrete_param_way&&_Right);
    void operator=(t_type_concrete_param_way&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_expr_concrete_param_way:public i_concrete_param_way{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_expr_concrete_param_way SelfClass;public:typedef i_concrete_param_way ParentClass;;
  public:
   t_tmpl_expr value;;
    public:void DoReset();
  public:
    t_expr_concrete_param_way(const t_expr_concrete_param_way&)=delete;t_expr_concrete_param_way();;
  public:
    t_expr_concrete_param_way(t_expr_concrete_param_way&&_Right);
    void operator=(t_expr_concrete_param_way&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_bool_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_bool_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_bool_tmpl_expr(const t_bool_tmpl_expr&)=delete;t_bool_tmpl_expr();;
  public:
    t_bool_tmpl_expr(t_bool_tmpl_expr&&_Right);
    void operator=(t_bool_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_string_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_string_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_string_tmpl_expr(const t_string_tmpl_expr&)=delete;t_string_tmpl_expr();;
  public:
    t_string_tmpl_expr(t_string_tmpl_expr&&_Right);
    void operator=(t_string_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_char_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_char_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_char_tmpl_expr(const t_char_tmpl_expr&)=delete;t_char_tmpl_expr();;
  public:
    t_char_tmpl_expr(t_char_tmpl_expr&&_Right);
    void operator=(t_char_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_num_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_num_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_num_tmpl_expr(const t_num_tmpl_expr&)=delete;t_num_tmpl_expr();;
  public:
    t_num_tmpl_expr(t_num_tmpl_expr&&_Right);
    void operator=(t_num_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_real_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_real_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_real_tmpl_expr(const t_real_tmpl_expr&)=delete;t_real_tmpl_expr();;
  public:
    t_real_tmpl_expr(t_real_tmpl_expr&&_Right);
    void operator=(t_real_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_nullptr_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_nullptr_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
    public:void DoReset();
  public:
    t_nullptr_tmpl_expr(const t_nullptr_tmpl_expr&)=delete;t_nullptr_tmpl_expr();;
  public:
    t_nullptr_tmpl_expr(t_nullptr_tmpl_expr&&_Right);
    void operator=(t_nullptr_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_or_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_or_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   vector<t_name> arr;;
    public:void DoReset();
  public:
    t_or_tmpl_expr(const t_or_tmpl_expr&)=delete;t_or_tmpl_expr();;
  public:
    t_or_tmpl_expr(t_or_tmpl_expr&&_Right);
    void operator=(t_or_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_hex_tmpl_expr:public i_tmpl_expr{
  public:
    class t_impl{
  public:typedef t_hex_tmpl_expr OwnerClass;;
  public:typedef t_impl SelfClass;;
  public:
   char x;; string value;;
    public:void DoReset();
  public:
    t_impl(const t_impl&)=delete;t_impl();;
  public:
    t_impl(t_impl&&_Right);
    void operator=(t_impl&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
    public:bool go(i_dev&dev);
    };
  public:
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_hex_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string value;;
    public:void DoReset();
  public:
    t_hex_tmpl_expr(const t_hex_tmpl_expr&)=delete;t_hex_tmpl_expr();;
  public:
    t_hex_tmpl_expr(t_hex_tmpl_expr&&_Right);
    void operator=(t_hex_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_var_tmpl_expr:public i_tmpl_expr{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_var_tmpl_expr SelfClass;public:typedef i_tmpl_expr ParentClass;;
  public:
   string name;;
    public:void DoReset();
  public:
    t_var_tmpl_expr(const t_var_tmpl_expr&)=delete;t_var_tmpl_expr();;
  public:
    t_var_tmpl_expr(t_var_tmpl_expr&&_Right);
    void operator=(t_var_tmpl_expr&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_pragma_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_pragma_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_pragma_class_stat(const t_pragma_class_stat&)=delete;t_pragma_class_stat();;
  public:
    t_pragma_class_stat(t_pragma_class_stat&&_Right);
    void operator=(t_pragma_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_include_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_include_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_include_class_stat(const t_include_class_stat&)=delete;t_include_class_stat();;
  public:
    t_include_class_stat(t_include_class_stat&&_Right);
    void operator=(t_include_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_preproc_if_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_preproc_if_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_preproc_if_class_stat(const t_preproc_if_class_stat&)=delete;t_preproc_if_class_stat();;
  public:
    t_preproc_if_class_stat(t_preproc_if_class_stat&&_Right);
    void operator=(t_preproc_if_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_preproc_else_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_preproc_else_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_preproc_else_class_stat(const t_preproc_else_class_stat&)=delete;t_preproc_else_class_stat();;
  public:
    t_preproc_else_class_stat(t_preproc_else_class_stat&&_Right);
    void operator=(t_preproc_else_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_preproc_endif_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_preproc_endif_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_preproc_endif_class_stat(const t_preproc_endif_class_stat&)=delete;t_preproc_endif_class_stat();;
  public:
    t_preproc_endif_class_stat(t_preproc_endif_class_stat&&_Right);
    void operator=(t_preproc_endif_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_define_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_define_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_define_class_stat(const t_define_class_stat&)=delete;t_define_class_stat();;
  public:
    t_define_class_stat(t_define_class_stat&&_Right);
    void operator=(t_define_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_undef_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_undef_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   string body;;
    public:void DoReset();
  public:
    t_undef_class_stat(const t_undef_class_stat&)=delete;t_undef_class_stat();;
  public:
    t_undef_class_stat(t_undef_class_stat&&_Right);
    void operator=(t_undef_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_sep_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_sep_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_sep sep;;
    public:void DoReset();
  public:
    t_sep_class_stat(const t_sep_class_stat&)=delete;t_sep_class_stat();;
  public:
    t_sep_class_stat(t_sep_class_stat&&_Right);
    void operator=(t_sep_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_null_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_null_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
    public:void DoReset();
  public:
    t_null_class_stat(const t_null_class_stat&)=delete;t_null_class_stat();;
  public:
    t_null_class_stat(t_null_class_stat&&_Right);
    void operator=(t_null_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_class_class_stat:public i_class_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_class_class_stat SelfClass;public:typedef i_class_stat ParentClass;;
  public:
   t_class body;;
    public:void DoReset();
  public:
    t_class_class_stat(const t_class_class_stat&)=delete;t_class_class_stat();;
  public:
    t_class_class_stat(t_class_class_stat&&_Right);
    void operator=(t_class_class_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:void Use(i_visitor&A);static SelfClass*UberCast(ParentClass*ptr);
  public:bool go(i_dev&dev);
  };
  class t_inl_file_stat{
  public:typedef t_inl_file OwnerClass;;
  public:typedef t_inl_file_stat SelfClass;;
  public:
   t_sep sep;; TAutoPtr<t_class> body;;
    public:void DoReset();
  public:
    t_inl_file_stat(const t_inl_file_stat&)=delete;t_inl_file_stat();;
  public:
    t_inl_file_stat(t_inl_file_stat&&_Right);
    void operator=(t_inl_file_stat&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
  public:bool go(i_dev&dev);
  };
public:
  ;
  public:typedef t_inl_file SelfClass;;
  public:
  vector<TAutoPtr<i_class_stat>> arr;;
    public:void DoReset();
  public:
    t_inl_file(const t_inl_file&)=delete;t_inl_file();;
  public:
    t_inl_file(t_inl_file&&_Right);
    void operator=(t_inl_file&&_Right);
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;static metatype*GetRTTI(IEnvRTTI&RTTI);static string GetFullName();
    };
  public:
public:bool go(i_dev&dev);
public:
};
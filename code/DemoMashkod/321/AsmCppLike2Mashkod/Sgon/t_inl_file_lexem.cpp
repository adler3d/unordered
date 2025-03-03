#include "ph.h"
#include "t_inl_file_lexem.h"

void t_inl_file::i_class_stat::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::i_class_stat::i_class_stat(){DoReset();}
t_inl_file::i_class_stat::i_class_stat(i_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::i_class_stat::operator=(i_class_stat&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::i_class_stat::ProxySys$$::metatype*t_inl_file::i_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_class_stat";;;
      }
void t_inl_file::i_class_stat::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::i_class_stat::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::i_class_stat::t_poly_impl::load()
      {
        go_for<t_access_mod_class_stat>();;
        go_for<t_fv_class_stat>();;
        go_for<t_typedef_class_stat>();;
        go_for<t_dtor_class_stat>();;
        go_for<t_ctor_class_stat>();;
        go_for<t_oper_cast_class_stat>();;
        go_for<t_common_oper_class_stat>();;
        go_for<t_namespace_class_stat>();;
        go_for<t_template_class_stat>();;
        go_for<t_enum_class_stat>();;
        go_for<t_using_class_stat>();;
        go_for<t_pragma_class_stat>();;
        go_for<t_include_class_stat>();;
        go_for<t_preproc_if_class_stat>();;
        go_for<t_preproc_else_class_stat>();;
        go_for<t_preproc_endif_class_stat>();;
        go_for<t_define_class_stat>();;
        go_for<t_undef_class_stat>();;
        go_for<t_sep_class_stat>();;
        go_for<t_null_class_stat>();;
        go_for<t_class_class_stat>();;
        (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_class_stat::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::i_expr::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::i_expr::i_expr(){DoReset();}
t_inl_file::i_expr::i_expr(i_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::i_expr::operator=(i_expr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::i_expr::ProxySys$$::metatype*t_inl_file::i_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_expr";;;
      }
void t_inl_file::i_expr::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::i_expr::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::i_expr::t_poly_impl::load()
      {
        go_for<t_block_expr>();;
        go_for<t_bool_expr>();;
        go_for<t_string_expr>();;
        go_for<t_char_expr>();;
        go_for<t_num_expr>();;
        go_for<t_real_expr>();;
        go_for<t_nullptr_expr>();;
        go_for<t_or_expr>();;
        go_for<t_hex_expr>();;
        go_for<t_var_expr>();;
        (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_expr::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::i_func_body::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::i_func_body::i_func_body(){DoReset();}
t_inl_file::i_func_body::i_func_body(i_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::i_func_body::operator=(i_func_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::i_func_body::ProxySys$$::metatype*t_inl_file::i_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_func_body";;;
      }
void t_inl_file::i_func_body::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::i_func_body::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::i_func_body::t_poly_impl::load()
      {
        go_for<t_zero_func_body>();;
        go_for<t_null_func_body>();;
        go_for<t_delete_func_body>();;
        go_for<t_impl_func_body>();;
        (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_func_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::i_tmpl_expr::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::i_tmpl_expr::i_tmpl_expr(){DoReset();}
t_inl_file::i_tmpl_expr::i_tmpl_expr(i_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::i_tmpl_expr::operator=(i_tmpl_expr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::i_tmpl_expr::ProxySys$$::metatype*t_inl_file::i_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
string t_inl_file::i_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "i_tmpl_expr";;;
      }
void t_inl_file::i_tmpl_expr::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::i_tmpl_expr::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::i_tmpl_expr::t_poly_impl::load()
      {
        go_for<t_call_tmpl_expr>();;
        go_for<t_block_tmpl_expr>();;
        go_for<t_bool_tmpl_expr>();;
        go_for<t_string_tmpl_expr>();;
        go_for<t_char_tmpl_expr>();;
        go_for<t_num_tmpl_expr>();;
        go_for<t_real_tmpl_expr>();;
        go_for<t_nullptr_tmpl_expr>();;
        go_for<t_or_tmpl_expr>();;
        go_for<t_hex_tmpl_expr>();;
        go_for<t_var_tmpl_expr>();;
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
bool t_inl_file::i_tmpl_expr::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_tmpl_expr::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::i_concrete_param_way::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::i_concrete_param_way::i_concrete_param_way(){DoReset();}
t_inl_file::i_concrete_param_way::i_concrete_param_way(i_concrete_param_way&&_Right){operator=(std::move(_Right));}
void t_inl_file::i_concrete_param_way::operator=(i_concrete_param_way&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::i_concrete_param_way::ProxySys$$::metatype*t_inl_file::i_concrete_param_way::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_concrete_param_way";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
string t_inl_file::i_concrete_param_way::ProxySys$$::GetFullName()
      {
        return "i_concrete_param_way";;;
      }
void t_inl_file::i_concrete_param_way::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::i_concrete_param_way::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::i_concrete_param_way::t_poly_impl::load()
      {
        go_for<t_pfunc_concrete_param_way>();;
        go_for<t_type_concrete_param_way>();;
        go_for<t_expr_concrete_param_way>();;
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
bool t_inl_file::i_concrete_param_way::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::i_concrete_param_way::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_lev03::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev03::t_lev03(){DoReset();}
t_inl_file::t_lev03::t_lev03(t_lev03&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev03::operator=(t_lev03&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev03::ProxySys$$::metatype*t_inl_file::t_lev03::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev03";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_expr>>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_lev03";;;
      }
bool t_inl_file::t_lev03::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("&,*,+,-,!,~",","));
      O+=dev.go_any_str_from_vec(oper,g_static_var_0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev05::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev05::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev05::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev05::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev05::t_oper::ProxySys$$::metatype*t_inl_file::t_lev05::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev05::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,%",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev05::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev05::t_item::t_item(){DoReset();}
t_inl_file::t_lev05::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev05::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev05::t_item::ProxySys$$::metatype*t_inl_file::t_lev05::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev05::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev05::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev05::t_lev05(){DoReset();}
t_inl_file::t_lev05::t_lev05(t_lev05&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev05::operator=(t_lev05&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev05::ProxySys$$::metatype*t_inl_file::t_lev05::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev05";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev05::ProxySys$$::GetFullName()
      {
        return "t_lev05";;;
      }
bool t_inl_file::t_lev05::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev06::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev06::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev06::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev06::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev06::t_oper::ProxySys$$::metatype*t_inl_file::t_lev06::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev06::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev06::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev06::t_item::t_item(){DoReset();}
t_inl_file::t_lev06::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev06::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev06::t_item::ProxySys$$::metatype*t_inl_file::t_lev06::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev06::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev06::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev06::t_lev06(){DoReset();}
t_inl_file::t_lev06::t_lev06(t_lev06&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev06::operator=(t_lev06&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev06::ProxySys$$::metatype*t_inl_file::t_lev06::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev06";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev06::ProxySys$$::GetFullName()
      {
        return "t_lev06";;;
      }
bool t_inl_file::t_lev06::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev07::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev07::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev07::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev07::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev07::t_oper::ProxySys$$::metatype*t_inl_file::t_lev07::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev07::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<<,>>",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev07::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev07::t_item::t_item(){DoReset();}
t_inl_file::t_lev07::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev07::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev07::t_item::ProxySys$$::metatype*t_inl_file::t_lev07::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev07::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev07::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev07::t_lev07(){DoReset();}
t_inl_file::t_lev07::t_lev07(t_lev07&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev07::operator=(t_lev07&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev07::ProxySys$$::metatype*t_inl_file::t_lev07::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev07";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev07::ProxySys$$::GetFullName()
      {
        return "t_lev07";;;
      }
bool t_inl_file::t_lev07::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev08::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev08::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev08::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev08::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev08::t_oper::ProxySys$$::metatype*t_inl_file::t_lev08::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev08::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<,<=,>,>=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev08::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev08::t_item::t_item(){DoReset();}
t_inl_file::t_lev08::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev08::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev08::t_item::ProxySys$$::metatype*t_inl_file::t_lev08::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev07>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev08::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev08::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev08::t_lev08(){DoReset();}
t_inl_file::t_lev08::t_lev08(t_lev08&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev08::operator=(t_lev08&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev08::ProxySys$$::metatype*t_inl_file::t_lev08::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev08";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev07>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev08::ProxySys$$::GetFullName()
      {
        return "t_lev08";;;
      }
bool t_inl_file::t_lev08::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev09::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev09::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev09::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev09::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev09::t_oper::ProxySys$$::metatype*t_inl_file::t_lev09::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev09::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("==,!=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev09::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev09::t_item::t_item(){DoReset();}
t_inl_file::t_lev09::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev09::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev09::t_item::ProxySys$$::metatype*t_inl_file::t_lev09::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev08>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev09::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev09::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev09::t_lev09(){DoReset();}
t_inl_file::t_lev09::t_lev09(t_lev09&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev09::operator=(t_lev09&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev09::ProxySys$$::metatype*t_inl_file::t_lev09::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev09";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev08>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev09::ProxySys$$::GetFullName()
      {
        return "t_lev09";;;
      }
bool t_inl_file::t_lev09::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev10::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev10::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev10::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev10::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev10::t_oper::ProxySys$$::metatype*t_inl_file::t_lev10::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev10::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev10::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev10::t_item::t_item(){DoReset();}
t_inl_file::t_lev10::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev10::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev10::t_item::ProxySys$$::metatype*t_inl_file::t_lev10::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev10::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev10::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev10::t_lev10(){DoReset();}
t_inl_file::t_lev10::t_lev10(t_lev10&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev10::operator=(t_lev10&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev10::ProxySys$$::metatype*t_inl_file::t_lev10::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev10";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev10::ProxySys$$::GetFullName()
      {
        return "t_lev10";;;
      }
bool t_inl_file::t_lev10::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev11::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev11::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev11::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev11::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev11::t_oper::ProxySys$$::metatype*t_inl_file::t_lev11::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev11::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("^",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev11::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev11::t_item::t_item(){DoReset();}
t_inl_file::t_lev11::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev11::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev11::t_item::ProxySys$$::metatype*t_inl_file::t_lev11::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev11::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev11::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev11::t_lev11(){DoReset();}
t_inl_file::t_lev11::t_lev11(t_lev11&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev11::operator=(t_lev11&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev11::ProxySys$$::metatype*t_inl_file::t_lev11::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev11";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev11::ProxySys$$::GetFullName()
      {
        return "t_lev11";;;
      }
bool t_inl_file::t_lev11::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev12::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev12::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev12::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev12::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev12::t_oper::ProxySys$$::metatype*t_inl_file::t_lev12::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev12::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("|",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev12::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev12::t_item::t_item(){DoReset();}
t_inl_file::t_lev12::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev12::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev12::t_item::ProxySys$$::metatype*t_inl_file::t_lev12::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev12::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev12::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev12::t_lev12(){DoReset();}
t_inl_file::t_lev12::t_lev12(t_lev12&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev12::operator=(t_lev12&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev12::ProxySys$$::metatype*t_inl_file::t_lev12::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev12";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev12::ProxySys$$::GetFullName()
      {
        return "t_lev12";;;
      }
bool t_inl_file::t_lev12::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev13::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev13::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev13::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev13::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev13::t_oper::ProxySys$$::metatype*t_inl_file::t_lev13::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev13::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev13::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev13::t_item::t_item(){DoReset();}
t_inl_file::t_lev13::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev13::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev13::t_item::ProxySys$$::metatype*t_inl_file::t_lev13::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev13::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev13::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev13::t_lev13(){DoReset();}
t_inl_file::t_lev13::t_lev13(t_lev13&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev13::operator=(t_lev13&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev13::ProxySys$$::metatype*t_inl_file::t_lev13::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev13";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev13::ProxySys$$::GetFullName()
      {
        return "t_lev13";;;
      }
bool t_inl_file::t_lev13::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_lev14::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_lev14::t_oper::t_oper(){DoReset();}
t_inl_file::t_lev14::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev14::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_lev14::t_oper::ProxySys$$::metatype*t_inl_file::t_lev14::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_oper";;;
      }
bool t_inl_file::t_lev14::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("||",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev14::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_lev14::t_item::t_item(){DoReset();}
t_inl_file::t_lev14::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev14::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_lev14::t_item::ProxySys$$::metatype*t_inl_file::t_lev14::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_lev14::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_lev14::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_lev14::t_lev14(){DoReset();}
t_inl_file::t_lev14::t_lev14(t_lev14&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_lev14::operator=(t_lev14&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_lev14::ProxySys$$::metatype*t_inl_file::t_lev14::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_lev14";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_lev14::ProxySys$$::GetFullName()
      {
        return "t_lev14";;;
      }
bool t_inl_file::t_lev14::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_expr::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_expr::t_expr(){DoReset();}
t_inl_file::t_expr::t_expr(t_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_expr::operator=(t_expr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_expr::ProxySys$$::metatype*t_inl_file::t_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_lev14>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_expr";;;
      }
bool t_inl_file::t_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev03::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev03::t_tmpl_lev03(){DoReset();}
t_inl_file::t_tmpl_lev03::t_tmpl_lev03(t_tmpl_lev03&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev03::operator=(t_tmpl_lev03&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev03::ProxySys$$::metatype*t_inl_file::t_tmpl_lev03::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev03";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_tmpl_expr>>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev03::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev03";;;
      }
bool t_inl_file::t_tmpl_lev03::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("&,*,+,-,!,~",","));
      O+=dev.go_any_str_from_vec(oper,g_static_var_0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev05::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev05::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev05::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev05::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev05::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev05::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev05::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev05::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,%",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev05::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev05::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev05::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev05::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev05::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev05::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev05::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev05::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev05::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev05::t_tmpl_lev05(){DoReset();}
t_inl_file::t_tmpl_lev05::t_tmpl_lev05(t_tmpl_lev05&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev05::operator=(t_tmpl_lev05&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev05::ProxySys$$::metatype*t_inl_file::t_tmpl_lev05::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev05";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev03>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev05::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev05";;;
      }
bool t_inl_file::t_tmpl_lev05::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev06::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev06::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev06::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev06::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev06::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev06::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev06::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev06::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev06::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev06::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev06::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev06::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev06::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev06::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev06::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev06::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev06::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev06::t_tmpl_lev06(){DoReset();}
t_inl_file::t_tmpl_lev06::t_tmpl_lev06(t_tmpl_lev06&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev06::operator=(t_tmpl_lev06&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev06::ProxySys$$::metatype*t_inl_file::t_tmpl_lev06::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev06";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev05>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev06::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev06";;;
      }
bool t_inl_file::t_tmpl_lev06::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev09::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev09::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev09::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev09::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev09::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev09::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev09::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev09::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("==,!=",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev09::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev09::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev09::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev09::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev09::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev09::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev09::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev09::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev09::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev09::t_tmpl_lev09(){DoReset();}
t_inl_file::t_tmpl_lev09::t_tmpl_lev09(t_tmpl_lev09&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev09::operator=(t_tmpl_lev09&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev09::ProxySys$$::metatype*t_inl_file::t_tmpl_lev09::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev09";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev06>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev09::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev09";;;
      }
bool t_inl_file::t_tmpl_lev09::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev10::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev10::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev10::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev10::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev10::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev10::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev10::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev10::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev10::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev10::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev10::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev10::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev10::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev10::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev10::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev10::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev10::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev10::t_tmpl_lev10(){DoReset();}
t_inl_file::t_tmpl_lev10::t_tmpl_lev10(t_tmpl_lev10&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev10::operator=(t_tmpl_lev10&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev10::ProxySys$$::metatype*t_inl_file::t_tmpl_lev10::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev10";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev09>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev10::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev10";;;
      }
bool t_inl_file::t_tmpl_lev10::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev11::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev11::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev11::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev11::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev11::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev11::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev11::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev11::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("^",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev11::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev11::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev11::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev11::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev11::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev11::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev11::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev11::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev11::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev11::t_tmpl_lev11(){DoReset();}
t_inl_file::t_tmpl_lev11::t_tmpl_lev11(t_tmpl_lev11&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev11::operator=(t_tmpl_lev11&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev11::ProxySys$$::metatype*t_inl_file::t_tmpl_lev11::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev11";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev10>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev11::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev11";;;
      }
bool t_inl_file::t_tmpl_lev11::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev12::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev12::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev12::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev12::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev12::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev12::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev12::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev12::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("|",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev12::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev12::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev12::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev12::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev12::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev12::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev12::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev12::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev12::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev12::t_tmpl_lev12(){DoReset();}
t_inl_file::t_tmpl_lev12::t_tmpl_lev12(t_tmpl_lev12&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev12::operator=(t_tmpl_lev12&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev12::ProxySys$$::metatype*t_inl_file::t_tmpl_lev12::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev12";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev11>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev12::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev12";;;
      }
bool t_inl_file::t_tmpl_lev12::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev13::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev13::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev13::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev13::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev13::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev13::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev13::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev13::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&&",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev13::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev13::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev13::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev13::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev13::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev13::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev13::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev13::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev13::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev13::t_tmpl_lev13(){DoReset();}
t_inl_file::t_tmpl_lev13::t_tmpl_lev13(t_tmpl_lev13&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev13::operator=(t_tmpl_lev13&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev13::ProxySys$$::metatype*t_inl_file::t_tmpl_lev13::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev13";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev12>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev13::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev13";;;
      }
bool t_inl_file::t_tmpl_lev13::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_lev14::t_oper::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_tmpl_lev14::t_oper::t_oper(){DoReset();}
t_inl_file::t_tmpl_lev14::t_oper::t_oper(t_oper&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev14::t_oper::operator=(t_oper&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_tmpl_lev14::t_oper::ProxySys$$::metatype*t_inl_file::t_tmpl_lev14::t_oper::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev14::t_oper::ProxySys$$::GetFullName()
      {
        return "t_oper";;;
      }
bool t_inl_file::t_tmpl_lev14::t_oper::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("||",","));
        D+=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev14::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->expr);
    }
t_inl_file::t_tmpl_lev14::t_item::t_item(){DoReset();}
t_inl_file::t_tmpl_lev14::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev14::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->oper=std::move(_Right.oper);; this->expr=std::move(_Right.expr);;
    }
t_inl_file::t_tmpl_lev14::t_item::ProxySys$$::metatype*t_inl_file::t_tmpl_lev14::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev14::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_tmpl_lev14::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(oper);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_tmpl_lev14::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_tmpl_lev14::t_tmpl_lev14(){DoReset();}
t_inl_file::t_tmpl_lev14::t_tmpl_lev14(t_tmpl_lev14&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_lev14::operator=(t_tmpl_lev14&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->expr=std::move(_Right.expr);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_tmpl_lev14::ProxySys$$::metatype*t_inl_file::t_tmpl_lev14::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_lev14";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev13>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_oper>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_lev14::ProxySys$$::GetFullName()
      {
        return "t_tmpl_lev14";;;
      }
bool t_inl_file::t_tmpl_lev14::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_expr::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_tmpl_expr::t_tmpl_expr(){DoReset();}
t_inl_file::t_tmpl_expr::t_tmpl_expr(t_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_expr::operator=(t_tmpl_expr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_lev14>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_tmpl_expr";;;
      }
bool t_inl_file::t_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_concrete_param::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_concrete_param::t_concrete_param(){DoReset();}
t_inl_file::t_concrete_param::t_concrete_param(t_concrete_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_concrete_param::operator=(t_concrete_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->body=std::move(_Right.body);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_concrete_param::ProxySys$$::metatype*t_inl_file::t_concrete_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_concrete_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_concrete_param_way>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_concrete_param::ProxySys$$::GetFullName()
      {
        return "t_concrete_param";;;
      }
bool t_inl_file::t_concrete_param::go(i_dev&dev){
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
void t_inl_file::t_concrete_params::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->arr); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_concrete_params::t_concrete_params(){DoReset();}
t_inl_file::t_concrete_params::t_concrete_params(t_concrete_params&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_concrete_params::operator=(t_concrete_params&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->arr=std::move(_Right.arr);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_concrete_params::ProxySys$$::metatype*t_inl_file::t_concrete_params::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_concrete_params";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_concrete_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_concrete_params::ProxySys$$::GetFullName()
      {
        return "t_concrete_params";;;
      }
bool t_inl_file::t_concrete_params::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("<");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(">");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_access_mod::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->keyword);
    }
t_inl_file::t_access_mod::t_access_mod(){DoReset();}
t_inl_file::t_access_mod::t_access_mod(t_access_mod&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_access_mod::operator=(t_access_mod&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->keyword=std::move(_Right.keyword);;
    }
t_inl_file::t_access_mod::ProxySys$$::metatype*t_inl_file::t_access_mod::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_access_mod";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");;
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
        return "t_access_mod";;;
      }
bool t_inl_file::t_access_mod::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("public,protected,private",","));
      D+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_access_mod_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->mod); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_access_mod_class_stat::t_access_mod_class_stat(){DoReset();}
t_inl_file::t_access_mod_class_stat::t_access_mod_class_stat(t_access_mod_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_access_mod_class_stat::operator=(t_access_mod_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->mod=std::move(_Right.mod);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_access_mod_class_stat::ProxySys$$::metatype*t_inl_file::t_access_mod_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_access_mod_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_access_mod>::GetRTTI(RTTI),"mod",int(&(((SelfClass*)nullptr)->*(&SelfClass::mod))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_access_mod_class_stat";;;
      }
void t_inl_file::t_access_mod_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_access_mod_class_stat::SelfClass*t_inl_file::t_access_mod_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_access_mod_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(mod);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const(":");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_raw_func_body::i_item::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_raw_func_body::i_item::i_item(){DoReset();}
t_inl_file::t_raw_func_body::i_item::i_item(i_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::i_item::operator=(i_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_raw_func_body::i_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::i_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_item";;;
      }
void t_inl_file::t_raw_func_body::i_item::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_raw_func_body::i_item::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_raw_func_body::i_item::t_poly_impl::load()
        {
          go_for<t_sep_item>();;
          go_for<t_s_item>();;
          go_for<t_c_item>();;
          go_for<t_code_item>();;
          go_for<t_div_item>();;
          go_for<t_block_item>();;
          (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_raw_func_body::i_item::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_raw_func_body::t_sep_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_raw_func_body::t_sep_item::t_sep_item(){DoReset();}
t_inl_file::t_raw_func_body::t_sep_item::t_sep_item(t_sep_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::t_sep_item::operator=(t_sep_item&&_Right)
    {
      struct hidden{static void foo(i_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_item::operator=(std::move(_Right));;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_raw_func_body::t_sep_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_sep_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_sep_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_sep_item";;;
      }
void t_inl_file::t_raw_func_body::t_sep_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_raw_func_body::t_sep_item::SelfClass*t_inl_file::t_raw_func_body::t_sep_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_raw_func_body::t_sep_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(sep);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_raw_func_body::t_s_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_raw_func_body::t_s_item::t_s_item(){DoReset();}
t_inl_file::t_raw_func_body::t_s_item::t_s_item(t_s_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::t_s_item::operator=(t_s_item&&_Right)
    {
      struct hidden{static void foo(i_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_item::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_raw_func_body::t_s_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_s_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_s_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_s_item";;;
      }
void t_inl_file::t_raw_func_body::t_s_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_raw_func_body::t_s_item::SelfClass*t_inl_file::t_raw_func_body::t_s_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_raw_func_body::t_s_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_str<t_str_item::t_impl>(value);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_raw_func_body::t_c_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_raw_func_body::t_c_item::t_c_item(){DoReset();}
t_inl_file::t_raw_func_body::t_c_item::t_c_item(t_c_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::t_c_item::operator=(t_c_item&&_Right)
    {
      struct hidden{static void foo(i_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_item::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_raw_func_body::t_c_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_c_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_c_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_c_item";;;
      }
void t_inl_file::t_raw_func_body::t_c_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_raw_func_body::t_c_item::SelfClass*t_inl_file::t_raw_func_body::t_c_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_raw_func_body::t_c_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_str<t_char_item::t_impl>(value);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_raw_func_body::t_code_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->code);
    }
t_inl_file::t_raw_func_body::t_code_item::t_code_item(){DoReset();}
t_inl_file::t_raw_func_body::t_code_item::t_code_item(t_code_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::t_code_item::operator=(t_code_item&&_Right)
    {
      struct hidden{static void foo(i_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_item::operator=(std::move(_Right));;
      }
   this->code=std::move(_Right.code);;
    }
t_inl_file::t_raw_func_body::t_code_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_code_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_code_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"code",int(&(((SelfClass*)nullptr)->*(&SelfClass::code))),"DEF","$");;
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
        return "t_code_item";;;
      }
void t_inl_file::t_raw_func_body::t_code_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_raw_func_body::t_code_item::SelfClass*t_inl_file::t_raw_func_body::t_code_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_raw_func_body::t_code_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("AZaz09")+"+-*?<>[](),.:;~!@#$_=%^&\\|");
        D+=dev.go_any(code,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_raw_func_body::t_div_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_raw_func_body::t_div_item::t_div_item(){DoReset();}
t_inl_file::t_raw_func_body::t_div_item::t_div_item(t_div_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::t_div_item::operator=(t_div_item&&_Right)
    {
      struct hidden{static void foo(i_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_item::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_raw_func_body::t_div_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_div_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_div_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_div_item";;;
      }
void t_inl_file::t_raw_func_body::t_div_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_raw_func_body::t_div_item::SelfClass*t_inl_file::t_raw_func_body::t_div_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_raw_func_body::t_div_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("/");
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_raw_func_body::t_block_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_raw_func_body::t_block_item::t_block_item(){DoReset();}
t_inl_file::t_raw_func_body::t_block_item::t_block_item(t_block_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::t_block_item::operator=(t_block_item&&_Right)
    {
      struct hidden{static void foo(i_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_item::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_raw_func_body::t_block_item::ProxySys$$::metatype*t_inl_file::t_raw_func_body::t_block_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_block_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_raw_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_block_item";;;
      }
void t_inl_file::t_raw_func_body::t_block_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_raw_func_body::t_block_item::SelfClass*t_inl_file::t_raw_func_body::t_block_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_raw_func_body::t_block_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_raw_func_body::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_raw_func_body::t_raw_func_body(){DoReset();}
t_inl_file::t_raw_func_body::t_raw_func_body(t_raw_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_func_body::operator=(t_raw_func_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_raw_func_body::ProxySys$$::metatype*t_inl_file::t_raw_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_raw_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_item>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_sep_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_s_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_c_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_code_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_div_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_block_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_raw_func_body::ProxySys$$::GetFullName()
      {
        return "t_raw_func_body";;;
      }
bool t_inl_file::t_raw_func_body::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_func_path::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_func_path::t_item::t_item(){DoReset();}
t_inl_file::t_func_path::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_func_path::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);; this->sep0=std::move(_Right.sep0);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_func_path::t_item::ProxySys$$::metatype*t_inl_file::t_func_path::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_func_path::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_str<t_name>(value);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("::");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_func_path::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_func_path::t_func_path(){DoReset();}
t_inl_file::t_func_path::t_func_path(t_func_path&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_func_path::operator=(t_func_path&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_func_path::ProxySys$$::metatype*t_inl_file::t_func_path::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_func_path";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_func_path::ProxySys$$::GetFullName()
      {
        return "t_func_path";;;
      }
bool t_inl_file::t_func_path::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_const_with_sep::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->keyword);
    }
t_inl_file::t_const_with_sep::t_const_with_sep(){DoReset();}
t_inl_file::t_const_with_sep::t_const_with_sep(t_const_with_sep&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_const_with_sep::operator=(t_const_with_sep&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->keyword=std::move(_Right.keyword);;
    }
t_inl_file::t_const_with_sep::ProxySys$$::metatype*t_inl_file::t_const_with_sep::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_const_with_sep";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_const_with_sep::ProxySys$$::GetFullName()
      {
        return "t_const_with_sep";;;
      }
bool t_inl_file::t_const_with_sep::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      static const auto g_static_var_1=QapStrFinder::fromArr(split("typename,const,unsigned",","));
      M+=dev.go_any_str_from_vec(keyword,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_keyword::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->keyword); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_keyword::t_keyword(){DoReset();}
t_inl_file::t_keyword::t_keyword(t_keyword&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_keyword::operator=(t_keyword&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->keyword=std::move(_Right.keyword);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_keyword::ProxySys$$::metatype*t_inl_file::t_keyword::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_keyword";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_keyword::ProxySys$$::GetFullName()
      {
        return "t_keyword";;;
      }
bool t_inl_file::t_keyword::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("friend,typename,extern,explicit,constexpr,virtual,const,static,inline,unsigned",","));
      M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_callconv::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->value); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_callconv::t_callconv(){DoReset();}
t_inl_file::t_callconv::t_callconv(t_callconv&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_callconv::operator=(t_callconv&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->value=std::move(_Right.value);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_callconv::ProxySys$$::metatype*t_inl_file::t_callconv::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_callconv";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_callconv::ProxySys$$::GetFullName()
      {
        return "t_callconv";;;
      }
bool t_inl_file::t_callconv::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("__cdecl,__stdcall,__fastcall,__thiscall,__vectorcall",","));
      M+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_ptr::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->cv); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_ptr::t_ptr(){DoReset();}
t_inl_file::t_ptr::t_ptr(t_ptr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_ptr::operator=(t_ptr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->cv=std::move(_Right.cv);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_ptr::ProxySys$$::metatype*t_inl_file::t_ptr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_ptr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_ptr::ProxySys$$::GetFullName()
      {
        return "t_ptr";;;
      }
bool t_inl_file::t_ptr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(cv);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("*");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_ref::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->cv); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->ref);
    }
t_inl_file::t_ref::t_ref(){DoReset();}
t_inl_file::t_ref::t_ref(t_ref&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_ref::operator=(t_ref&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->cv=std::move(_Right.cv);; this->sep=std::move(_Right.sep);; this->ref=std::move(_Right.ref);;
    }
t_inl_file::t_ref::ProxySys$$::metatype*t_inl_file::t_ref::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_ref";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"ref",int(&(((SelfClass*)nullptr)->*(&SelfClass::ref))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_ref::ProxySys$$::GetFullName()
      {
        return "t_ref";;;
      }
bool t_inl_file::t_ref::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(cv);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      static const auto g_static_var_2=QapStrFinder::fromArr(split("&&,&",","));
      M+=dev.go_any_str_from_vec(ref,g_static_var_2);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_type_with_sep::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->concrete_params);
    }
t_inl_file::t_type_with_sep::t_type_with_sep(){DoReset();}
t_inl_file::t_type_with_sep::t_type_with_sep(t_type_with_sep&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_type_with_sep::operator=(t_type_with_sep&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->name=std::move(_Right.name);; this->concrete_params=std::move(_Right.concrete_params);;
    }
t_inl_file::t_type_with_sep::ProxySys$$::metatype*t_inl_file::t_type_with_sep::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_type_with_sep";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"concrete_params",int(&(((SelfClass*)nullptr)->*(&SelfClass::concrete_params))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_type_with_sep::ProxySys$$::GetFullName()
      {
        return "t_type_with_sep";;;
      }
bool t_inl_file::t_type_with_sep::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(concrete_params);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_scope_with_sep::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_scope_with_sep::t_scope_with_sep(){DoReset();}
t_inl_file::t_scope_with_sep::t_scope_with_sep(t_scope_with_sep&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_scope_with_sep::operator=(t_scope_with_sep&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_scope_with_sep::ProxySys$$::metatype*t_inl_file::t_scope_with_sep::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_scope_with_sep";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_scope_with_sep::ProxySys$$::GetFullName()
      {
        return "t_scope_with_sep";;;
      }
bool t_inl_file::t_scope_with_sep::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("::");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_scopes::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sws); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_scopes::t_item::t_item(){DoReset();}
t_inl_file::t_scopes::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_scopes::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sws=std::move(_Right.sws);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_scopes::t_item::ProxySys$$::metatype*t_inl_file::t_scopes::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_scope_with_sep>::GetRTTI(RTTI),"sws",int(&(((SelfClass*)nullptr)->*(&SelfClass::sws))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_type_with_sep>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_scopes::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_scopes::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(sws);
        if(!ok)return ok;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_scopes::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->first); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_scopes::t_scopes(){DoReset();}
t_inl_file::t_scopes::t_scopes(t_scopes&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_scopes::operator=(t_scopes&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->first=std::move(_Right.first);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_scopes::ProxySys$$::metatype*t_inl_file::t_scopes::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_scopes";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_type_with_sep>::GetRTTI(RTTI),"first",int(&(((SelfClass*)nullptr)->*(&SelfClass::first))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_scopes::ProxySys$$::GetFullName()
      {
        return "t_scopes";;;
      }
bool t_inl_file::t_scopes::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(first);
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_global::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_global::t_global(){DoReset();}
t_inl_file::t_global::t_global(t_global&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_global::operator=(t_global&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_global::ProxySys$$::metatype*t_inl_file::t_global::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_global";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
string t_inl_file::t_global::ProxySys$$::GetFullName()
      {
        return "t_global";;;
      }
bool t_inl_file::t_global::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("::");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_raw_type_expr::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->global); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->scopes);
    }
t_inl_file::t_raw_type_expr::t_raw_type_expr(){DoReset();}
t_inl_file::t_raw_type_expr::t_raw_type_expr(t_raw_type_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_raw_type_expr::operator=(t_raw_type_expr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->global=std::move(_Right.global);; this->sep=std::move(_Right.sep);; this->scopes=std::move(_Right.scopes);;
    }
t_inl_file::t_raw_type_expr::ProxySys$$::metatype*t_inl_file::t_raw_type_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_raw_type_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_global>>::GetRTTI(RTTI),"global",int(&(((SelfClass*)nullptr)->*(&SelfClass::global))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_scopes>::GetRTTI(RTTI),"scopes",int(&(((SelfClass*)nullptr)->*(&SelfClass::scopes))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_raw_type_expr::ProxySys$$::GetFullName()
      {
        return "t_raw_type_expr";;;
      }
bool t_inl_file::t_raw_type_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(global);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(scopes);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_arr_body::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->sep2); detail::FieldTryDoReset(this->sep3);
    }
t_inl_file::t_arr_body::t_arr_body(){DoReset();}
t_inl_file::t_arr_body::t_arr_body(t_arr_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_arr_body::operator=(t_arr_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->sep1=std::move(_Right.sep1);; this->expr=std::move(_Right.expr);; this->sep2=std::move(_Right.sep2);; this->sep3=std::move(_Right.sep3);;
    }
t_inl_file::t_arr_body::ProxySys$$::metatype*t_inl_file::t_arr_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_arr_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_arr_body::ProxySys$$::GetFullName()
      {
        return "t_arr_body";;;
      }
bool t_inl_file::t_arr_body::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_const("[");
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      M+=dev.go_const("]");
      if(!ok)return ok;
      O+=dev.go_auto(sep3);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::i_name_part(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::i_name_part(i_name_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::operator=(i_name_part&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_name_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_name_part";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::t_poly_impl::load()
          {
            go_for<t_raw_name_part>();;
            go_for<t_brackets_name_part>();;
            (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::i_func_param(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::i_func_param(i_func_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::operator=(i_func_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_func_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_func_param";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::t_poly_impl::load()
          {
            go_for<t_pfunc_func_param>();;
            go_for<t_var_args_func_param>();;
            go_for<t_type_func_param>();;
            go_for<t_expr_func_param>();;
            (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::i_typeexpr(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::i_typeexpr(i_typeexpr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::operator=(i_typeexpr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_typeexpr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
string t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::ProxySys$$::GetFullName()
      {
        return "i_typeexpr";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::t_poly_impl::load()
          {
            go_for<t_impl_typeexpr>();;
            go_for<t_decl_typeexpr>();;
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }
bool t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->cvs); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::t_type_expr_with_sep_and_cv(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::t_type_expr_with_sep_and_cv(t_type_expr_with_sep_and_cv&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::operator=(t_type_expr_with_sep_and_cv&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->cvs=std::move(_Right.cvs);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_type_expr_with_sep_and_cv";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_const_with_sep>>::GetRTTI(RTTI),"cvs",int(&(((SelfClass*)nullptr)->*(&SelfClass::cvs))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_type_expr_with_sep_and_cv";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(cvs);
          if(!ok)return ok;
          M+=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::t_name_part(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::t_name_part(t_name_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::operator=(t_name_part&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_name_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<i_name_part>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_name_part";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_name_part::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->name);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::t_raw_name_part(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::t_raw_name_part(t_raw_name_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::operator=(t_raw_name_part&&_Right)
    {
      struct hidden{static void foo(i_name_part(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_name_part::operator=(std::move(_Right));;
      }
   this->name=std::move(_Right.name);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_raw_name_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");;
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
        return "t_raw_name_part";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_raw_name_part::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_str<t_name>(name);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::i_part(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::i_part(i_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::operator=(i_part&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_part";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::t_poly_impl::load()
            {
              go_for<t_amp_part>();;
              go_for<t_star_part>();;
              (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::t_amp(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::t_amp(t_amp&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::operator=(t_amp&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_amp";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_amp";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            static const auto g_static_var_0=QapStrFinder::fromArr(split("&,&&",","));
            D+=dev.go_any_str_from_vec(body,g_static_var_0);
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::t_amp_part(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::t_amp_part(t_amp_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::operator=(t_amp_part&&_Right)
    {
      struct hidden{static void foo(i_part(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_part::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_amp_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_amp>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_amp_part";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_amp_part::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_auto(body);
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->stars); detail::FieldTryDoReset(this->amp);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::t_star_part(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::t_star_part(t_star_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::operator=(t_star_part&&_Right)
    {
      struct hidden{static void foo(i_part(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_part::operator=(std::move(_Right));;
      }
   this->stars=std::move(_Right.stars);; this->amp=std::move(_Right.amp);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_star_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"stars",int(&(((SelfClass*)nullptr)->*(&SelfClass::stars))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_amp>>::GetRTTI(RTTI),"amp",int(&(((SelfClass*)nullptr)->*(&SelfClass::amp))),"DEF","$");;
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
        return "t_star_part";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_star_part::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            static const auto g_static_var_0=CharMask::fromStr("*");
            M+=dev.go_any(stars,g_static_var_0);
            if(!ok)return ok;
            O+=dev.go_auto(amp);
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->stamp_part); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->namepart); detail::FieldTryDoReset(this->arrbody);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_brackets_name_part(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::t_brackets_name_part(t_brackets_name_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::operator=(t_brackets_name_part&&_Right)
    {
      struct hidden{static void foo(i_name_part(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_name_part::operator=(std::move(_Right));;
      }
   this->stamp_part=std::move(_Right.stamp_part);; this->sep=std::move(_Right.sep);; this->namepart=std::move(_Right.namepart);; this->arrbody=std::move(_Right.arrbody);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_brackets_name_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<i_part>>::GetRTTI(RTTI),"stamp_part",int(&(((SelfClass*)nullptr)->*(&SelfClass::stamp_part))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_name_part>>::GetRTTI(RTTI),"namepart",int(&(((SelfClass*)nullptr)->*(&SelfClass::namepart))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_arr_body>>::GetRTTI(RTTI),"arrbody",int(&(((SelfClass*)nullptr)->*(&SelfClass::arrbody))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_amp>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_amp_part>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_star_part>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::ProxySys$$::GetFullName()
      {
        return "t_brackets_name_part";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("(");
          if(!ok)return ok;
          M+=dev.go_auto(stamp_part);
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          O+=dev.go_auto(namepart);
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          O+=dev.go_auto(arrbody);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::t_func_param_value(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::t_func_param_value(t_func_param_value&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::operator=(t_func_param_value&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->value=std::move(_Right.value);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_func_param_value";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_func_param_value";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_func_param_value::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("=");
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_auto(value);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->value); detail::FieldTryDoReset(this->sep2);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::t_func_param(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::t_func_param(t_func_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::operator=(t_func_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->body=std::move(_Right.body);; this->sep1=std::move(_Right.sep1);; this->value=std::move(_Right.value);; this->sep2=std::move(_Right.sep2);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_func_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_param>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");;
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
        return "t_func_param";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_func_param::go(i_dev&dev){
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
          O+=dev.go_auto(value);
          if(!ok)return ok;
          O+=dev.go_auto(sep2);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::t_func_params(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::t_func_params(t_func_params&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::operator=(t_func_params&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_func_params";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_func_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
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
        return "t_func_params";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_func_params::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_const("(");
          if(!ok)return ok;
          O+=dev.go_vec(arr,",");
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->type);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::t_addr(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::t_addr(t_addr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::operator=(t_addr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->type=std::move(_Right.type);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_addr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::ProxySys$$::GetFullName()
      {
        return "t_addr";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_addr::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_auto(type);
            if(!ok)return ok;
            M+=dev.go_const("::");
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->addr); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->params);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_pfunc(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::t_pfunc(t_pfunc&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::operator=(t_pfunc&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->type=std::move(_Right.type);; this->addr=std::move(_Right.addr);; this->name=std::move(_Right.name);; this->params=std::move(_Right.params);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_pfunc";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_addr>::GetRTTI(RTTI),"addr",int(&(((SelfClass*)nullptr)->*(&SelfClass::addr))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_addr>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::ProxySys$$::GetFullName()
      {
        return "t_pfunc";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(type);
          if(!ok)return ok;
          M+=dev.go_const("(");
          if(!ok)return ok;
          O+=dev.go_auto(addr);
          if(!ok)return ok;
          M+=dev.go_const("*");
          if(!ok)return ok;
          O+=dev.go_str<t_name>(name);
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          M+=dev.go_auto(params);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_pfunc_func_param(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::t_pfunc_func_param(t_pfunc_func_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::operator=(t_pfunc_func_param&&_Right)
    {
      struct hidden{static void foo(i_func_param(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_param::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_pfunc_func_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_pfunc>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::ProxySys$$::GetFullName()
      {
        return "t_pfunc_func_param";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_pfunc_func_param::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_auto(value);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::t_var_args_func_param(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::t_var_args_func_param(t_var_args_func_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::operator=(t_var_args_func_param&&_Right)
    {
      struct hidden{static void foo(i_func_param(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_param::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_var_args_func_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_var_args_func_param";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_var_args_func_param::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_const("...");
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::t_const(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::t_const(t_const&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::operator=(t_const&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_const";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::ProxySys$$::GetFullName()
      {
        return "t_const";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_const::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_const("const");
            if(!ok)return ok;
            O+=dev.go_auto(sep);
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->cv); detail::FieldTryDoReset(this->namepart);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_type_func_param(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::t_type_func_param(t_type_func_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::operator=(t_type_func_param&&_Right)
    {
      struct hidden{static void foo(i_func_param(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_param::operator=(std::move(_Right));;
      }
   this->type=std::move(_Right.type);; this->sep=std::move(_Right.sep);; this->cv=std::move(_Right.cv);; this->namepart=std::move(_Right.namepart);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_type_func_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_name_part>>::GetRTTI(RTTI),"namepart",int(&(((SelfClass*)nullptr)->*(&SelfClass::namepart))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_const>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::ProxySys$$::GetFullName()
      {
        return "t_type_func_param";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_type_func_param::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(type);
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          O+=dev.go_auto(cv);
          if(!ok)return ok;
          O+=dev.go_auto(namepart);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::t_expr_func_param(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::t_expr_func_param(t_expr_func_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::operator=(t_expr_func_param&&_Right)
    {
      struct hidden{static void foo(i_func_param(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_param::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_expr_func_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_expr_func_param";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_expr_func_param::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_minor<t_type_func_param>(body);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::i_fv_body(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::i_fv_body(i_fv_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::operator=(i_fv_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_fv_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_fv_body";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::t_poly_impl::load()
            {
              go_for<t_impl_func_body>();;
              go_for<t_zero_func_body>();;
              go_for<t_delete_func_body>();;
              (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::i_fv_end(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::i_fv_end(i_fv_end&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::operator=(i_fv_end&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_fv_end";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_fv_end";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::t_poly_impl::load()
            {
              go_for<t_func_fv_end>();;
              go_for<t_var_fv_end>();;
              (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::t_impl_func_body(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::t_impl_func_body(t_impl_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::operator=(t_impl_func_body&&_Right)
    {
      struct hidden{static void foo(i_fv_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_fv_body::operator=(std::move(_Right));;
      }
   this->sep=std::move(_Right.sep);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_raw_func_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_impl_func_body";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_impl_func_body::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            O+=dev.go_auto(sep);
            if(!ok)return ok;
            M+=dev.go_auto(body);
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::t_zero_func_body(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::t_zero_func_body(t_zero_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::operator=(t_zero_func_body&&_Right)
    {
      struct hidden{static void foo(i_fv_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_fv_body::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_zero_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_zero_func_body";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_zero_func_body::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_const("=0;");
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::t_delete_func_body(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::t_delete_func_body(t_delete_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::operator=(t_delete_func_body&&_Right)
    {
      struct hidden{static void foo(i_fv_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_fv_body::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_delete_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_delete_func_body";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_delete_func_body::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            D+=dev.go_const("=delete;");
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->cv1); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::t_func_fv_end(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::t_func_fv_end(t_func_fv_end&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::operator=(t_func_fv_end&&_Right)
    {
      struct hidden{static void foo(i_fv_end(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_fv_end::operator=(std::move(_Right));;
      }
   this->params=std::move(_Right.params);; this->cv1=std::move(_Right.cv1);; this->sep1=std::move(_Right.sep1);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_func_fv_end";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_func_fv_end";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_auto(params);
            if(!ok)return ok;
            O+=dev.go_auto(cv1);
            if(!ok)return ok;
            O+=dev.go_auto(sep1);
            if(!ok)return ok;
            M+=dev.go_auto(body);
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::i_fv_item(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::i_fv_item(i_fv_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::operator=(i_fv_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_fv_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_fv_item";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::t_poly_impl::load()
              {
                go_for<t_func_fv_item>();;
                go_for<t_var_fv_item>();;
                (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->cv1);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::t_func_fv_item(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::t_func_fv_item(t_func_fv_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::operator=(t_func_fv_item&&_Right)
    {
      struct hidden{static void foo(i_fv_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_fv_item::operator=(std::move(_Right));;
      }
   this->params=std::move(_Right.params);; this->cv1=std::move(_Right.cv1);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_func_fv_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");;
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
        return "t_func_fv_item";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_func_fv_item::go(i_dev&dev){
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              M+=dev.go_auto(params);
              if(!ok)return ok;
              O+=dev.go_auto(cv1);
              if(!ok)return ok;
              return ok;
            }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->arrbody); detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::t_var_fv_item(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::t_var_fv_item(t_var_fv_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::operator=(t_var_fv_item&&_Right)
    {
      struct hidden{static void foo(i_fv_item(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_fv_item::operator=(std::move(_Right));;
      }
   this->arrbody=std::move(_Right.arrbody);; this->value=std::move(_Right.value);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_var_fv_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_arr_body>>::GetRTTI(RTTI),"arrbody",int(&(((SelfClass*)nullptr)->*(&SelfClass::arrbody))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_param_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_var_fv_item";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_item::go(i_dev&dev){
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              O+=dev.go_auto(arrbody);
              if(!ok)return ok;
              O+=dev.go_auto(value);
              if(!ok)return ok;
              return ok;
            }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::t_body(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::t_body(t_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::operator=(t_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_item>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_body";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_body::go(i_dev&dev){
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              D+=dev.go_auto(body);
              if(!ok)return ok;
              return ok;
            }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->cv); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep2); detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->sep3);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::t_item(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->cv=std::move(_Right.cv);; this->sep1=std::move(_Right.sep1);; this->name=std::move(_Right.name);; this->sep2=std::move(_Right.sep2);; this->body=std::move(_Right.body);; this->sep3=std::move(_Right.sep3);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_item::go(i_dev&dev){
              t_fallback scope(dev,__FUNCTION__);
              auto&ok=scope.ok;
              auto&D=scope.mandatory;
              auto&M=scope.mandatory;
              auto&O=scope.optional;
              M+=dev.go_const(",");
              if(!ok)return ok;
              O+=dev.go_auto(sep0);
              if(!ok)return ok;
              O+=dev.go_auto(cv);
              if(!ok)return ok;
              O+=dev.go_auto(sep1);
              if(!ok)return ok;
              M+=dev.go_str<t_name>(name);
              if(!ok)return ok;
              O+=dev.go_auto(sep2);
              if(!ok)return ok;
              M+=dev.go_auto(body);
              if(!ok)return ok;
              O+=dev.go_auto(sep3);
              if(!ok)return ok;
              return ok;
            }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_end(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::t_var_fv_end(t_var_fv_end&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::operator=(t_var_fv_end&&_Right)
    {
      struct hidden{static void foo(i_fv_end(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_fv_end::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_var_fv_end";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_func_fv_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_var_fv_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::ProxySys$$::GetFullName()
      {
        return "t_var_fv_end";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            O+=dev.go_auto(body);
            if(!ok)return ok;
            O+=dev.go_auto(arr);
            if(!ok)return ok;
            M+=dev.go_const(";");
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep_wa); detail::FieldTryDoReset(this->keywords); detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->cv); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->path); detail::FieldTryDoReset(this->callconv); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->way);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_fv_stat(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_fv_stat(t_fv_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::operator=(t_fv_stat&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep_wa=std::move(_Right.sep_wa);; this->keywords=std::move(_Right.keywords);; this->type=std::move(_Right.type);; this->cv=std::move(_Right.cv);; this->sep0=std::move(_Right.sep0);; this->path=std::move(_Right.path);; this->callconv=std::move(_Right.callconv);; this->name=std::move(_Right.name);; this->sep1=std::move(_Right.sep1);; this->way=std::move(_Right.way);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_fv_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep_wa",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep_wa))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_keyword>>::GetRTTI(RTTI),"keywords",int(&(((SelfClass*)nullptr)->*(&SelfClass::keywords))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_type_expr>>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_callconv>>::GetRTTI(RTTI),"callconv",int(&(((SelfClass*)nullptr)->*(&SelfClass::callconv))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_name_part>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_fv_end>>::GetRTTI(RTTI),"way",int(&(((SelfClass*)nullptr)->*(&SelfClass::way))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_zero_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_delete_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_func_fv_end>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_var_fv_end>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::ProxySys$$::GetFullName()
      {
        return "t_fv_stat";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(sep_wa);
          if(!ok)return ok;
          O+=dev.go_auto(keywords);
          if(!ok)return ok;
          M+=dev.go_auto(type);
          if(!ok)return ok;
          O+=dev.go_auto(cv);
          if(!ok)return ok;
          O+=dev.go_auto(sep0);
          if(!ok)return ok;
          O+=dev.go_auto(path);
          if(!ok)return ok;
          O+=dev.go_auto(callconv);
          if(!ok)return ok;
          M+=dev.go_auto(name);
          if(!ok)return ok;
          O+=dev.go_auto(sep1);
          if(!ok)return ok;
          M+=dev.go_auto(way);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::t_global(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::t_global(t_global&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::operator=(t_global&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_global";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
string t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::ProxySys$$::GetFullName()
      {
        return "t_global";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_global::go(i_dev&dev){
            t_fallback scope(dev,__FUNCTION__);
            auto&ok=scope.ok;
            auto&D=scope.mandatory;
            auto&M=scope.mandatory;
            auto&O=scope.optional;
            M+=dev.go_const("::");
            if(!ok)return ok;
            return ok;
          }
void t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->global); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->scopes); detail::FieldTryDoReset(this->ptrs); detail::FieldTryDoReset(this->ref);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_impl_typeexpr(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::t_impl_typeexpr(t_impl_typeexpr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::operator=(t_impl_typeexpr&&_Right)
    {
      struct hidden{static void foo(i_typeexpr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_typeexpr::operator=(std::move(_Right));;
      }
   this->global=std::move(_Right.global);; this->sep=std::move(_Right.sep);; this->scopes=std::move(_Right.scopes);; this->ptrs=std::move(_Right.ptrs);; this->ref=std::move(_Right.ref);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl_typeexpr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_global>>::GetRTTI(RTTI),"global",int(&(((SelfClass*)nullptr)->*(&SelfClass::global))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_scopes>::GetRTTI(RTTI),"scopes",int(&(((SelfClass*)nullptr)->*(&SelfClass::scopes))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_ptr>>::GetRTTI(RTTI),"ptrs",int(&(((SelfClass*)nullptr)->*(&SelfClass::ptrs))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_ref>>::GetRTTI(RTTI),"ref",int(&(((SelfClass*)nullptr)->*(&SelfClass::ref))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_global>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::ProxySys$$::GetFullName()
      {
        return "t_impl_typeexpr";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_impl_typeexpr::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          O+=dev.go_auto(global);
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_auto(scopes);
          if(!ok)return ok;
          O+=dev.go_auto(ptrs);
          if(!ok)return ok;
          O+=dev.go_auto(ref);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->sep2);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::t_decl_typeexpr(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::t_decl_typeexpr(t_decl_typeexpr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::operator=(t_decl_typeexpr&&_Right)
    {
      struct hidden{static void foo(i_typeexpr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_typeexpr::operator=(std::move(_Right));;
      }
   this->sep0=std::move(_Right.sep0);; this->sep1=std::move(_Right.sep1);; this->expr=std::move(_Right.expr);; this->sep2=std::move(_Right.sep2);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_decl_typeexpr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::ProxySys$$::GetFullName()
      {
        return "t_decl_typeexpr";;;
      }
void t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::SelfClass*t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::t_type_expr::t_decl_typeexpr::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("decltype");
          if(!ok)return ok;
          O+=dev.go_auto(sep0);
          if(!ok)return ok;
          M+=dev.go_const("(");
          if(!ok)return ok;
          O+=dev.go_auto(sep1);
          if(!ok)return ok;
          M+=dev.go_auto(expr);
          if(!ok)return ok;
          O+=dev.go_auto(sep2);
          if(!ok)return ok;
          M+=dev.go_const(")");
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_fv_class_stat::t_type_expr::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr(){DoReset();}
t_inl_file::t_fv_class_stat::t_type_expr::t_type_expr(t_type_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::t_type_expr::operator=(t_type_expr&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::t_type_expr::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::t_type_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_type_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<i_typeexpr>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_type_expr_with_sep_and_cv>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_name_part>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_raw_name_part>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_brackets_name_part>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_func_param_value>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_func_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_func_params>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_pfunc>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_pfunc_func_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_var_args_func_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_type_func_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_expr_func_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_fv_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_impl_typeexpr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_decl_typeexpr>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::t_type_expr::ProxySys$$::GetFullName()
      {
        return "t_type_expr";;;
      }
bool t_inl_file::t_fv_class_stat::t_type_expr::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_fv_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_fv_class_stat::t_fv_class_stat(){DoReset();}
t_inl_file::t_fv_class_stat::t_fv_class_stat(t_fv_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_fv_class_stat::operator=(t_fv_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_fv_class_stat::ProxySys$$::metatype*t_inl_file::t_fv_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_fv_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_type_expr::t_fv_stat>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_type_expr>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_fv_class_stat::ProxySys$$::GetFullName()
      {
        return "t_fv_class_stat";;;
      }
void t_inl_file::t_fv_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_fv_class_stat::SelfClass*t_inl_file::t_fv_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_fv_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_typedef_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_typedef_class_stat::t_typedef_class_stat(){DoReset();}
t_inl_file::t_typedef_class_stat::t_typedef_class_stat(t_typedef_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_typedef_class_stat::operator=(t_typedef_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->sep=std::move(_Right.sep);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_typedef_class_stat::ProxySys$$::metatype*t_inl_file::t_typedef_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_typedef_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_fv_stat>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_typedef_class_stat";;;
      }
void t_inl_file::t_typedef_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_typedef_class_stat::SelfClass*t_inl_file::t_typedef_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_typedef_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("typedef");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_real::t_f::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_real::t_f::t_f(){DoReset();}
t_inl_file::t_real::t_f::t_f(t_f&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_real::t_f::operator=(t_f&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_real::t_f::ProxySys$$::metatype*t_inl_file::t_real::t_f::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_f";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<char>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_f";;;
      }
bool t_inl_file::t_real::t_f::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=CharMask::fromStr("fF");
        D+=dev.go_any_char(body,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_real::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->bef); detail::FieldTryDoReset(this->aft); detail::FieldTryDoReset(this->ext);
    }
t_inl_file::t_real::t_real(){DoReset();}
t_inl_file::t_real::t_real(t_real&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_real::operator=(t_real&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->bef=std::move(_Right.bef);; this->aft=std::move(_Right.aft);; this->ext=std::move(_Right.ext);;
    }
t_inl_file::t_real::ProxySys$$::metatype*t_inl_file::t_real::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_real";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_f>>::GetRTTI(RTTI),"ext",int(&(((SelfClass*)nullptr)->*(&SelfClass::ext))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_f>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_real::ProxySys$$::GetFullName()
      {
        return "t_real";;;
      }
bool t_inl_file::t_real::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      M+=dev.go_any(bef,g_static_var_0);
      if(!ok)return ok;
      M+=dev.go_const(".");
      if(!ok)return ok;
      static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
      O+=dev.go_any(aft,g_static_var_2);
      if(!ok)return ok;
      O+=dev.go_auto(ext);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_call_param::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_call_param::t_call_param(){DoReset();}
t_inl_file::t_call_param::t_call_param(t_call_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_call_param::operator=(t_call_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->expr=std::move(_Right.expr);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_call_param::ProxySys$$::metatype*t_inl_file::t_call_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_call_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
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
        return "t_call_param";;;
      }
bool t_inl_file::t_call_param::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_call_params::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_call_params::t_call_params(){DoReset();}
t_inl_file::t_call_params::t_call_params(t_call_params&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_call_params::operator=(t_call_params&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_call_params::ProxySys$$::metatype*t_inl_file::t_call_params::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_call_params";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_call_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_call_params::ProxySys$$::GetFullName()
      {
        return "t_call_params";;;
      }
bool t_inl_file::t_call_params::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_block_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_block_expr::t_block_expr(){DoReset();}
t_inl_file::t_block_expr::t_block_expr(t_block_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_block_expr::operator=(t_block_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->sep0=std::move(_Right.sep0);; this->expr=std::move(_Right.expr);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_block_expr::ProxySys$$::metatype*t_inl_file::t_block_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_block_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_block_expr::ProxySys$$::GetFullName()
      {
        return "t_block_expr";;;
      }
void t_inl_file::t_block_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_block_expr::SelfClass*t_inl_file::t_block_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_block_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_bool_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_bool_expr::t_bool_expr(){DoReset();}
t_inl_file::t_bool_expr::t_bool_expr(t_bool_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_bool_expr::operator=(t_bool_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_bool_expr::ProxySys$$::metatype*t_inl_file::t_bool_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_bool_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_bool_expr";;;
      }
void t_inl_file::t_bool_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_bool_expr::SelfClass*t_inl_file::t_bool_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_bool_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_string_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_string_expr::t_string_expr(){DoReset();}
t_inl_file::t_string_expr::t_string_expr(t_string_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_string_expr::operator=(t_string_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_string_expr::ProxySys$$::metatype*t_inl_file::t_string_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_string_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_string_expr";;;
      }
void t_inl_file::t_string_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_string_expr::SelfClass*t_inl_file::t_string_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_string_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_str_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_char_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_char_expr::t_char_expr(){DoReset();}
t_inl_file::t_char_expr::t_char_expr(t_char_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_char_expr::operator=(t_char_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_char_expr::ProxySys$$::metatype*t_inl_file::t_char_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_char_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_char_expr";;;
      }
void t_inl_file::t_char_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_char_expr::SelfClass*t_inl_file::t_char_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_char_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_char_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_num_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_num_expr::t_num_expr(){DoReset();}
t_inl_file::t_num_expr::t_num_expr(t_num_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_num_expr::operator=(t_num_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_num_expr::ProxySys$$::metatype*t_inl_file::t_num_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_num_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_num_expr";;;
      }
void t_inl_file::t_num_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_num_expr::SelfClass*t_inl_file::t_num_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_num_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      D+=dev.go_any(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_real_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_real_expr::t_real_expr(){DoReset();}
t_inl_file::t_real_expr::t_real_expr(t_real_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_real_expr::operator=(t_real_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_real_expr::ProxySys$$::metatype*t_inl_file::t_real_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_real_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_real_expr";;;
      }
void t_inl_file::t_real_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_real_expr::SelfClass*t_inl_file::t_real_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_real_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_real>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_nullptr_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_nullptr_expr::t_nullptr_expr(){DoReset();}
t_inl_file::t_nullptr_expr::t_nullptr_expr(t_nullptr_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_nullptr_expr::operator=(t_nullptr_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_nullptr_expr::ProxySys$$::metatype*t_inl_file::t_nullptr_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_nullptr_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_nullptr_expr";;;
      }
void t_inl_file::t_nullptr_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_nullptr_expr::SelfClass*t_inl_file::t_nullptr_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_nullptr_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("nullptr");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_or_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_or_expr::t_or_expr(){DoReset();}
t_inl_file::t_or_expr::t_or_expr(t_or_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_or_expr::operator=(t_or_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_or_expr::ProxySys$$::metatype*t_inl_file::t_or_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_or_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_name>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
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
        return "t_or_expr";;;
      }
void t_inl_file::t_or_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_or_expr::SelfClass*t_inl_file::t_or_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_or_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_bin_oper(arr,"|");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_hex_expr::t_impl::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->x); detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_hex_expr::t_impl::t_impl(){DoReset();}
t_inl_file::t_hex_expr::t_impl::t_impl(t_impl&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_hex_expr::t_impl::operator=(t_impl&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->x=std::move(_Right.x);; this->value=std::move(_Right.value);;
    }
t_inl_file::t_hex_expr::t_impl::ProxySys$$::metatype*t_inl_file::t_hex_expr::t_impl::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<char>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_impl";;;
      }
bool t_inl_file::t_hex_expr::t_impl::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("0");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("xX");
        D+=dev.go_any_char(x,g_static_var_1);
        if(!ok)return ok;
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09afAF"));
        D+=dev.go_any(value,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_hex_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_hex_expr::t_hex_expr(){DoReset();}
t_inl_file::t_hex_expr::t_hex_expr(t_hex_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_hex_expr::operator=(t_hex_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_hex_expr::ProxySys$$::metatype*t_inl_file::t_hex_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_hex_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_hex_expr::ProxySys$$::GetFullName()
      {
        return "t_hex_expr";;;
      }
void t_inl_file::t_hex_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_hex_expr::SelfClass*t_inl_file::t_hex_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_hex_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_var_expr::i_ext::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_var_expr::i_ext::i_ext(){DoReset();}
t_inl_file::t_var_expr::i_ext::i_ext(i_ext&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::i_ext::operator=(i_ext&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_var_expr::i_ext::ProxySys$$::metatype*t_inl_file::t_var_expr::i_ext::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_ext";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
string t_inl_file::t_var_expr::i_ext::ProxySys$$::GetFullName()
      {
        return "i_ext";;;
      }
void t_inl_file::t_var_expr::i_ext::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_var_expr::i_ext::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_var_expr::i_ext::t_poly_impl::load()
        {
          go_for<t_arr_ext>();;
          go_for<t_call_ext>();;
          go_for<t_tmpl_ext>();;
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }
bool t_inl_file::t_var_expr::i_ext::t_poly_impl::go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_var_expr::i_ext::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_var_expr::t_arr_ext::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_var_expr::t_arr_ext::t_arr_ext(){DoReset();}
t_inl_file::t_var_expr::t_arr_ext::t_arr_ext(t_arr_ext&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::t_arr_ext::operator=(t_arr_ext&&_Right)
    {
      struct hidden{static void foo(i_ext(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_ext::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_var_expr::t_arr_ext::ProxySys$$::metatype*t_inl_file::t_var_expr::t_arr_ext::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_arr_ext";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_arr_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_var_expr::t_arr_ext::ProxySys$$::GetFullName()
      {
        return "t_arr_ext";;;
      }
void t_inl_file::t_var_expr::t_arr_ext::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_var_expr::t_arr_ext::SelfClass*t_inl_file::t_var_expr::t_arr_ext::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_var_expr::t_arr_ext::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_var_expr::t_call_ext::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->concrete_params); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_var_expr::t_call_ext::t_call_ext(){DoReset();}
t_inl_file::t_var_expr::t_call_ext::t_call_ext(t_call_ext&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::t_call_ext::operator=(t_call_ext&&_Right)
    {
      struct hidden{static void foo(i_ext(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_ext::operator=(std::move(_Right));;
      }
   this->concrete_params=std::move(_Right.concrete_params);; this->sep=std::move(_Right.sep);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_var_expr::t_call_ext::ProxySys$$::metatype*t_inl_file::t_var_expr::t_call_ext::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_call_ext";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"concrete_params",int(&(((SelfClass*)nullptr)->*(&SelfClass::concrete_params))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_call_params>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_var_expr::t_call_ext::ProxySys$$::GetFullName()
      {
        return "t_call_ext";;;
      }
void t_inl_file::t_var_expr::t_call_ext::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_var_expr::t_call_ext::SelfClass*t_inl_file::t_var_expr::t_call_ext::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_var_expr::t_call_ext::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        M+=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_var_expr::t_tmpl_ext::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->concrete_params);
    }
t_inl_file::t_var_expr::t_tmpl_ext::t_tmpl_ext(){DoReset();}
t_inl_file::t_var_expr::t_tmpl_ext::t_tmpl_ext(t_tmpl_ext&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::t_tmpl_ext::operator=(t_tmpl_ext&&_Right)
    {
      struct hidden{static void foo(i_ext(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_ext::operator=(std::move(_Right));;
      }
   this->concrete_params=std::move(_Right.concrete_params);;
    }
t_inl_file::t_var_expr::t_tmpl_ext::ProxySys$$::metatype*t_inl_file::t_var_expr::t_tmpl_ext::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_ext";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"concrete_params",int(&(((SelfClass*)nullptr)->*(&SelfClass::concrete_params))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_var_expr::t_tmpl_ext::ProxySys$$::GetFullName()
      {
        return "t_tmpl_ext";;;
      }
void t_inl_file::t_var_expr::t_tmpl_ext::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_var_expr::t_tmpl_ext::SelfClass*t_inl_file::t_var_expr::t_tmpl_ext::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_var_expr::t_tmpl_ext::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_var_expr::t_part::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->bef); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->aft); detail::FieldTryDoReset(this->ext); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_var_expr::t_part::t_part(){DoReset();}
t_inl_file::t_var_expr::t_part::t_part(t_part&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::t_part::operator=(t_part&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->bef=std::move(_Right.bef);; this->name=std::move(_Right.name);; this->aft=std::move(_Right.aft);; this->ext=std::move(_Right.ext);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_var_expr::t_part::ProxySys$$::metatype*t_inl_file::t_var_expr::t_part::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_part";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_ext>>::GetRTTI(RTTI),"ext",int(&(((SelfClass*)nullptr)->*(&SelfClass::ext))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_var_expr::t_part::ProxySys$$::GetFullName()
      {
        return "t_part";;;
      }
bool t_inl_file::t_var_expr::t_part::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(bef);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(aft);
        if(!ok)return ok;
        O+=dev.go_auto(ext);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_var_expr::t_step::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->part); detail::FieldTryDoReset(this->sep2);
    }
t_inl_file::t_var_expr::t_step::t_step(){DoReset();}
t_inl_file::t_var_expr::t_step::t_step(t_step&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::t_step::operator=(t_step&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->oper=std::move(_Right.oper);; this->sep1=std::move(_Right.sep1);; this->part=std::move(_Right.part);; this->sep2=std::move(_Right.sep2);;
    }
t_inl_file::t_var_expr::t_step::ProxySys$$::metatype*t_inl_file::t_var_expr::t_step::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_step";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_part>::GetRTTI(RTTI),"part",int(&(((SelfClass*)nullptr)->*(&SelfClass::part))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_var_expr::t_step::ProxySys$$::GetFullName()
      {
        return "t_step";;;
      }
bool t_inl_file::t_var_expr::t_step::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        static const auto g_static_var_1=QapStrFinder::fromArr(split("->,.,::",","));
        M+=dev.go_any_str_from_vec(oper,g_static_var_1);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(part);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_var_expr::t_impl::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->global); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->head); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_var_expr::t_impl::t_impl(){DoReset();}
t_inl_file::t_var_expr::t_impl::t_impl(t_impl&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::t_impl::operator=(t_impl&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->global=std::move(_Right.global);; this->sep0=std::move(_Right.sep0);; this->head=std::move(_Right.head);; this->sep1=std::move(_Right.sep1);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_var_expr::t_impl::ProxySys$$::metatype*t_inl_file::t_var_expr::t_impl::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_global>>::GetRTTI(RTTI),"global",int(&(((SelfClass*)nullptr)->*(&SelfClass::global))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_part>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_step>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
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
        return "t_impl";;;
      }
bool t_inl_file::t_var_expr::t_impl::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(global);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(head);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_var_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->name);
    }
t_inl_file::t_var_expr::t_var_expr(){DoReset();}
t_inl_file::t_var_expr::t_var_expr(t_var_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_expr::operator=(t_var_expr&&_Right)
    {
      struct hidden{static void foo(i_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_expr::operator=(std::move(_Right));;
      }
   this->name=std::move(_Right.name);;
    }
t_inl_file::t_var_expr::ProxySys$$::metatype*t_inl_file::t_var_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_var_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_arr_ext>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_call_ext>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_ext>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_part>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_step>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_var_expr::ProxySys$$::GetFullName()
      {
        return "t_var_expr";;;
      }
void t_inl_file::t_var_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_var_expr::SelfClass*t_inl_file::t_var_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_var_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_impl>(name);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_ctor_init_list::t_init_param::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->arr); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_ctor_init_list::t_init_param::t_init_param(){DoReset();}
t_inl_file::t_ctor_init_list::t_init_param::t_init_param(t_init_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_ctor_init_list::t_init_param::operator=(t_init_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->name=std::move(_Right.name);; this->arr=std::move(_Right.arr);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_ctor_init_list::t_init_param::ProxySys$$::metatype*t_inl_file::t_ctor_init_list::t_init_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_init_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_call_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
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
        return "t_init_param";;;
      }
bool t_inl_file::t_ctor_init_list::t_init_param::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        M+=dev.go_const("(");
        if(!ok)return ok;
        O+=dev.go_vec(arr,",");
        if(!ok)return ok;
        M+=dev.go_const(")");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_ctor_init_list::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_ctor_init_list::t_ctor_init_list(){DoReset();}
t_inl_file::t_ctor_init_list::t_ctor_init_list(t_ctor_init_list&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_ctor_init_list::operator=(t_ctor_init_list&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->params=std::move(_Right.params);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_ctor_init_list::ProxySys$$::metatype*t_inl_file::t_ctor_init_list::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_ctor_init_list";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_init_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_init_param>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_ctor_init_list::ProxySys$$::GetFullName()
      {
        return "t_ctor_init_list";;;
      }
bool t_inl_file::t_ctor_init_list::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const(":");
      if(!ok)return ok;
      M+=dev.go_vec(params,",");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_zero_func_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_zero_func_body::t_zero_func_body(){DoReset();}
t_inl_file::t_zero_func_body::t_zero_func_body(t_zero_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_zero_func_body::operator=(t_zero_func_body&&_Right)
    {
      struct hidden{static void foo(i_func_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_body::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_zero_func_body::ProxySys$$::metatype*t_inl_file::t_zero_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_zero_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_zero_func_body";;;
      }
void t_inl_file::t_zero_func_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_zero_func_body::SelfClass*t_inl_file::t_zero_func_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_zero_func_body::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("=0;");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_null_func_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_null_func_body::t_null_func_body(){DoReset();}
t_inl_file::t_null_func_body::t_null_func_body(t_null_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_null_func_body::operator=(t_null_func_body&&_Right)
    {
      struct hidden{static void foo(i_func_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_body::operator=(std::move(_Right));;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_null_func_body::ProxySys$$::metatype*t_inl_file::t_null_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_null_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_null_func_body";;;
      }
void t_inl_file::t_null_func_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_null_func_body::SelfClass*t_inl_file::t_null_func_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_null_func_body::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_delete_func_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_delete_func_body::t_delete_func_body(){DoReset();}
t_inl_file::t_delete_func_body::t_delete_func_body(t_delete_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_delete_func_body::operator=(t_delete_func_body&&_Right)
    {
      struct hidden{static void foo(i_func_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_body::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_delete_func_body::ProxySys$$::metatype*t_inl_file::t_delete_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_delete_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_delete_func_body";;;
      }
void t_inl_file::t_delete_func_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_delete_func_body::SelfClass*t_inl_file::t_delete_func_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_delete_func_body::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("=delete;");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_impl_func_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->init_list); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_impl_func_body::t_impl_func_body(){DoReset();}
t_inl_file::t_impl_func_body::t_impl_func_body(t_impl_func_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_impl_func_body::operator=(t_impl_func_body&&_Right)
    {
      struct hidden{static void foo(i_func_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_func_body::operator=(std::move(_Right));;
      }
   this->sep=std::move(_Right.sep);; this->init_list=std::move(_Right.init_list);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_impl_func_body::ProxySys$$::metatype*t_inl_file::t_impl_func_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl_func_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_ctor_init_list>>::GetRTTI(RTTI),"init_list",int(&(((SelfClass*)nullptr)->*(&SelfClass::init_list))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_raw_func_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_impl_func_body";;;
      }
void t_inl_file::t_impl_func_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_impl_func_body::SelfClass*t_inl_file::t_impl_func_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_impl_func_body::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      O+=dev.go_auto(init_list);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_dtor_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->callconv); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->path); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_dtor_class_stat::t_dtor_class_stat(){DoReset();}
t_inl_file::t_dtor_class_stat::t_dtor_class_stat(t_dtor_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_dtor_class_stat::operator=(t_dtor_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->callconv=std::move(_Right.callconv);; this->sep0=std::move(_Right.sep0);; this->path=std::move(_Right.path);; this->name=std::move(_Right.name);; this->sep1=std::move(_Right.sep1);; this->params=std::move(_Right.params);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_dtor_class_stat::ProxySys$$::metatype*t_inl_file::t_dtor_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_dtor_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_callconv>>::GetRTTI(RTTI),"callconv",int(&(((SelfClass*)nullptr)->*(&SelfClass::callconv))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_dtor_class_stat";;;
      }
void t_inl_file::t_dtor_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_dtor_class_stat::SelfClass*t_inl_file::t_dtor_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_dtor_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(callconv);
      if(!ok)return ok;
      O+=dev.go_auto(path);
      if(!ok)return ok;
      M+=dev.go_const("~");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(params);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_ctor_class_stat::t_impl::t_explicit::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_ctor_class_stat::t_impl::t_explicit::t_explicit(){DoReset();}
t_inl_file::t_ctor_class_stat::t_impl::t_explicit::t_explicit(t_explicit&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_ctor_class_stat::t_impl::t_explicit::operator=(t_explicit&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_ctor_class_stat::t_impl::t_explicit::ProxySys$$::metatype*t_inl_file::t_ctor_class_stat::t_impl::t_explicit::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_explicit";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_explicit";;;
      }
bool t_inl_file::t_ctor_class_stat::t_impl::t_explicit::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("explicit");
          if(!ok)return ok;
          M+=dev.go_auto(sep);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_ctor_class_stat::t_impl::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->callconv); detail::FieldTryDoReset(this->prefix); detail::FieldTryDoReset(this->path); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->concrete_params); detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_ctor_class_stat::t_impl::t_impl(){DoReset();}
t_inl_file::t_ctor_class_stat::t_impl::t_impl(t_impl&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_ctor_class_stat::t_impl::operator=(t_impl&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->callconv=std::move(_Right.callconv);; this->prefix=std::move(_Right.prefix);; this->path=std::move(_Right.path);; this->name=std::move(_Right.name);; this->sep=std::move(_Right.sep);; this->concrete_params=std::move(_Right.concrete_params);; this->params=std::move(_Right.params);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_ctor_class_stat::t_impl::ProxySys$$::metatype*t_inl_file::t_ctor_class_stat::t_impl::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_callconv>>::GetRTTI(RTTI),"callconv",int(&(((SelfClass*)nullptr)->*(&SelfClass::callconv))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_explicit>>::GetRTTI(RTTI),"prefix",int(&(((SelfClass*)nullptr)->*(&SelfClass::prefix))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"concrete_params",int(&(((SelfClass*)nullptr)->*(&SelfClass::concrete_params))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_explicit>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_ctor_class_stat::t_impl::ProxySys$$::GetFullName()
      {
        return "t_impl";;;
      }
bool t_inl_file::t_ctor_class_stat::t_impl::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        O+=dev.go_auto(prefix);
        if(!ok)return ok;
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        O+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_ctor_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_ctor_class_stat::t_ctor_class_stat(){DoReset();}
t_inl_file::t_ctor_class_stat::t_ctor_class_stat(t_ctor_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_ctor_class_stat::operator=(t_ctor_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_ctor_class_stat::ProxySys$$::metatype*t_inl_file::t_ctor_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_ctor_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_ctor_class_stat::ProxySys$$::GetFullName()
      {
        return "t_ctor_class_stat";;;
      }
void t_inl_file::t_ctor_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_ctor_class_stat::SelfClass*t_inl_file::t_ctor_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_ctor_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_oper_cast_class_stat::t_impl::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->callconv); detail::FieldTryDoReset(this->path); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->cv); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_oper_cast_class_stat::t_impl::t_impl(){DoReset();}
t_inl_file::t_oper_cast_class_stat::t_impl::t_impl(t_impl&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_oper_cast_class_stat::t_impl::operator=(t_impl&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->callconv=std::move(_Right.callconv);; this->path=std::move(_Right.path);; this->sep0=std::move(_Right.sep0);; this->type=std::move(_Right.type);; this->sep1=std::move(_Right.sep1);; this->params=std::move(_Right.params);; this->cv=std::move(_Right.cv);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_oper_cast_class_stat::t_impl::ProxySys$$::metatype*t_inl_file::t_oper_cast_class_stat::t_impl::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_callconv>>::GetRTTI(RTTI),"callconv",int(&(((SelfClass*)nullptr)->*(&SelfClass::callconv))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_oper_cast_class_stat::t_impl::ProxySys$$::GetFullName()
      {
        return "t_impl";;;
      }
bool t_inl_file::t_oper_cast_class_stat::t_impl::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_const("operator");
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(type);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(cv);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_oper_cast_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_oper_cast_class_stat::t_oper_cast_class_stat(){DoReset();}
t_inl_file::t_oper_cast_class_stat::t_oper_cast_class_stat(t_oper_cast_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_oper_cast_class_stat::operator=(t_oper_cast_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_oper_cast_class_stat::ProxySys$$::metatype*t_inl_file::t_oper_cast_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper_cast_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_oper_cast_class_stat::ProxySys$$::GetFullName()
      {
        return "t_oper_cast_class_stat";;;
      }
void t_inl_file::t_oper_cast_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_oper_cast_class_stat::SelfClass*t_inl_file::t_oper_cast_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_oper_cast_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_common_oper_class_stat::t_impl::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->keywords); detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->cv0); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->callconv); detail::FieldTryDoReset(this->path); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->oper); detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->cv1); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_common_oper_class_stat::t_impl::t_impl(){DoReset();}
t_inl_file::t_common_oper_class_stat::t_impl::t_impl(t_impl&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_common_oper_class_stat::t_impl::operator=(t_impl&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->keywords=std::move(_Right.keywords);; this->type=std::move(_Right.type);; this->cv0=std::move(_Right.cv0);; this->sep0=std::move(_Right.sep0);; this->callconv=std::move(_Right.callconv);; this->path=std::move(_Right.path);; this->sep1=std::move(_Right.sep1);; this->oper=std::move(_Right.oper);; this->params=std::move(_Right.params);; this->cv1=std::move(_Right.cv1);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_common_oper_class_stat::t_impl::ProxySys$$::metatype*t_inl_file::t_common_oper_class_stat::t_impl::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_keyword>>::GetRTTI(RTTI),"keywords",int(&(((SelfClass*)nullptr)->*(&SelfClass::keywords))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv0",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_callconv>>::GetRTTI(RTTI),"callconv",int(&(((SelfClass*)nullptr)->*(&SelfClass::callconv))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_func_path>>::GetRTTI(RTTI),"path",int(&(((SelfClass*)nullptr)->*(&SelfClass::path))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"oper",int(&(((SelfClass*)nullptr)->*(&SelfClass::oper))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_impl";;;
      }
bool t_inl_file::t_common_oper_class_stat::t_impl::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(keywords);
        if(!ok)return ok;
        M+=dev.go_auto(type);
        if(!ok)return ok;
        O+=dev.go_auto(cv0);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        O+=dev.go_auto(path);
        if(!ok)return ok;
        M+=dev.go_const("operator");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        static const auto g_static_var_8=QapStrFinder::fromArr(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[],->",","));
        M+=dev.go_any_str_from_vec(oper,g_static_var_8);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(cv1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_common_oper_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_common_oper_class_stat::t_common_oper_class_stat(){DoReset();}
t_inl_file::t_common_oper_class_stat::t_common_oper_class_stat(t_common_oper_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_common_oper_class_stat::operator=(t_common_oper_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_common_oper_class_stat::ProxySys$$::metatype*t_inl_file::t_common_oper_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_common_oper_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_common_oper_class_stat::ProxySys$$::GetFullName()
      {
        return "t_common_oper_class_stat";;;
      }
void t_inl_file::t_common_oper_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_common_oper_class_stat::SelfClass*t_inl_file::t_common_oper_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_common_oper_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_parents::t_item::t_pub::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->mod); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_parents::t_item::t_pub::t_pub(){DoReset();}
t_inl_file::t_parents::t_item::t_pub::t_pub(t_pub&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_parents::t_item::t_pub::operator=(t_pub&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->mod=std::move(_Right.mod);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_parents::t_item::t_pub::ProxySys$$::metatype*t_inl_file::t_parents::t_item::t_pub::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_pub";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_access_mod>::GetRTTI(RTTI),"mod",int(&(((SelfClass*)nullptr)->*(&SelfClass::mod))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_pub";;;
      }
bool t_inl_file::t_parents::t_item::t_pub::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_auto(mod);
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_parents::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->pub); detail::FieldTryDoReset(this->name);
    }
t_inl_file::t_parents::t_item::t_item(){DoReset();}
t_inl_file::t_parents::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_parents::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->pub=std::move(_Right.pub);; this->name=std::move(_Right.name);;
    }
t_inl_file::t_parents::t_item::ProxySys$$::metatype*t_inl_file::t_parents::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_pub>>::GetRTTI(RTTI),"pub",int(&(((SelfClass*)nullptr)->*(&SelfClass::pub))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_pub>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_parents::t_item::ProxySys$$::GetFullName()
      {
        return "t_item";;;
      }
bool t_inl_file::t_parents::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        O+=dev.go_auto(pub);
        if(!ok)return ok;
        M+=dev.go_str<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>(name);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_parents::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_parents::t_parents(){DoReset();}
t_inl_file::t_parents::t_parents(t_parents&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_parents::operator=(t_parents&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_parents::ProxySys$$::metatype*t_inl_file::t_parents::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_parents";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_parents::ProxySys$$::GetFullName()
      {
        return "t_parents";;;
      }
bool t_inl_file::t_parents::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const(":");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_vec(arr,",");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_class_body::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_class_body::t_class_body(){DoReset();}
t_inl_file::t_class_body::t_class_body(t_class_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_class_body::operator=(t_class_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_class_body::ProxySys$$::metatype*t_inl_file::t_class_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_class_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_class_stat>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
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
        return "t_class_body";;;
      }
bool t_inl_file::t_class_body::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("{");
      if(!ok)return ok;
      O+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_class::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->keyword); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->parents); detail::FieldTryDoReset(this->sep2); detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->sep3);
    }
t_inl_file::t_class::t_class(){DoReset();}
t_inl_file::t_class::t_class(t_class&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_class::operator=(t_class&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->keyword=std::move(_Right.keyword);; this->sep0=std::move(_Right.sep0);; this->name=std::move(_Right.name);; this->sep1=std::move(_Right.sep1);; this->parents=std::move(_Right.parents);; this->sep2=std::move(_Right.sep2);; this->body=std::move(_Right.body);; this->sep3=std::move(_Right.sep3);;
    }
t_inl_file::t_class::ProxySys$$::metatype*t_inl_file::t_class::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_class";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_parents>>::GetRTTI(RTTI),"parents",int(&(((SelfClass*)nullptr)->*(&SelfClass::parents))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_class_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");;
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
        return "t_class";;;
      }
bool t_inl_file::t_class::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
      M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      O+=dev.go_auto(parents);
      if(!ok)return ok;
      O+=dev.go_auto(sep2);
      if(!ok)return ok;
      O+=dev.go_auto(body);
      if(!ok)return ok;
      O+=dev.go_auto(sep3);
      if(!ok)return ok;
      M+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_namespace_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_namespace_class_stat::t_namespace_class_stat(){DoReset();}
t_inl_file::t_namespace_class_stat::t_namespace_class_stat(t_namespace_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_namespace_class_stat::operator=(t_namespace_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->sep0=std::move(_Right.sep0);; this->name=std::move(_Right.name);; this->sep1=std::move(_Right.sep1);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_namespace_class_stat::ProxySys$$::metatype*t_inl_file::t_namespace_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_namespace_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_class_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_namespace_class_stat";;;
      }
void t_inl_file::t_namespace_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_namespace_class_stat::SelfClass*t_inl_file::t_namespace_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_namespace_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("namespace");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_template_class_stat::i_template_body::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_template_class_stat::i_template_body::i_template_body(){DoReset();}
t_inl_file::t_template_class_stat::i_template_body::i_template_body(i_template_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::i_template_body::operator=(i_template_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_template_class_stat::i_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::i_template_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_template_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_template_body";;;
      }
void t_inl_file::t_template_class_stat::i_template_body::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_template_class_stat::i_template_body::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_template_class_stat::i_template_body::t_poly_impl::load()
        {
          go_for<t_oper_cast_template_body>();;
          go_for<t_common_oper_template_body>();;
          go_for<t_ctor_template_body>();;
          go_for<t_func_template_body>();;
          go_for<t_class_template_body>();;
          (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::i_template_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_template_class_stat::i_template_param::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_template_class_stat::i_template_param::i_template_param(){DoReset();}
t_inl_file::t_template_class_stat::i_template_param::i_template_param(i_template_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::i_template_param::operator=(i_template_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_template_class_stat::i_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::i_template_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_template_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_template_param";;;
      }
void t_inl_file::t_template_class_stat::i_template_param::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_template_class_stat::i_template_param::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_template_class_stat::i_template_param::t_poly_impl::load()
        {
          go_for<t_name_template_param>();;
          go_for<t_type_template_param>();;
          (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_template_class_stat::i_template_param::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_template_class_stat::t_template_param::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->bef); detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->aft);
    }
t_inl_file::t_template_class_stat::t_template_param::t_template_param(){DoReset();}
t_inl_file::t_template_class_stat::t_template_param::t_template_param(t_template_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_template_param::operator=(t_template_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->bef=std::move(_Right.bef);; this->body=std::move(_Right.body);; this->aft=std::move(_Right.aft);;
    }
t_inl_file::t_template_class_stat::t_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_template_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_template_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"bef",int(&(((SelfClass*)nullptr)->*(&SelfClass::bef))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_param>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"aft",int(&(((SelfClass*)nullptr)->*(&SelfClass::aft))),"DEF","$");;
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
        return "t_template_param";;;
      }
bool t_inl_file::t_template_class_stat::t_template_param::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(bef);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        O+=dev.go_auto(aft);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_oper_cast_template_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_template_class_stat::t_oper_cast_template_body::t_oper_cast_template_body(){DoReset();}
t_inl_file::t_template_class_stat::t_oper_cast_template_body::t_oper_cast_template_body(t_oper_cast_template_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_oper_cast_template_body::operator=(t_oper_cast_template_body&&_Right)
    {
      struct hidden{static void foo(i_template_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_template_body::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_template_class_stat::t_oper_cast_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_oper_cast_template_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_oper_cast_template_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_oper_cast_class_stat::t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_template_class_stat::t_oper_cast_template_body::ProxySys$$::GetFullName()
      {
        return "t_oper_cast_template_body";;;
      }
void t_inl_file::t_template_class_stat::t_oper_cast_template_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::t_oper_cast_template_body::SelfClass*t_inl_file::t_template_class_stat::t_oper_cast_template_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::t_oper_cast_template_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_common_oper_template_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_template_class_stat::t_common_oper_template_body::t_common_oper_template_body(){DoReset();}
t_inl_file::t_template_class_stat::t_common_oper_template_body::t_common_oper_template_body(t_common_oper_template_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_common_oper_template_body::operator=(t_common_oper_template_body&&_Right)
    {
      struct hidden{static void foo(i_template_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_template_body::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_template_class_stat::t_common_oper_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_common_oper_template_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_common_oper_template_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_common_oper_class_stat::t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_common_oper_template_body";;;
      }
void t_inl_file::t_template_class_stat::t_common_oper_template_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::t_common_oper_template_body::SelfClass*t_inl_file::t_template_class_stat::t_common_oper_template_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::t_common_oper_template_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_ctor_template_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_template_class_stat::t_ctor_template_body::t_ctor_template_body(){DoReset();}
t_inl_file::t_template_class_stat::t_ctor_template_body::t_ctor_template_body(t_ctor_template_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_ctor_template_body::operator=(t_ctor_template_body&&_Right)
    {
      struct hidden{static void foo(i_template_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_template_body::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_template_class_stat::t_ctor_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_ctor_template_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_ctor_template_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_ctor_class_stat::t_impl>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_ctor_template_body";;;
      }
void t_inl_file::t_template_class_stat::t_ctor_template_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::t_ctor_template_body::SelfClass*t_inl_file::t_template_class_stat::t_ctor_template_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::t_ctor_template_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_func_template_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->keywords); detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->cv0); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->callconv); detail::FieldTryDoReset(this->func_name); detail::FieldTryDoReset(this->concrete_params); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->sep2); detail::FieldTryDoReset(this->cv1); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_template_class_stat::t_func_template_body::t_func_template_body(){DoReset();}
t_inl_file::t_template_class_stat::t_func_template_body::t_func_template_body(t_func_template_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_func_template_body::operator=(t_func_template_body&&_Right)
    {
      struct hidden{static void foo(i_template_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_template_body::operator=(std::move(_Right));;
      }
   this->keywords=std::move(_Right.keywords);; this->type=std::move(_Right.type);; this->cv0=std::move(_Right.cv0);; this->sep0=std::move(_Right.sep0);; this->callconv=std::move(_Right.callconv);; this->func_name=std::move(_Right.func_name);; this->concrete_params=std::move(_Right.concrete_params);; this->sep1=std::move(_Right.sep1);; this->params=std::move(_Right.params);; this->sep2=std::move(_Right.sep2);; this->cv1=std::move(_Right.cv1);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_template_class_stat::t_func_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_func_template_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_func_template_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_keyword>>::GetRTTI(RTTI),"keywords",int(&(((SelfClass*)nullptr)->*(&SelfClass::keywords))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv0",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_callconv>>::GetRTTI(RTTI),"callconv",int(&(((SelfClass*)nullptr)->*(&SelfClass::callconv))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"func_name",int(&(((SelfClass*)nullptr)->*(&SelfClass::func_name))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"concrete_params",int(&(((SelfClass*)nullptr)->*(&SelfClass::concrete_params))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_func_params>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_const_with_sep>>::GetRTTI(RTTI),"cv1",int(&(((SelfClass*)nullptr)->*(&SelfClass::cv1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_func_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_func_template_body";;;
      }
void t_inl_file::t_template_class_stat::t_func_template_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::t_func_template_body::SelfClass*t_inl_file::t_template_class_stat::t_func_template_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::t_func_template_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(keywords);
        if(!ok)return ok;
        M+=dev.go_auto(type);
        if(!ok)return ok;
        O+=dev.go_auto(cv0);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        O+=dev.go_auto(callconv);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(func_name);
        if(!ok)return ok;
        O+=dev.go_auto(concrete_params);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        M+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        O+=dev.go_auto(cv1);
        if(!ok)return ok;
        M+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_class_template_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->keyword); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->parents); detail::FieldTryDoReset(this->sep2); detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->sep3);
    }
t_inl_file::t_template_class_stat::t_class_template_body::t_class_template_body(){DoReset();}
t_inl_file::t_template_class_stat::t_class_template_body::t_class_template_body(t_class_template_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_class_template_body::operator=(t_class_template_body&&_Right)
    {
      struct hidden{static void foo(i_template_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_template_body::operator=(std::move(_Right));;
      }
   this->keyword=std::move(_Right.keyword);; this->sep0=std::move(_Right.sep0);; this->name=std::move(_Right.name);; this->sep1=std::move(_Right.sep1);; this->params=std::move(_Right.params);; this->parents=std::move(_Right.parents);; this->sep2=std::move(_Right.sep2);; this->body=std::move(_Right.body);; this->sep3=std::move(_Right.sep3);;
    }
t_inl_file::t_template_class_stat::t_class_template_body::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_class_template_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_class_template_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"keyword",int(&(((SelfClass*)nullptr)->*(&SelfClass::keyword))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_concrete_params>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_parents>>::GetRTTI(RTTI),"parents",int(&(((SelfClass*)nullptr)->*(&SelfClass::parents))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_class_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");;
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
        return "t_class_template_body";;;
      }
void t_inl_file::t_template_class_stat::t_class_template_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::t_class_template_body::SelfClass*t_inl_file::t_template_class_stat::t_class_template_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::t_class_template_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
        M+=dev.go_any_str_from_vec(keyword,g_static_var_0);
        if(!ok)return ok;
        M+=dev.go_auto(sep0);
        if(!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_auto(params);
        if(!ok)return ok;
        O+=dev.go_auto(parents);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        O+=dev.go_auto(body);
        if(!ok)return ok;
        O+=dev.go_auto(sep3);
        if(!ok)return ok;
        M+=dev.go_const(";");
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::t_unsgnd(){DoReset();}
t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::t_unsgnd(t_unsgnd&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::operator=(t_unsgnd&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_unsgnd";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_unsgnd";;;
      }
bool t_inl_file::t_template_class_stat::t_name_template_param::t_unsgnd::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("unsigned");
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_template_class_stat::t_name_template_param::t_value::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body); detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_template_class_stat::t_name_template_param::t_value::t_value(){DoReset();}
t_inl_file::t_template_class_stat::t_name_template_param::t_value::t_value(t_value&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_name_template_param::t_value::operator=(t_value&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);; this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_template_class_stat::t_name_template_param::t_value::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_name_template_param::t_value::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_value";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_template_class_stat::t_name_template_param::t_value::ProxySys$$::GetFullName()
      {
        return "t_value";;;
      }
bool t_inl_file::t_template_class_stat::t_name_template_param::t_value::go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          M+=dev.go_const("=");
          if(!ok)return ok;
          O+=dev.go_auto(sep);
          if(!ok)return ok;
          M+=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
void t_inl_file::t_template_class_stat::t_name_template_param::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->unsgnd0); detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->unsgnd1); detail::FieldTryDoReset(this->sep2); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep3); detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_template_class_stat::t_name_template_param::t_name_template_param(){DoReset();}
t_inl_file::t_template_class_stat::t_name_template_param::t_name_template_param(t_name_template_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_name_template_param::operator=(t_name_template_param&&_Right)
    {
      struct hidden{static void foo(i_template_param(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_template_param::operator=(std::move(_Right));;
      }
   this->unsgnd0=std::move(_Right.unsgnd0);; this->sep0=std::move(_Right.sep0);; this->type=std::move(_Right.type);; this->sep1=std::move(_Right.sep1);; this->unsgnd1=std::move(_Right.unsgnd1);; this->sep2=std::move(_Right.sep2);; this->name=std::move(_Right.name);; this->sep3=std::move(_Right.sep3);; this->value=std::move(_Right.value);;
    }
t_inl_file::t_template_class_stat::t_name_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_name_template_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_name_template_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"unsgnd0",int(&(((SelfClass*)nullptr)->*(&SelfClass::unsgnd0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"unsgnd1",int(&(((SelfClass*)nullptr)->*(&SelfClass::unsgnd1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep2",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep2))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep3",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep3))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_unsgnd>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_value>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_template_class_stat::t_name_template_param::ProxySys$$::GetFullName()
      {
        return "t_name_template_param";;;
      }
void t_inl_file::t_template_class_stat::t_name_template_param::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::t_name_template_param::SelfClass*t_inl_file::t_template_class_stat::t_name_template_param::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::t_name_template_param::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_str<t_unsgnd>(unsgnd0);
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(type);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_str<t_unsgnd>(unsgnd1);
        if(!ok)return ok;
        O+=dev.go_auto(sep2);
        if(!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep3);
        if(!ok)return ok;
        O+=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_head::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->params); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_template_class_stat::t_head::t_head(){DoReset();}
t_inl_file::t_template_class_stat::t_head::t_head(t_head&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_head::operator=(t_head&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->params=std::move(_Right.params);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_template_class_stat::t_head::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_head::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_head";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_template_param>>::GetRTTI(RTTI),"params",int(&(((SelfClass*)nullptr)->*(&SelfClass::params))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
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
        return "t_head";;;
      }
bool t_inl_file::t_template_class_stat::t_head::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("template");
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_const("<");
        if(!ok)return ok;
        O+=dev.go_vec(params,",");
        if(!ok)return ok;
        M+=dev.go_const(">");
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::t_type_template_param::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->head); detail::FieldTryDoReset(this->type); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->name);
    }
t_inl_file::t_template_class_stat::t_type_template_param::t_type_template_param(){DoReset();}
t_inl_file::t_template_class_stat::t_type_template_param::t_type_template_param(t_type_template_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::t_type_template_param::operator=(t_type_template_param&&_Right)
    {
      struct hidden{static void foo(i_template_param(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_template_param::operator=(std::move(_Right));;
      }
   this->head=std::move(_Right.head);; this->type=std::move(_Right.type);; this->sep=std::move(_Right.sep);; this->name=std::move(_Right.name);;
    }
t_inl_file::t_template_class_stat::t_type_template_param::ProxySys$$::metatype*t_inl_file::t_template_class_stat::t_type_template_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_type_template_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<t_head>>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");;
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
        return "t_type_template_param";;;
      }
void t_inl_file::t_template_class_stat::t_type_template_param::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::t_type_template_param::SelfClass*t_inl_file::t_template_class_stat::t_type_template_param::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::t_type_template_param::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(head);
        if(!ok)return ok;
        static const auto g_static_var_1=QapStrFinder::fromArr(split("class,typename",","));
        M+=dev.go_any_str_from_vec(type,g_static_var_1);
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        O+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_template_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->head); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_template_class_stat::t_template_class_stat(){DoReset();}
t_inl_file::t_template_class_stat::t_template_class_stat(t_template_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_template_class_stat::operator=(t_template_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->head=std::move(_Right.head);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_template_class_stat::ProxySys$$::metatype*t_inl_file::t_template_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_template_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_head>::GetRTTI(RTTI),"head",int(&(((SelfClass*)nullptr)->*(&SelfClass::head))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<i_template_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_template_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_oper_cast_template_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_common_oper_template_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_ctor_template_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_func_template_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_class_template_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_name_template_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_head>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_type_template_param>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_template_class_stat::ProxySys$$::GetFullName()
      {
        return "t_template_class_stat";;;
      }
void t_inl_file::t_template_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_template_class_stat::SelfClass*t_inl_file::t_template_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_template_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(head);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_enum_class_stat::i_body::DoReset()
    {
      {
        ;
      }
    }
t_inl_file::t_enum_class_stat::i_body::i_body(){DoReset();}
t_inl_file::t_enum_class_stat::i_body::i_body(i_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::i_body::operator=(i_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
    }
t_inl_file::t_enum_class_stat::i_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::i_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="i_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "i_body";;;
      }
void t_inl_file::t_enum_class_stat::i_body::Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
bool t_inl_file::t_enum_class_stat::i_body::go(i_dev&dev){QapDebugMsg("no way.");return false;}
bool t_inl_file::t_enum_class_stat::i_body::t_poly_impl::load()
        {
          go_for<t_impl_body>();;
          go_for<t_empty_body>();;
          (void)count;(void)first_id;(void)out_arr;(void)this;
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
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load();
  out_arr_size=out_arr.size();
  return scope.ok;
}
bool t_inl_file::t_enum_class_stat::i_body::t_poly_impl::go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}
void t_inl_file::t_enum_class_stat::t_value::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_enum_class_stat::t_value::t_value(){DoReset();}
t_inl_file::t_enum_class_stat::t_value::t_value(t_value&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::t_value::operator=(t_value&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->expr=std::move(_Right.expr);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_enum_class_stat::t_value::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_value::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_value";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
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
        return "t_value";;;
      }
bool t_inl_file::t_enum_class_stat::t_value::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("=");
        if(!ok)return ok;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_auto(expr);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_enum_class_stat::t_item::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_enum_class_stat::t_item::t_item(){DoReset();}
t_inl_file::t_enum_class_stat::t_item::t_item(t_item&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::t_item::operator=(t_item&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->name=std::move(_Right.name);; this->sep1=std::move(_Right.sep1);; this->value=std::move(_Right.value);;
    }
t_inl_file::t_enum_class_stat::t_item::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_item::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_item";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_value>>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
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
        return "t_item";;;
      }
bool t_inl_file::t_enum_class_stat::t_item::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        O+=dev.go_auto(sep0);
        if(!ok)return ok;
        M+=dev.go_str<t_name>(name);
        if(!ok)return ok;
        O+=dev.go_auto(sep1);
        if(!ok)return ok;
        O+=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_enum_class_stat::t_comma_with_sep::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_enum_class_stat::t_comma_with_sep::t_comma_with_sep(){DoReset();}
t_inl_file::t_enum_class_stat::t_comma_with_sep::t_comma_with_sep(t_comma_with_sep&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::t_comma_with_sep::operator=(t_comma_with_sep&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_enum_class_stat::t_comma_with_sep::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_comma_with_sep::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_comma_with_sep";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_comma_with_sep";;;
      }
bool t_inl_file::t_enum_class_stat::t_comma_with_sep::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const(",");
        if(!ok)return ok;
        O+=dev.go_auto(sep);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_enum_class_stat::t_impl_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->arr); detail::FieldTryDoReset(this->comma);
    }
t_inl_file::t_enum_class_stat::t_impl_body::t_impl_body(){DoReset();}
t_inl_file::t_enum_class_stat::t_impl_body::t_impl_body(t_impl_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::t_impl_body::operator=(t_impl_body&&_Right)
    {
      struct hidden{static void foo(i_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_body::operator=(std::move(_Right));;
      }
   this->arr=std::move(_Right.arr);; this->comma=std::move(_Right.comma);;
    }
t_inl_file::t_enum_class_stat::t_impl_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_impl_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_item>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_comma_with_sep>>::GetRTTI(RTTI),"comma",int(&(((SelfClass*)nullptr)->*(&SelfClass::comma))),"DEF","$");;
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
        return "t_impl_body";;;
      }
void t_inl_file::t_enum_class_stat::t_impl_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_enum_class_stat::t_impl_body::SelfClass*t_inl_file::t_enum_class_stat::t_impl_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_enum_class_stat::t_impl_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        M+=dev.go_const("{");
        if(!ok)return ok;
        O+=dev.go_vec(arr,",");
        if(!ok)return ok;
        O+=dev.go_auto(comma);
        if(!ok)return ok;
        M+=dev.go_const("}");
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_enum_class_stat::t_empty_body::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_enum_class_stat::t_empty_body::t_empty_body(){DoReset();}
t_inl_file::t_enum_class_stat::t_empty_body::t_empty_body(t_empty_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::t_empty_body::operator=(t_empty_body&&_Right)
    {
      struct hidden{static void foo(i_body(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_body::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_enum_class_stat::t_empty_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_empty_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_empty_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_empty_body";;;
      }
void t_inl_file::t_enum_class_stat::t_empty_body::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_enum_class_stat::t_empty_body::SelfClass*t_inl_file::t_enum_class_stat::t_empty_body::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_enum_class_stat::t_empty_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const(";");
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_enum_class_stat::t_body::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_enum_class_stat::t_body::t_body(){DoReset();}
t_inl_file::t_enum_class_stat::t_body::t_body(t_body&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::t_body::operator=(t_body&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_enum_class_stat::t_body::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::t_body::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_body";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<TAutoPtr<i_body>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_body";;;
      }
bool t_inl_file::t_enum_class_stat::t_body::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_enum_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->name); detail::FieldTryDoReset(this->sep1); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_enum_class_stat::t_enum_class_stat(){DoReset();}
t_inl_file::t_enum_class_stat::t_enum_class_stat(t_enum_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_enum_class_stat::operator=(t_enum_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->sep0=std::move(_Right.sep0);; this->name=std::move(_Right.name);; this->sep1=std::move(_Right.sep1);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_enum_class_stat::ProxySys$$::metatype*t_inl_file::t_enum_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_enum_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_body>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_value>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_item>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_comma_with_sep>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_impl_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_empty_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_body>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_enum_class_stat::ProxySys$$::GetFullName()
      {
        return "t_enum_class_stat";;;
      }
void t_inl_file::t_enum_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_enum_class_stat::SelfClass*t_inl_file::t_enum_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_enum_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("enum");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      O+=dev.go_str<t_name>(name);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      O+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_using_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->type);
    }
t_inl_file::t_using_class_stat::t_using_class_stat(){DoReset();}
t_inl_file::t_using_class_stat::t_using_class_stat(t_using_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_using_class_stat::operator=(t_using_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->sep=std::move(_Right.sep);; this->type=std::move(_Right.type);;
    }
t_inl_file::t_using_class_stat::ProxySys$$::metatype*t_inl_file::t_using_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_using_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr>::GetRTTI(RTTI),"type",int(&(((SelfClass*)nullptr)->*(&SelfClass::type))),"DEF","$");;
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
        return "t_using_class_stat";;;
      }
void t_inl_file::t_using_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_using_class_stat::SelfClass*t_inl_file::t_using_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_using_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("using");
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(type);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_tmpl_call_param::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_tmpl_call_param::t_tmpl_call_param(){DoReset();}
t_inl_file::t_tmpl_call_param::t_tmpl_call_param(t_tmpl_call_param&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_tmpl_call_param::operator=(t_tmpl_call_param&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep0=std::move(_Right.sep0);; this->expr=std::move(_Right.expr);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_tmpl_call_param::ProxySys$$::metatype*t_inl_file::t_tmpl_call_param::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_tmpl_call_param";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_tmpl_call_param::ProxySys$$::GetFullName()
      {
        return "t_tmpl_call_param";;;
      }
bool t_inl_file::t_tmpl_call_param::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_call_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->func); detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_call_tmpl_expr::t_call_tmpl_expr(){DoReset();}
t_inl_file::t_call_tmpl_expr::t_call_tmpl_expr(t_call_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_call_tmpl_expr::operator=(t_call_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->func=std::move(_Right.func);; this->sep=std::move(_Right.sep);; this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_call_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_call_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_call_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"func",int(&(((SelfClass*)nullptr)->*(&SelfClass::func))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<vector<t_tmpl_call_param>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_call_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_call_tmpl_expr";;;
      }
void t_inl_file::t_call_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_call_tmpl_expr::SelfClass*t_inl_file::t_call_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_call_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_str<t_name>(func);
      if(!ok)return ok;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_vec(arr,",");
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_block_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep0); detail::FieldTryDoReset(this->expr); detail::FieldTryDoReset(this->sep1);
    }
t_inl_file::t_block_tmpl_expr::t_block_tmpl_expr(){DoReset();}
t_inl_file::t_block_tmpl_expr::t_block_tmpl_expr(t_block_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_block_tmpl_expr::operator=(t_block_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->sep0=std::move(_Right.sep0);; this->expr=std::move(_Right.expr);; this->sep1=std::move(_Right.sep1);;
    }
t_inl_file::t_block_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_block_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_block_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep0",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep0))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_tmpl_expr>::GetRTTI(RTTI),"expr",int(&(((SelfClass*)nullptr)->*(&SelfClass::expr))),"DEF","$");; Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep1",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep1))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_block_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_block_tmpl_expr";;;
      }
void t_inl_file::t_block_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_block_tmpl_expr::SelfClass*t_inl_file::t_block_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_block_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_const("(");
      if(!ok)return ok;
      O+=dev.go_auto(sep0);
      if(!ok)return ok;
      M+=dev.go_auto(expr);
      if(!ok)return ok;
      O+=dev.go_auto(sep1);
      if(!ok)return ok;
      M+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_pfunc_concrete_param_way::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_pfunc_concrete_param_way::t_pfunc_concrete_param_way(){DoReset();}
t_inl_file::t_pfunc_concrete_param_way::t_pfunc_concrete_param_way(t_pfunc_concrete_param_way&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_pfunc_concrete_param_way::operator=(t_pfunc_concrete_param_way&&_Right)
    {
      struct hidden{static void foo(i_concrete_param_way(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_concrete_param_way::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_pfunc_concrete_param_way::ProxySys$$::metatype*t_inl_file::t_pfunc_concrete_param_way::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_pfunc_concrete_param_way";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_pfunc>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_pfunc_concrete_param_way::ProxySys$$::GetFullName()
      {
        return "t_pfunc_concrete_param_way";;;
      }
void t_inl_file::t_pfunc_concrete_param_way::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_pfunc_concrete_param_way::SelfClass*t_inl_file::t_pfunc_concrete_param_way::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_pfunc_concrete_param_way::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_type_concrete_param_way::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_type_concrete_param_way::t_type_concrete_param_way(){DoReset();}
t_inl_file::t_type_concrete_param_way::t_type_concrete_param_way(t_type_concrete_param_way&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_type_concrete_param_way::operator=(t_type_concrete_param_way&&_Right)
    {
      struct hidden{static void foo(i_concrete_param_way(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_concrete_param_way::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_type_concrete_param_way::ProxySys$$::metatype*t_inl_file::t_type_concrete_param_way::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_type_concrete_param_way";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_type_concrete_param_way::ProxySys$$::GetFullName()
      {
        return "t_type_concrete_param_way";;;
      }
void t_inl_file::t_type_concrete_param_way::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_type_concrete_param_way::SelfClass*t_inl_file::t_type_concrete_param_way::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_type_concrete_param_way::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_expr_concrete_param_way::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_expr_concrete_param_way::t_expr_concrete_param_way(){DoReset();}
t_inl_file::t_expr_concrete_param_way::t_expr_concrete_param_way(t_expr_concrete_param_way&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_expr_concrete_param_way::operator=(t_expr_concrete_param_way&&_Right)
    {
      struct hidden{static void foo(i_concrete_param_way(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_concrete_param_way::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_expr_concrete_param_way::ProxySys$$::metatype*t_inl_file::t_expr_concrete_param_way::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_expr_concrete_param_way";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_tmpl_expr>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_expr_concrete_param_way::ProxySys$$::GetFullName()
      {
        return "t_expr_concrete_param_way";;;
      }
void t_inl_file::t_expr_concrete_param_way::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_expr_concrete_param_way::SelfClass*t_inl_file::t_expr_concrete_param_way::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_expr_concrete_param_way::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_minor<t_type_concrete_param_way>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_bool_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_bool_tmpl_expr::t_bool_tmpl_expr(){DoReset();}
t_inl_file::t_bool_tmpl_expr::t_bool_tmpl_expr(t_bool_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_bool_tmpl_expr::operator=(t_bool_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_bool_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_bool_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_bool_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_bool_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_bool_tmpl_expr";;;
      }
void t_inl_file::t_bool_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_bool_tmpl_expr::SelfClass*t_inl_file::t_bool_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_bool_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_string_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_string_tmpl_expr::t_string_tmpl_expr(){DoReset();}
t_inl_file::t_string_tmpl_expr::t_string_tmpl_expr(t_string_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_string_tmpl_expr::operator=(t_string_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_string_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_string_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_string_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_string_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_string_tmpl_expr";;;
      }
void t_inl_file::t_string_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_string_tmpl_expr::SelfClass*t_inl_file::t_string_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_string_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_str_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_char_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_char_tmpl_expr::t_char_tmpl_expr(){DoReset();}
t_inl_file::t_char_tmpl_expr::t_char_tmpl_expr(t_char_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_char_tmpl_expr::operator=(t_char_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_char_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_char_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_char_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_char_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_char_tmpl_expr";;;
      }
void t_inl_file::t_char_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_char_tmpl_expr::SelfClass*t_inl_file::t_char_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_char_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_char_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_num_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_num_tmpl_expr::t_num_tmpl_expr(){DoReset();}
t_inl_file::t_num_tmpl_expr::t_num_tmpl_expr(t_num_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_num_tmpl_expr::operator=(t_num_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_num_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_num_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_num_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_num_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_num_tmpl_expr";;;
      }
void t_inl_file::t_num_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_num_tmpl_expr::SelfClass*t_inl_file::t_num_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_num_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      D+=dev.go_any(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_real_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_real_tmpl_expr::t_real_tmpl_expr(){DoReset();}
t_inl_file::t_real_tmpl_expr::t_real_tmpl_expr(t_real_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_real_tmpl_expr::operator=(t_real_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_real_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_real_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_real_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_real_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_real_tmpl_expr";;;
      }
void t_inl_file::t_real_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_real_tmpl_expr::SelfClass*t_inl_file::t_real_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_real_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_real>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_nullptr_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_nullptr_tmpl_expr::t_nullptr_tmpl_expr(){DoReset();}
t_inl_file::t_nullptr_tmpl_expr::t_nullptr_tmpl_expr(t_nullptr_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_nullptr_tmpl_expr::operator=(t_nullptr_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_nullptr_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_nullptr_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_nullptr_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
string t_inl_file::t_nullptr_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_nullptr_tmpl_expr";;;
      }
void t_inl_file::t_nullptr_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_nullptr_tmpl_expr::SelfClass*t_inl_file::t_nullptr_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_nullptr_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("nullptr");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_or_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_or_tmpl_expr::t_or_tmpl_expr(){DoReset();}
t_inl_file::t_or_tmpl_expr::t_or_tmpl_expr(t_or_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_or_tmpl_expr::operator=(t_or_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->arr=std::move(_Right.arr);;
    }
t_inl_file::t_or_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_or_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_or_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<vector<t_name>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_or_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_or_tmpl_expr";;;
      }
void t_inl_file::t_or_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_or_tmpl_expr::SelfClass*t_inl_file::t_or_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_or_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_bin_oper(arr,"|");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_hex_tmpl_expr::t_impl::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->x); detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_hex_tmpl_expr::t_impl::t_impl(){DoReset();}
t_inl_file::t_hex_tmpl_expr::t_impl::t_impl(t_impl&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_hex_tmpl_expr::t_impl::operator=(t_impl&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->x=std::move(_Right.x);; this->value=std::move(_Right.value);;
    }
t_inl_file::t_hex_tmpl_expr::t_impl::ProxySys$$::metatype*t_inl_file::t_hex_tmpl_expr::t_impl::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_impl";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<char>::GetRTTI(RTTI),"x",int(&(((SelfClass*)nullptr)->*(&SelfClass::x))),"DEF","$");; Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_hex_tmpl_expr::t_impl::ProxySys$$::GetFullName()
      {
        return "t_impl";;;
      }
bool t_inl_file::t_hex_tmpl_expr::t_impl::go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("0");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("xX");
        D+=dev.go_any_char(x,g_static_var_1);
        if(!ok)return ok;
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09afAF"));
        D+=dev.go_any(value,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
void t_inl_file::t_hex_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->value);
    }
t_inl_file::t_hex_tmpl_expr::t_hex_tmpl_expr(){DoReset();}
t_inl_file::t_hex_tmpl_expr::t_hex_tmpl_expr(t_hex_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_hex_tmpl_expr::operator=(t_hex_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->value=std::move(_Right.value);;
    }
t_inl_file::t_hex_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_hex_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_hex_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"value",int(&(((SelfClass*)nullptr)->*(&SelfClass::value))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_impl>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_hex_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_hex_tmpl_expr";;;
      }
void t_inl_file::t_hex_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_hex_tmpl_expr::SelfClass*t_inl_file::t_hex_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_hex_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_var_tmpl_expr::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->name);
    }
t_inl_file::t_var_tmpl_expr::t_var_tmpl_expr(){DoReset();}
t_inl_file::t_var_tmpl_expr::t_var_tmpl_expr(t_var_tmpl_expr&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_var_tmpl_expr::operator=(t_var_tmpl_expr&&_Right)
    {
      struct hidden{static void foo(i_tmpl_expr(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_tmpl_expr::operator=(std::move(_Right));;
      }
   this->name=std::move(_Right.name);;
    }
t_inl_file::t_var_tmpl_expr::ProxySys$$::metatype*t_inl_file::t_var_tmpl_expr::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_var_tmpl_expr";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"name",int(&(((SelfClass*)nullptr)->*(&SelfClass::name))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::t_var_tmpl_expr::ProxySys$$::GetFullName()
      {
        return "t_var_tmpl_expr";;;
      }
void t_inl_file::t_var_tmpl_expr::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_var_tmpl_expr::SelfClass*t_inl_file::t_var_tmpl_expr::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_var_tmpl_expr::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_fv_class_stat::t_type_expr>(name);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_pragma_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_pragma_class_stat::t_pragma_class_stat(){DoReset();}
t_inl_file::t_pragma_class_stat::t_pragma_class_stat(t_pragma_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_pragma_class_stat::operator=(t_pragma_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_pragma_class_stat::ProxySys$$::metatype*t_inl_file::t_pragma_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_pragma_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_pragma_class_stat";;;
      }
void t_inl_file::t_pragma_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_pragma_class_stat::SelfClass*t_inl_file::t_pragma_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_pragma_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#pragma");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_include_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_include_class_stat::t_include_class_stat(){DoReset();}
t_inl_file::t_include_class_stat::t_include_class_stat(t_include_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_include_class_stat::operator=(t_include_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_include_class_stat::ProxySys$$::metatype*t_inl_file::t_include_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_include_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_include_class_stat";;;
      }
void t_inl_file::t_include_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_include_class_stat::SelfClass*t_inl_file::t_include_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_include_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#include");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_preproc_if_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_preproc_if_class_stat::t_preproc_if_class_stat(){DoReset();}
t_inl_file::t_preproc_if_class_stat::t_preproc_if_class_stat(t_preproc_if_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_preproc_if_class_stat::operator=(t_preproc_if_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_preproc_if_class_stat::ProxySys$$::metatype*t_inl_file::t_preproc_if_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_preproc_if_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_preproc_if_class_stat";;;
      }
void t_inl_file::t_preproc_if_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_preproc_if_class_stat::SelfClass*t_inl_file::t_preproc_if_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_preproc_if_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#if");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_preproc_else_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_preproc_else_class_stat::t_preproc_else_class_stat(){DoReset();}
t_inl_file::t_preproc_else_class_stat::t_preproc_else_class_stat(t_preproc_else_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_preproc_else_class_stat::operator=(t_preproc_else_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_preproc_else_class_stat::ProxySys$$::metatype*t_inl_file::t_preproc_else_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_preproc_else_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_preproc_else_class_stat";;;
      }
void t_inl_file::t_preproc_else_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_preproc_else_class_stat::SelfClass*t_inl_file::t_preproc_else_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_preproc_else_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#else");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_preproc_endif_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_preproc_endif_class_stat::t_preproc_endif_class_stat(){DoReset();}
t_inl_file::t_preproc_endif_class_stat::t_preproc_endif_class_stat(t_preproc_endif_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_preproc_endif_class_stat::operator=(t_preproc_endif_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_preproc_endif_class_stat::ProxySys$$::metatype*t_inl_file::t_preproc_endif_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_preproc_endif_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_preproc_endif_class_stat";;;
      }
void t_inl_file::t_preproc_endif_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_preproc_endif_class_stat::SelfClass*t_inl_file::t_preproc_endif_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_preproc_endif_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#endif");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_define_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_define_class_stat::t_define_class_stat(){DoReset();}
t_inl_file::t_define_class_stat::t_define_class_stat(t_define_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_define_class_stat::operator=(t_define_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_define_class_stat::ProxySys$$::metatype*t_inl_file::t_define_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_define_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_define_class_stat";;;
      }
void t_inl_file::t_define_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_define_class_stat::SelfClass*t_inl_file::t_define_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_define_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#define");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_undef_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_undef_class_stat::t_undef_class_stat(){DoReset();}
t_inl_file::t_undef_class_stat::t_undef_class_stat(t_undef_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_undef_class_stat::operator=(t_undef_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_undef_class_stat::ProxySys$$::metatype*t_inl_file::t_undef_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_undef_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<string>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_undef_class_stat";;;
      }
void t_inl_file::t_undef_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_undef_class_stat::SelfClass*t_inl_file::t_undef_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_undef_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("#undef");
      if(!ok)return ok;
      D+=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_sep_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->sep);
    }
t_inl_file::t_sep_class_stat::t_sep_class_stat(){DoReset();}
t_inl_file::t_sep_class_stat::t_sep_class_stat(t_sep_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_sep_class_stat::operator=(t_sep_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->sep=std::move(_Right.sep);;
    }
t_inl_file::t_sep_class_stat::ProxySys$$::metatype*t_inl_file::t_sep_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_sep_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");;
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
        return "t_sep_class_stat";;;
      }
void t_inl_file::t_sep_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_sep_class_stat::SelfClass*t_inl_file::t_sep_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_sep_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_null_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
    }
t_inl_file::t_null_class_stat::t_null_class_stat(){DoReset();}
t_inl_file::t_null_class_stat::t_null_class_stat(t_null_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_null_class_stat::operator=(t_null_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
    }
t_inl_file::t_null_class_stat::ProxySys$$::metatype*t_inl_file::t_null_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_null_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
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
        return "t_null_class_stat";;;
      }
void t_inl_file::t_null_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_null_class_stat::SelfClass*t_inl_file::t_null_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_null_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_class_class_stat::DoReset()
    {
      {
        detail::TryDoReset<SelfClass>(this);;
      }
   detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_class_class_stat::t_class_class_stat(){DoReset();}
t_inl_file::t_class_class_stat::t_class_class_stat(t_class_class_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_class_class_stat::operator=(t_class_class_stat&&_Right)
    {
      struct hidden{static void foo(i_class_stat(*)=(SelfClass*)nullptr){}};;;;
      if(&_Right==this)return;
      {
        i_class_stat::operator=(std::move(_Right));;
      }
   this->body=std::move(_Right.body);;
    }
t_inl_file::t_class_class_stat::ProxySys$$::metatype*t_inl_file::t_class_class_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_class_class_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=Sys$$<ParentClass>::GetRTTI(RTTI);
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_class>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_class_class_stat";;;
      }
void t_inl_file::t_class_class_stat::Use(i_visitor&A){A.Do(this);}
t_inl_file::t_class_class_stat::SelfClass*t_inl_file::t_class_class_stat::UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
bool t_inl_file::t_class_class_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::t_inl_file_stat::DoReset()
    {
      {
        ;
      }
   detail::FieldTryDoReset(this->sep); detail::FieldTryDoReset(this->body);
    }
t_inl_file::t_inl_file_stat::t_inl_file_stat(){DoReset();}
t_inl_file::t_inl_file_stat::t_inl_file_stat(t_inl_file_stat&&_Right){operator=(std::move(_Right));}
void t_inl_file::t_inl_file_stat::operator=(t_inl_file_stat&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
   this->sep=std::move(_Right.sep);; this->body=std::move(_Right.body);;
    }
t_inl_file::t_inl_file_stat::ProxySys$$::metatype*t_inl_file::t_inl_file_stat::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_inl_file_stat";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=Sys$$<OwnerClass>::GetRTTI(RTTI);
        }
   Info->AddMemberDEF(Sys$$<t_sep>::GetRTTI(RTTI),"sep",int(&(((SelfClass*)nullptr)->*(&SelfClass::sep))),"DEF","$");; Info->AddMemberDEF(Sys$$<TAutoPtr<t_class>>::GetRTTI(RTTI),"body",int(&(((SelfClass*)nullptr)->*(&SelfClass::body))),"DEF","$");;
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
        return "t_inl_file_stat";;;
      }
bool t_inl_file::t_inl_file_stat::go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      O+=dev.go_auto(sep);
      if(!ok)return ok;
      M+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
void t_inl_file::DoReset()
    {
      {
        ;
      }
  detail::FieldTryDoReset(this->arr);
    }
t_inl_file::t_inl_file(){DoReset();}
t_inl_file::t_inl_file(t_inl_file&&_Right){operator=(std::move(_Right));}
void t_inl_file::operator=(t_inl_file&&_Right)
    {
      ;
      if(&_Right==this)return;
      {
        ;
      }
  this->arr=std::move(_Right.arr);;
    }
t_inl_file::ProxySys$$::metatype*t_inl_file::ProxySys$$::GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name="t_inl_file";;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
            Info->SubType=nullptr;
            Info->OwnType=nullptr;
        }
  Info->AddMemberDEF(Sys$$<vector<TAutoPtr<i_class_stat>>>::GetRTTI(RTTI),"arr",int(&(((SelfClass*)nullptr)->*(&SelfClass::arr))),"DEF","$");;
        {
          RTTI.OnRegEnd(Info);
        }
        {
            Info->AddNested(Sys$$<t_lev03>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev05>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev06>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev07>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev08>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev09>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev10>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev11>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev12>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev13>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_lev14>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev03>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev05>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev06>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev09>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev10>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev11>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev12>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev13>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_lev14>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_concrete_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_concrete_params>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_access_mod>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_access_mod_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_raw_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_func_path>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_const_with_sep>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_keyword>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_callconv>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_ptr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_ref>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_type_with_sep>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_scope_with_sep>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_scopes>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_global>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_raw_type_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_arr_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_fv_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_typedef_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_real>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_call_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_call_params>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_block_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_bool_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_string_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_char_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_num_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_real_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_nullptr_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_or_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_hex_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_var_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_ctor_init_list>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_zero_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_null_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_delete_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_impl_func_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_dtor_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_ctor_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_oper_cast_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_common_oper_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_parents>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_class_body>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_class>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_namespace_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_template_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_enum_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_using_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_tmpl_call_param>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_call_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_block_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_pfunc_concrete_param_way>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_type_concrete_param_way>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_expr_concrete_param_way>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_bool_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_string_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_char_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_num_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_real_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_nullptr_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_or_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_hex_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_var_tmpl_expr>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_pragma_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_include_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_preproc_if_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_preproc_else_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_preproc_endif_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_define_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_undef_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_sep_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_null_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_class_class_stat>::GetRTTI(RTTI));; Info->AddNested(Sys$$<t_inl_file_stat>::GetRTTI(RTTI));;;
        }
        Info->SelfTesting();
        return Info;
      }
string t_inl_file::ProxySys$$::GetFullName()
      {
        return "t_inl_file";;;
      }
bool t_inl_file::go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
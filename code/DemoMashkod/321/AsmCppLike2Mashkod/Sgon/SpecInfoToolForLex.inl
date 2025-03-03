template<class TYPE>
string go_func_ptr_to_hex(bool (TYPE::*pfunc)(i_dev&dev)){
  struct{bool (TYPE::*pfunc)(i_dev&dev);} result={pfunc};return HToS(*(int*)&result);
}

template<class TYPE>
string poly_func_ptr_to_hex(bool (*pfunc)(i_dev&dev,TAutoPtr<TYPE>&ref)){
  struct{bool (*pfunc)(i_dev&dev,TAutoPtr<TYPE>&ref);} result={pfunc};return HToS(*(int*)&result);
}

template<class TYPE>
string get_poly_specinfo()
{
  auto&f=poly_func_ptr_to_hex<TYPE>;
  return "base:(st:"+f(&TYPE::t_poly_impl::go_st)+",lt:"+f(&TYPE::t_poly_impl::go_lt)+")";
}

template<class TYPE>
string get_impl_specinfo(){return "impl:"+go_func_ptr_to_hex(&TYPE::go);}
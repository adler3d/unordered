короче елси надо загрузить тип типа TAutoPtr<какой-то_интерфейс>
то тогда надо вызвать дл€ какой-то_интерфейс::t_poly_impl::go_lt
и дело сделано.

если нам досталс€ TAutoPtr<какой-то_лексер>
то мы дл€ него вызываем метод какой-то_лексер::go.

если нам досталс€ какой-то_лексер
то мы дл€ него вызываем метод какой-то_лексер::go.

всЄ просто.
если нам досталась строка.
то мы еЄ просто пибавл€ем.
если char, то тоже его тупо прибавл€ем.
если число, то тогда ломаем программу.

template<class TYPE>
static bool go_for_poly(i_dev&dev,TAutoPtr<TYPE>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isLoad()){
    ok=TYPE::t_poly_impl::go_lt(dev,ref);
  }
  if(dev.isSave()){
    ok=TYPE::t_poly_impl::go_st(dev,ref);
  }
  return ok;
}

string unsafe_toStr(IEnvRTTI&Env,string&ref){return ref;}
template<class TYPE>
string unsafe_toStr(IEnvRTTI&Env,TAutoPtr<TYPE>&ref){
  тут что-то особенное использующее go_st и go_lt. точнее строго go_st.
}

template<class TYPE>
string unsafe_toStr(IEnvRTTI&Env,TYPE&ref)
{
  TTypeStruct*pType=Sys$$<TYPE>::GetRTTI(Env);
  QapAssert(!pType->extInfo.SpecInfo.empty());
  auto&arr=pType->Members;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    
  }
  ->extInfo.SpecInfo;
  
  сейчас € сгенерирую новое описание лексем в котором уже бдет нужна€ мне функци€.
  сделал.
  провер€ю на компилируемость.
  хот€ уже можно писать саму функцию.
  так. это функци€ будет работать с TTypeStruct
}

короче € придумал как вот это код:

if(p_fullname.find("t_fv_stat\1")!=string::npos)
{
  int gg=1;
  auto&value=*(t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat*)dev.top.pValue;
  if(auto*pf=t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::UberCast(value.way.get()))
  {
    auto&Env=*value.way.Product.pType->Env.get();
    string bef;
    #define F(FIELD)bef+=toStr(Env,value.FIELD);
    F(keywords);
    F(type);
    F(cv);
    F(sep0);
    F(path);
    F(sep1);
    #undef F
    auto aft=toStr(Env,pf->params)+toStr(Env,pf->cv1);
    qap_add_back(dev.out)=bef+value.name+aft+";";//+"//way.pType="+value.way.Product.pType->GetFullName();
  }
}

заменить на вот этот:

if(p_fullname.find("t_fv_stat\1")!=string::npos)
{
  int gg=1;
  auto&value=*(t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat*)dev.top.pValue;
  if(auto*pf=t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_func_fv_end::UberCast(value.way.get()))
  {
    auto&Env=*value.way.Product.pType->Env.get();
    pf->body=nullptr;
    qap_add_back(dev.out)=unsafe_toStr(Env,value);
  }
}

































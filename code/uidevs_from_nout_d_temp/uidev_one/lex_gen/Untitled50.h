������ ���� ���� ��������� ��� ���� TAutoPtr<�����-��_���������>
�� ����� ���� ������� ��� �����-��_���������::t_poly_impl::go_lt
� ���� �������.

���� ��� �������� TAutoPtr<�����-��_������>
�� �� ��� ���� �������� ����� �����-��_������::go.

���� ��� �������� �����-��_������
�� �� ��� ���� �������� ����� �����-��_������::go.

�� ������.
���� ��� ��������� ������.
�� �� � ������ ���������.
���� char, �� ���� ��� ���� ����������.
���� �����, �� ����� ������ ���������.

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
  ��� ���-�� ��������� ������������ go_st � go_lt. ������ ������ go_st.
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
  
  ������ � ���������� ����� �������� ������ � ������� ��� ���� ������ ��� �������.
  ������.
  �������� �� ���������������.
  ���� ��� ����� ������ ���� �������.
  ���. ��� ������� ����� �������� � TTypeStruct
}

������ � �������� ��� ��� ��� ���:

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

�������� �� ��� ����:

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

































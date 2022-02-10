#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(rettype,adduni,arr,field_type,field)\
  rettype*adduni(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    if(!p){p=&qap_add_back(arr);p->field=value;}\
    return p;\
  }

//template<typename TYPE,size_t COUNT>inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}

template<class TYPE,class FUNC>
int qap_minval_id_for_vec(vector_view<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector_view<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;                         
  int id=0;auto val=func(arr[0],0); 
  for(int i=1;i<arr.size();i++){                    
    auto&ex=arr[i];                                 
    auto tmp=func(ex,i);                  
    if(tmp>=val)continue;               
    val=tmp;id=i;                 
  }                                                 
  return id;
}

template<class TYPE>bool qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}
template<class TYPE>bool qap_includes(const vector_view<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}

#define QAP_MINVAL_ID_OF_VEC(arr,code)qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return code;})

template<class TYPE,class FUNC>void qap_foreach(vector<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(const vector<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(vector_view<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(const vector_view<TYPE>&arr,FUNC func){for(int i=0;i<arr.size();i++)func(arr[i],i);}
#define QAP_FOREACH(arr,code)qap_foreach(arr,[&](decltype(arr[0])&ex,int i){code;})
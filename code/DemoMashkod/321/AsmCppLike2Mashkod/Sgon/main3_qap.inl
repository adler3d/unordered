//enum Value_type{ obj_type, array_type, str_type, bool_type, int_type, real_type, null_type };

#define TYPE_LIST(F)\
F(int,int,0)\
F(str,string,"")\
F(bool,bool,false)\
F(real,double,0.0)
//end

template<class TYPE>
struct qap_get_def{
  static string value(){return "";};
};

#define F(JS_TYPE,TYPE,VALUE)template<>struct qap_get_def<TYPE>{static string value(){return #VALUE;}};
TYPE_LIST(F)
#undef F

template<class TYPE>struct qap_get_def<vector<TYPE>>{static string value(){return "";}};

#define F(JS_TYPE,TYPE,VALUE)static void qap_doreset(TYPE&ref){ref=VALUE;}
TYPE_LIST(F)
#undef F

template<class TYPE>
static typename std::enable_if<std::is_object<TYPE>::value,void>::type
qap_doreset(TYPE&ref)
{
  ref.DoReset();
}

template<class TYPE>
static void qap_doreset(vector<TYPE>&ref)
{
  ref.clear();
}

#define F(JS_TYPE,TYPE,VALUE)static void qap_load(TYPE&ref,json_spirit::Value&val){ref=val.get_##JS_TYPE();}
TYPE_LIST(F)
#undef F

template<class TYPE>
typename std::enable_if<std::is_object<TYPE>::value,void>::type
static qap_load(TYPE&ref,json_spirit::Value&val)
{
  auto&obj=val.get_obj();
  ref.load(obj);
}

template<class TYPE>
static void qap_load(vector<TYPE>&ref,json_spirit::Value&val)
{
  auto&arr=val.get_array();
  ref.resize(arr.size());
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=ref[i];
    auto&ax=arr[i];
    qap_load(ex,ax);
  }
}

#undef TYPE_LIST
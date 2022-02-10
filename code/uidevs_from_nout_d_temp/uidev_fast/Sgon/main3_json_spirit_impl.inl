public:
  void load(json_spirit::Value::Config_type::Object_type&object)
  {
    using namespace json_spirit;
    auto go=[this,&object](const string&field_name)->int
    {
      for(int i=0;i<object.size();i++)
      {
        auto&ex=object[i];
        string&name=ex.name_;
        if(name==field_name)return i;
      }
      return -1;
    };
    #define DEF_SKIP()
    #define DEF_PRO_USE_IT(NUMBER,TYPE,NAME,MODE,VALUE,RESERVED)\
      {\
        static const string field_name=#NAME;\
        int field_index=go(field_name);\
        if(field_index>=0){\
          auto&ex=object[field_index];\
          qap_load(this->NAME,ex.value_);\
        }else{\
          qap_doreset(this->NAME);\
        }\
      }
    DEF_PRO_VARIABLE(DEF_SKIP,DEF_PRO_USE_IT,DEF_SKIP)
    #undef DEF_PRO_USE_IT
    #undef DEF_SKIP
  }
public:
#include "QapGenStruct.inl"
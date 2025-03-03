//`Регистрируем системные типы
#ifdef DEF_PRO_REG_TYPES_SYS
  #define RegType(TYPE)class Sys_##TYPE{public:\
    static int GetTypeID(int*p=NULL){static int UID=-1;return p?UID=*p:UID;}\
    public:static QapType *GetRTTI(QapRTTI &RTTI){\
    QapTypeSys *Info=NULL;\
    if(!RTTI.Register<QapTypeSys>(&Info,SToS(#TYPE),&GetTypeID)){\
      Info->SystemID=0;\
    }\
    return Info;\
  }};
  DEF_PRO_REG_TYPES_SYS(RegType)
  #undef RegType
  #undef DEF_PRO_REG_TYPES_SYS
#endif //DEF_PRO_REG_TYPES_SYS//
//`Регистрируем структурные типы
#ifdef DEF_PRO_REG_TYPES_STRUCT
  #define RegType(TYPE)class Sys_##TYPE{public:static QapTypeStruct*GetRTTI(QapRTTI &RTTI){\
    return TYPE::GetRTTI(RTTI);\
  }};;
  DEF_PRO_REG_TYPES_STRUCT(RegType);
  #undef RegType
  #undef DEF_PRO_REG_TYPES_STRUCT
#endif //DEF_PRO_REG_TYPES_STRUCT//
//`Регистрируем векторы типы
#ifdef DEF_PRO_REG_TYPES_VECTOR
  #define RegType(TYPE)class Sys_vector_##TYPE{public:\
    static int GetTypeID(int*p=NULL){static int UID=-1;return p?UID=*p:UID;}\
    inline static int GetCount(void*p){vector<TYPE>&v=*(vector<TYPE>*)p;return v.size();}\
    inline static void SetCount(void*p,int c){vector<TYPE>&v=*(vector<TYPE>*)p;v.resize(c);}\
    inline static void*GetItem(void*p,int i){vector<TYPE>&v=*(vector<TYPE>*)p;return &v[i];}\
    template<class QAP_RTTI>static QapType *GetRTTI(QAP_RTTI &RTTI){\
    string Name="vector<"#TYPE">";QapTypeVector *Info=NULL;\
    if(!RTTI.Register<QapTypeVector>(&Info,Name,&GetTypeID)){\
      Info->SubType=Sys_##TYPE::GetRTTI(RTTI);\
      Info->GetCount=&GetCount;\
      Info->SetCount=&SetCount;\
      Info->GetItem=&GetItem;\
    }\
    return Info;\
  }};;
  DEF_PRO_REG_TYPES_VECTOR(RegType);
  #undef RegType
  #undef DEF_PRO_REG_TYPES_VECTOR
#endif //DEF_PRO_REG_TYPES_VECTOR//
//`Регистрируем POD типы
#ifdef DEF_PRO_REG_TYPES_POD
  #define RegType(TYPE,FUNC,CODE)class Sys_##TYPE{public:\
    static int GetTypeID(int*p=NULL){static int UID=-1;return p?UID=*p:UID;}\
    inline static void ToStr(string&s,void*pValue){s+=FUNC(*(TYPE*)pValue);}\
    inline static void ToCode(string&s,void*pValue){s+=CODE(*(TYPE*)pValue);}\
    public:static QapType *GetRTTI(QapRTTI &RTTI){\
    QapTypePOD *Info=NULL;\
    if(!RTTI.Register<QapTypePOD>(&Info,SToS(#TYPE),&GetTypeID)){\
      Info->Size=sizeof(TYPE);\
      Info->DynToStr=&ToStr;\
      Info->DynToCode=&ToCode;\
    }\
    return Info;\
  }};;
  DEF_PRO_REG_TYPES_POD(RegType);
  #undef RegType
  #undef DEF_PRO_REG_TYPES_POD
#endif //DEF_PRO_REG_TYPES_POD//
//`Регистрируем сущьностей типы
#ifdef DEF_PRO_REG_TYPES_ENTITY
  #define RegType(TYPE)class Sys_##TYPE{public:static QapType *GetRTTI(QapRTTI &RTTI){\
    return TYPE::GetRTTI(RTTI);\
  }};;
  DEF_PRO_REG_TYPES_ENTITY(RegType);
  #undef RegType
  //`Регистрируем смартпойнтры типы
  #define DEF_PRO_REG_TYPES_QAPPTR(F)DEF_PRO_REG_TYPES_ENTITY(F)
  #ifdef DEF_PRO_REG_TYPES_QAPPTR
    #define RegType(TYPE)class Sys_QapPtr_##TYPE{public:\
      static int GetTypeID(int*p=NULL){static int UID=-1;return p?UID=*p:UID;}\
      template<class QAP_RTTI>static QapType *GetRTTI(QAP_RTTI &RTTI){\
      string Name=#TYPE##"*";QapTypePtr*Info=NULL;\
      if(!RTTI.Register<QapTypePtr>(&Info,Name,&GetTypeID)){\
        Info->SubType=Sys_##TYPE::GetRTTI(RTTI);\
        Info->DoGet=&QapPtr<TYPE>::GetSID;\
        Info->DoSet=&QapPtr<TYPE>::SetSID;\
        Info->DoCap=&QapPtr<TYPE>::GetCaption;\
        Info->DoLiv=&QapPtr<TYPE>::IsValid;\
      }\
      return Info;\
    }};
    DEF_PRO_REG_TYPES_QAPPTR(RegType);
    #undef RegType
    #undef DEF_PRO_REG_TYPES_QAPPTR
  #endif //DEF_PRO_REG_TYPES_QAPPTR//
  #define DEF_PRO_REG_TYPES_QAPREF(F)DEF_PRO_REG_TYPES_ENTITY(F)
  #ifdef DEF_PRO_REG_TYPES_QAPREF
    #define RegType(TYPE)class Sys_QapRef_##TYPE{public:\
      static int GetTypeID(int*p=NULL){static int UID=-1;return p?UID=*p:UID;}\
      template<class QAP_RTTI>static QapType*GetRTTI(QAP_RTTI &RTTI){\
      string Name=#TYPE##"*";QapTypeRef*Info=NULL;\
      if(!RTTI.Register<QapTypeRef>(&Info,Name,&GetTypeID)){\
        Info->SubType=Sys_##TYPE::GetRTTI(RTTI);\
        Info->DoGet=&QapRef<TYPE>::GetType;\
      }\
      return Info;\
    }};
    DEF_PRO_REG_TYPES_QAPREF(RegType);
    #undef RegType
    #undef DEF_PRO_REG_TYPES_QAPREF
  #endif //DEF_PRO_REG_TYPES_SMTPTR//
  #undef DEF_PRO_REG_TYPES_ENTITY
#endif //DEF_PRO_REG_TYPES_ENTITY//
//`Регистрируем строковые типы
#ifdef DEF_PRO_REG_TYPES_STRING
  #define RegType(TYPE)class Sys_##TYPE{public:\
    static int GetTypeID(int*p=NULL){static int UID=-1;return p?UID=*p:UID;}\
    public:static QapType *GetRTTI(QapRTTI &RTTI){\
    QapTypeString *Info=NULL;\
    if(!RTTI.Register<QapTypeString>(&Info,SToS(#TYPE),&GetTypeID)){\
      Info->SystemID=0;\
    }\
    return Info;\
  }};
  DEF_PRO_REG_TYPES_STRING(RegType)
  #undef RegType
  #undef DEF_PRO_REG_TYPES_STRING
#endif //DEF_PRO_REG_TYPES_STRING//
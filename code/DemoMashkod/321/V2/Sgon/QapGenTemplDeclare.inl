#ifdef FULLCLASSNAME
  #define DEF_PRO_COMMENT0(A,B)A##B
  #define DEF_PRO_COMMENT(A,B)DEF_PRO_COMMENT0(A,B)
  class FULLCLASSNAME():public DeclareType{
  public:
  /*#*/define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FULLCLASSNAME())PARENT(DeclareType)
  /*#*/define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,TWeakPtr<DeclareType>,ElementType,DEF,$,$)\
  ADDEND()
  DEF_PRO_COMMENT(/,/=====+>>>>>FULLCLASSNAME())
  /*#*/include "QapGenStruct.inl"
  DEF_PRO_COMMENT(/,/<<<<<+=====FULLCLASSNAME())
  public:
  };
  #undef DEF_PRO_COMMENT0
  //`#undef DEF_PRO_COMMENT1
  //`#undef DEF_PRO_COMMENT2
  #undef DEF_PRO_COMMENT
  #undef FULLCLASSNAME
#endif// FULLCLASSNAME
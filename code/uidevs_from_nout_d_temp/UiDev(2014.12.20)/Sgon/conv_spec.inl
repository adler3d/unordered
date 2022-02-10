#ifdef DEF_CONV_SPEC
  #define DEF_PRO_GET_DEST(A)A
  #define DEF_PRO_GET_SOURCE(A)
  struct dest_conv{
    typedef dest_type in_type;
    typedef DEF_CONV_SPEC(DEF_PRO_GET_DEST,DEF_PRO_GET_SOURCE) out_type;
    static out_type*get(in_type*pValue){return (out_type*)(void*)pValue;}
  };
  #undef DEF_PRO_GET_DEST
  #undef DEF_PRO_GET_SOURCE
  #define DEF_PRO_GET_DEST(A)
  #define DEF_PRO_GET_SOURCE(A)A
  struct source_conv{
    typedef source_type in_type;
    typedef DEF_CONV_SPEC(DEF_PRO_GET_DEST,DEF_PRO_GET_SOURCE) out_type;
    static out_type*get(in_type*pValue){return (out_type*)(void*)pValue;}
  };
  static dest_conv::out_type*get(dest_conv::in_type*pValue){return dest_conv::get(pValue);}
  static source_conv::out_type*get(source_conv::in_type*pValue){return source_conv::get(pValue);}
  #undef DEF_PRO_GET_DEST
  #undef DEF_PRO_GET_SOURCE
  #undef DEF_CONV_SPEC
#endif //DEF_CONV_SPEC
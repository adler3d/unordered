#ifndef QAP_SHOW_FLOATS
  static_assert(false,"no way");
  //usage:
  //#define QAP_SHOW_FLOATS(F)F(c.x)F(c.y)F(cx)F(cy)
  //#include "qap_show_floats.inl"
#else
  auto msg=string(
    #define MSG(TEXT)string(TEXT)+"\n"+
    #define F(VAR)string(#VAR " = "+std::to_string(VAR)+"\n")+
    QAP_SHOW_FLOATS(MSG,F)
    #undef F
    #undef MSG
    ""
  );
  QapDebugMsg(msg);
  #undef QAP_SHOW_FLOATS
#endif //QAP_SHOW_FLOATS
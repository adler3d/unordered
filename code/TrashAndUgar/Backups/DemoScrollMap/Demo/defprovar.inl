#define ADD(TYPE,NAME,VALUE)TYPE NAME;
DEF_PRO_VARIABLE(ADD)
#undef ADD
//===
void DoReset()
{
  t_$ $;
  #define ADD(TYPE,NAME,VALUE)t_$::set(this->NAME,VALUE);
  DEF_PRO_VARIABLE(ADD)
  #undef ADD
}
#ifdef DEF_PRO_CLASSNAME
  void operator=(DEF_PRO_CLASSNAME()&&ref){oper_set(std::move(ref));}
  DEF_PRO_CLASSNAME()(DEF_PRO_CLASSNAME()&&ref){DoReset();oper_set(std::move(ref));}
  void oper_set(DEF_PRO_CLASSNAME()&&ref)
  {
    #define F(TYPE,NAME,VALUE)this->NAME=std::move(ref.NAME);
    DEF_PRO_VARIABLE(F);
    #undef F
  }
  DEF_PRO_CLASSNAME()(){DoReset();}
  #undef DEF_PRO_CLASSNAME
#endif //DEF_PRO_CLASSNAME
#undef DEF_PRO_VARIABLE
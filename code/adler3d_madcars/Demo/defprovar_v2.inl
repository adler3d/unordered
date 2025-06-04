#define ADD(TYPE,NAME,VALUE)TYPE NAME;
DEF_PRO_VARIABLE(ADD)
#undef ADD
//===
void load(Value&d)
{
  #define F(TYPE,NAME,VALUE)t_jsonobj2cpp::use(d,#NAME,this->NAME);
  DEF_PRO_VARIABLE(F)
  #undef F
}
//===
#undef DEF_PRO_VARIABLE
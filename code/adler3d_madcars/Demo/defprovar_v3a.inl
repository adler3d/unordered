#define DEF_ALGO_LOAD_3A(TYPE,NAME,VALUE)this->NAME=ref.NAME;
#define DEF_ALGO_SAVE_3A(TYPE,NAME,VALUE)ref.NAME=this->NAME;
#define DEF_ALGO_DIFF_3A(TYPE,NAME,VALUE)if(bool(VALUE))sqrdiff_to_result+=VALUE*sqrdiff(ref.NAME,this->NAME);
#define DEF_ALGO_LOAD_3G(TYPE,NAME,VALUE)this->NAME.load_from(ref.NAME);
#define DEF_ALGO_SAVE_3G(TYPE,NAME,VALUE)this->NAME.save_to(ref.NAME);
#define DEF_ALGO_DIFF_3G(TYPE,NAME,VALUE)if(bool(VALUE))sqrdiff_to_result+=VALUE*sqrdiff(ref.NAME,this->NAME);
#ifdef DEF_PRO_3G
  #define DEF_ALGO_LOAD(TYPE,NAME,VALUE)DEF_ALGO_LOAD_3G(TYPE,NAME,VALUE)
  #define DEF_ALGO_SAVE(TYPE,NAME,VALUE)DEF_ALGO_SAVE_3G(TYPE,NAME,VALUE)
  #define DEF_ALGO_DIFF(TYPE,NAME,VALUE)DEF_ALGO_DIFF_3G(TYPE,NAME,VALUE)
#else
  #define DEF_ALGO_LOAD(TYPE,NAME,VALUE)DEF_ALGO_LOAD_3A(TYPE,NAME,VALUE)
  #define DEF_ALGO_SAVE(TYPE,NAME,VALUE)DEF_ALGO_SAVE_3A(TYPE,NAME,VALUE)
  #define DEF_ALGO_DIFF(TYPE,NAME,VALUE)DEF_ALGO_DIFF_3A(TYPE,NAME,VALUE)
#endif
//===
#define ADD(TYPE,NAME,VALUE)TYPE NAME;
DEF_PRO_VARIABLE(ADD)
#undef ADD
//===
void load_from(OtherSide&ref){
  DEF_PRO_VARIABLE(DEF_ALGO_LOAD)
}
void save_to(OtherSide&ref){
  DEF_PRO_VARIABLE(DEF_ALGO_SAVE)
}
#ifdef DEF_PRO_WITHOUT_DIFF
  #undef DEF_PRO_WITHOUT_DIFF
#else
  real sqrdiff_to(const SelfClass&ref)const{
    real sqrdiff_to_result=0;
    DEF_PRO_VARIABLE(DEF_ALGO_DIFF)
    return sqrdiff_to_result;
  }
#endif
void load_from(OtherSide*ptr){if(ptr)load_from(*ptr);}
void save_to(OtherSide*ptr){if(ptr)save_to(*ptr);}
//===
#undef DEF_PRO_VARIABLE
//===

#ifdef DEF_PRO_3G
  #undef DEF_PRO_3G
#endif //DEF_PRO_3G

#ifdef DEF_PRO_3C
  static_assert(false,"no impl");
  #undef DEF_PRO_3C
#endif //DEF_PRO_3C

#undef DEF_ALGO_DIFF
#undef DEF_ALGO_SAVE
#undef DEF_ALGO_LOAD

#undef DEF_ALGO_DIFF_3G
#undef DEF_ALGO_SAVE_3G
#undef DEF_ALGO_LOAD_3G
#undef DEF_ALGO_DIFF_3A
#undef DEF_ALGO_SAVE_3A
#undef DEF_ALGO_LOAD_3A
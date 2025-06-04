//#define DEF_UNIT_NAME cpDampedRotarySpring
#ifndef DEF_INSIDE_FIX
  #define DEF_INSIDE_FIX
  #define DEF_COMBINE0(A,B)A##_##B
  #define DEF_COMBINE(A,B)DEF_COMBINE0(A,B)

  #define preStep DEF_COMBINE(preStep,DEF_UNIT_NAME)
  #define applyCachedImpulse DEF_COMBINE(applyCachedImpulse,DEF_UNIT_NAME)
  #define applyImpulse DEF_COMBINE(applyImpulse,DEF_UNIT_NAME)
  #define getImpulse DEF_COMBINE(getImpulse,DEF_UNIT_NAME)

  #define recycleBin DEF_COMBINE(recycleBin,DEF_UNIT_NAME)
  #define eachContext DEF_COMBINE(eachContext,DEF_UNIT_NAME)
  #define Klass DEF_COMBINE(Klass,DEF_UNIT_NAME)
#else
  #undef Klass
  #undef eachContext
  #undef recycleBin

  #undef getImpulse
  #undef applyImpulse
  #undef applyCachedImpulse
  #undef preStep

  #undef DEF_INSIDE_FIX
  #undef DEF_COMBINE1
  #undef DEF_COMBINE
  #undef DEF_UNIT_NAME
#endif
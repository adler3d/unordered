#ifdef DEF_BUILD_MACRO
  #include "../Macro/preproc.h"
#else
//=====>>>>>preproc

#define FULLCLASSNAME()DeclareTypeSelfPtr
//=====+>>>>>DeclareTypeSelfPtr
#include "QapGenTemplDeclare.inl"
//<<<<<+=====DeclareTypeSelfPtr

#define FULLCLASSNAME()DeclareTypeAutoPtr
//=====+>>>>>DeclareTypeAutoPtr
#include "QapGenTemplDeclare.inl"
//<<<<<+=====DeclareTypeAutoPtr

#define FULLCLASSNAME()DeclareTypeWeakPtr
//=====+>>>>>DeclareTypeWeakPtr
#include "QapGenTemplDeclare.inl"
//<<<<<+=====DeclareTypeWeakPtr

#define FULLCLASSNAME()DeclareTypeHardPtr
//=====+>>>>>DeclareTypeHardPtr
#include "QapGenTemplDeclare.inl"
//<<<<<+=====DeclareTypeHardPtr

#define FULLCLASSNAME()DeclareTypeVector
//=====+>>>>>DeclareTypeVector
#include "QapGenTemplDeclare.inl"
//<<<<<+=====DeclareTypeVector


//<<<<<=====preproc
#endif //DEF_BUILD_MICRO//
#if(0)
#define DEF_PRO_HEAD
#include "StdAfx.h"
#undef DEF_PRO_HEAD
#endif
#define DEF_PRO_FULL

//-----
#define ThisCompileUnit ThisCompileUnit$TD3DGameBox
#define ThisCompileUnitInstance ThisCompileUnitInstance$TD3DGameBox
#include "TD3DGameBox.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

#define ThisCompileUnit ThisCompileUnit$caption_finder
#define ThisCompileUnitInstance ThisCompileUnitInstance$caption_finder
#include "caption_finder.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

#define ThisCompileUnit ThisCompileUnit$last_hope_loader
#define ThisCompileUnitInstance ThisCompileUnitInstance$last_hope_loader
#include "last_hope_loader.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

#define ThisCompileUnit ThisCompileUnit$PageWithHiddenBooks
#define ThisCompileUnitInstance ThisCompileUnitInstance$PageWithHiddenBooks
#include "PageWithHiddenBooks.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

#define ThisCompileUnit ThisCompileUnit$PageWithPerf
#define ThisCompileUnitInstance ThisCompileUnitInstance$PageWithPerf
#include "PageWithPerf.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

#define ThisCompileUnit ThisCompileUnit$QapPublicUberXImpl
#define ThisCompileUnitInstance ThisCompileUnitInstance$QapPublicUberXImpl
#include "QapPublicUberXImpl.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

#define ThisCompileUnit ThisCompileUnit$MsgBox
#define ThisCompileUnitInstance ThisCompileUnitInstance$MsgBox
#include "MsgBox.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

//-----
#undef DEF_PRO_FULL
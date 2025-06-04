#ifdef NDEBUG
  #define QAP_CHIPMUNK_KEEP_NDEBUG
#else
  #define NDEBUG
#endif

#include "chipmunk/chipmunk.h"

extern "C" {
#include "cfix_undef_all_c.inl"
#include "cfix_undef_all_h.inl"
/*
#include "chipmunk/chipmunk_private.h"

#include "chipmunk/chipmunk.c"
#include "chipmunk/cpArbiter.c"
#include "chipmunk/cpArray.c"
#include "chipmunk/cpBBTree.c"
#include "chipmunk/cpBody.c"
#include "chipmunk/cpCollision.c"
#include "chipmunk/cpConstraint.c"
#include "chipmunk/cpDampedRotarySpring.c"
#include "chipmunk/cpDampedSpring.c"
#include "chipmunk/cpGearJoint.c"
#include "chipmunk/cpGrooveJoint.c"
#include "chipmunk/cpHashSet.c"
//#include "chipmunk/cpHastySpace.c"
#include "chipmunk/cpMarch.c"
#include "chipmunk/cpPinJoint.c"
#include "chipmunk/cpPivotJoint.c"
#include "chipmunk/cpPolyline.c"
#include "chipmunk/cpPolyShape.c"
#include "chipmunk/cpRatchetJoint.c"
#include "chipmunk/cpRobust.c"
#include "chipmunk/cpRotaryLimitJoint.c"
#include "chipmunk/cpShape.c"
#include "chipmunk/cpSimpleMotor.c"
#include "chipmunk/cpSlideJoint.c"
#include "chipmunk/cpSpace.c"
#include "chipmunk/cpSpaceComponent.c"
#include "chipmunk/cpSpaceDebug.c"
#include "chipmunk/cpSpaceHash.c"
#include "chipmunk/cpSpaceQuery.c"
#include "chipmunk/cpSpaceStep.c"
#include "chipmunk/cpSpatialIndex.c"
#include "chipmunk/cpSweep1D.c"
*/
}

#ifndef QAP_CHIPMUNK_KEEP_NDEBUG
  #undef NDEBUG
#else
  #undef QAP_CHIPMUNK_KEEP_NDEBUG
#endif
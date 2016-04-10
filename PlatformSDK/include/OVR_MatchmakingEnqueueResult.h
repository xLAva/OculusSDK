// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_MATCHMAKINGENQUEUERESULT_H
#define OVR_MATCHMAKINGENQUEUERESULT_H

#include "OVR_Platform_Defs.h"
#include <stddef.h>

typedef struct ovrMatchmakingEnqueueResult *ovrMatchmakingEnqueueResultHandle;

OVRP_PUBLIC_FUNCTION(unsigned int) ovr_MatchmakingEnqueueResult_GetAverageWait(const ovrMatchmakingEnqueueResultHandle obj);
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_MatchmakingEnqueueResult_GetMaxExpectedWait(const ovrMatchmakingEnqueueResultHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_MatchmakingEnqueueResult_GetPool(const ovrMatchmakingEnqueueResultHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_MatchmakingEnqueueResult_GetRequestHash(const ovrMatchmakingEnqueueResultHandle obj);

#endif

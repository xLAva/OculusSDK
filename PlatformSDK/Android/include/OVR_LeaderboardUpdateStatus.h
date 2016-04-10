// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_LEADERBOARDUPDATESTATUS_H
#define OVR_LEADERBOARDUPDATESTATUS_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ovrLeaderboardUpdateStatus *ovrLeaderboardUpdateStatusHandle;

OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardUpdateStatus_GetDidUpdate(const ovrLeaderboardUpdateStatusHandle obj);

#endif

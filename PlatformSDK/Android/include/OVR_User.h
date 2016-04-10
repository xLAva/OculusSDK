// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_USER_H
#define OVR_USER_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>

typedef struct ovrUser *ovrUserHandle;

OVRP_PUBLIC_FUNCTION(ovrID) ovr_User_GetID(const ovrUserHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetImageUrl(const ovrUserHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetInviteToken(const ovrUserHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetOculusID(const ovrUserHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresence(const ovrUserHandle obj);

#endif

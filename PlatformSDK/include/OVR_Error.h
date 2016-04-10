// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_ERROR_H
#define OVR_ERROR_H

#include "OVR_Platform_Defs.h"
#include <stddef.h>

typedef struct ovrError *ovrErrorHandle;

OVRP_PUBLIC_FUNCTION(int) ovr_Error_GetCode(const ovrErrorHandle obj);
OVRP_PUBLIC_FUNCTION(int) ovr_Error_GetHttpCode(const ovrErrorHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_Error_GetMessage(const ovrErrorHandle obj);

#endif

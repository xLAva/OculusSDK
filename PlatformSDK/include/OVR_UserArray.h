// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_USERARRAY_H
#define OVR_USERARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_User.h"
#include <stddef.h>

typedef struct ovrUserArray *ovrUserArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_UserArray_GetElement(const ovrUserArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(size_t) ovr_UserArray_GetSize(const ovrUserArrayHandle obj);

#endif

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_PRODUCTARRAY_H
#define OVR_PRODUCTARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Product.h"
#include <stddef.h>

typedef struct ovrProductArray *ovrProductArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrProductHandle) ovr_ProductArray_GetElement(const ovrProductArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(size_t) ovr_ProductArray_GetSize(const ovrProductArrayHandle obj);

#endif

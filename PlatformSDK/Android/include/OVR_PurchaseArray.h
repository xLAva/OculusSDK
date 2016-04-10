// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_PURCHASEARRAY_H
#define OVR_PURCHASEARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Purchase.h"
#include <stddef.h>

typedef struct ovrPurchaseArray *ovrPurchaseArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrPurchaseHandle) ovr_PurchaseArray_GetElement(const ovrPurchaseArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(size_t) ovr_PurchaseArray_GetSize(const ovrPurchaseArrayHandle obj);

#endif

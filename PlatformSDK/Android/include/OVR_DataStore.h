// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_DATASTORE_H
#define OVR_DATASTORE_H

#include "OVR_Platform_Defs.h"
#include <stddef.h>

typedef struct ovrDataStore *ovrDataStoreHandle;

OVRP_PUBLIC_FUNCTION(unsigned int) ovr_DataStore_Contains(const ovrDataStoreHandle obj, const char *key);
OVRP_PUBLIC_FUNCTION(const char *) ovr_DataStore_GetValue(const ovrDataStoreHandle obj, const char *key);

#endif

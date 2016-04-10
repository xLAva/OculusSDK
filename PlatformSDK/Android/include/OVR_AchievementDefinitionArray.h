// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_ACHIEVEMENTDEFINITIONARRAY_H
#define OVR_ACHIEVEMENTDEFINITIONARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_AchievementDefinition.h"
#include <stddef.h>

typedef struct ovrAchievementDefinitionArray *ovrAchievementDefinitionArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrAchievementDefinitionHandle) ovr_AchievementDefinitionArray_GetElement(const ovrAchievementDefinitionArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(size_t) ovr_AchievementDefinitionArray_GetSize(const ovrAchievementDefinitionArrayHandle obj);

#endif

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_USERPROOF_H
#define OVR_USERPROOF_H

#include "OVR_Platform_Defs.h"
#include <stddef.h>

typedef struct ovrUserProof *ovrUserProofHandle;

OVRP_PUBLIC_FUNCTION(const char *) ovr_UserProof_GetNonce(const ovrUserProofHandle obj);

#endif

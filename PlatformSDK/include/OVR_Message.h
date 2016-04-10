// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/models.yaml

#ifndef OVR_MESSAGE_H
#define OVR_MESSAGE_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include "OVR_MessageType.h"
#include "OVR_Error.h"
#include "OVR_UserProof.h"
#include "OVR_Purchase.h"
#include "OVR_Room.h"
#include "OVR_RoomArray.h"
#include "OVR_User.h"
#include "OVR_UserArray.h"
#include "OVR_PurchaseArray.h"
#include "OVR_ProductArray.h"
#include "OVR_AchievementDefinitionArray.h"
#include "OVR_AchievementProgressArray.h"
#include "OVR_NetworkingPeer.h"
#include "OVR_LeaderboardEntryArray.h"
#include "OVR_LeaderboardUpdateStatus.h"
#include "OVR_MatchmakingEnqueueResult.h"
#include "OVR_MatchmakingEnqueueResultAndRoom.h"
#include "OVR_MatchmakingRoomArray.h"
#include "OVR_PingResult.h"
#include <stddef.h>

typedef struct ovrMessage *ovrMessageHandle;

OVRP_PUBLIC_FUNCTION(ovrAchievementDefinitionArrayHandle) ovr_Message_GetAchievementDefinitionArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrAchievementProgressArrayHandle) ovr_Message_GetAchievementProgressArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrErrorHandle) ovr_Message_GetError(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrLeaderboardEntryArrayHandle) ovr_Message_GetLeaderboardEntryArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrLeaderboardUpdateStatusHandle) ovr_Message_GetLeaderboardUpdateStatus(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrMatchmakingEnqueueResultHandle) ovr_Message_GetMatchmakingEnqueueResult(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrMatchmakingEnqueueResultAndRoomHandle) ovr_Message_GetMatchmakingEnqueueResultAndRoom(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrMatchmakingRoomArrayHandle) ovr_Message_GetMatchmakingRoomArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrNetworkingPeerHandle) ovr_Message_GetNetworkingPeer(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrPingResultHandle) ovr_Message_GetPingResult(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrProductArrayHandle) ovr_Message_GetProductArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrPurchaseHandle) ovr_Message_GetPurchase(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrPurchaseArrayHandle) ovr_Message_GetPurchaseArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Message_GetRequestID(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrRoomHandle) ovr_Message_GetRoom(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrRoomArrayHandle) ovr_Message_GetRoomArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_Message_GetString(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrMessageType) ovr_Message_GetType(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_Message_GetUser(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Message_GetUserArray(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(ovrUserProofHandle) ovr_Message_GetUserProof(const ovrMessageHandle obj);
OVRP_PUBLIC_FUNCTION(bool) ovr_Message_IsError(const ovrMessageHandle obj);

#endif

#ifndef OVR_ROOMJOINABILITY_H
#define OVR_ROOMJOINABILITY_H

#ifdef __cplusplus
extern "C" {
#endif

//Keep this in sync with Joinability.cs in the Unity SDK!!!!!
typedef enum {
  // OVR_ENUM_START
  ovrRoom_JoinabilityUnknown,
  ovrRoom_JoinabilityAreIn,
  ovrRoom_JoinabilityAreKicked,
  ovrRoom_JoinabilityCanJoin,
  ovrRoom_JoinabilityIsFull,
  ovrRoom_JoinabilityNoViewer,
  ovrRoom_JoinabilityPolicyPrevents
  // OVR_ENUM_END
} ovrRoomJoinability;

#ifdef __cplusplus
}
#endif

#endif

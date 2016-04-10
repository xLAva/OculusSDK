#ifndef OVR_ROOMJOINPOLICY_H
#define OVR_ROOMJOINPOLICY_H

#ifdef __cplusplus
extern "C" {
#endif

//Keep this in sync with JoinPolicy.cs in the Unity SDK!!!!!
typedef enum {
  // OVR_ENUM_START
  ovrRoom_JoinPolicyNone,
  ovrRoom_JoinPolicyEveryone,
  ovrRoom_JoinPolicyFriendsOfMembers,
  ovrRoom_JoinPolicyFriendsOfOwner,
  ovrRoom_JoinPolicyInvitedUsers,
  // OVR_ENUM_END
} ovrRoomJoinPolicy;

#ifdef __cplusplus
}
#endif

#endif

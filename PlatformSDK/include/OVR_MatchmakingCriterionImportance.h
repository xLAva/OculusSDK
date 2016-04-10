#ifndef OVR_MATCHMAKINGCRITERIONIMPORTANCE_H
#define OVR_MATCHMAKINGCRITERIONIMPORTANCE_H

#ifdef __cplusplus
extern "C" {
#endif

//Keep this in sync with MatchmakingCriterionImportance.cs in the Unity SDK!!!!!
typedef enum {
  // OVR_ENUM_START
  ovrMatchmaking_ImportanceRequired,
  ovrMatchmaking_ImportanceHigh,
  ovrMatchmaking_ImportanceMedium,
  ovrMatchmaking_ImportanceLow,
  // OVR_ENUM_END
} ovrMatchmakingCriterionImportance;

#ifdef __cplusplus
}
#endif

#endif

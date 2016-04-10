#ifndef OVR_TYPES_H
#define OVR_TYPES_H

#include "OVR_KeyValuePairType.h"
#include "OVR_MatchmakingCriterionImportance.h"

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

/// Represents a single state change in the platform such as the
/// response to a request, or some new information from the backend.
typedef uint64_t ovrRequest;

typedef struct {
  const char *key;
  ovrKeyValuePairType valueType;

  const char *stringValue;
  int intValue;
  double doubleValue;

} ovrKeyValuePair;

typedef struct {
  const char *key;
  ovrMatchmakingCriterionImportance importance;

  ovrKeyValuePair *paramterArray;
  unsigned int paramterArrayCount;

} ovrMatchmakingCriterion;


typedef struct {
  ovrKeyValuePair *customQueryDataArray;
  unsigned int customQueryDataArrayCount;

  ovrMatchmakingCriterion *customQueryCriterionArray;
  unsigned int customQueryCriterionArrayCount;
} ovrMatchmakingCustomQueryData;


/// A unique identifier for some entity in the system (user, room, etc).
///
typedef uint64_t ovrID;

#ifdef __cplusplus
}
#endif

#endif

#ifndef OVR_KEYVALUEPAIRTYPE_H
#define OVR_KEYVALUEPAIRTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

//Keep this in sync with .cs in the Unity SDK!!!!!
typedef enum {
  // OVR_ENUM_START
  ovrKeyValuePairType_String,
  ovrKeyValuePairType_Int,
  ovrKeyValuePairType_Double,
  // OVR_ENUM_END
} ovrKeyValuePairType;

#ifdef __cplusplus
}
#endif

#endif

#ifndef OVR_ROOMTYPE_H
#define OVR_ROOMTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

//Keep this in sync with RoomType.cs in the Unity SDK!!!!!
typedef enum {
  ovrRoom_TypeUnknown,
  ovrRoom_TypeMatchmaking,
  ovrRoom_TypeModerated,
  ovrRoom_TypePrivate,
  ovrRoom_TypeSolo,
} ovrRoomType;

#ifdef __cplusplus
}
#endif

#endif

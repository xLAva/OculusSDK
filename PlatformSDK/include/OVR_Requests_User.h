// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/requests.yaml

#ifndef OVR_REQUESTS_USER_H
#define OVR_REQUESTS_USER_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// Overview:
/// User objects represent people in the real world; their hopes, their dreams, and their current presence information.
///
/// Verifying Identify:
/// You can pass the result of ovr_UserProof_Generate() and ovr_GetLoggedInUserID()
/// to your your backend. Your server can use our api to verify identity.
/// 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
///
/// NOTE: the nonce is only good for one check and then it's invalidated.
///
/// App-Scoped IDs:
/// To protect user privacy, users have a different ovrID across different applications. If you are caching them,
/// make sure that you're also restricting them per application.

/// Retrieve the user with the given ID. This may fail if the ID is invalid
/// or the user is blocked.
/// NOTE: Users will have a unique ID per application.
///
/// \param userID User ID retrieved with this application.
///
/// A message with type ::ovrMessage_User_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrUserHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUser().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_Get(ovrID userID);

/// Return an access token for this user, suitable for making REST calls against graph.oculus.com.
///
/// A message with type ::ovrMessage_User_GetAccessToken will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ovr_Message_GetString().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetAccessToken();

/// Retrieve the currently signed in user.
///
/// NOTE: This may not return the user's presence as it should always be
/// 'online' in your application.
///
/// NOTE: Users will have a unique ID per application
///
/// A message with type ::ovrMessage_User_GetLoggedInUser will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrUserHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUser().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUser();

/// Retrieve a list of the logged in user's friends.
///
/// A message with type ::ovrMessage_User_GetLoggedInUserFriends will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUserFriends();

/// Part of the scheme to confirm the identity of a particular user in your backend.
/// You can pass the result of ovr_UserProof_Generate() and ovr_GetLoggedInUserID()
/// to your your backend. Your server can use our api to verify identity.
/// 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
///
/// NOTE: the nonce is only good for one check and then it's invalidated.
///
/// A message with type ::ovrMessage_User_GetUserProof will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrUserProofHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserProof().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetUserProof();

#endif

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/requests.yaml

#ifndef OVR_REQUESTS_ENTITLEMENT_H
#define OVR_REQUESTS_ENTITLEMENT_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// # Entitlements
///
/// When a user has an entitlement to an application, it means they have purchased
/// and downloaded the application via the Oculus store, or are otherwise entitled
/// to run the application. The Platform SDK entitlement check system allows you to
/// verify at run-time that the currently user attempting to run your application
/// is in fact entitled. This check works even if the user is offline.
///
/// It's critical to note that this entitlement check does not happen automatically,
/// and if it fails it does not automatically exit the application or have any other
/// side effect. It's up to you to call the entitlement check and handle failure
/// however you see fit.
///
/// To make an entitlement check use ovr_Entitlement_GetIsViewerEntitled(). This is
/// an asynchronous call, so you may wish to avoid making other platform calls until
/// you handle the response, but this is not strictly required.
///
/// ## Development:
///
/// During development the entitlement check can return false unless a number of
/// additional steps are taken. Most of these steps will require you to set things
/// up using the developer website at https://dashboard.oculus.com.
///
/// Each application must be set up:
///
///  1. You must create an application at https://dashboard.oculus.com and obtain
///       the application ID, which you provide to the Platform SDK.
///  2. You must upload a binary package for your application on the developer
///       website at https://dashboard.oculus.com/application/[YOUR_APP_ID]/build.
///       During development this package does not need to function in any way, but
///       it does need to exist.
///
/// Each developer that needs to pass the application's entitlement check must:
///
///  1. Have an entitlement to the application by being added as a developer for the
///       application, which can be set up on the developer website at
///       https://dashboard.oculus.com/application/[YOUR_APP_ID]/developers.
///  2. Be able to see a binary package for the application by being in a release
///       channel that has a binary package, which can be set up on the developer
///       website at https://dashboard.oculus.com/application/[YOUR_APP_ID]/build.
///  3. (Windows Only) Use the Oculus store to download the application. The
///       developer does not need to run the downloaded copy of the application,
///       which is why the package does not need to be functional.
///
/// Once the above steps are completed, the entitlement check should succeed even if
/// running a local build of your application.

/// Get whether or not the current user is entitled to the current app.
///
/// A message with type ::ovrMessage_Entitlement_GetIsViewerEntitled will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occured, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Entitlement_GetIsViewerEntitled();

#endif

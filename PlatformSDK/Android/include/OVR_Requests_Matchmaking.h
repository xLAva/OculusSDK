// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!
// To make additional changes, modify LibOVRPlatform/codegen/requests.yaml

#ifndef OVR_REQUESTS_MATCHMAKING_H
#define OVR_REQUESTS_MATCHMAKING_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include <stdbool.h>

/// \file
/// # Modes
///
/// There are three modes for matchmaking, each of which behaves very
/// differently.  However, the modes do share some of the same functions.
///
/// ## BOUT Mode
///
/// All users are in one pool, rooms are created for them once the match has
/// been made.
///
/// ### Main flow
///
/// 1. Call ovr_Matchmaking_Enqueue.
/// 2. Handle ovrMessage_Notification_Matchmaking_MatchFound notification
/// 3. Call ovr_Room_Join
/// 4. (for skill matching only) ovr_Matchmaking_StartMatch
/// 5. (for skill matching only) ovr_Matchmaking_ReportResultInsecure
///
/// ## ROOM Mode
///
/// There are two matchmaking queues.  Users are either hosting rooms or looking
/// for rooms hosted by someone else.
/// The host's room is created before the host is put into the matchmaking queue.
/// Room mode is not as good for matching as Bout mode because, as users are divided into
/// two queues, each person has fewer options.  Prefer Room mode when rooms themselves
/// have notable characteristics, such as when they outlive individual matches.
///
/// ### Main flow
///
/// For parties joining a room: as BOUT
/// For hosting a room:
///
/// 1. EITHER ovr_Matchmaking_CreateAndEnqueueRoom
///    OR ovr_Matchmaking_CreateRoom (handle response) and then ovr_Matchmaking_EnqueueRoom
/// 2. Handle ovrMessage_Notification_Matchmaking_MatchFound notification
/// 3. (for skill matching only) ovr_Matchmaking_StartMatch
/// 4. (for skill matching only) ovr_Matchmaking_ReportResultInsecure
///
/// ## BROWSE Mode
///
/// As in Room mode, there is a queue of rooms looking for users to join them.  Users are not
/// enqueued; instead, they "search" for rooms that are acceptable matches.
/// After some filtering on the server side, just as with the other modes, a list of rooms is returned,
/// and the client chooses from among them.
/// Because the central matchmaking server manages less of this mode, there are some disadvantages
/// relative to BOUT and ROOM mode: there are more race conditions, for example when multiple users try
/// simultaneously to join the same room, and rooms can be starved more easily.  However, this mode is
/// provided for when users should be given a choice of which room to join.
///
/// ### Main flow
///
/// For parties joining a room:
///
/// 1. Call ovr_Matchmaking_Browse
/// 2. Handle ovrMessage_Matchmaking_Browse; choose a room from among the returned list
/// 3. Call ovr_Room_Join
/// 4. (for skill matching only) ovr_Matchmaking_StartMatch
/// 5. (for skill matching only) ovr_Matchmaking_ReportResultInsecure
///
/// For hosting a room: as ROOM mode
///
/// # Pools
///
/// 'pool' - this parameter for all APIs refers to a configuration for a game mode you set up in advance
/// at https://dashboard.oculus.com/application/[YOUR_APP_ID]/matchmaking
/// You can have many pools for a given application, and each will have a completely separate queue.
///
/// # Features
///
/// The matchmaking service supports several built-in features as well as 'custom criteria' - see below.
/// The best way to learn about currently supported features is to configure your pool at
/// https://dashboard.oculus.com/application/[YOUR_APP_ID]/matchmaking
/// NOTE: more than 2-player matchmaking is not yet supported, but it's coming soon.
///
/// # Match quality
///
/// Each rule (either your Custom criteria or built-in rules like skill matching and ping time optimization) yields a number
/// between 0 and 1.  These values are multiplied together to get a value between 0 and 1.  0.5 is considered to be
/// a marginal match, 0.9 an excellent match.
/// When a user is first enqueued, we have high standards (say, 0.9 or above).  As time goes on, standards decrease until we will allow
/// marginal matches (say, 0.5 or above).
///
/// ## Example 1
///
/// Two users have a peer-to-peer network round trip time of 50ms.  You configured your application to say that 100ms is a good time.  So let's say that 50ms
/// yields a really good value of 0.95.
/// User A has a medium-importance criterion (see "Custom criteria") that user B wields a banana katana, but B does not have one, yielding a value of 0.75.
/// The total match quality from A's perspective is 0.95 * 0.75 = .71 .  Thus, A and B will be matched but not before waiting a bit to
/// see if better matches come along.
///
/// ## Example 2
///
/// User A has a high-importance criterion (see "Custom criteria") that user B speaks English, but user B doesn't, yielding a value of 0.6 from A's perspective.
/// User A and B are a decent skill match, but not superb, yielding a value of 0.8.
/// Users A and B both require that each other are members of the Awesome Guild, and they both are, yielding a value of 1.0.
/// The total is 1.0 * 0.8 * 0.6 = 0.48.  This is less than 0.5 so the users are unlikely to ever be matched.
///
/// # Custom criteria
///
/// A room or user can both (a) specify facts about itself as well as (b) criteria (or filters) that it requires or
/// would prefer of ones it is matched with.  So "criteria" are applied to prospective matches and "query data"
/// describe yourself.
/// Queries are specified in advance at https://dashboard.oculus.com/application/[YOUR_APP_ID]/matchmaking,
/// and referenced here.
///
/// Each rule gives a value of 1.0 if it passes, but has a different "failure value" depending on its importance.
/// These are combined as described in the "Match quality" section above.
///
/// * Required - match will not occur if there's no match.  Failure value: 0.0
/// * High - match can be made if one high-importance rule fails.  Failure value: 0.59
/// * Medium - match can be made if two medium-importance rules fail.  Failure value: 0.77
/// * Low - match can be made if three low-importance rules miss, or one medium- and one low-importance rule misses.
///   Failure value: 0.84.
///
/// ## Example (C++)
///
///     // facts about this user/room
///     // names were specified in the developer portal
///     ovrKeyValuePair queryData[3] = {
///       makePair("minimum_dogs", 10), // makePair is a helper that creates a ovrKeyValuePair
///       makePair("favorite_hashtag", "YOLO"),
///       makePair("value_of_pi", 3.14159),
///     };
///
///     // criteria names were specified in the developer portal
///     ovrMatchmakingCriterion queryCriteria[3] = {
///       {"pi_close_enough", ovrMatchmaking_ImportanceHigh},
///       {"correct_favorite_hashtag", ovrMatchmaking_ImportanceRequired},
///       {"sufficient_dogs", ovrMatchmaking_ImportanceLow}
///     };
///
///     ovrMatchmakingCustomQueryData customQuery = {
///       queryData,
///       3,
///       queryCriteria,
///       3
///     };

/// Modes: BROWSE
/// Return a list of matchmaking rooms in the current pool filtered by skill and ping (if enabled)
///
/// \param pool a matchmaking pool with type 'browse' defined for the app.
/// \param customQueryData optional. custom query data
///
/// A message with type ::ovrMessage_Matchmaking_Browse will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrMatchmakingRoomArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetMatchmakingRoomArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_Browse(const char *pool, ovrMatchmakingCustomQueryData *customQueryData);

/// Modes: BOUT, BROWSE (for Rooms only), ROOM (for both parties and rooms)
/// Makes a best effort to cancel a previous Enqueue request before a match occurs.  Typically triggered
/// when a user gives up waiting.  If you don't cancel but the user goes offline, the user will be timed
/// out of the queue within 30 seconds.
///
/// \param pool the pool in question
/// \param requestHash Returned from ovr_Matchmaking_[CreateAnd]Enqueue[Room] which is used to find your entry in the queue.
///
/// A message with type ::ovrMessage_Matchmaking_Cancel will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occured, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_Cancel(const char *pool, const char *requestHash);

/// Modes: BOUT, BROWSE (for Rooms only), ROOM (for both parties and rooms)
/// Makes a best effort to cancel a previous Enqueue request before a match occurs.  Typically triggered
/// when a user gives up waiting.  If you don't cancel but the user goes offline, the user will be timed
/// out of the queue within 30 seconds.
///
/// A message with type ::ovrMessage_Matchmaking_Cancel2 will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occured, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_Cancel2();

/// Modes: BROWSE, ROOM
/// See overview documentation above.
/// Create a matchmaking room using of the specified size, join it, and enqueue
/// it. This is the preferred method, but if you do not wish to automatically
/// enqueue the room you may call CreateRoom instead.
///
/// Visit https://developer2.oculus.com/application/[YOUR_APP_ID]/matchmaking
/// to set up pools and queries
///
/// \param pool the matchmaking pool to use and is defined for the app.
/// \param maxUsers the maximum number of users allowed in the room, including the host. NOTE: more than 2-player matchmaking is not yet supported.
/// \param subscribeToUpdates if true will send a message with type ovrMessage_RoomUpdateNotification when room data changes, such as when users join or leave.
/// \param customQueryData Optional.  See "Custom criteria" section above.
///
/// A message with type ::ovrMessage_Matchmaking_CreateAndEnqueueRoom will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrMatchmakingEnqueueResultAndRoomHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetMatchmakingEnqueueResultAndRoom().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_CreateAndEnqueueRoom(const char *pool, unsigned int maxUsers, bool subscribeToUpdates, ovrMatchmakingCustomQueryData *customQueryData);

/// Create a matchmaking room of the specified size and join it, but do
/// not enqueue the room. After creation you may call EnqueueRoom, but generally
/// it's preferred to call CreateAndEnqueueRoom.
///
/// After creation you may enqueue the room by calling EnqueueRoom. If you wish
/// to automatically enqueue the room, use CreateAndEnqueueRoom instead.
///
/// Visit https://developer2.oculus.com/application/[YOUR_APP_ID]/matchmaking
/// to set up pools and queries
///
/// \param pool the matchmaking pool to use and is defined for the app.
/// \param maxUsers the maximum number of users allowed in the room, including the host. NOTE: more than 2-player matchmaking is not yet supported.
/// \param subscribeToUpdates if true will send a message with type ovrMessage_RoomUpdateNotification when room data changes, such as when users join or leave.
///
/// A message with type ::ovrMessage_Matchmaking_CreateRoom will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrRoomHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetRoom().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_CreateRoom(const char *pool, unsigned int maxUsers, bool subscribeToUpdates);

/// Modes: BOUT, ROOM (User only)
/// See overview documentation above.
/// Enqueue yourself to await an available matchmaking room.  ovrMessage_MatchmakingMatchFoundNotification
/// gets enqueued when a match is found.
///
/// \param pool the pool to enqueue in
/// \param customQueryData Optional.  See "Custom criteria" section above.
///
/// A message with type ::ovrMessage_Matchmaking_Enqueue will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrMatchmakingEnqueueResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetMatchmakingEnqueueResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_Enqueue(const char *pool, ovrMatchmakingCustomQueryData *customQueryData);

/// Modes: BROWSE, ROOM (Room only)
/// See overview documentation above.
/// Enqueue yourself to await an available matchmaking room.  ovrMessage_MatchmakingMatchFoundNotification
/// gets enqueued when a match is found.
///
/// The response contains useful information to display to the user to set expectations for
/// how long it will take to get a match.
///
/// \param roomID Returned either from ovrMessage_MatchmakingMatchFoundNotification or from ovr_Matchmaking_CreateRoom.  This same ID can be used for Room namespace calls such as ovr_Matchmaking_JoinRoom
/// \param customQueryData Optional.  See "Custom criteria" section above.
///
/// A message with type ::ovrMessage_Matchmaking_EnqueueRoom will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrMatchmakingEnqueueResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetMatchmakingEnqueueResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_EnqueueRoom(ovrID roomID, ovrMatchmakingCustomQueryData *customQueryData);

/// Modes: BOUT, BROWSE, ROOM
/// Joins a room returned by a previous call to ovr_Matchmaking_Enqueue or ovr_Matchmaking_Browse.
///
/// \param roomID ID of a room previously returned from ovrMessage_MatchmakingMatchFoundNotification or ovr_Message_MatchmakingBrowse
/// \param subscribeToUpdates if true will send a message with type ovrMessage_RoomUpdateNotification when room data changes, such as when users join or leave.
///
/// A message with type ::ovrMessage_Matchmaking_JoinRoom will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error ocurred, the message will contain a payload of type ::ovrRoomHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetRoom().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_JoinRoom(ovrID roomID, bool subscribeToUpdates);

/// Modes: BOUT, BROWSE, ROOM
/// See overview documentation above.
/// Call only when you've called ovr_Matchmaking_StartMatch to begin a rated skill match, and then the match finishes.
/// The service will record the result and update the skills of all players involved based on the results.
/// This method is insecure because, as a client API, it is susceptible to tampering and therefore cheating
/// to manipulate skill ratings.
///
/// A message with type ::ovrMessage_Matchmaking_ReportResultInsecure will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occured, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_ReportResultInsecure(ovrID roomID, ovrKeyValuePair *data, unsigned int numItems);

/// Modes: BOUT, BROWSE, ROOM
/// See overview documentation above.
/// Call after calling ovr_Matchmaking_JoinRoom when players are present to begin a rated match for which you plan to report the results
/// using ovr_Matchmaking_ReportResultInsecure.
///
/// A message with type ::ovrMessage_Matchmaking_StartMatch will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occured, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Matchmaking_StartMatch(ovrID roomID);

#endif

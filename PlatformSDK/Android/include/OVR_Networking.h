#ifndef OVR_NETWORKING_H
#define OVR_NETWORKING_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Represents a data packet received from a remote peer.
///
typedef struct ovrPacket* ovrPacketHandle;

typedef enum {
  /// Sends a message using an unreliable data channel (UDP-based).  No delivery
  /// or ordering guarantees are provided.  Sending will fail unless a connection
  /// to the peer has already been established, either via a previous call to
  /// ovr_Net_SendPacket() or an explicit ovr_Net_Connect().
  ///
  /// Ideally, each message should fit into a single packet; therefore, it's
  /// recommended to keep them under ~1200 bytes.
  ovrSend_Unreliable = 0,

  /// Messages are delivered reliably and in order.  The networking layer retries
  /// until each message is acknowledged by the peer.  Outgoing messages are
  /// buffered until a working connection to the peer is established.
  ovrSend_Reliable
} ovrSendPolicy;

typedef enum {
  ovrPeerState_Unknown = 0,
  /// Connection to the peer has been established.
  ///
  ovrPeerState_Connected,
  /// A timeout expired while attempting to (re)establish a connection.  This
  /// can happen if peer is unreachable or rejected the connection.
  ovrPeerState_Timeout,
} ovrPeerConnectionState;

OVRP_PUBLIC_FUNCTION(ovrID) ovr_Packet_GetSenderID(ovrPacketHandle packet);
OVRP_PUBLIC_FUNCTION(size_t) ovr_Packet_GetSize(ovrPacketHandle packet);
OVRP_PUBLIC_FUNCTION(const char *) ovr_Packet_GetBytes(ovrPacketHandle packet);
OVRP_PUBLIC_FUNCTION(ovrSendPolicy) ovr_Packet_GetSendPolicy(ovrPacketHandle packet);
OVRP_PUBLIC_FUNCTION(void) ovr_Packet_Free(ovrPacketHandle packet);

/// Read the next incoming packet.  Returns null when no more packets
/// are available.  Returned handle points to an object representing data
/// read from the network.  Ownership of that object is transferred to the
/// application; use ovr_Packet_Free() to release memory!
///
/// Typical use would look like:
///   ovrPacketHandle packet;
///   while (packet = ovr_Net_ReadPacket()) {
///     ovrID sender = ovr_Packet_GetSender(packet);
///     // dispatch packet
///     ovr_Packet_Free(packet);
///   }
OVRP_PUBLIC_FUNCTION(ovrPacketHandle) ovr_Net_ReadPacket();

/// Send a sequence of bytes to another user.  `length` must be less
/// than or equal to the allocated length of `bytes`.  A new connection
/// to `userID` will be established (asynchronously) unless one already
/// exists.
///
/// Depending on the policy, this message may be buffered until a valid
/// connection to the peer exists.  The function will return false if the
/// packet can't be enqueued for sending (e.g. there's not enough memory)
/// or the policy prohibits buffering.  See ovrSendPolicy and ovr_Net_Connect().
OVRP_PUBLIC_FUNCTION(bool) ovr_Net_SendPacket(ovrID userID,
                                              size_t length,
                                              const void* bytes,
                                              ovrSendPolicy policy);

/// Connects to the peer with the specified user id.  This function returns
/// immediately; once the connection is established, a message of type
/// `ovrMessage_NetworkingPeerConnectionStateChange` will be enqueued.
///
/// Note that ovr_Net_SendPacket() implicitly connects; however, it does not
/// buffer messages in unreliable mode.  ovr_Net_Connect() allows the application
/// to delay sending messages until an actual connection has been established.
OVRP_PUBLIC_FUNCTION(void) ovr_Net_Connect(ovrID peerID);

/// Allow `peerID` to establish a peer-to-peer connection to this host.  Expected
/// to be called after receiving `ovrMessage_NetworkingPeerConnection`; this
/// function is a no-op if there are no pending connection attempts from
/// `peerID`.
OVRP_PUBLIC_FUNCTION(void) ovr_Net_Accept(ovrID peerID);

/// Destroy the connection to `peerID` if one exists.  Note that in most cases
/// this is not needed, as the library manages the pool of connections and
/// discards unused ones.
OVRP_PUBLIC_FUNCTION(void) ovr_Net_Close(ovrID peerID);


/// Ping the user with the given ID.  Once the request completes, a message of
/// type ovrMessage_Notification_Networking_PingResult will be enqueued.
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Net_Ping(ovrID peerID);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // OVR_NETWORKING_H

#ifndef _mach_exc_user_
#define _mach_exc_user_

/* Module mach_exc */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>

#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char*, mach_msg_type_number_t);
typedef struct {
  char* name;
  function_ptr_t function;
} function_table_entry;
typedef function_table_entry* function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef mach_exc_MSG_COUNT
#define mach_exc_MSG_COUNT 3
#endif /* mach_exc_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>

#ifdef __BeforeMigUserHeader
__BeforeMigUserHeader
#endif /* __BeforeMigUserHeader */

#include <sys/cdefs.h>
    __BEGIN_DECLS

#if defined(__cplusplus)
    extern "C" {
#endif

/* Routine mach_exception_raise_OVR */
#ifdef mig_external
  mig_external
#else
extern
#endif /* mig_external */
      kern_return_t
      mach_exception_raise_OVR(
          mach_port_t exception_port,
          mach_port_t thread,
          mach_port_t task,
          exception_type_t exception,
          mach_exception_data_t code,
          mach_msg_type_number_t codeCnt);

/* Routine mach_exception_raise_state_OVR */
#ifdef mig_external
  mig_external
#else
extern
#endif /* mig_external */
      kern_return_t
      mach_exception_raise_state_OVR(
          mach_port_t exception_port,
          exception_type_t exception,
          const mach_exception_data_t code,
          mach_msg_type_number_t codeCnt,
          int* flavor,
          const thread_state_t old_state,
          mach_msg_type_number_t old_stateCnt,
          thread_state_t new_state,
          mach_msg_type_number_t* new_stateCnt);

/* Routine mach_exception_raise_state_identity_OVR */
#ifdef mig_external
  mig_external
#else
extern
#endif /* mig_external */
      kern_return_t
      mach_exception_raise_state_identity_OVR(
          mach_port_t exception_port,
          mach_port_t thread,
          mach_port_t task,
          exception_type_t exception,
          mach_exception_data_t code,
          mach_msg_type_number_t codeCnt,
          int* flavor,
          thread_state_t old_state,
          mach_msg_type_number_t old_stateCnt,
          thread_state_t new_state,
          mach_msg_type_number_t* new_stateCnt);

  __END_DECLS

/********************** Caution **************************/
/* The following data types should be used to calculate  */
/* maximum message sizes only. The actual message may be */
/* smaller, and the position of the arguments within the */
/* message layout may vary from what is presented here.  */
/* For example, if any of the arguments are variable-    */
/* sized, and less than the maximum is sent, the data    */
/* will be packed tight in the actual message to reduce  */
/* the presence of holes.                                */
/********************** Caution **************************/

/* typedefs for all requests */

#ifndef __Request__mach_exc_subsystem__defined
#define __Request__mach_exc_subsystem__defined

#ifdef __MigPackStructs
#pragma pack(4)
#endif
  typedef struct {
    mach_msg_header_t Head;
    /* start of the kernel processed data */
    mach_msg_body_t msgh_body;
    mach_msg_port_descriptor_t thread;
    mach_msg_port_descriptor_t task;
    /* end of the kernel processed data */
    NDR_record_t NDR;
    exception_type_t exception;
    mach_msg_type_number_t codeCnt;
    int64_t code[2];
  } __Request__mach_exception_raise_t;
#ifdef __MigPackStructs
#pragma pack()
#endif

#ifdef __MigPackStructs
#pragma pack(4)
#endif
  typedef struct {
    mach_msg_header_t Head;
    NDR_record_t NDR;
    exception_type_t exception;
    mach_msg_type_number_t codeCnt;
    int64_t code[2];
    int flavor;
    mach_msg_type_number_t old_stateCnt;
    natural_t old_state[144];
  } __Request__mach_exception_raise_state_t;
#ifdef __MigPackStructs
#pragma pack()
#endif

#ifdef __MigPackStructs
#pragma pack(4)
#endif
  typedef struct {
    mach_msg_header_t Head;
    /* start of the kernel processed data */
    mach_msg_body_t msgh_body;
    mach_msg_port_descriptor_t thread;
    mach_msg_port_descriptor_t task;
    /* end of the kernel processed data */
    NDR_record_t NDR;
    exception_type_t exception;
    mach_msg_type_number_t codeCnt;
    int64_t code[2];
    int flavor;
    mach_msg_type_number_t old_stateCnt;
    natural_t old_state[144];
  } __Request__mach_exception_raise_state_identity_t;
#ifdef __MigPackStructs
#pragma pack()
#endif
#endif /* !__Request__mach_exc_subsystem__defined */

/* union of all requests */

#ifndef __RequestUnion__mach_exc_subsystem__defined
#define __RequestUnion__mach_exc_subsystem__defined
  union __RequestUnion__mach_exc_subsystem {
    __Request__mach_exception_raise_t Request_mach_exception_raise;
    __Request__mach_exception_raise_state_t Request_mach_exception_raise_state;
    __Request__mach_exception_raise_state_identity_t Request_mach_exception_raise_state_identity;
  };
#endif /* !__RequestUnion__mach_exc_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__mach_exc_subsystem__defined
#define __Reply__mach_exc_subsystem__defined

#ifdef __MigPackStructs
#pragma pack(4)
#endif
  typedef struct {
    mach_msg_header_t Head;
    NDR_record_t NDR;
    kern_return_t RetCode;
  } __Reply__mach_exception_raise_t;
#ifdef __MigPackStructs
#pragma pack()
#endif

#ifdef __MigPackStructs
#pragma pack(4)
#endif
  typedef struct {
    mach_msg_header_t Head;
    NDR_record_t NDR;
    kern_return_t RetCode;
    int flavor;
    mach_msg_type_number_t new_stateCnt;
    natural_t new_state[144];
  } __Reply__mach_exception_raise_state_t;
#ifdef __MigPackStructs
#pragma pack()
#endif

#ifdef __MigPackStructs
#pragma pack(4)
#endif
  typedef struct {
    mach_msg_header_t Head;
    NDR_record_t NDR;
    kern_return_t RetCode;
    int flavor;
    mach_msg_type_number_t new_stateCnt;
    natural_t new_state[144];
  } __Reply__mach_exception_raise_state_identity_t;
#ifdef __MigPackStructs
#pragma pack()
#endif
#endif /* !__Reply__mach_exc_subsystem__defined */

/* union of all replies */

#ifndef __ReplyUnion__mach_exc_subsystem__defined
#define __ReplyUnion__mach_exc_subsystem__defined
  union __ReplyUnion__mach_exc_subsystem {
    __Reply__mach_exception_raise_t Reply_mach_exception_raise;
    __Reply__mach_exception_raise_state_t Reply_mach_exception_raise_state;
    __Reply__mach_exception_raise_state_identity_t Reply_mach_exception_raise_state_identity;
  };
#endif /* !__RequestUnion__mach_exc_subsystem__defined */

#ifndef subsystem_to_name_map_mach_exc
#define subsystem_to_name_map_mach_exc                                            \
  {"mach_exception_raise_OVR", 2405}, {"mach_exception_raise_state_OVR", 2406}, { \
    "mach_exception_raise_state_identity_OVR", 2407                               \
  }
#endif

#ifdef __AfterMigUserHeader
  __AfterMigUserHeader
#endif /* __AfterMigUserHeader */

#ifdef mig_external
      mig_external
#else
extern
#endif /* mig_external */
          boolean_t mach_exc_server_OVR(mach_msg_header_t * InHeadP, mach_msg_header_t * OutHeadP);

#if defined(__cplusplus)
} // extern"C"
#endif

#endif /* _mach_exc_user_ */

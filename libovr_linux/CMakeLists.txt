cmake_minimum_required(VERSION 2.6)

project(libovr)


#set(FORCE_32BIT 0)
#set(LIBTYPE "static")

set(COMPILE_FLAGS "-Wall -Wextra -pipe -fPIC -msse2 -fno-strict-aliasing")

if(FORCE_32BIT)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -m32")
endif()


if(SINGLE_PROCESS)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -DOVR_SINGLE_PROCESS")
endif()

if("${LIBTYPE}" STREQUAL "shared")
    set(LIB_TYPE "MODULE")
else()
    set(LIB_TYPE "STATIC")
endif()


set(3RDPARTYPATH "../OculusSDK/3rdParty")

set(OTHER_SOURCE
${3RDPARTYPATH}/EDID/edid.cpp
${3RDPARTYPATH}/TinyXml/tinyxml2.cpp
)

set(LIBOVRPATH "../OculusSDK/LibOVR")
set(LIBOVRKERNELPATH "../OculusSDK/LibOVRKernel")

include_directories("${LIBOVRPATH}/Include")
include_directories("${LIBOVRPATH}/Src")
include_directories("${LIBOVRKERNELPATH}/Src")

set(LIBOVR_SOURCE
${LIBOVRPATH}/Src/OVR_StereoProjection.cpp
${LIBOVRPATH}/Src/Service/Service_NetClient.cpp
${LIBOVRPATH}/Src/Service/Service_NetSessionCommon.cpp
${LIBOVRPATH}/Src/CAPI/GL/CAPI_GL_DistortionRenderer.cpp
${LIBOVRPATH}/Src/CAPI/GL/CAPI_GL_HSWDisplay.cpp
${LIBOVRPATH}/Src/CAPI/GL/CAPI_GL_Util.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_HMDRenderState.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_DistortionTiming.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_FrameTimeManager3.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_DistortionRenderer.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_HMDState.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_HSWDisplay.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_FrameLatencyTracker.cpp
${LIBOVRPATH}/Src/OVR_Linux_UDEV.cpp
${LIBOVRPATH}/Src/Net/OVR_BitStream.cpp
${LIBOVRPATH}/Src/Net/OVR_NetworkPlugin.cpp
${LIBOVRPATH}/Src/Net/OVR_Unix_Socket.cpp
${LIBOVRPATH}/Src/Net/OVR_RPC1.cpp
${LIBOVRPATH}/Src/Net/OVR_Socket.cpp
${LIBOVRPATH}/Src/Net/OVR_PacketizedTCPSocket.cpp
${LIBOVRPATH}/Src/Net/OVR_Session.cpp
${LIBOVRPATH}/Src/Util/Util_Render_Stereo.cpp
${LIBOVRPATH}/Src/Util/Util_LatencyTest2Reader.cpp
${LIBOVRPATH}/Src/Util/Util_Interface.cpp
${LIBOVRPATH}/Src/OVR_Stereo.cpp
${LIBOVRPATH}/Src/OVR_CAPI_Util.cpp
${LIBOVRPATH}/Src/OVR_Profile.cpp
${LIBOVRPATH}/Src/Vision/SensorFusion/Vision_SensorStateReader.cpp
${LIBOVRPATH}/Src/Displays/OVR_Display.cpp
${LIBOVRPATH}/Src/Displays/OVR_Linux_Display.cpp
${LIBOVRPATH}/Src/Displays/OVR_Linux_SDKWindow.cpp
${LIBOVRPATH}/Src/OVR_SerialFormat.cpp
${LIBOVRPATH}/Src/OVR_CAPI.cpp
)

#${LIBOVRPATH}/Src/OVR_CAPIShim.c


set(LIBOVRKERNEL_SOURCE
${LIBOVRKERNELPATH}/Src/GL/CAPI_GLE.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Log.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_String_FormatUtil.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_CRC32.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Callbacks.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_ThreadsPthread.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Timer.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_String.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_JSON.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Lockless.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_DebugHelp.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_String_PathUtil.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_File.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_SharedMemory.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_FileFILE.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Std.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Atomic.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_ThreadCommandQueue.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Rand.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_RefCount.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_SysFile.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Alg.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_UTF8Util.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_System.cpp
${LIBOVRKERNELPATH}/Src/Kernel/OVR_Allocator.cpp
${LIBOVRKERNELPATH}/Src/Util/Util_SystemGUI.cpp
${LIBOVRKERNELPATH}/Src/Util/Util_GetSystemSpecs.cpp
${LIBOVRKERNELPATH}/Src/Util/Util_ImageWindow.cpp
${LIBOVRKERNELPATH}/Src/Util/Util_Watchdog.cpp
${LIBOVRKERNELPATH}/Src/Util/Util_SystemInfo.cpp
${LIBOVRKERNELPATH}/Src/Util/Util_LongPollThread.cpp
)
#${LIBOVRKERNELPATH}/Src/Kernel/OVR_ThreadsWinAPI.cpp
#${LIBOVRKERNELPATH}/Src/Kernel/OVR_mach_exc_OSX.c
#${LIBOVRKERNELPATH}/Src/Util/Util_Direct3D.cpp

set(LIB_SOURCE_FILES
    ${OTHER_SOURCE}
    ${LIBOVRKERNEL_SOURCE}
    ${LIBOVR_SOURCE}
)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${COMPILE_FLAGS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS} -std=c++11")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${COMPILE_FLAGS} -std=c++11")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -DOVR_BUILD_DEBUG ${COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -DOVR_BUILD_DEBUG ${COMPILE_FLAGS} -std=c++11")

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    message("flags: ${CMAKE_CXX_FLAGS_DEBUG}")
else()
    message("flags: ${CMAKE_CXX_FLAGS_RELEASE}")
endif()


set(EXTRA_LIBS ${EXTRA_LIBS} udev)
set(EXTRA_LIBS ${EXTRA_LIBS} Xinerama)
add_library(ovr ${LIB_TYPE} ${LIB_SOURCE_FILES})


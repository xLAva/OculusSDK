cmake_minimum_required(VERSION 2.6)

project(libovr)


#set(FORCE_32BIT 0)
#set(LIBTYPE "static")

set(COMPILE_FLAGS "-Wall -Wextra -pipe -fPIC -msse2")

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

set(LIBOVR_SOURCE
${LIBOVRPATH}/Src/Net/OVR_BitStream.cpp
${LIBOVRPATH}/Src/Net/OVR_Unix_Socket.cpp
${LIBOVRPATH}/Src/Net/OVR_NetworkPlugin.cpp
${LIBOVRPATH}/Src/Net/OVR_PacketizedTCPSocket.cpp
${LIBOVRPATH}/Src/Net/OVR_RPC1.cpp
${LIBOVRPATH}/Src/Net/OVR_Session.cpp
${LIBOVRPATH}/Src/Net/OVR_Socket.cpp
${LIBOVRPATH}/Src/Service/Service_NetClient.cpp
${LIBOVRPATH}/Src/Service/Service_NetSessionCommon.cpp
${LIBOVRPATH}/Src/Tracking/Tracking_SensorStateReader.cpp
${LIBOVRPATH}/Src/Displays/OVR_Display.cpp
${LIBOVRPATH}/Src/Displays/OVR_Linux_Display.cpp
${LIBOVRPATH}/Src/Displays/OVR_Linux_SDKWindow.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_DistortionRenderer.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_HSWDisplay.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_FrameTimeManager.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_HMDRenderState.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_HMDState.cpp
${LIBOVRPATH}/Src/CAPI/CAPI_LatencyStatistics.cpp
${LIBOVRPATH}/Src/CAPI/GL/CAPI_GL_DistortionRenderer.cpp
${LIBOVRPATH}/Src/CAPI/GL/CAPI_GL_HSWDisplay.cpp
${LIBOVRPATH}/Src/CAPI/GL/CAPI_GL_Util.cpp
${LIBOVRPATH}/Src/CAPI/GL/CAPI_GLE.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Alg.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Allocator.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Atomic.cpp
${LIBOVRPATH}/Src/Kernel/OVR_CRC32.cpp
${LIBOVRPATH}/Src/Kernel/OVR_DebugHelp.cpp
${LIBOVRPATH}/Src/Kernel/OVR_File.cpp
${LIBOVRPATH}/Src/Kernel/OVR_FileFILE.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Lockless.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Log.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Math.cpp
${LIBOVRPATH}/Src/Kernel/OVR_RefCount.cpp
${LIBOVRPATH}/Src/Kernel/OVR_SharedMemory.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Std.cpp
${LIBOVRPATH}/Src/Kernel/OVR_String.cpp
${LIBOVRPATH}/Src/Kernel/OVR_String_FormatUtil.cpp
${LIBOVRPATH}/Src/Kernel/OVR_String_PathUtil.cpp
${LIBOVRPATH}/Src/Kernel/OVR_SysFile.cpp
${LIBOVRPATH}/Src/Kernel/OVR_System.cpp
${LIBOVRPATH}/Src/Kernel/OVR_ThreadsPthread.cpp
${LIBOVRPATH}/Src/Kernel/OVR_ThreadCommandQueue.cpp
${LIBOVRPATH}/Src/Kernel/OVR_Timer.cpp
${LIBOVRPATH}/Src/Kernel/OVR_UTF8Util.cpp
${LIBOVRPATH}/Src/Util/Util_Interface.cpp
${LIBOVRPATH}/Src/Util/Util_LatencyTest2Reader.cpp
${LIBOVRPATH}/Src/Util/Util_Render_Stereo.cpp
${LIBOVRPATH}/Src/Util/Util_SystemInfo.cpp
${LIBOVRPATH}/Src/Util/Util_SystemGUI.cpp
${LIBOVRPATH}/Src/OVR_CAPI.cpp
${LIBOVRPATH}/Src/OVR_SerialFormat.cpp
${LIBOVRPATH}/Src/OVR_JSON.cpp
${LIBOVRPATH}/Src/OVR_Profile.cpp
${LIBOVRPATH}/Src/OVR_Stereo.cpp
)

set(LIB_SOURCE_FILES
    ${OTHER_SOURCE}
    ${LIBOVR_SOURCE}
)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2 ${COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 ${COMPILE_FLAGS}")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -DOVR_BUILD_DEBUG ${COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -DOVR_BUILD_DEBUG ${COMPILE_FLAGS}")

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    message("flags: ${CMAKE_CXX_FLAGS_DEBUG}")
else()
    message("flags: ${CMAKE_CXX_FLAGS_RELEASE}")
endif()


		set(EXTRA_LIBS ${EXTRA_LIBS} udev)
		set(EXTRA_LIBS ${EXTRA_LIBS} Xinerama)
add_library(ovr ${LIB_TYPE} ${LIB_SOURCE_FILES})


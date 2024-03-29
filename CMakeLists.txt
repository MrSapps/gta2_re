cmake_minimum_required (VERSION 3.5)
project (decomp)

ENABLE_LANGUAGE(ASM_MASM)

SET(CMAKE_WARN_VS6 CACHE BOOL OFF)

add_library (mss32 SHARED
    Source/3rdParty/mss.h
    Source/3rdParty/mss.cpp
    )
target_compile_definitions(mss32 PRIVATE BUILD_MSS)

add_custom_command (
    TARGET mss32
    POST_BUILD
    COMMAND del $(TargetPath)
)


add_library (Source 
    Source/3rdParty/mss.h
    Source/types.hpp
    Source/winmain.cpp
    Source/frosty_pasteur_0xC1EA8.hpp
    Source/frosty_pasteur_0xC1EA8.cpp
    Source/map_0x370.hpp
    Source/map_0x370.cpp
    Source/nostalgic_ellis_0x28.hpp
    Source/nostalgic_ellis_0x28.cpp
    Source/fix16.hpp
    Source/fix16.cpp
    Source/error.hpp
    Source/error.cpp
    Source/memory.hpp
    Source/memory.cpp
    Source/chunk.hpp
    Source/keybrd_0x204.hpp
    Source/keybrd_0x204.cpp
    Source/debug.hpp
    Source/debug.cpp
    Source/cSampleManager.hpp
    Source/cSampleManager.cpp
    Source/sound_obj.hpp
    Source/sound_obj.cpp
    Source/dma_video.hpp
    Source/dma_video.cpp
    Source/magical_germain_0x8EC.hpp
    Source/magical_germain_0x8EC.cpp
    Source/sharp_pare_0x15D8.hpp
    Source/sharp_pare_0x15D8.cpp
    Source/Bink.hpp
    Source/Bink.cpp
    Source/gbh_graphics.hpp
    Source/gbh_graphics.cpp
    Source/text_0x14.hpp
    Source/text_0x14.cpp
    Source/root_sound.hpp
    Source/root_sound.cpp
    Source/angry_lewin_0x85C.hpp
    Source/angry_lewin_0x85C.cpp
    Source/laughing_blackwell_0x1EB54.hpp
    Source/laughing_blackwell_0x1EB54.cpp
    Source/Game_0x40.hpp
    Source/Game_0x40.cpp
    Source/jolly_poitras_0x2BC0.hpp
    Source/jolly_poitras_0x2BC0.cpp
    Source/goofy_thompson.hpp
    Source/goofy_thompson.cpp
    Source/input.hpp
    Source/input.cpp
    Source/lucid_hamilton.hpp
    Source/lucid_hamilton.cpp
    Source/registry.hpp
    Source/registry.cpp
    Source/file.hpp
    Source/file.cpp
    Source/sharp_bose_0x54.hpp
    Source/sharp_bose_0x54.cpp
    Source/distracted_einstein_0xC.hpp
    Source/distracted_einstein_0xC.cpp
    Source/gtx_0x106C.hpp
    Source/gtx_0x106C.cpp)
target_compile_definitions(Source PRIVATE _CRT_SECURE_NO_WARNINGS _CRT_NON_CONFORMING_SWPRINTFS)

include_directories(Source)
include_directories(${decomp_SOURCE_DIR})

add_executable (decomp_main WIN32 Source
    test.cpp
    StdAfx.cpp
    resources.rc)
target_link_libraries(decomp_main mss32)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

# NOICF is required because skip_ovly_5AAE20 and skip_psxt_5AAE30 have identical bodies and the linker will make them one and the same
# however the real binary does have 2 copies. NOREF keeps functions that are not yet called so we can diff the content against the original.
if (${MSVC_VERSION} GREATER 1200)
set (CMAKE_EXE_LINKER_FLAGS "/MAP:output.map /OPT:NOICF,NOREF /SAFESEH:NO" )
else()
set (CMAKE_EXE_LINKER_FLAGS "/MAP:output.map /OPT:NOICF,NOREF" )
endif()
set (CMAKE_SHARED_LINKER_FLAGS "/OPT:NOICF,NOREF")

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )

if (${MSVC_VERSION} EQUAL 1200)
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/ML /W3 /GX" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/Ob2" "" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/GR" "/EHsc" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()
endif()

target_link_libraries (decomp_main Source)

message(STATUS "${MSVC_VERSION}=${${MSVC_VERSION}}")

if (${MSVC_VERSION} GREATER 1200)
   SET ( CMAKE_SHARED_LINKER_FLAGS /MANIFEST:NO )
endif()

install (TARGETS decomp_main DESTINATION bin)
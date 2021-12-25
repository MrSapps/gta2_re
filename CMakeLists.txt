cmake_minimum_required (VERSION 3.5)
project (decomp)

ENABLE_LANGUAGE(ASM_MASM)

SET(CMAKE_WARN_VS6 CACHE BOOL OFF)

add_library (Source 
    Source/error.hpp
    Source/error.cpp
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
    
include_directories(Source)
include_directories(${decomp_SOURCE_DIR})

add_executable (decomp_main WIN32 Source
    test.cpp
    StdAfx.cpp
    test.rc)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

# NOICF is required because skip_ovly_5AAE20 and skip_psxt_5AAE30 have identical bodies and the linker will make them one and the same
# however the real binary does have 2 copies. NOREF keeps functions that are not yet called so we can diff the content against the original.
set (CMAKE_EXE_LINKER_FLAGS "/MAP:output.map /OPT:NOICF,NOREF" )
set (CMAKE_SHARED_LINKER_FLAGS "/OPT:NOICF,NOREF")

set_source_files_properties(
    test2.asm
    PROPERTIES
    COMPILE_FLAGS "/safeseh"
)

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/ML /W3 /GX" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/Ob2" "" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/GR" "" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()


target_link_libraries (decomp_main Source)

SET ( CMAKE_SHARED_LINKER_FLAGS /MANIFEST:NO )

install (TARGETS decomp_main DESTINATION bin)
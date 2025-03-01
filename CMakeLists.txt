cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(VMLBuild)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(FPFNA)

include("${VITASDK}/share/vita.cmake" REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -marm -mtune=cortex-a9 -mfpu=neon -Wno-incompatible-pointer-types -Wno-stringop-overflow -Wno-deprecated-declarations -Wl,-q -O3 -Wall")

add_custom_target(FPFNADependencies)

compile_mono_external_import(
    ASSEMBLY System.dll
    TARGET FPFNADependencies
    LIBPATH ${MONO_PATH}
)

compile_mono_external_import(
    ASSEMBLY System.Xml.dll
    TARGET FPFNADependencies
    LIBPATH ${MONO_PATH}
)

compile_mono_external_import(
    ASSEMBLY FNA.dll
    TARGET FPFNADependencies
)

add_subdirectory(SourceFiles)
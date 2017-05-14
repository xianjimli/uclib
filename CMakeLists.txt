cmake_minimum_required(VERSION 3.5)

project(uclib)

set(SYS_LIBS )
if(APPLE)
    # If OSX
	list(APPEND SYS_LIBS -lm -lpthread)
    ADD_DEFINITIONS(
        -DMACOS -Wall -g -Wunused-variable -Wunused-parameter -Wunused-function -Wunused
        -Wno-deprecated  -Wwrite-strings
    )
elseif(UNIX)
    # If unix
	list(APPEND SYS_LIBS -lm -lpthread)
    ADD_DEFINITIONS(
        -DUNIX -g -fPIC -Wunused-variable -Wunused-parameter -Wunused-function -Wunused
        -Wno-deprecated  -Wwrite-strings
    )
else()
    # If windows
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS -DHAVE_STRUCT_TIMESPEC)
endif()

set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR} )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR} )

# Second, for multi-config builds (e.g. msvc)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
 string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
 set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BIN_DIR} )
 set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BIN_DIR} )
 set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BIN_DIR} )
 message(STATUS CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG})
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

link_directories(${BIN_DIR})
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(uclib)
add_subdirectory(tools)
add_subdirectory(tests)


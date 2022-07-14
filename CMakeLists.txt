#
# Copyright (c) 2022 Harvest Technology Group Pty Ltd. All Rights Reserved.
#
cmake_minimum_required(VERSION 3.21.0)

include(cmake/cross-compile.cmake)

project(
  templ-cmake
  VERSION 0.1.0
  LANGUAGES CXX)

# ##############################################################################
# CMake build flags
# ##############################################################################
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE_INIT
    "-Wall -03 -DNDEBUG -ffast-math -fexpensive-optimizations -flto -fno-exceptions"
)

# Assure -DNDEBUG is set for all compilers (remove assert calls)
if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
  add_definitions(-DNDEBUG)
endif()

# ##############################################################################
# Project name
# ##############################################################################
set(CMAKE_PROJECT_NAME "lib-templ-cmake")
set(PROJECT_NAME "lib-templ-cmake")

# ##############################################################################
# Bundle requirement for Apple builds
# ##############################################################################
if(APPLE)
  set_target_properties(
    ${APP_NAME}
    PROPERTIES BUNDLE True
               MACOSX_BUNDLE_GUI_IDENTIFIER ${PROJECT_NAME}
               MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME}
               MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
               MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1")
endif()

# ##############################################################################
# Locations of binaries, libraries and scripts
# ##############################################################################
include(cmake/determine-locations.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})
set(RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# ##############################################################################
# Main project directory
# ##############################################################################
add_subdirectory(project)

link_directories(${CMAKE_SOURCE_DIR}${LIBRARY_DIR})

# ##############################################################################
# Linting and formatting
# ##############################################################################
# Allows to perform linting and formatting, uses ${LINT_SOURCES},
# include/internal, include/interface, compile_commands.json,
# ${CMAKE_SOURCE_DIR}, ${CMAKE_BINARY_DIR} set(EXCLUDE_DIRECTORIES
# "./project/include/external,./build")
include(cmake/linter.cmake)

# ##############################################################################
# Documentation
# ##############################################################################
# Usage: make doc
option(BUILD_DOCUMENTATION "Build the documentation" ON)

# ##############################################################################
# Testing
# ##############################################################################
option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
  install(TARGETS ${PROJECT_NAME}-test DESTINATION "bin")
endif()

# ##############################################################################
# Install - Used by CI
# ##############################################################################
install(DIRECTORY "project/include/interface/" DESTINATION "include")

# ##############################################################################
# Debian Packaging
# ##############################################################################

# Usage: cpack -G DEB Usage: cpack Allows to create a .deb package
# include(cmake/project-cpack.cmake)

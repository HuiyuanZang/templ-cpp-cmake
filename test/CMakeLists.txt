#
# Copyright (c) 2022 Harvest Technology Group Pty Ltd. All Rights Reserved.
#

# ##############################################################################
# Include directories
# ##############################################################################
set(HEADERS_PATH ../project/include/)
include_directories(${HEADERS_PATH}external)
include_directories(${HEADERS_PATH}interface)
include_directories(${HEADERS_PATH}internal)

# ##############################################################################
# Clone Google Test
# ##############################################################################
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0)

option(INSTALL_GTEST "Enable installation of googletest." OFF)

FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

include_directories(${googletest_SOURCE_DIR}/googletest/include/)
include_directories(${googletest_SOURCE_DIR}/googlemock/include/)

# ##############################################################################
# Source groups
# ##############################################################################
file(GLOB SOURCES "*/*.cpp" "*.cpp")

# ##############################################################################
# Target
# ##############################################################################
add_executable(${PROJECT_NAME}-test Test.cpp ${SOURCES})

# ##############################################################################
# Dependencies
# ##############################################################################
target_link_libraries(${PROJECT_NAME}-test PRIVATE GTest::GTest ${PROJECT_NAME}
                                                   -pthread)

# ##############################################################################
# Tests
# ##############################################################################
add_test(NAME unit-test COMMAND ${BINARY_DIR}/${PROJECT_NAME}-test)

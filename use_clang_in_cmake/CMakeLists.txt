cmake_minimum_required(VERSION 3.0.0)
project(use_clang_in_cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS_DEBUG   "-std=c++11 -Wall -Wno-unused-local-typedefs -Wno-unused-function -fPIC -g")
SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -Wall -Wno-unused-local-typedefs -Wno-unused-function -fPIC -O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

MESSAGE(STATUS "MY_BUILD_PLATFORM: ${MY_BUILD_PLATFORM}")
MESSAGE(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")

set(DIR_PROJECT .)

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
  ${DIR_PROJECT}
)

aux_source_directory(. SRC_ROOT)
set(SRC_LIST ${SRC_ROOT})

ADD_EXECUTABLE(use_clang_in_cmake ${SRC_LIST})

TARGET_LINK_LIBRARIES(use_clang_in_cmake
  ${CONAN_LIBS}
	pthread
	rt
)

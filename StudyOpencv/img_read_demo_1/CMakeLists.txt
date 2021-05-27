cmake_minimum_required(VERSION 3.0.0)
project(img_encode_decode)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS_DEBUG   "-std=c++11 -Wall -Wno-unused-local-typedefs -Wno-unused-function -fPIC -g")
SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -Wall -Wno-unused-local-typedefs -Wno-unused-function -fPIC -O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

MESSAGE(STATUS "MY_BUILD_PLATFORM: ${MY_BUILD_PLATFORM}")
MESSAGE(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")

set(DIR_UTILS ../utils)

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
  ${DIR_UTILS}
)

aux_source_directory(. SRC_ROOT)
aux_source_directory(${DIR_UTILS} SRC_UTILS)
set(SRC_LIST
    ${SRC_ROOT}
    ${SRC_UTILS})

add_executable(main ${SRC_LIST})
target_link_libraries(main ${CONAN_LIBS})

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

add_executable(main main.cpp)
target_link_libraries(main ${CONAN_LIBS})

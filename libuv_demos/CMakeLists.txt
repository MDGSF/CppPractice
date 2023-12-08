CMAKE_MINIMUM_REQUIRED(VERSION 3.13.1)

PROJECT(libuvdemos)

include(${VENDOR_LINUX_HOME}/vendor_linux.cmake)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src/helloworld)

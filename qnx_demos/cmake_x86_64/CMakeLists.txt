cmake_minimum_required(VERSION 3.5)

include(x86_64-qnx.toolchain.cmake)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

ADD_EXECUTABLE(cmake_x86_64 "main.cpp")

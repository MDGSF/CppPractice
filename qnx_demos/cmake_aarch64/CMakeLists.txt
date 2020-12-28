cmake_minimum_required(VERSION 3.5)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

ADD_EXECUTABLE(cmake1 "main.cpp")

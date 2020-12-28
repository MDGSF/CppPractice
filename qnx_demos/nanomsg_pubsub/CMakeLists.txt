cmake_minimum_required(VERSION 3.5)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

ADD_EXECUTABLE(pubsub "main.cpp")
TARGET_LINK_LIBRARIES(pubsub
	${CMAKE_CURRENT_SOURCE_DIR}/nanomsg_lib/libnanomsg.so
	Threads::Threads)


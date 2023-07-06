CMAKE_MINIMUM_REQUIRED(VERSION 3.13.1)

project(main)

add_executable(${PROJECT_NAME}
  main.cpp
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  pthread
  m
  rt
)

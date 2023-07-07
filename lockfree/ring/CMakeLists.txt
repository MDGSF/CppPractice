CMAKE_MINIMUM_REQUIRED(VERSION 3.13.1)

project(ring)

#######################################

add_executable(test01
  test01.cpp
)

TARGET_LINK_LIBRARIES(test01
  pthread
  m
  rt
)

#######################################

add_executable(test02
  test02.cpp
)

TARGET_LINK_LIBRARIES(test02
  pthread
  m
  rt
)

#######################################

add_executable(testmpmc
  testmpmc.cpp
)

TARGET_LINK_LIBRARIES(testmpmc
  pthread
  m
  rt
)

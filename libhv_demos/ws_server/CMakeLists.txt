cmake_minimum_required(VERSION 3.5) # 设置 CMake 最小版本
project(ws_server) # 设置工程名
add_executable(${PROJECT_NAME} main.cpp) # 生成可执行文件

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
  /home/huangjian/opt/vendor/libhv/libhv-1.2.6/include/hv
)

TARGET_LINK_DIRECTORIES(${PROJECT_NAME} PRIVATE
  /home/huangjian/opt/vendor/libhv/libhv-1.2.6/lib
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  pthread
  m
  hv
)

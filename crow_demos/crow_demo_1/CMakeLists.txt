cmake_minimum_required(VERSION 3.5) # 设置 CMake 最小版本
project(hello_cmake) # 设置工程名
add_executable(${PROJECT_NAME} main.cpp) # 生成可执行文件

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
  /home/huangjian/opt/vendor/crow/crow-1.0.4/include
  /home/huangjian/opt/vendor/asio/asio-1-23-0-header-only/include
)

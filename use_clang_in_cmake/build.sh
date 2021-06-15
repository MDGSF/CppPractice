#!/bin/bash

set -e
set -x

if [ ! -d "build" ]; then
  mkdir build
fi
pushd build

# cp -arf conan_profiles/clang ~/.conan/profiles/clang
conan install .. --build=missing --profile clang

export CC=/home/huangjian/local/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-16.04/bin/clang
export CXX=/home/huangjian/local/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-16.04/bin/clang++
cmake .. \
  -DCMAKE_USER_MAKE_RULES_OVERRIDE=ClangOverrides.txt \
  -D_CMAKE_TOOLCHAIN_PREFIX=llvm- \
  -DCMAKE_BUILD_TYPE=Release

cmake --build .


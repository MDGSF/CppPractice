#!/usr/bin/env bash

set -e

SCRIPT_DIR=$(dirname "$0")
PROJECT_DIR=$(cd "$SCRIPT_DIR"; pwd)
BUILD_DIR=build/x86_64_qnx

cd "$PROJECT_DIR"
mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_TOOLCHAIN_FILE=x86_64-qnx.toolchain.cmake \
  $PROJECT_DIR

make -j $(nproc)


#!/usr/bin/env bash

SCRIPT_HOME=$(cd `dirname $0` && pwd)
SOLUTION_HOME=$(cd $SCRIPT_HOME && pwd)

echo "SCRIPT_HOME = $SCRIPT_HOME"
echo "SOLUTION_HOME = $SOLUTION_HOME"

mkdir -p build
cd build

cmake \
    -DCMAKE_SYSTEM_NAME=Linux \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_COMPILER=g++ \
    -DCMAKE_C_COMPILER=gcc \
    -DCMAKE_AR=ar \
    -DVENDOR_LINUX_HOME=$VENDOR_LINUX_HOME \
    ..

make
# make VERBOSE=1

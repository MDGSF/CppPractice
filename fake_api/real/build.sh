#!/usr/bin/env bash
g++ -I.. -fPIC -O3 -DNDEBUG -shared -Wl,-soname,libhello.so -o libhello.so Hello.cpp


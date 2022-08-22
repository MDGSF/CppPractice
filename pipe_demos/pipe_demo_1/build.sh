#!/usr/bin/env bash
rm main test test.log
g++ test.cpp -o test
g++ main.cpp -lpthread -std=c++11 -o main

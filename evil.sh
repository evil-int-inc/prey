#!/bin/bash

from=$1

./compiler-to-cpp "$from"
g++ -w -o app to/Main.cpp
./app
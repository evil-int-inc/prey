#!/bin/bash

from=$1

./compiler-to-cpp "$from"
g++ -o app to/Main.cpp
./app
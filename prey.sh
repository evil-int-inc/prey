#!/bin/bash

from=$1

# Cleaning
if [ -f app ]; then
  rm app
fi
if [ -d to ]; then
  rm -rf to
fi

# Check if g++ is installed
if ! command -v g++ &> /dev/null; then
  echo "g++ is not installed. Installing..."
  # Detect OS
  if [ "$(uname -s)" == "Darwin" ]; then
    # Mac OS detected, install with Xcode tools
    if ! command -v xcodebuild &> /dev/null; then
      echo "Xcode command line tools are not installed. Installing..."
      xcode-select --install
    else
      echo "Xcode command line tools are installed. Using them for g++..."
    fi
  # Detect package manager based on distro (common ones)
  elif [ -x "$(command -v apt-get)" ]; then
    sudo apt-get update && sudo apt-get install g++ -y
  elif [ -x "$(command -v yum)" ]; then
    sudo yum install gcc-c++ -y
  elif [ -x "$(command -v dnf)" ]; then
    sudo dnf install gcc-c++ -y
  else
    echo "Package manager not detected. Please install g++ manually."
    exit 1
  fi
  echo "g++ installation complete."
fi

# Preparing compilation environment
mkdir to
cp ./library/c++/* to

# Checking code validity at a compile time and then compile
./compiler-to-cpp "$from"

# Compile to binary
# TODO: compile to c++23
g++ -w -o app to/Main.cpp -std=c++20

# Launch app
./app

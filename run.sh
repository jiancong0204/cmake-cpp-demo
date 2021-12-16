#!/bin/bash

set -e

echo 'Project in '$PWD
mkdir -p build

cd build
rm -rf *

cmake ..
make -j

echo ' '
echo 'Run the program'
# ./demo
#!/bin/sh

mkdir build
cd build
if [ $1 > 1 ]; then
    cmake .. -DCOUNTARGS=$1
else
    cmake .. -DCOUNTARGS=1
fi

make

make install

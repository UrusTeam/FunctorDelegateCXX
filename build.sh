#!/bin/sh

mkdir build
cd build
if [ $1 > 1 ]; then
    cmake .. -DCOUNTARGS=$1
else
    cmake .. -DCOUNTARGS=1
fi

make
./Hopter ../include/FastDelegate.hxx FastDelegate.h
./HopterUrus ../include/FastFunctor.hxx FastFunctor.h
cp FastFunctor.h ../
cp FastDelegate.h ../
make install

#!/usr/bin/env bash
# Kwagsh developers 2018
# use this installer to clone-and-compile kwagsh in one line
# supports Ubuntu 16 LTS

sudo apt-get update
yes "" | sudo apt-get install build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost-all-dev
export CXXFLAGS="-std=gnu++11"
git clone https://github.com/kwash-dev/Kwagsh
cd kwagsh
mkdir build && cd $_
cmake ..
make

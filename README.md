
## Thanks to Cryptonote Developers, Bytecoin Developers, Monero Developers, Karbo Project (Aiwe), Qwertycoin Community for their idea which was used by Kwagsh
 
 
 
[<img width="200" src="https://avatars0.githubusercontent.com/u/37370757?s=400&v=4"/>](http://kwagsh.xyz) 
 
Kwagsh is a core implementation of CryptoNote. It is open source and completely free to use without restrictions. Anyone is welcome to contribute to Kwagsh's codebase! If you have a fix or code change, feel free to submit is as a pull request directly to the "master" branch. In cases where the change is relatively small or does not affect other parts of the codebase it may be merged in immediately by any one of the collaborators. On the other hand, if the change is particularly large or complex, it is expected that it will be discussed at length either well in advance of the pull request being submitted, or even directly on the pull request. 
 
Compiling Kwagsh from Source 
Follow the Kwagsh build instructions 
 
## Pre-requisite
```
sudo apt-get install build-essential python-dev gcc g++ git cmake libboost-all-dev
```
 
## Kwagsh Build Instructions 
Download the project from github  
``` 
sudo git clone https://github.com/kwash-dev/kwagsh.git  
``` 
``` 
cd kwagsh sudo mkdir build && cd build && sudo mkdir release && cd release sudo cmake CMAKE_BUILD_TYPE=Release ../.. && sudo make 
``` 
# After built is completed run the daemon 
``` 
sudo ./kwagshd  
``` 
and allow it to sync, once sync is completed open another terminal and run simple wallet  
``` 
sudo ./simplewallet 
``` 
# Start Mining 
You can either Mine in Pool or solo mining 
 
 
# Pool  
Mine in this pool http://pool.kwagsh.xyz 
commit:97bb7e
Update README.md

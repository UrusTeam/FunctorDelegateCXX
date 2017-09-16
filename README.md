# FunctorDelegateCXX
Fast Delegate C++ for Urus. Base source from http://www.codeproject.com/KB/cpp/FastFunctor.aspx

# About
This is a fast delegate C++ for Urus SHAL for backward compatibilities with APM 2.x Boards.

-   What do you could do with it?

    Well, this is used in the heart of Ardupilot hardware abstraction layer to store functions in pointers with posibilities to execute them anywhere on your program.

This was implemented on the master-AVR branch from Ardupilot, but since Intel come in to Ardupilot, the guys began to rewrite and port it and the rest of the code with owned code and this original code was removed from this point:

https://github.com/ArduPilot/ardupilot/commit/4dd47ead0e6565b5ac9c001f294b868d8a50129d

https://github.com/UrusTeam/URUS/commit/4dd47ead0e6565b5ac9c001f294b868d8a50129d

Fast Delegate now is performed by Intel and it called functor into the main Ardupilot HAL. The new implemantation build produces about 0.1% - 0.2% less size than the original.

The code was developed by an Australian Engineer, Don Clugston (i don't know if he known that his code was used in ardupilot). You could see his profile on the provided link at top of this readme.

Thanks a lot Mr. Don!

# Building

There are three builds, one build maintain the original source and produce the default options and the second build produces our customized implementations, and the third is the test.

# On Win32
You need to have installed Cygwin https://www.cygwin.com/ or Msys2 http://www.msys2.org/ with gcc toolchain, git tools and cmake build system. (Cygwin and Msys are Posix/Unix compliant for Windows.)
Once you have allready installed the tools proceed with these steps in the terminal:

$ git clone https://github.com/UrusTeam/FunctorDelegateCXX.git

$ sh build.sh

# On Ubuntu/Debian
open the terminal:

$ sudo apt-get install gcc git cmake

$ git clone https://github.com/UrusTeam/FunctorDelegateCXX.git

$ sh build.sh


# On MacOS/Darwin
On MacOS you need to have installed XCode, on Sierra and later you can download it typing gcc command and you will prompted for download:

$ gcc

after it install macports https://www.macports.org/install.php
Once you have allready installed the tools proceed with these steps in the terminal:

$ git clone https://github.com/UrusTeam/FunctorDelegateCXX.git

$ sh build.sh

# Use and Run test

The build produce two header files in the root of this build.sh. FastFunctor.h is for use in Urus SHAL and FastDelegate.h is for research and test purposes.

If you want to produce more input arguments then you could give count arguments as option to the script:

$ sh build.sh [count]

The binaries is installed on install path dir, you will see the test there.

----------------------

Have a fun!

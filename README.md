# newton_cpp

[![Build Status](https://travis-ci.org/Null0rg/newton.svg?branch=master)](https://travis-ci.org/Null0rg/newton)
[![Build status](https://ci.appveyor.com/api/projects/status/2mqf5pdncf45i5c1?svg=true)](https://ci.appveyor.com/project/miho/newton-cpp)

This project is for teaching purposes only. It features an immature C++-based implementation of the well known [Newton Method](https://en.wikipedia.org/wiki/Newton%27s_method) and demonstrates how to write unit tests for it.

## How To Build and Test

### Requirements

- C+\+ compiler with C+\+11 support (tested with Clang, GCC, MSVC+\+ 2017 on x64)
- CMake >= 3.5
- make (only on Unix/Linux)
- MSBuild.exe (only on Windows, usually comes with MSVC+\+)

#### Bash (Linux/macOS/Cygwin/other Unix-like Shell)

    cd /path/to/project
    mkdir build && cd build
    cmake .. && make && make test
    
#### Windows (CMD)

    "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\vsdevcmd" -arch=x64
    cd \path\to\project
    mkdir build
    cd build
    cmake ..
    MSBuild.exe .\newton_test.vcxproj
    MSBuild.exe .\RUN_TESTS.vcxproj

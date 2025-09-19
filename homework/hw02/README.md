# HW02

## Project Structure
```
.
├── CMakeLists.txt
├── include/
│   └── functionPrime.h
└── src/
    ├── main_hw2.cc
    └── functionPrime.cpp
```

## Build Instructions

### Linux / macOS (tested on Ubuntu 24.04)
```
# Configure the project
cmake -S . -B build

# Build the executable
cmake --build build

# Run it
./build/hw02
```

### Windows (with CMake + Visual Studio or MSVC)
```
# Configure
cmake -S . -B build

# Build (Release configuration)
cmake --build build --config Release

# Run
.\build\Release\hw02.exe
```

> ⚠️ Requires **CMake ≥ 3.10** and a C++17 compiler (e.g., g++, clang++, MSVC).

# HW04

## Project Structure

```
.
├── CMakeLists.txt
├── include/
└── src/
    ├── main.cpp
```

## Build Instructions

### Linux / macOS (tested on Ubuntu 24.04)

```
# Configure the project
cmake -S . -B build

# Build the executable
cmake --build build

# Run it
./build/hw04
```

#### Build and Run

```
cmake -S . -B build && cmake --build build && ./build/hw04
```

#### Debug

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

### Windows (with CMake + Visual Studio or MSVC)

```
# Configure
cmake -S . -B build

# Build (Release configuration)
cmake --build build --config Release

# Run
.\build\Release\hw04.exe
```

> ⚠️ Requires **CMake ≥ 3.10** and a C++17 compiler (e.g., g++, clang++, MSVC).

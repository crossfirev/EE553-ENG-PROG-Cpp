# HW01

## Project Layout

```
.
└── homework/
    └── hw01/
        ├── include/
        ├── src/
        │   └── main_hw01.cpp
        └── CMakeLists.txt
```

The executable will be created in `homework/hw01/build/` and will be named `hw01`.

---

## Build & Run

### Option A: VS Code (repo root, with .vscode/tasks.json .vscode/launch.json)

From the repo root (`EE553-ENG-PROG-Cpp/`):

- **Run:** `Tasks: Run Task → run: hw01`
- **Debug:** pick **Debug hw01** and press **F5**

### Option B: CMake CLI (inside `homework/hw01`)

```
cd homework/hw01

# Configure (Debug by default)
cmake -S . -B build

# Build
cmake --build build

# Run
./build/hw01
```

One-liner:

```
cd homework/hw01 && cmake -S . -B build && cmake --build build && ./build/hw01 cd ../..
```

**Switch build type** (optional):

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Windows (MSVC)

```
cd homework\hw01
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\hw01.exe
```

> Requires **CMake ≥ 3.23** and a C++17 compiler (g++, clang++, or MSVC).

---

## Minimal “No-CMake” Build (for quick tests)

Sometimes you just want to compile without any CMake configuration.

### Linux / macOS / WSL

```
cd homework/hw01
g++ -std=c++17 -Wall -Wextra -Wpedantic -I include src/*.cpp -o hw01
./hw01
```

### Windows (MSVC `cl`)

```
cd homework\hw01
cl /std:c++17 /W4 /EHsc /I include src\*.cpp /Fehw01.exe
.\hw01.exe
```

> ⚠️ This bypasses CMake completely. Use only for quick builds; it won’t include future options/libs defined in CMake.

---

## Clean

```
# From homework/hw01
rm -rf build
# Windows
rmdir /s /q build
```

---

## Notes

- The target name = folder name (`hw01` → `hw01` binary).
- Keep `.cpp` files in `src/` and headers in `include/`.

# HW02

## Project Layout

```
.
└── homework/
    └── hw02/
        ├── include/
        ├── src/
        │   └── main_hw01.cpp
        ├── CMakeLists.txt
        └── robotpath.dat
```

The executable will be created in `homework/hw02/build/` and will be named `hw02`.

---

## Build & Run

### Option A: VS Code (repo root, with .vscode/tasks.json .vscode/launch.json)

From the repo root (`EE553-ENG-PROG-Cpp/`):

- **Run:** `Tasks: Run Task → run: hw02`
- **Debug:** pick **Debug hw02** and press **F5**

### Option B: CMake CLI (inside `homework/hw02`)

```
cd homework/hw02

# Configure (Debug by default)
cmake -S . -B build

# Build
cmake --build build

# Run
./build/hw02
```

One-liner:

```
cd homework/hw02 && cmake -S . -B build && cmake --build build && ./build/hw02 cd ../..
```

**Switch build type** (optional):

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Windows (MSVC)

```
cd homework\hw02
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\hw02.exe
```

> Requires **CMake ≥ 3.23** and a C++17 compiler (g++, clang++, or MSVC).

---

## Minimal “No-CMake” Build (for quick tests)

Sometimes you just want to compile without any CMake configuration.

### Linux / macOS / WSL

```
cd homework/hw02
g++ -std=c++17 -Wall -Wextra -Wpedantic -I include src/*.cpp -o hw02
./hw02
```

### Windows (MSVC `cl`)

```
cd homework\hw02
cl /std:c++17 /W4 /EHsc /I include src\*.cpp /Fehw01.exe
.\hw02.exe
```

> ⚠️ This bypasses CMake completely. Use only for quick builds; it won’t include future options/libs defined in CMake.

---

## Clean

```
# From homework/hw02
rm -rf build
# Windows
rmdir /s /q build
```

---

## Notes

- The target name = folder name (`hw02` → `hw02` binary).
- Keep `.cpp` files in `src/` and headers in `include/`.

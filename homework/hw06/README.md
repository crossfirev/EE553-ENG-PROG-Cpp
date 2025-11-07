# HW06

## Project Layout

```
.
└── homework/
    └── hw06/
        ├── include/
        ├── src/
        │   └── main_hw01.cpp
        └── CMakeLists.txt
```

The executable will be created in `homework/hw06/build/` and will be named `hw06`.

---

## Build & Run

### Option A: VS Code (repo root, with .vscode/tasks.json .vscode/launch.json)

From the repo root (`EE553-ENG-PROG-Cpp/`):

- **Run:** `Tasks: Run Task → run: hw06`
- **Debug:** pick **Debug hw06** and press **F5**

### Option B: CMake CLI (inside `homework/hw06`)

```
cd homework/hw06

# Configure (Debug by default)
cmake -S . -B build

# Build
cmake --build build

# Run
./build/hw06
```

One-liner:

```
cd homework/hw06 && cmake -S . -B build && cmake --build build && ./build/hw06 cd ../..
```

**Switch build type** (optional):

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Windows (MSVC)

```
cd homework\hw06
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\hw06.exe
```

> Requires **CMake ≥ 3.23** and a C++17 compiler (g++, clang++, or MSVC).

---

## Minimal “No-CMake” Build (for quick tests)

Sometimes you just want to compile without any CMake configuration.

### Linux / macOS / WSL

```
cd homework/hw06
g++ -std=c++17 -Wall -Wextra -Wpedantic -I include src/*.cpp -o hw06
./hw06
```

### Windows (MSVC `cl`)

```
cd homework\hw06
cl /std:c++17 /W4 /EHsc /I include src\*.cpp /Fehw01.exe
.\hw06.exe
```

> ⚠️ This bypasses CMake completely. Use only for quick builds; it won’t include future options/libs defined in CMake.

---

## Clean

```
# From homework/hw06
rm -rf build
# Windows
rmdir /s /q build
```

---

## Notes

- The target name = folder name (`hw06` → `hw06` binary).
- Keep `.cpp` files in `src/` and headers in `include/`.

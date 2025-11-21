# HW07

## Project Layout

```
.
└── homework/
    └── hw07/
        ├── include/
        ├── src/
        │   └── main_hw01.cpp
        └── CMakeLists.txt
```

The executable will be created in `homework/hw07/build/` and will be named `hw07`.

---

## Build & Run

### Option A: VS Code (repo root, with .vscode/tasks.json .vscode/launch.json)

From the repo root (`EE553-ENG-PROG-Cpp/`):

- **Run:** `Tasks: Run Task → run: hw07`
- **Debug:** pick **Debug hw07** and press **F5**

### Option B: CMake CLI (inside `homework/hw07`)

```
cd homework/hw07

# Configure (Debug by default)
cmake -S . -B build

# Build
cmake --build build

# Run
./build/hw07
```

One-liner:

```
cd homework/hw07 && cmake -S . -B build && cmake --build build && ./build/hw07 cd ../..
```

**Switch build type** (optional):

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Windows (MSVC)

```
cd homework\hw07
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\hw07.exe
```

> Requires **CMake ≥ 3.23** and a C++17 compiler (g++, clang++, or MSVC).

---

## Minimal “No-CMake” Build (for quick tests)

Sometimes you just want to compile without any CMake configuration.

### Linux / macOS / WSL

```
cd homework/hw07
g++ -std=c++17 -Wall -Wextra -Wpedantic -I include src/*.cpp -o hw07
./hw07
```

### Windows (MSVC `cl`)

```
cd homework\hw07
cl /std:c++17 /W4 /EHsc /I include src\*.cpp /Fehw01.exe
.\hw07.exe
```

> ⚠️ This bypasses CMake completely. Use only for quick builds; it won’t include future options/libs defined in CMake.

---

## Clean

```
# From homework/hw07
rm -rf build
# Windows
rmdir /s /q build
```

---

## Notes

- The target name = folder name (`hw07` → `hw07` binary).
- Keep `.cpp` files in `src/` and headers in `include/`.

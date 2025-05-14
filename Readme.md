# Valkron Engine

The goal of this project is to learn about how Game Engines work and how they are made.

#### Mainly i follow [The Cherno's Game Engine series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) as i think it is a good starting point.

This project includes:
- [GLFW](https://github.com/glfw/glfw) for Windowing in Windows
- [spdlog](https://github.com/gabime/spdlog) a very fast logging library

## Setup

### Currently this project only supports Windows

### Prerequisites

- C++23 compatible compiler (MSVC, Clang, GCC) **NOTE: Clang not tested**
- CMake 3.31 or newer
- Git

### Cloning the Repository

Clone with submodules to get spdlog and glfw:

```sh
cd Valkron
git clone --recurse-submodules https://github.com/filipgaming008/Valkron.git
```

If you forgot `--recurse-submodules`, run:

```sh
git submodule update --init --recursive
```

### Building the Engine

#### Build Valkron only
```sh
cd Valkron/Valkron
cmake -S . -B build
cmake --build build
```

#### Build the Sandbox application - (Valkron must be built first)
```sh
cd Valkron/Sandbox
cmake -S . -B build
cmake --build build
```

#### Build everything from the root
```sh
cd Valkron
cmake -S . -B build
cmake --build build
```
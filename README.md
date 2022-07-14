# Project Name

Short description

## About

Detailed description

# Getting Started

If you are new here, please read the [contribution](./.github/contributing.md) documentation.

To enable C++ CMake CI, ensure `build_cmake.yml` and `cmake_config.json` files are present. Information about pipeline setup can be found in [templ-cmake](https://github.com/HInfinity/templ-cmake/blob/main/.github/ci.md).

## Requirements

- Project requirements for development and release

## Project Layout

```
├── .github
├── .vscode
├── assets
├── build
├── cmake
│   ├── Linter.cmake
│   └── ProjectCPack.cmake
├── install
│   └── install.sh
├── licenses
│   └── external.txt
├── packages
│   └── project.deb
├── project
│   ├── configs
│   │   └── example.json
│   ├── include
│   │   ├── external
│   │   |    └── ExternalExample.hpp
│   │   ├── interface
│   │   |    └── InterfaceExample.hpp
│   │   └── internal
│   │        └── InternalExample.hpp
│   ├── lib
│   │   ├── arm64
│   │   |    └── example.so.1.0.0
│   │   └── x86_64
│   │        ├── example.so
│   │        └── example.so.1.0.0
│   ├── log
│   │   └── example.txt
│   └── src
│   │   └── Example.cpp
├── scripts
│   ├── arm64
│   │   └── example.sh
│   └── x86_64
│       └── example.sh
├── test
│   └── test.cpp
├── .clang-format
├── .clang-tidy
├── .gitignore
├── CPPLINT.cfg
├── README.md
└── workspace.code-workspace

```

## Installation

1. Install development dependencies:

```sh
 dependencies to install
```

# Usage

1. Open `workspace.code-workspace` in vscode

2. Open a new terminal and enter the following:

```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j8
```

3. Navigate to `build/bin/arm64` or `build/bin/armv7l` or `build/bin/x86_64` and run the software

```sh
cd ./build/bin/x86_64
./ProjectName
```

## Debugging

1. GDB - primary debugger for C++ projects

```sh
cd ./build/bin/x86_64
gdb ./ProjectName
```

- run - to start the application
- quit - to quit GDB
- bt - backtrace
- thread apply all bt - show backtrace from all threads

2. valgrind - memory management software

## Deployment

1. Update software version

- Open `cmake/project-cpack.cmake` and update CPACK_PACKAGE_VERSION.

2. Build .DEB package

```sh
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j8
cpack
```

3. Navigate to `install/` and update the script if required

4. Navigate to `packages/` and locate the newly build debian package

5. Ensure ProjectName.deb packages are present

6. ...

## FAQ

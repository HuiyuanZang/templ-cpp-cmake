# Continuous Integration

Information about CI runners can be found in [templ-com-doc](https://github.com/HInfinity/templ-com-doc/tree/main/CI/ci_runners.md).

This document might be outdated, please navigate to [templ-cmake](https://github.com/HInfinity/templ-cmake/blob/main/.github/ci.md) to ensure the latest information is provided.

## Using GitHub Actions for CI

1. Create and copy a new Personal Access Token (PAT)
2. Add the PAT value to the repository which requires CI builds located under `Settings/Secrets/Actions/Repository secrets/`
3. Name the new secret _REPO_TOKEN_.

## Build Matrix

Build matrix configuration is performed through [cmake_config.json](./workflows/cmake_config.json).

The matrix allows to choose:

- GitHub-hosted or self-hosted runners
- C and C++ compilers
- Dependencies to be installed when running GitHub Actions
- CMake flags to be passed to Build and Test steps of the CI process
- Upload built artifacts to GitHub

### Examples

It is possible to choose any combination of the runners from the examples below; however, you have to ensure that the artifact names are unique within the build matrix to not overwrite them.

Cross-compile for ARM64 with GCC and Android 24 with Clang:

Note: one disadvantage of cross-compilation is the inability to run automated testing.

```json
{
  "config": [
    {
      "name": "Android 24 Clang",
      "artifact": "android-24-arm64",
      "artifact_extension": "",
      "os": ["self-hosted", "Linux", "X64"],
      "cc": "clang",
      "cxx": "clang++",
      "dependencies": "sudo apt-get install -y ccache ninja-build pkg-config",
      "cmake_flags": "-DCROSS_COMPILE=ANDROID"
    },
    {
      "name": "ARM64 Ubuntu 18.04 GCC",
      "artifact": "linux-arm64",
      "artifact_extension": "",
      "os": ["self-hosted", "Linux", "X64"],
      "cc": "gcc",
      "cxx": "g++",
      "dependencies": "sudo apt-get install -y ccache ninja-build pkg-config gcc-aarch64-linux-gnu g++-aarch64-linux-gnu",
      "cmake_flags": "-DCROSS_COMPILE=ARM64 -DARM_TOOLCHAIN_DIR=/usr/bin/"
    }
  ]
}
```

Build on a self-hosted ARM64 runner (Jetson Nano):

```json
{
  "config": [
    {
      "name": "ARM64 Ubuntu 18.04 GCC",
      "artifact": "linux-arm64",
      "artifact_extension": "",
      "os": ["self-hosted", "Linux", "ARM64"],
      "cc": "gcc",
      "cxx": "g++",
      "dependencies": "sudo apt-get install -y ccache",
      "cmake_flags": ""
    }
  ]
}
```

Build on a self-hosted Windows 10 x64 runner:

```json
{
  "config": [
    {
      "name": "Windows 10 MSVC",
      "artifact": "win-x64",
      "artifact_extension": "",
      "os": ["self-hosted", "Windows", "X64"],
      "cc": "cl",
      "cxx": "cl",
      "environment_script": "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Auxiliary/Build/vcvars64.bat",
      "dependencies": "",
      "cmake_flags": ""
    }
  ]
}
```

Build on a self-hosted Linux Ubuntu 18.04 x64 runner:

```json
{
  "config": [
    {
      "name": "Ubuntu 18.04 GCC",
      "artifact": "linux-18.04-x64",
      "artifact_extension": "",
      "os": ["self-hosted", "Linux", "X64"],
      "cc": "gcc",
      "cxx": "g++",
      "dependencies": "sudo apt-get install -y ccache ninja-build pkg-config",
      "cmake_flags": ""
    }
  ]
}
```

Example build of a .deb package on a self-hosted Linux Ubuntu 18.04 x64 runner:

```json
{
  "config": [
    {
      "name": "Ubuntu 18.04 GCC",
      "artifact": "linux-18.04-x64",
      "artifact_extension": "deb",
      "os": ["self-hosted", "Linux", "X64"],
      "cc": "gcc",
      "cxx": "g++",
      "dependencies": "sudo apt-get install -y ccache ninja-build pkg-config",
      "cmake_flags": ""
    }
  ]
}
```

Build on runners hosted by GitHub for the three major operating systems(Windows, Linux and MacOS):

Note: Using GitHub hosted runners is not advised as there is a limited number of minutes available per month.

```json
{
  "config": [
    {
      "name": "Windows Latest MSVC",
      "artifact": "win-x64",
      "artifact_extension": "",
      "os": "windows-latest",
      "cc": "cl",
      "cxx": "cl",
      "environment_script": "C:/Program Files/Microsoft Visual Studio/2022/Enterprise/VC/Auxiliary/Build/vcvars64.bat",
      "dependencies": "",
      "cmake_flags": ""
    },
    {
      "name": "Ubuntu 18.04 GCC",
      "artifact": "linux-18.04-x64",
      "artifact_extension": "",
      "os": "ubuntu-18.04",
      "cc": "gcc",
      "cxx": "g++",
      "dependencies": "sudo apt-get install -y ccache ninja-build pkg-config",
      "cmake_flags": ""
    },
    {
      "name": "macOS Latest Clang",
      "artifact": "macos",
      "artifact_extension": "",
      "os": "macos-latest",
      "cc": "clang",
      "cxx": "clang++",
      "dependencies": "HOMEBREW_NO_AUTO_UPDATE=1 HOMEBREW_NO_INSTALL_CLEANUP=1 brew install ninja pkg-config",
      "cmake_flags": ""
    }
  ]
}
```

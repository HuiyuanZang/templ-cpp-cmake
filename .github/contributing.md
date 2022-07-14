# Contributing to C++ projects owned by [Harvest Technology Group](https://harvest.technology)

Harvest Technology Group requires each developer to follow the standards defined in [Version Control Procedure](https://www.dropbox.com/home/888-BMS/TEC/PRO%20-%20Procedure) and [Coding Standard](https://www.dropbox.com/home/888-BMS/TEC/STD%20-%20Standard) located in Dropbox.

## Development Environment

Please use [Visual Studio Code](https://code.visualstudio.com/) to contribute to this project.
Opening the project must be done through `workspace.code-workspace` because it allows to apply the configurations within the IDE.
When opening the project for the first time please install the recommended extensions to improve the experience vscode provides.

Useful setup instructions:
https://steelph0enix.github.io/posts/vscode-cpp-setup/

### Testing

[Google Test Framework](https://github.com/google/googletest) is the testing framework used for C++ projects. templ-cmake provides the setup required to download, install and test manually and as a part of the CI process within GitHub.

### Linting and Formatting

It is important to ensure that the following configuration files exist within the root directory of the repository:

- .clang-format
- .clang-tidy
- CPPLINT.cfg
- cmake/Linter.cmake (Make sure you include the following in your CMakeLists.txt to trigger linting and formatting)
  ```CMake
  include(cmake/linter.cmake)
  ```

For development environments to operate correctly you need to install the following tools:

- Clang-Format - allows to format C++ code based on .clang-format file. Some of the formatting options include indentation, pointer alignment, whitespace configuration, aligning variable names and values within a file and other (https://clang.llvm.org/docs/ClangFormatStyleOptions.html).
- Clang-Tidy - C++ linter which provides static analysis, including naming conventions, nullptr use and other (https://clang.llvm.org/extra/clang-tidy/).
- cpplint - C++ linter created by Google which follows Google C++ standards (https://github.com/cpplint/cpplint).
- cppcheck - linter which focuses on undefined behaviour and security vulnerabilities (https://cppcheck.sourceforge.io/).
- Python

You can specify files and directories which need to be excluded from linting by manually adding them to `CMakeLists.txt` file or when running CMake from cli by listing them using a comma separator:

```sh
cmake .. -DEXCLUDE_DIRECTORIES=./test -DEXCLUDE_FILES=./src/ExampleFile.cpp,./include/internal/ExampleFile.hpp
```

It is also possible to run custom build targets which allow to check for syntax errors and styling issues as well as fix primitive linting errors:

- Build with clang-tidy, cppcheck and cpplint enabled: `make`.
- Build with only cpplint enabled: `make cpplint`.
- Build with only cppcheck enabled: `make cppcheck`.
- Build with only clang-tidy enabled which applies fixes based on static syntax evaluation: `make tidy`.
- Build with only clang-format enabled which applies styling fixes: `make format`.
- Build with no linting: `cmake .. -DNOLINT=1`

### Linux

```sh
sudo apt-get install -y clang-format-10 clang-tidy-10 cppcheck python3-pip python3.6 ninja-build
pip3 install cpplint cmake_format
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-10 100
sudo update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-10 100
```

If vscode complains about clangd server missing on a Linux machine, use the command below and restart vscode after:

```sh
sudo apt-get install clangd-9 && sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-9 100
```

Install the latest [CMake](https://cmake.org/download/).

```sh
 sudo apt remove cmake; cd ~/Downloads; wget https://github.com/Kitware/CMake/releases/download/v3.23.1/cmake-3.23.1.tar.gz && tar -xvf cmake-3.23.1.tar.gz && cd cmake-3.23.1 && ./configure && make && sudo make install
```

### MacOS

```sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

brew install clang-format coreutils cppcheck python llvm

pip3 install cpplint cmake_format

ln -s "$(brew --prefix llvm)/bin/clang-format" "/usr/local/bin/clang-format"
ln -s "$(brew --prefix llvm)/bin/clang-tidy" "/usr/local/bin/clang-tidy"
ln -s "$(brew --prefix llvm)/bin/clang-apply-replacements" "/usr/local/bin/clang-apply-replacements"
```

### Windows PowerShell

Run as Administrator

```PowerShell
cd "$HOME\Downloads"
Invoke-WebRequest -OutFile cmake-3.23.0-windows-x86_64.msi -Uri https://github.com/Kitware/CMake/releases/download/v3.23.0/cmake-3.23.0-windows-x86_64.msi
msiexec /i "cmake-3.23.0-windows-x86_64.msi"

Invoke-WebRequest -OutFile cppcheck-2.7-x64.msi -Uri https://github.com/danmar/cppcheck/releases/download/2.7/cppcheck-2.7-x64-Setup.msi
msiexec /i "cppcheck-2.7-x64.msi"

pip install cpplint cmake_format
```

## File and Directory Naming

- C++ files must use PascalCase and be named after the main class inside the file unless it is the entry(main) file.
- Directories must use camelCase
- C++ header files must use .hpp extension and source files must use .cpp

## Pull Requests

### How to Send Pull Requests

Check out a new branch, make modifications and push the branch:

```sh
$ git checkout -b feature/name-of-feature
# edit files
$ git commit
$ git push --set-upstream origin feature/name-of-feature
```

Open a pull request against the develop or main branch within the repo.

### How to Receive Comments

- If the PR is not ready for review, please mark it as
  [`draft`](https://github.blog/2019-02-14-introducing-draft-pull-requests/).
- Make sure CLA is signed and all required CI checks are clear.
- Submit small, focused PRs addressing a single
  concern/issue.
- Make sure the PR title reflects the contribution.
- Write a summary that helps understand the change.
- Include usage examples in the summary, where applicable.
- Include benchmarks (before/after) in the summary, for contributions that are
  performance enhancements.
- Make sure generated files are not included in pull requests.

### How to Get PRs Merged

A PR is considered to be **ready to merge** when:

- It has received approval from at least one other contributor.
- All feedbacks are resolved.
- Urgent fixes can take exception as long as they have been actively communicated.

Any Maintainer can merge the PR once it is **ready to merge**. Note, that some
PRs may not be merged immediately if the repo is in the process of a release and
the maintainers decided to defer the PR to the next release train.

**Always merge pull requests by squashing commits into one**.

Remember that CMake project structure is an evolving specification.
If you have any suggestions regarding the structure, formatting or linting please navigate to [Template CMake Project](https://github.com/HInfinity/templ-cmake/issues) and create an issue for it.

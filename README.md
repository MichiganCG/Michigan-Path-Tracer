# Michigan Path Tracer
The physically based path tracing software built by [MCG](MichiganCG.org)!

### Build
This project is currently pretty empty, after satisfying the prerequisite below, you can build and run it using a proper IDE (CLion highly recommended!) that supports CMake, or the following commands:
```shell
# assuming you have successfully cloned from git
# and your current directory is just inside the repo
mkdir build && cd build
cmake ..
cmake --build .
# now there should be an executable called `mpt`, that is your build!
```

### Prerequisite
- Any compiler that supports C++ 20 (e.g. `gcc` or `clang`)
- CMake 3.26 or above (download using `apt` or [here](https://cmake.org/download/))

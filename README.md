# Convenient Timers

This is a repo that holds a simple timer class meant to be inherited by future simulations.

## Installation instructions using CMake

To work with this library, clone this directory and issue the following commands:

```bash
cd <Timer Dir>  # The src's parent
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=<Where you want the installation to go> ..
cmake --build . 
cmake --install . 
```

From this point, all one needs to do is include `find_package()` and `target_link_libraries()` in their CMake project. For example, suppose the project is named `Clock`, then a minimal `CMakeLists.txt` might look like this

```cmake
cmake_minimum_required(VERSION 3.0)
project(Clock)

find_package(TimerBase REQUIRED)

add_executable(clock main.cpp)

target_link_libraries(clock PUBLIC TimerBase::timer_base)
```

Then the `main.cpp` file might look like

```cpp
#include <timer_base.hpp>

// ...
// Include Clock headers
// ...

int main(int argc, char * argv [])
{
    Timers::Timer my_timer = Timers::Timer();
    my_timer.print_time(true);
    // ...
    // Clock stuff
    // ...
    return 0;
}
```

With this, one then should execute the following commands in the `Clock` directory to build the software with the `TimerBase` imported library.

```bash
mkdir clock_build
cd clock_build
cmake -DCMAKE_PREFIX_PATH=<TimerBase Install Destination> ..
cmake --build . 
```

Note: the instructions above follows [those found here](https://cmake.org/cmake/help/git-stage/guide/importing-exporting/index.html#exporting-targets) quite closely.
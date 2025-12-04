# C++ / CMake / Ninja – Quick Reference

Project layout (this repo)
--------------------------

- **Source dir:** `./`
- **Build dir:** `./build`
- **Binary:** `./build/hello_ninja`


## Configure & build

**Normal configure (Release-ish by default):**

```bash
cmake -S . -B build -G Ninja

Debug configure (with -g, better for gdb):

cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug

Build with Ninja (after configure):

cmake --build build

Clean build directory completely:

rm -rf build

Clean using Ninja (if build already exists):

ninja -C build clean

Run the program

From project root:

./build/hello_ninja

One-off compile without CMake (quick tests)

Not the main workflow, just handy sometimes:

g++ -std=c++17 -Wall -Wextra -Wpedantic -g main.cpp -o main
./main

Debugging with gdb (terminal)

Start debugger on the built binary:

gdb ./build/hello_ninja

Inside gdb:

break main      # set breakpoint at main()
run             # run program
next / step     # step over / into
print sum       # show variable
bt              # backtrace (call stack)
quit            # exit gdb

VS Code (Remote SSH) workflow

    Edit code in VS Code (connected to SSH: pi400).

    Build:

Ctrl + Shift + B

Runs CMake + Ninja via tasks.json.

Debug:

    F5

    Launches the Debug hello_ninja configuration.

    If behavior doesn’t match the code you see, you almost certainly forgot to rebuild.
    C++ is not like Next.js: EDIT → BUILD → RUN/DEBUG.

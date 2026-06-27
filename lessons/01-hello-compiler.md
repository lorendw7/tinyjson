# Lesson 01 — Hello, compiler

## Goal

Prove your C++ toolchain works and understand the skeleton that every C++
program shares.

## The code

See [`src/main.cpp`](../src/main.cpp).

```cpp
#include <iostream>

int main() {
    std::cout << "tinyjson: toolchain OK" << std::endl;
    return 0;
}
```

## Line by line

- `#include <iostream>` — a *preprocessor directive*. Before compilation, it
  pastes in the declarations for input/output streams, giving us `std::cout`.
- `int main()` — the function the program starts from. `int` is its return
  type; the empty `()` means it takes no arguments.
- `{ ... }` — a *block*; the body of the function.
- `std::cout << "..."` — send text to standard output. `std::` is the
  namespace of the standard library. `<<` is the stream-insertion operator.
- `std::endl` — write a newline and flush the buffer.
- `return 0;` — hand control back to the OS with a success code.

## Build & run

```sh
g++ -std=c++20 -Wall -Wextra src/main.cpp -o tinyjson
./tinyjson
```

Expected output:

```
tinyjson: toolchain OK
```

`-std=c++17` picks the language version, `-Wall -Wextra` turn on helpful
warnings. Get used to running with warnings on from day one.

## Next

Lesson 02: how do we represent a JSON value in C++ memory?

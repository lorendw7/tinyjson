# tinyjson — Learn C++ from Scratch by Building a Mini JSON Interpreter

A hands-on, bilingual (中文 / English) course. We build a small JSON parser
step by step, and every single line of C++ is explained. No prior C++
knowledge is assumed — we start from `main()` and grow toward a real recursive
descent parser.

## Why JSON?

JSON is small enough to understand in full, yet it exercises almost every core
C++ skill you need:

- value types, `enum class`, and `std::variant`
- strings, `std::string_view`, containers (`std::vector`, `std::map`)
- classes, constructors, and value semantics
- references, ownership, move semantics, and RAII
- recursion
- error handling (`std::optional`, exceptions, a hand-rolled `Result`)
- templates and C++20 concepts

## Target standard

We build with **C++20** (`-std=c++20`), the most modern standard fully
supported by the course toolchain (g++ 11.4). Each lesson calls out which
standard a feature comes from, so you learn the timeline too: C++17 gave us
`std::variant` / `std::optional` / `std::string_view` / `std::from_chars`;
C++20 gave us concepts, ranges, and the spaceship operator `<=>`.

## Course Roadmap

The roadmap is split into two arcs. **Arc 1 (01–07)** builds a working parser
with the simplest design that teaches the fundamentals. **Arc 2 (08–14)** then
*refactors* that working code into idiomatic modern C++ — the most valuable
skill of all is improving code you already understand.

### Arc 1 — Build a working parser

| Lesson | Topic | C++ concepts |
| ------ | ----- | ------------ |
| 01 | Hello, compiler | `main`, `#include`, `std::cout`, build & run |
| 02 | Representing a JSON value | `enum class`, `struct`, default member init, `using` aliases, forward declaration |
| 03 | The tokenizer (lexer) | `std::string_view`, loops, `switch`, token enums |
| 04 | Parsing literals | functions, `std::optional`, `std::from_chars`, `bool`/`null`/numbers |
| 05 | Parsing strings | escape handling, building a `std::string` char-by-char |
| 06 | Parsing arrays | `std::vector`, recursion, `emplace_back`, moving into containers |
| 07 | Parsing objects | `std::map`, structured bindings, key/value |

### Arc 2 — Refactor into modern C++

| Lesson | Topic | C++ concepts |
| ------ | ----- | ------------ |
| 08 | Replace the tagged struct | `std::variant`, `std::visit`, the overload pattern |
| 09 | Ownership & memory | value semantics, copy vs move, move constructors, RAII, why recursion needs the heap |
| 10 | const-correctness & references | `const&` params, value vs reference, accessors that don't copy |
| 11 | Serializing back to text | `std::ostream`, recursion, `std::visit` with overloaded lambdas |
| 12 | Error handling | exceptions vs a `Result<T>` type, error codes, `std::optional` revisited |
| 13 | Templates & concepts | function templates, a generic `get<T>()`, C++20 `concept`/`requires` |
| 14 | Tests & polish | a tiny assertion harness, edge cases, RAII for resources |

## Layout

```
tinyjson/
├── README.md        # this file
├── lessons/         # one markdown note per lesson (English)
├── src/             # the growing source code
└── tests/           # small test programs
```

## Build

```sh
g++ -std=c++20 -Wall -Wextra src/main.cpp -o tinyjson
./tinyjson
```

## How this course is taught

Each lesson is delivered in the chat in a bilingual format: a Chinese
explanation followed by the English equivalent, then the exact code, then a
line-by-line walkthrough. The committed code and the `lessons/` notes are the
permanent record. English is used for all written documentation and code
comments.

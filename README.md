# tinyjson — Learn C++ from Scratch by Building a Mini JSON Interpreter

A hands-on, bilingual (中文 / English) course. We build a small JSON parser
step by step, and every single line of C++ is explained. No prior C++
knowledge is assumed — we start from `main()` and grow toward a real recursive
descent parser.

## Why JSON?

JSON is small enough to understand in full, yet it exercises almost every core
C++ skill you need:

- value types and `enum`
- strings, containers (`std::vector`, `std::map`)
- classes and constructors
- pointers, references, and ownership
- recursion
- error handling

## Course Roadmap

| Lesson | Topic | C++ concepts |
| ------ | ----- | ------------ |
| 01 | Hello, compiler | `main`, `#include`, `std::cout`, build & run |
| 02 | Representing a JSON value | `enum class`, `struct`, types |
| 03 | The tokenizer (lexer) | `std::string`, loops, `switch` |
| 04 | Parsing literals | functions, `bool`/`null`/numbers |
| 05 | Parsing strings | escape handling, `std::string` building |
| 06 | Parsing arrays | `std::vector`, recursion |
| 07 | Parsing objects | `std::map`, key/value |
| 08 | Putting it together | a full `parse()` entry point |
| 09 | Serializing back to text | `std::ostream`, recursion again |
| 10 | Errors & polish | exceptions, edge cases, tests |

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
g++ -std=c++17 -Wall -Wextra src/main.cpp -o tinyjson
./tinyjson
```

## How this course is taught

Each lesson is delivered in the chat in a bilingual format: a Chinese
explanation followed by the English equivalent, then the exact code, then a
line-by-line walkthrough. The committed code and the `lessons/` notes are the
permanent record. English is used for all written documentation and code
comments.

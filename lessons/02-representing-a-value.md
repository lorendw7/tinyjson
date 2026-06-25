# Lesson 02 — Representing a JSON value

## Goal

Design the in-memory type that can hold *any* JSON value, before writing a
parser. A parser is just "text → this type", so we need the type first.

## The six shapes of JSON

`null`, `true/false`, number, string, array, object. A value is exactly one
of these at a time. The classic C++ way to model "one of several" is a **type
tag** (an `enum class`) plus storage.

## Key ideas

### `enum class Type`

```cpp
enum class Type { Null, Boolean, Number, String, Array, Object };
```

A scoped enumeration. You write `Type::Number`, not just `Number`, so names
don't collide. Unlike a plain `enum`, it does not implicitly convert to `int`.

### Recursion needs a forward declaration

JSON arrays hold JSON values, so `Value` refers to itself indirectly:

```cpp
struct Value;                                 // "this name exists"
using Array  = std::vector<Value>;
using Object = std::map<std::string, Value>;
struct Value { /* ... uses Array, Object ... */ };
```

We *declare* `Value` first so `Array`/`Object` can name it, then *define* it.

### `using` aliases

`using Array = std::vector<Value>;` makes a readable alias. `std::vector` is a
growable array; `std::map<std::string, Value>` is a sorted key→value table.

### One-field-per-shape (for now)

`Value` keeps every field side by side and uses `type` to say which one is
valid. It is wasteful but maximally clear. Lesson 08+ replaces it with
`std::variant`.

## Build & run

```sh
g++ -std=c++17 -Wall -Wextra src/main.cpp -o tinyjson && ./tinyjson
```

Expected:

```
root is an object with 3 keys
tags has 2 elements
```

We constructed `{ "name": "tiny", "stars": 5, "tags": [true, null] }`
entirely by hand — proof the data model works.

## Next

Lesson 03: the tokenizer — chopping raw text into tokens.

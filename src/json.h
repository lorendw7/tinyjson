// tinyjson — Lesson 02: representing a JSON value
//
// A JSON value is one of six things: null, true/false, a number, a string,
// an array of values, or an object (string -> value). In C++ we model "one
// of several shapes" with a *type tag* (an enum) plus storage for each shape.

#ifndef TINYJSON_JSON_H
#define TINYJSON_JSON_H

#include <map>
#include <string>
#include <vector>

namespace tinyjson {

// The tag tells us which shape a value currently holds.
enum class Type {
    Null,
    Boolean,
    Number,
    String,
    Array,
    Object,
};

// Forward declaration: Array and Object below need to mention Value before
// Value is fully defined, because JSON is recursive (arrays hold values).
struct Value;

using Array = std::vector<Value>;
using Object = std::map<std::string, Value>;

// For now Value just carries every field side by side. This is wasteful
// (an object stores empty number/string/array slots too); in a later lesson
// we replace it with std::variant. Clarity first, efficiency later.
struct Value {
    Type type = Type::Null;

    bool boolean = false;     // valid when type == Boolean
    double number = 0.0;      // valid when type == Number
    std::string string;       // valid when type == String
    Array array;              // valid when type == Array
    Object object;            // valid when type == Object
};

} // namespace tinyjson

#endif // TINYJSON_JSON_H

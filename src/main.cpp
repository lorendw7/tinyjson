// tinyjson — driver program
//
// Lesson 02: we build a JSON value *by hand* to prove our data model can
// represent real JSON, before we write any parser. Target value:
//
//   { "name": "tiny", "stars": 5, "tags": [true, null] }

#include <iostream>

#include "json.h"

using namespace tinyjson;

int main() {
    Value root;
    root.type = Type::Object;

    Value name;
    name.type = Type::String;
    name.string = "tiny";

    Value stars;
    stars.type = Type::Number;
    stars.number = 5;

    Value t;
    t.type = Type::Boolean;
    t.boolean = true;

    Value n; // stays Type::Null by default

    Value tags;
    tags.type = Type::Array;
    tags.array.push_back(t);
    tags.array.push_back(n);

    root.object["name"] = name;
    root.object["stars"] = stars;
    root.object["tags"] = tags;

    std::cout << "root is an object with " << root.object.size()
              << " keys\n";
    std::cout << "tags has " << root.object["tags"].array.size()
              << " elements\n";
    return 0;
}

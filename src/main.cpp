#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class Type
{
    Null,
    Boolean,
    Number,
    String,
    Array,
    Object
};

struct Value;

using Array = std::vector<Value>;
using Object = std::map<std::string, Value>;

struct Value
{
    Type type = Type::Null;
    bool boolean = false;
    double number = 0.0;
    std::string str;
    Array array;
    Object object;
};

int main()
{
    Value root;
    Value v1, v2;
    v1.type = Type::Boolean;
    v1.boolean = true;
    v2.type = Type::Null;
    Array tags;
    tags.push_back(v1);
    tags.push_back(v2);
    Object obj;
    Value v3, v4, v5;
    v3.type = Type::Array;
    v3.array = tags;
    obj["tags"] = v3;
    v4.type = Type::String;
    v4.str = "tiny";
    obj["name"] = v4;
    v5.type = Type::Number;
    v5.number = 5;
    obj["stars"] = v5;
    root.type = Type::Object;
    root.object = obj;
    std::cout << "root is an object with " << root.object.size() << " keys\n";
    std::cout << "tags has " << root.object["tags"].array.size() << " elements\n";

    return 0;
}
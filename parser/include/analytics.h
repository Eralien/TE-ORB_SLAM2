#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include <parser.h>

class ClassData
{
public:
    std::string name;
    int count;
public:
    ClassData(std::string className) : name(className), count(1) {};

    bool operator==(const ClassData &other) const
    {
        return name == other.name;
    }

    bool operator!=(const ClassData &other) const
    {
        return !(*this == other);
    }
};


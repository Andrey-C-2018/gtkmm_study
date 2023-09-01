#pragma once
#include <istream>

struct ISerializable {
    virtual void deserialize(std::istream &in) = 0;
    virtual ~ISerializable() = default;
};

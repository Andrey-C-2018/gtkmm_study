#pragma once
#include <istream>

struct ISerializable {
    virtual void serialize(std::istream &in) = 0;
    virtual ~ISerializable() = default;
};

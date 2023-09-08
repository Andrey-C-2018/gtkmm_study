#pragma once

struct IReader;

struct ISerializable {
    virtual void deserialize(IReader &in) = 0;
    virtual ~ISerializable() = default;
};

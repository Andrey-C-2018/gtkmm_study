#pragma once

struct IReader {
    virtual bool ready() const = 0;
    virtual const char *readLine() = 0;
    virtual void close() = 0;
    virtual ~IReader() = default;
};

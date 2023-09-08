#pragma once
#include <glibmm/refptr.h>
#include <giomm/datainputstream.h>
#include "IReader.h"

class InputStreamReader : public IReader {
    Glib::RefPtr<Gio::DataInputStream> in;
    std::string buffer, prev;
    bool eof;

public:
    explicit InputStreamReader(Glib::RefPtr<Gio::FileInputStream> in);

    InputStreamReader(const InputStreamReader &obj) = delete;
    InputStreamReader(InputStreamReader &&obj) = default;
    InputStreamReader &operator=(const InputStreamReader &obj) = delete;
    InputStreamReader &operator=(InputStreamReader &&obj) = default;

    bool ready() const override;
    const char *readLine() override;
    void close() override;

    ~InputStreamReader() override;
};

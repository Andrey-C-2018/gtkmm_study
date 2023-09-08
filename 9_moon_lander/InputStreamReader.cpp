#include <giomm/file.h>
#include "InputStreamReader.h"

InputStreamReader::InputStreamReader(Glib::RefPtr<Gio::FileInputStream> in_) : \
                                        in(Gio::DataInputStream::create(in_)),
                                        eof(false) {

    eof = !in->read_line(buffer);
    eof = eof || buffer.empty();
}

bool InputStreamReader::ready() const {

    return !eof;
}

const char *InputStreamReader::readLine() {

    if (!eof) {
        prev = buffer;
        eof = !in->read_line(buffer);
        eof = eof || buffer.empty();
    }
    return prev.c_str();
}

void InputStreamReader::close() {

    if (!in->is_closed())
        in->close();
}

InputStreamReader::~InputStreamReader() {

    InputStreamReader::close();
}

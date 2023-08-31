#include <cstddef>
#include "Color.h"

const Color Color::RED(0xff, 0, 0);
const Color Color::ORANGE(0xff, 0x9a, 0x00);
const Color Color::YELLOW(0xff, 0xff, 0x00);
const Color Color::GREEN(0x00, 0xff, 0x00);
const Color Color::BLUE(0x00, 0x00, 0xff);
const Color Color::VIOLET(0x7f, 0x00, 0xff);

Color::Color(unsigned char red_, unsigned char green_, unsigned char blue_) : \
				red(red_), green(green_), blue(blue_) {}

Color::Color(size_t color_index) : red(0), green(0), blue(0) {

    const Color *predef_color;
    switch (color_index) {
        case 0: predef_color = &BLACK; break;
        case 1: predef_color = &RED; break;
        case 2: predef_color = &ORANGE; break;
        case 3: predef_color = &YELLOW; break;
        case 4: predef_color = &GREEN; break;
        case 5: predef_color = &BLUE; break;
        case 6: predef_color = &VIOLET; break;
        default: predef_color = &WHITE;
    }
    operator=(*predef_color);
}

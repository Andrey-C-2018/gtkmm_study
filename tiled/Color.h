#pragma once
#include <cstddef>

class Color final {
public:
    static const Color BLACK, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, WHITE;

private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;

public:
	Color(unsigned char red, unsigned char green, unsigned char blue);
    explicit Color(size_t color_index);

    inline unsigned char getRed() const;
	inline unsigned char getGreen() const;
	inline unsigned char getBlue() const;
};

//***************************************************

unsigned char Color::getRed() const {

	return red;
}

unsigned char Color::getGreen() const {

	return green;
}

unsigned char Color::getBlue() const {

	return blue;
}

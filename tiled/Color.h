#pragma once

class Color final {
	unsigned char red;
	unsigned char green;
	unsigned char blue;

public:
	Color(unsigned char red, unsigned char green, unsigned char blue);

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

#include "Rocket.h"

Rocket::Rocket(const GameObject *landscape_) : landscape(landscape_),
                                                X(0.0), Y(0.0), \
                                                speed_x(0.0), speed_y(1.0), accel(0.05) {
    assert (landscape);
    auto coord = getPosition();
    X = (double)coord.x;
    Y = (double)coord.y;
}

void Rocket::setPosition(size_t x, size_t y) {

    X = (double)x;
    Y = (double)y;
    GameObject::setPosition(x, y);
}

void Rocket::move(bool throttle, bool left, bool right) {

    speed_y += throttle ? -accel : accel;

    if (left)
        speed_x -= accel;
    else if (right)
        speed_x += accel;

    applySpeedChanges();
}

void Rocket::applySpeedChanges() {

    X += speed_x;
    Y += speed_y;
    auto width = (double)getWidth();
    auto landscape_width = (double)landscape->getWidth();

    if (X < 0) {
        X = 0;
        speed_x = 0;
    }
    if (X + width > landscape_width) {
        X = landscape_width - width;
        speed_x = 0;
    }
    if (Y < 0) {
        Y = 0;
        speed_y = 0;
    }
    GameObject::setPosition((size_t)X, (size_t)Y);
}

bool Rocket::isStopped() const {

    return speed_y < 10 * accel;
}

void Rocket::crash() {

    for (size_t i = 0; i < getWidth(); i++)
        for (size_t j = 0; j < getHeight(); j++) {
            Color c = getPixel(i, j);
            if (c != TRANSPARENT)
                setPixel(i, j, Color::RED);
        }
}

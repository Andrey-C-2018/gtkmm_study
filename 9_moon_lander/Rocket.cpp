#include "Rocket.h"

Rocket::Rocket(const GameObject *landscape_) : landscape(landscape_),
                                                speed_x(0.0), speed_y(1.0), accel(0.05) {
    assert (landscape);
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

    auto coord = getPosition();
    double x = (double)coord.x + speed_x;
    double y = (double)coord.y + speed_y;
    auto width = (double)getWidth();
    auto landscape_width = (double)landscape->getWidth();

    if (x < 0) {
        x = 0;
        speed_x = 0;
    }
    if (x + width > landscape_width) {
        x = landscape_width - width;
        speed_x = 0;
    }
    if (y < 0) {
        y = 0;
        speed_y = 0;
    }
    setPosition((size_t)x, (size_t)y);
}

bool Rocket::isStopped() const {

    return speed_y < 10 * accel;
}

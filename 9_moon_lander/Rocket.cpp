#include "Rocket.h"

Rocket::Rocket(const GameObject *landscape_) : landscape(landscape_),
                                                speed_x(0.0), speed_y(0.0), \
                                                throttle(false), left(false), right(false) {
    assert (landscape);
}

bool Rocket::move() {

    speed_y += throttle ? -accel : accel;

    if (left)
        speed_x -= accel;
    else if (right)
        speed_x += accel;

    auto coord = getPosition();
    setPosition((size_t)((double)coord.x + speed_x), (size_t)((double)coord.y + speed_y));
    return true;
}

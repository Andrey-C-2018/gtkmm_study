#pragma once
#include "GameObject.h"

class Rocket : public GameObject {
    const GameObject *landscape;
    double speed_x, speed_y, accel;
    bool throttle, left, right;

public:
    Rocket(const GameObject *landscape);

    Rocket(const Rocket &obj) = delete;
    Rocket(Rocket &&obj) = default;
    Rocket &operator=(const Rocket &obj) = delete;
    Rocket &operator=(Rocket &&obj) = default;

    bool move();
    bool throttleUp();
    bool turnRight();
    bool turnLeft();

    ~Rocket() override = default;
};

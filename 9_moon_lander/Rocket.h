#pragma once
#include "GameObject.h"

class Rocket : public GameObject {
    const GameObject *landscape;
    double X, Y, speed_x, speed_y, accel;

    void applySpeedChanges();

public:
    explicit Rocket(const GameObject *landscape);

    Rocket(const Rocket &obj) = delete;
    Rocket(Rocket &&obj) = default;
    Rocket &operator=(const Rocket &obj) = delete;
    Rocket &operator=(Rocket &&obj) = default;

    void setPosition(size_t x, size_t y) override;
    void move(bool throttle, bool left, bool right);
    bool isStopped() const;
    void crash();

    ~Rocket() override = default;
};

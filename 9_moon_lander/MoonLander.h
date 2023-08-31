#pragma once
#include <tiled/IEventsHandler.h>
#include "GameObject.h"

class MoonLander : public IEventsHandler {
    GameObject moon, rocket, platform;

public:
    explicit MoonLander();

    void onInit(IGameScreen &screen) override;
    void onMouseLButtonDown(size_t col, size_t row) override{ }
    void onMouseLButtonUp(size_t col, size_t row) override { }
    void onMouseWheelDown(size_t col, size_t row) override { }
    void onMouseWheelUp(size_t col, size_t row) override { }
    void onMouseRButtonDown(size_t col, size_t row) override { }
    void onMouseRButtonUp(size_t col, size_t row) override { }
    void onKeyPress(char ch) override;
    void onKeyReleased(char ch) override { }
    void onTimer();

    void reset();
    void reset(size_t cols_count, size_t rows_count, size_t mines_count);

    ~MoonLander() override;
};

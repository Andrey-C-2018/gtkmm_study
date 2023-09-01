#pragma once
#include <tiled/IEventsHandler.h>
#include "GameObject.h"

class MoonLander : public IEventsHandler {
    static constexpr float height_ratio = 1.8F;
    GameObject landscape, platform;

    static void loadGameObjData(GameObject &obj, const char *resource_name);

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

    ~MoonLander() override;
};

#include <fstream>
#include <iostream>
#include <cassert>
#include <tiled/IGameScreen.h>
#include "MoonLander.h"

MoonLander::MoonLander() {

    const char *resources[] = {"landscape.csv", "platform.csv"};
    GameObject *objects[] = {&landscape, &platform};
    for (size_t i = 0; i < sizeof resources / sizeof(const char*); i++)
        loadGameObjData(*objects[i], resources[i]);
}

void MoonLander::onInit(IGameScreen &screen) {

    auto height = (size_t)((float)landscape.getHeight() * height_ratio);
    screen.setSize(landscape.getWidth(), height, Color::BLACK);

    landscape.setPosition(0, height - landscape.getHeight());
    platform.setPosition((landscape.getWidth() - platform.getWidth() - 4) / 2, height - 1);
    landscape.draw(screen);
    platform.draw(screen);
}

void MoonLander::onKeyPress(char ch) {


}

void MoonLander::loadGameObjData(GameObject &obj, const char *resource_name) {

    assert (resource_name);
    std::ifstream in(resource_name, std::ios::in);
    if (!in.is_open()) {
        std::cerr << "the resource was not found: " << resource_name << std::endl;
        return;
    }

    obj.deserialize(in);
    in.close();
}

void MoonLander::onTimer() {

}

MoonLander::~MoonLander() = default;

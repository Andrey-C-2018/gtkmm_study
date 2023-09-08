#include <fstream>
#include <iostream>
#include <cassert>
#include <giomm/file.h>
#include <tiled/IGameScreen.h>
#include "MoonLander.h"
#include "InputStreamReader.h"

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
    std::string res_path = "resource:///res/";
    res_path += resource_name;
    auto res = Gio::File::create_for_uri(res_path);

    auto stream = res->read();
    auto in = InputStreamReader(stream);

    obj.deserialize(in);
}

void MoonLander::onTimer() {

}

MoonLander::~MoonLander() = default;

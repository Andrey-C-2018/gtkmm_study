#include <iostream>
#include <cassert>
#include <giomm/file.h>
#include <tiled/IGameScreen.h>
#include "MoonLander.h"
#include "InputStreamReader.h"

MoonLander::MoonLander() : rocket(&landscape) {

    const char *resources[] = {"landscape.csv", "platform.csv", "rocket.csv"};
    GameObject *objects[] = {&landscape, &platform, &rocket};
    assert (sizeof objects / sizeof(objects[0]) == sizeof resources / sizeof(const char *));

    std::string res_path;
    for (size_t i = 0; i < sizeof resources / sizeof(const char*); i++) {
        res_path = "resource:///res/";
        res_path += resources[i];
        auto res = Gio::File::create_for_uri(res_path);

        auto stream = res->read();
        auto in = InputStreamReader(stream);

        objects[i]->deserialize(in);
    }
}

void MoonLander::onInit(IGameScreen &screen) {

    auto height = (size_t)((float)landscape.getHeight() * height_ratio);
    screen.setSize(landscape.getWidth(), height, Color::BLACK);

    landscape.setPosition(0, height - landscape.getHeight());
    platform.setPosition((landscape.getWidth() - platform.getWidth() - 4) / 2, height - 1);
    rocket.setPosition((landscape.getWidth() - rocket.getWidth()) / 2, 0);

    landscape.draw(screen);
    platform.draw(screen);
    rocket.draw(screen);
}

void MoonLander::onKeyPress(char ch) {


}

void MoonLander::onTimer() {

}

MoonLander::~MoonLander() = default;

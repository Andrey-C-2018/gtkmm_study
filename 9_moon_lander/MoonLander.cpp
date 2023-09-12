#include <iostream>
#include <cassert>
#include <giomm/file.h>
#include <tiled/IGameScreen.h>
#include "MoonLander.h"
#include "InputStreamReader.h"

MoonLander::MoonLander() : height(0), rocket(&landscape), \
                            up_pressed(false), left_pressed(false), right_pressed(false), \
                            screen(nullptr) {

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

void MoonLander::onInit(IGameScreen &screen_) {

    screen = &screen_;
    height = (size_t)((float)landscape.getHeight() * height_ratio);
    screen->setSize(landscape.getWidth(), height, Color::BLACK);

    landscape.setPosition(0, height - landscape.getHeight());
    platform.setPosition((landscape.getWidth() - platform.getWidth() - 4) / 2, height - 1);
    rocket.setPosition((landscape.getWidth() - rocket.getWidth()) / 2, 0);

    landscape.draw(*screen);
    platform.draw(*screen);
    rocket.draw(*screen);
}

void MoonLander::onKeyPress(char ch) {

    switch (ch) {
        case 's': up_pressed = true; break;
        case 'a': left_pressed = true; break;
        case 'd': right_pressed = true;
        default: break;
    }
}

void MoonLander::onKeyReleased(char ch) {

    switch (ch) {
        case 's': up_pressed = false; break;
        case 'a': left_pressed = false; break;
        case 'd': right_pressed = false;
        default: break;
    }
}

void MoonLander::onTimer() {

    rocket.move(up_pressed, left_pressed, right_pressed);
    auto coords = rocket.getPosition();
    if (coords.y >= height - rocket.getHeight() - platform.getHeight()) {
        rocket.setPosition(coords.x, height - rocket.getHeight() - platform.getHeight());
    }

    screen->reset(Color::BLACK);
    landscape.draw(*screen);
    rocket.draw(*screen);
    screen->redraw();
}

MoonLander::~MoonLander() = default;

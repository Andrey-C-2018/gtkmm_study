#include <fstream>
#include <tiled/IGameScreen.h>
#include "MoonLander.h"

MoonLander::MoonLander() {

    std::ifstream in;
    in.open("moon.csv", std::ios::in);
    moon.serialize(in);
    in.close();
}

void MoonLander::onInit(IGameScreen &screen) {

    screen.setSize(moon.getWidth(), moon.getHeight(), Color::BLACK);
}

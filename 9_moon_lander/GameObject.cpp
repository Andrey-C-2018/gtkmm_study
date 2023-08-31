#include <cassert>
#include <tiled/IGameScreen.h>
#include "GameObject.h"

GameObject::GameObject() : x(0), y(0) { }

void GameObject::serialize(std::istream &in) {

    std::string buffer, token;
    while (!in.eof()) {
        std::getline(in, buffer);

        std::vector<Color> row;
        size_t prev = 0, p = buffer.find(',');
        while (prev != buffer.size() && p != std::string::npos) {
            char *end = nullptr;
            auto color_index = std::strtoul(buffer.c_str() + prev, &end, 10);
            Color c((size_t)color_index);
            row.emplace_back(c);
            prev = p + 1;
        }

        if (!row.empty())
            data.emplace_back(row);
    }
}

void GameObject::draw(IGameScreen &screen) {

    for (size_t i = y; i < data.size(); i++)
        for (size_t j = x; j < data[0].size(); j++)
            screen.setCellColor(j, i, data[i][j]);
}

void GameObject::setPosition(int x_, int y_) {

    assert (x >= 0);
    assert (y >= 0);
    x = x;
    y = y;
}

bool GameObject::intersectsWith(const GameObject &obj) const {

    if (data.empty() || obj.data.empty()) return false;
    auto x2 = x + data[0].size();
    auto y2 = y + data.size();
    auto obj_x2 = obj.x + obj.data[0].size();
    auto obj_y2 = obj.y + obj.data.size();

    bool v1 = x <= obj.x && obj.x <= x2 && y <= obj.y && obj.y <= y2;
    bool v2 = x <= obj_x2 && obj_x2 <= x2 && y <= obj_y2 && obj_y2 <= y2;
    bool v3 = x <= obj.x && obj.x <= x2 && y <= obj_y2 && obj_y2 <= y2;
    bool v4 = x <= obj_x2 && obj_x2 <= x2 && y <= obj.y && obj.y <= y2;

    bool V1 = obj.x <= x && x <= obj_x2 && obj.y <= y && y <= obj_y2;
    bool V2 = obj.x <= x2 && x2 <= obj_x2 && obj.y <= y2 && y2 <= obj_y2;
    bool V3 = obj.x <= x && x <= obj_x2 && obj.y <= y2 && y2 <= obj_y2;
    bool V4 = obj.x <= x2 && x2 <= obj_x2 && obj.y <= y && y <= obj_y2;

    return v1 || v2 || v3 || v4 || V1 || V2 || V3 || V4;
}

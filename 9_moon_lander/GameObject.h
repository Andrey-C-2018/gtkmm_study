#pragma once
#include <cassert>
#include <cstdlib>
#include <vector>
#include <tiled/Color.h>
#include "ISerializable.h"
#include "Point.h"

struct IGameScreen;

class GameObject : public ISerializable {
    std::vector<std::vector<Color>> data;
    size_t x, y;

    static inline void addColorToRow(const char *p_str, std::vector<Color> &row);

public:
    GameObject();

    GameObject(const GameObject &obj) = default;
    GameObject(GameObject &&obj) = default;
    GameObject &operator=(const GameObject &obj) = default;
    GameObject &operator=(GameObject &&obj) = default;

    void deserialize(IReader &in) override;
    void draw(IGameScreen &screen);
    inline Point getPosition() const;
    void setPosition(size_t x, size_t y);

    inline size_t getWidth() const;
    inline size_t getHeight() const;
    bool intersectsWithRect(const GameObject &obj) const;

    ~GameObject() override = default;
};

//***************************************************

size_t GameObject::getWidth() const {

    return data.empty() ? 0 : data[0].size();
}

size_t GameObject::getHeight() const {

    return data.size();
}

Point GameObject::getPosition() const {

    return {x, y};
}

void GameObject::addColorToRow(const char *p_str, std::vector<Color> &row) {

    assert (p_str);
    assert ('0' <= *p_str && *p_str <= '9');

    auto color_index = atoi(p_str);
    Color c((size_t)color_index);
    row.emplace_back(c);
}
#pragma once
#include <vector>
#include <tiled/Color.h>
#include "ISerializable.h"

class GameObject : public ISerializable {
    std::vector<std::vector<Color>> data;
    size_t x, y;

public:
    GameObject();

    GameObject(const GameObject &obj) = default;
    GameObject(GameObject &&obj) = default;
    GameObject &operator=(const GameObject &obj) = default;
    GameObject &operator=(GameObject &&obj) = default;

    void deserialize(IReader &in) override;
    void draw(IGameScreen &screen);
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
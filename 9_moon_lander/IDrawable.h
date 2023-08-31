#pragma once

struct IGameScreen;

struct IDrawable {
    virtual void draw(IGameScreen &screen) = 0;
    virtual ~IDrawable() = default;
};

#pragma once

#include <raylib.h>

#include "IEntity.hpp"

namespace TomatoSurvivor {

class AEntity : public IEntity {
  public:
    virtual ~AEntity() = default;
    void update() = 0;

    void render() override {
        DrawCircleV({position.x, position.y + 100}, radius, color);
    }

    Vector2 getPosition() const override {
        return position;
    }

    void setPosition(Vector2 _position) override {
        position = _position;
    }

    int getRadius() const {
        return radius;
    }

  protected:
    Vector2 position;
    Vector2 velocity;
    Color color;
    int radius;
};

} // namespace TomatoSurvivor

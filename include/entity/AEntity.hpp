#pragma once

#include <raylib.h>

#include "IEntity.hpp"

namespace TomatoSurvivor {

class AEntity : public IEntity {
  public:
    virtual ~AEntity() = default;
    void update() = 0;

    void render() override {
        DrawCircleV(position, radius, color);
    }

    Vector2 getPosition() const override {
        return position;
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

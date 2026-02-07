#pragma once

#include "AEntity.hpp"

namespace TomatoSurvivor {

class Arrow : public AEntity {
  public:
    Arrow(float r, float x, float y, float vx = 0, float vy = 0) {
        position = {x, y};
        velocity = {vx, vy};
        color = GRAY;
        radius = r;
    }

    Arrow(float r, Vector2 pos, Vector2 vel = {0, 0}) {
        position = pos;
        velocity = vel;
        color = GRAY;
        radius = r;
    }

    ~Arrow() = default;

    void update() override {
        position.x += velocity.x;
        position.y += velocity.y;
    }

  private:
};

} // namespace TomatoSurvivor

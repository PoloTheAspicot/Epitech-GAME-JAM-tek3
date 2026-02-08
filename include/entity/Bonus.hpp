#pragma once

#include "AEntity.hpp"

namespace TomatoSurvivor {
class Bonus : public AEntity {
  public:
    Bonus(float r, float x, float y, float vx = 0, float vy = 0) {
        position = {x, y};
        velocity = {vx, vy};
        offset = {0, 0};
        color = GREEN;
        radius = r;
    }

    Bonus(float r, Vector2 pos, Vector2 vel = {0, 0}) {
        position = pos;
        velocity = vel;
        color = GREEN;
        radius = r;
    }

    ~Bonus() = default;

    void update() override {
        position.x += velocity.x;
        position.y += velocity.y;
    }
  private:
};
} // namespace TomatoSurvivor

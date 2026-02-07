#pragma once

#include "AEntity.hpp"

namespace TomatoSurvivor {

class Sword : public AEntity {
  public:
    Sword(float x, float y, float vx = 0, float vy = 0) {
        position = {x, y};
        velocity = {vx, vy};
        color = GRAY;
        radius = 20;
    }

    Sword(Vector2 pos, Vector2 vel = {0, 0}) {
        position = pos;
        velocity = vel;
        color = GRAY;
        radius = 20;
    }

    ~Sword() = default;

    void update() override {
        position.x += velocity.x;
        position.y += velocity.y;
    }

  private:
};

} // namespace TomatoSurvivor

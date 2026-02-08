#pragma once

#include <raylib.h>

#include "AEntity.hpp"

namespace TomatoSurvivor {

class Damage : public AEntity {
  public:
    Damage(float r, float x, float y, float vx = 0, float vy = 0) {
        position = {x, y};
        velocity = {vx, vy};
        radius = r;
    }

    void update() override {
        position.x += velocity.x;
        position.y += velocity.y;
    }

  private:
};

} // namespace TomatoSurvivor

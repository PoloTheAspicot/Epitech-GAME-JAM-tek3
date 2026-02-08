#pragma once

#include "AEntity.hpp"

namespace TomatoSurvivor {

class Arrow : public AEntity {
  public:
    Arrow(float r, float x, float y, float vx = 0, float vy = 0) {
        position = {x, y};
        velocity = {vx, vy};
        offset = {0, 0};
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
        float angleRad = atan2(velocity.y, velocity.x);
        float length = 130 / 10.24f;
        offset.x = cos(angleRad) * length;
        offset.y = sin(angleRad) * length;
    }

  private:
};

} // namespace TomatoSurvivor

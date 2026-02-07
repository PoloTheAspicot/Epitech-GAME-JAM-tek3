#pragma once

#include "AEntity.hpp"

namespace Tomato {

class Sword : public AEntity {
  public:
    Sword(float x, float y, float vx, float vy) {
        position = {x, y};
        velocity = {vx, vy};
    }

    Sword(Vector2 pos, Vector2 vel) {
        position = pos;
        velocity = vel;
    }

    ~Sword() = default;

  private:
};

} // namespace Tomato

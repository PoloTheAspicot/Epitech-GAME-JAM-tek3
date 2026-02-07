#pragma once

#include "AEntity.hpp"

namespace Tomato {

class Tomato : public AEntity {
  public:
    Tomato(float x, float y, float vx, float vy) {
        position = {x, y};
        velocity = {vx, vy};
    };

    Tomato(Vector2 pos, Vector2 vel) {
        position = pos;
        velocity = vel;
    };

    ~Tomato() = default;

  private:
};

} // namespace Tomato

#pragma once

#include "AEntity.hpp"

namespace TomatoSurvivor {

class Tomato : public AEntity {
  public:
    Tomato(float x, float y, float vx = 0, float vy = 0) {
        position = {x, y};
        velocity = {vx, vy};
        color = RED;
        radius = 40;
    }

    Tomato(Vector2 pos, Vector2 vel = {0, 0}) {
        position = pos;
        velocity = vel;
        color = RED;
        radius = 40;
    }

    ~Tomato() = default;

    void update() override {
        input();
        position.x += velocity.x;
        position.y += velocity.y;
    }

  private:
    void input() {
        velocity = {0, 0};
        if (IsKeyDown(KEY_RIGHT)) velocity.x = 2.0f;
        if (IsKeyDown(KEY_LEFT)) velocity.x = -2.0f;
        if (IsKeyDown(KEY_UP)) velocity.y = -2.0f;
        if (IsKeyDown(KEY_DOWN)) velocity.y = 2.0f;
    }
};

} // namespace TomatoSurvivor

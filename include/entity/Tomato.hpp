#pragma once

#include "AEntity.hpp"
#include "Config.hpp"

namespace TomatoSurvivor {

class Tomato : public AEntity {
  public:
    Tomato(float r, float x, float y, float vx = 0, float vy = 0) {
        position = {x, y};
        velocity = {vx, vy};
        color = RED;
        radius = r;
    }

    Tomato(float r, Vector2 pos, Vector2 vel = {0, 0}) {
        position = pos;
        velocity = vel;
        color = RED;
        radius = r;
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
        if (IsKeyDown(Config::KEY_RIGHT_MOVE)) velocity.x = 2.0f;
        if (IsKeyDown(Config::KEY_LEFT_MOVE)) velocity.x = -2.0f;
        if (IsKeyDown(Config::KEY_UP_MOVE)) velocity.y = -2.0f;
        if (IsKeyDown(Config::KEY_DOWN_MOVE)) velocity.y = 2.0f;
    }
};

} // namespace TomatoSurvivor

#pragma once

#include <raylib.h>

#include "IEntity.hpp"

namespace TomatoSurvivor {

class AEntity : public IEntity {
  public:
    virtual ~AEntity() = default;
    void update() = 0;
    void render(bool show_hitbox) override {
        DrawTexture(texture, position.x - radius, position.y + 100 - radius, WHITE);
        if (show_hitbox)
            DrawCircleV({position.x, position.y + 100}, radius, color);
    }

    Vector2 getPosition() const override {
        return position;
    }

    void setPosition(Vector2 _position) override {
        position = _position;
    }

    void setTexture(Texture2D _texture) override {
        texture = _texture;
    }

    int getRadius() const {
        return radius;
    }

  protected:
    Vector2 position;
    Vector2 velocity;
    Color color;
    int radius;
    Texture2D texture;
};

} // namespace TomatoSurvivor

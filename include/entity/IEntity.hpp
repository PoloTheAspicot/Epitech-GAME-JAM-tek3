#pragma once

namespace TomatoSurvivor {

class IEntity {
  public:
    virtual ~IEntity() = default;
    virtual void update() = 0;
    virtual void render(bool show_hitbox) = 0;
    virtual Vector2 getPosition() const = 0;
    virtual void setSpeed(float) = 0;
    virtual void setPosition(Vector2) = 0;
    virtual void setTexture(Texture2D) = 0;
    virtual int getRadius() const = 0;
};

} // namespace TomatoSurvivor

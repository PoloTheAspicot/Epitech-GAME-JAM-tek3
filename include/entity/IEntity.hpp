#pragma once

namespace TomatoSurvivor {

class IEntity {
  public:
    virtual ~IEntity() = default;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual Vector2 getPosition() const = 0;
    virtual int getRadius() const = 0;
};

} // namespace TomatoSurvivor

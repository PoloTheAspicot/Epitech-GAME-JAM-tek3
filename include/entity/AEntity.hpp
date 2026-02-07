#pragma once

#include <raylib.h>

#include "IEntity.hpp"

namespace Tomato {

class AEntity : public IEntity {
  public:
    virtual ~AEntity() = default;
    void update() override;
    void render() override;

  protected:
    Vector2 position;
    Vector2 velocity;
};

} // namespace Tomato

#pragma once

namespace Tomato {

class IEntity {
  public:
    virtual ~IEntity() = default;
    virtual void update() = 0;
    virtual void render() = 0;
};

} // namespace Tomato

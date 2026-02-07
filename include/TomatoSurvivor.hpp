#pragma once

#include <memory>
#include <vector>

#include "entity/IEntity.hpp"

namespace Tomato {
class TomatoSurvivor {
  public:
    TomatoSurvivor() = default;
    ~TomatoSurvivor() = default;
    void loop();
  private:
    void update();
    void render();
    std::unique_ptr<IEntity> _tomato;
    std::vector<std::unique_ptr<IEntity>> _swords;
};
} // namespace Tomato

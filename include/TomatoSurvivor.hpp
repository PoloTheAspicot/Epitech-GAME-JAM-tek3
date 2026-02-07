#pragma once

#include <raylib.h>

#include <memory>
#include <vector>

#include "entity/IEntity.hpp"

namespace TomatoSurvivor {

static constexpr Vector2 WINDOW_SIZE = {800, 800};

class TomatoSurvivor {
  public:
    TomatoSurvivor();
    ~TomatoSurvivor();
    void loop();
  private:
    void update();
    void render();
    void checkCollisions();
    void checkCollisionsSwords();
    void checkCollisionsBonuses();
    void spawnSword();
    void spawnBonus();

    std::unique_ptr<IEntity> _tomato;
    std::vector<std::unique_ptr<IEntity>> _swords;
    std::vector<std::unique_ptr<IEntity>> _bonuses;
    float _timer = 300;
    float _score = 0;
};
} // namespace TomatoSurvivor

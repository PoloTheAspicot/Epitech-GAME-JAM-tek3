#pragma once

#include <raylib.h>

#include <memory>
#include <vector>

#include "entity/IEntity.hpp"

namespace TomatoSurvivor {
    
static constexpr Vector2 WINDOW_SIZE = {800, 900};
static constexpr Vector2 GAME_SIZE = {800, 800};
static constexpr auto TEXT_TIME = "Time: ";
static constexpr auto TEXT_SCORE = "Score: ";
static constexpr auto TEXT_SHOP = "Next shop: ";
static constexpr auto TEXT_ARROW = "Next arrow: ";

class TomatoSurvivor {
  public:
    TomatoSurvivor();
    ~TomatoSurvivor();
    void loop();
    void death_menu();
    void reset();
    float getScore() const { return _score; }
    bool still_alive;
    bool return_to_menu = false;
  private:
    void update();
    void render();
    void checkCollisions();
    void checkCollisionsArrows();
    void checkCollisionsBonuses();
    void spawnArrow();
    void spawnBonus();

    std::unique_ptr<IEntity> _tomato;
    std::vector<std::unique_ptr<IEntity>> _arrows;
    std::vector<std::unique_ptr<IEntity>> _bonuses;
    float _timer = 300.0;
    float _score = 0.0;
    float _playerSpeed = 2.0;
    float _playerSize = 50.0;
    float _arrowSpeed = 4.0;
    float _arrowSize = 10.0;
    float _arrowDamage = 30.0;
    float _arrowSpawnDelay = 1.0;
    float _maxNumberArrows = 4.0;
    float _nextArrowSpawn = _arrowSpawnDelay;
    float _bonusSize = 30.0;
    float _bonusTimeGain = 10.0;
    float _bonusScore = 100.0;
    float _invicibilityTime = 0.5;
    float _playerInvicibility = 0.0;
    float _spawnShopDelay = 30.0;
    float _nextShopSpawn = _spawnShopDelay;
    Music music;
    float volume;
    float pan = 0.0f; 
};
} // namespace TomatoSurvivor

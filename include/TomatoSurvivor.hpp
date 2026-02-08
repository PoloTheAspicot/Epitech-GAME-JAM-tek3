#pragma once

#include <raylib.h>

#include <memory>
#include <vector>
#include <utility>

#include "entity/IEntity.hpp"
#include "PowerUps.hpp"

namespace TomatoSurvivor {

static constexpr Vector2 WINDOW_SIZE = {800, 900};
static constexpr Vector2 GAME_SIZE = {800, 800};
static constexpr auto TEXT_TIME = "Time: ";
static constexpr auto TEXT_SCORE = "Score: ";
static constexpr auto TEXT_SHOP = "Next shop: ";
static constexpr auto TEXT_ARROW = "Next arrow: ";
static constexpr float DIFFICULTY_INC = 800;
static constexpr int DAMAGE_SIZE = 20;
static constexpr int HEAL_SIZE = 20;
static constexpr int PARTICLE_LIFETIME = 40;

class TomatoSurvivor {
  public:
    TomatoSurvivor();
    ~TomatoSurvivor();
    void loop();
    void death_menu();
    void pause_menu();
    void reset();
    float getScore() const { return _score; }
    bool still_alive;
    bool return_to_menu = false;
    bool abandoned = false;
  private:
    void update();
    void render();
    void checkCollisions();
    void checkCollisionsArrows();
    void checkCollisionsBonuses();
    void spawnArrow();
    void spawnBonus();
    void increaseDifficulty();
    void initializePowerUps();
    void ChosePowerUp();

    std::unique_ptr<IEntity> _tomato;
    std::vector<std::unique_ptr<IEntity>> _arrows;
    std::vector<std::unique_ptr<IEntity>> _bonuses;
    std::vector<std::pair<std::unique_ptr<IEntity>, int>> _particles;
    float _timer = 300;
    float _score = 0.0;
    float _playerSpeed = 3.0;
    float _playerSize = 50.0;
    float _arrowSpeed = 2.0;
    float _arrowSize = 10.0;
    float _arrowDamage = 20.0;
    float _arrowSpawnDelay = 2.0;
    float _maxNumberArrows = 3.0;
    float _nextArrowSpawn = _arrowSpawnDelay;
    float _bonusSize = 30.0;
    float _bonusTimeGain = 10.0;
    float _bonusScore = 100.0;
    float _invincibilityTime = 0.5;
    float _playerInvincibility = 0.0;
    float _spawnShopDelay = 20.0;
    float _nextShopSpawn = _spawnShopDelay;
    float _next_DifficultyLevel = DIFFICULTY_INC;
    Music music;
    float volume;
    float pan;
    Texture2D tomato_texture;
    Texture2D water_texture;
    Texture2D arrow_texture;
    Texture2D damage_texture;
    Texture2D heal_texture;
    bool show_hitbox;
    std::vector<PowerUp> _allPowerUps = {};
};

} // namespace TomatoSurvivor

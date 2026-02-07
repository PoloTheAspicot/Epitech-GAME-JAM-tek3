#include <random>
#include <algorithm>
#include <iostream>

#include "entity/Tomato.hpp"
#include "entity/Arrow.hpp"
#include "entity/Bonus.hpp"
#include "TomatoSurvivor.hpp"

namespace TomatoSurvivor
{

TomatoSurvivor::TomatoSurvivor() {
    InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Tomato Survivor");
    srand(time(0));
    SetTargetFPS(60);

    _tomato = std::make_unique<Tomato>(_playerSize, WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2);
    spawnBonus();
}

TomatoSurvivor::~TomatoSurvivor() {
    CloseWindow();
}

void TomatoSurvivor::update() {
    if (_tomato) {
        _tomato->update();
        if (_tomato->getPosition().x > GAME_SIZE.x)
            _tomato->setPosition({GAME_SIZE.x, _tomato->getPosition().y});
        if (_tomato->getPosition().y > GAME_SIZE.y)
            _tomato->setPosition({_tomato->getPosition().x, GAME_SIZE.y});
        if (_tomato->getPosition().x < 0)
            _tomato->setPosition({0, _tomato->getPosition().y});
        if (_tomato->getPosition().y < 0)
            _tomato->setPosition({_tomato->getPosition().x, 0});
    }
    for (unsigned int i = 0; i < _arrows.size(); i++) {
        auto &arrow = _arrows[i];
        arrow->update();
        if (arrow->getPosition().x > GAME_SIZE.x)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
        else if (arrow->getPosition().y > GAME_SIZE.y)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
        else if (arrow->getPosition().x < 0)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
        else if (arrow->getPosition().y < 0)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
    }
}

void TomatoSurvivor::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (_tomato)
        _tomato->render();
    for (auto &arrow : _arrows)
        arrow->render();
    for (auto &bonus : _bonuses)
        bonus->render();
    DrawRectangle(0, 0, 800, 100, LIGHTGRAY);

    DrawText(TextFormat(TEXT_TIME), 10, 10, 35, BLACK);
    DrawText(TextFormat("%.1f", _timer), 10 + TextLength(TEXT_TIME) * 20, 10, 35, RED);
    DrawText(TextFormat(TEXT_SCORE), 10, 55, 35, BLACK);
    DrawText(TextFormat("%.0f", _score), 10 + TextLength(TEXT_SCORE) * 20, 55, 35, RED);
    DrawText(TextFormat(TEXT_SHOP), 350, 10, 35, BLACK);
    DrawText(TextFormat("%.1f", _nextShopSpawn), 350 + TextLength(TEXT_SHOP) * 20, 10, 35, RED);
    DrawText(TextFormat(TEXT_ARROW), 350, 55, 35, BLACK);
    DrawText(TextFormat("%.1f", std::abs(_nextArrowSpawn)), 350 + TextLength(TEXT_ARROW) * 20, 55, 35, RED);

    EndDrawing();
}

void TomatoSurvivor::loop() {
    while (!WindowShouldClose()) {
        _timer -= GetFrameTime();
        _nextShopSpawn -= GetFrameTime();
        if (_nextArrowSpawn > 0)
            _nextArrowSpawn -= GetFrameTime();
        if (_playerInvicibility > 0)
            _playerInvicibility -= GetFrameTime();
        if (_nextShopSpawn <= 0) {
            _nextShopSpawn = _spawnShopDelay;
        }
        if (_nextArrowSpawn <= 0 && _arrows.size() < _maxNumberArrows) {
            _nextArrowSpawn = _arrowSpawnDelay;
            spawnArrow();
        }
        update();
        checkCollisions();
        render();
    }
}

void TomatoSurvivor::checkCollisions() {
    checkCollisionsArrows();
    checkCollisionsBonuses();
}

void TomatoSurvivor::checkCollisionsArrows() {
    if (_playerInvicibility > 0)
        return;
    for (unsigned int i = 0; i < _arrows.size(); i++) {
        auto &arrow = _arrows[i];
        arrow->update();
        if (CheckCollisionCircles(_tomato->getPosition(), _tomato->getRadius(),
            arrow->getPosition(), arrow->getRadius())) {
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
            _timer -= _arrowDamage;
            _playerInvicibility = _invicibilityTime;
        }
    }
}

void TomatoSurvivor::checkCollisionsBonuses() {
    for (auto &bonus : _bonuses) {
        if (CheckCollisionCircles(_tomato->getPosition(), _tomato->getRadius(),
            bonus->getPosition(), bonus->getRadius())) {
            _timer += 10;
            _score += 100;
            if (_score >= _next_DifficultyLevel) {
                increaseDifficulty();
                _next_DifficultyLevel += DIFFICULTY_INC;
            }
            _bonuses.erase(std::remove(_bonuses.begin(), _bonuses.end(), bonus), _bonuses.end());
            spawnBonus();
        }
    }
}

void TomatoSurvivor::spawnArrow() {
    Vector2 pos = {0.0, 0.0};
    Vector2 vel = {0.0, 0.0};

    if (rand() % 2) {
        pos.x = (int)rand() % ((int)GAME_SIZE.x - 100) + 100;
        vel.y = _arrowSpeed;
        if (rand() % 2) {
            vel.y *= -1;
            pos.y = GAME_SIZE.y;
        }
        vel.x = rand() % 3 * (pos.x < 400 ? 1 : -1);
    } else {
        pos.y = (int)rand() % ((int)GAME_SIZE.y - 100) + 100;
        vel.x = _arrowSpeed;
        if (rand() % 2) {
            vel.x *= -1;
            pos.x = GAME_SIZE.x;
        }
        vel.y = rand() % 3 * (pos.y < 400 ? 1 : -1);
    }
    _arrows.emplace_back(std::make_unique<Arrow>(_arrowSize, pos, vel));
    // std::cerr << "creating arrow at: " << pos.x << ", " << pos.y << " vel: " << vel.x << ", " << vel.y << std::endl;
}

void TomatoSurvivor::spawnBonus() {
    _bonuses.emplace_back(std::make_unique<Bonus>(
        _bonusSize, (int)rand() % (int)GAME_SIZE.x, (int)rand() % (int)GAME_SIZE.y));
}

void TomatoSurvivor::increaseDifficulty() {
    _arrowSpeed *= 1.2;
    _arrowSize += 1.0;
    _arrowDamage *= 1.5;
    _arrowSpawnDelay *= 0.8;
    _maxNumberArrows += 1.0;
}

} // namespace TomatoSurvivor

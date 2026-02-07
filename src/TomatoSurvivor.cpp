#include <random>
#include <algorithm>

#include "entity/Tomato.hpp"
#include "entity/Arrow.hpp"
#include "entity/Bonus.hpp"
#include "TomatoSurvivor.hpp"

namespace TomatoSurvivor
{

TomatoSurvivor::TomatoSurvivor() {
    InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "raylib [core] example - input keys");
    srand(time(0));
    SetTargetFPS(60);

    _tomato = std::make_unique<Tomato>(WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2);
    spawnBonus();
}

TomatoSurvivor::~TomatoSurvivor() {
    CloseWindow();
}

void TomatoSurvivor::update() {
    if (_tomato)
        _tomato->update();
    for (auto &arrow : _arrows)
        arrow->update();
    for (auto &bonus : _bonuses)
        bonus->update();
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
    DrawText(TextFormat("TIME: %.0f SECONDS", _timer), 10, 10, 20, BLACK);
    DrawText(TextFormat("SCORE: %.0f", _score), 10, 30, 20, BLACK);

    EndDrawing();
}

void TomatoSurvivor::loop() {
    while (!WindowShouldClose()) {
        _timer -= GetFrameTime();
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
}

void TomatoSurvivor::checkCollisionsBonuses() {
    for (auto &bonus : _bonuses) {
        if (CheckCollisionCircles(_tomato->getPosition(), _tomato->getRadius(),
            bonus->getPosition(), bonus->getRadius())) {
            _timer += 10;
            _score += 100;
            _bonuses.erase(std::remove(_bonuses.begin(), _bonuses.end(), bonus), _bonuses.end());
            spawnBonus();
        }
    }
}

void TomatoSurvivor::spawnArrow() {
    // _arrows.push_back(std::make_unique<Arrow>(
    //     (int)rand() % (int)WINDOW_SIZE.x, (int)rand() % (int)WINDOW_SIZE.y));
}

void TomatoSurvivor::spawnBonus() {
    _bonuses.push_back(std::make_unique<Bonus>(
        (int)rand() % (int)WINDOW_SIZE.x, (int)rand() % (int)WINDOW_SIZE.y));
}

} // namespace TomatoSurvivor

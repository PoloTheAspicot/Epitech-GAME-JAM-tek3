#include <random>
#include <algorithm>
#include <iostream>

#include "entity/Tomato.hpp"
#include "entity/Arrow.hpp"
#include "entity/Bonus.hpp"
#include "TomatoSurvivor.hpp"
#include "Pause.hpp"

namespace TomatoSurvivor
{

void TomatoSurvivor::initializePowerUps() {
    _allPowerUps.push_back(PowerUp(80.0, &_bonusTimeGain, 10.0, PowerUp::OPERATION::ADD,
        "Bonuses grant you more seconds"));
    _allPowerUps.push_back(PowerUp(50.0, &_bonusScore, 1.5, PowerUp::OPERATION::MUL,
        "Bonuses grant you half more score"));
    _allPowerUps.push_back(PowerUp(50.0, &_playerSpeed, 1.5, PowerUp::OPERATION::ADD,
        "Grants you faster movements"));
    _allPowerUps.push_back(PowerUp(30.0, &_arrowSpeed, 1.2, PowerUp::OPERATION::DIV,
        "Arrows move slower"));
    _allPowerUps.push_back(PowerUp(100.0, &_arrowDamage, 1.5, PowerUp::OPERATION::DIV,
        "Arrows deal less damage to you"));
    _allPowerUps.push_back(PowerUp(80.0, &_maxNumberArrows, 1.0, PowerUp::OPERATION::SUB,
        "Less arrows will spawn"));
    _allPowerUps.push_back(PowerUp(150.0, &_playerInvincibility, 10.0, PowerUp::OPERATION::ADD,
        "Become invincible for a sort period of time"));
}

TomatoSurvivor::TomatoSurvivor() {
    InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Tomato Survivor");
    InitAudioDevice();
    srand(time(0));
    SetTargetFPS(60);

    _tomato = std::make_unique<Tomato>(_playerSpeed, _playerSize, WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2, _playerSpeed);
    tomato_texture = LoadTexture("assets/tomato.png");
    tomato_texture.height = _playerSize*2;
    tomato_texture.width = _playerSize*2;
    water_texture = LoadTexture("assets/water_bucket.png");
    water_texture.height = _bonusSize*2;
    water_texture.width = _bonusSize*2;
    arrow_texture = LoadTexture("assets/arrow.png");
    arrow_texture.height = _arrowSize*4;
    arrow_texture.width = _arrowSize*4;
    _tomato->setTexture(tomato_texture);
    spawnBonus();
    music = LoadMusicStream("assets/Tears.ogg");
    volume = 0.9f;
    pan = 0.0f;
    SetMusicPan(music, pan);
    SetMusicVolume(music, volume);
    still_alive = true;
    show_hitbox = false;
    initializePowerUps();
}

TomatoSurvivor::~TomatoSurvivor() {
    CloseWindow();
}

void TomatoSurvivor::reset() {
    _arrows.clear();
    _bonuses.clear();
    _timer = 300;
    _score = 0.0;
    _playerSpeed = 3.0;
    _playerSize = 50.0;
    _arrowSpeed = 2.0;
    _arrowSize = 10.0;
    _arrowDamage = 20.0;
    _arrowSpawnDelay = 2.0;
    _maxNumberArrows = 3.0;
    _nextArrowSpawn = _arrowSpawnDelay;
    _bonusSize = 30.0;
    _bonusTimeGain = 10.0;
    _bonusScore = 100.0;
    _invincibilityTime = 0.5;
    _playerInvincibility = 0.0;
    _spawnShopDelay = 20.0;
    _nextShopSpawn = _spawnShopDelay;
    _next_DifficultyLevel = DIFFICULTY_INC;
    _tomato->setPosition({WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2});
    spawnBonus();
    still_alive = true;
    return_to_menu = false;
    abandoned = false;
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
    for (auto &bonus : _bonuses)
        bonus->update();
        if (arrow->getPosition().x > GAME_SIZE.x)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
        else if (arrow->getPosition().y > GAME_SIZE.y)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
        else if (arrow->getPosition().x < 0)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
        else if (arrow->getPosition().y < 0)
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
    }
    UpdateMusicStream(music);
}

void TomatoSurvivor::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (_tomato)
        _tomato->render(show_hitbox);
    for (auto &arrow : _arrows)
        arrow->render(show_hitbox);
    for (auto &bonus : _bonuses)
        bonus->render(show_hitbox);
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
    PlayMusicStream(music);
    while (!WindowShouldClose() && still_alive) {
        _timer -= GetFrameTime();
        _nextShopSpawn -= GetFrameTime();
        if (_nextArrowSpawn > 0)
            _nextArrowSpawn -= GetFrameTime();
        if (_playerInvincibility > 0)
            _playerInvincibility -= GetFrameTime();
        
        if (_nextShopSpawn <= 0) {
            _nextShopSpawn = _spawnShopDelay;
            /*
            Ajouter une fonction qui fait :
            - met le jeu en pause (obv)
            - choisit 3 powerup differents aléatoirement
            - les displays côte à côte avec leur fonction render(?) (-> à faire mais ez juste la description et le cost)
            - display un bouton "ignore choices"
            - quand le joueur clique sur un powerup, appeler PowerUp->operate, true si c bon et false s'il peut pas payer
            - et voilà on quitte et on revient au jeu
            - après avoir appeler operate, appeler _tomato->setSpeed(_playerSpeed); c important
            */
        }
        if (_nextArrowSpawn <= 0 && _arrows.size() < _maxNumberArrows) {
            _nextArrowSpawn = _arrowSpawnDelay;
            spawnArrow();
        }
        update();
        checkCollisions();
        render();
        if (IsKeyPressed(Config::KEY_PAUSE))
            pause_menu();
        if (IsKeyPressed(KEY_LEFT_CONTROL)) {
            if (!show_hitbox)
                show_hitbox = 1;
            else
                show_hitbox = 0;
        }
        if (_timer <= 0) {
            still_alive = false;
        }
    }
    
    if (!WindowShouldClose()) {
        death_menu();
    }
}

void TomatoSurvivor::checkCollisions() {
    checkCollisionsArrows();
    checkCollisionsBonuses();
}

void TomatoSurvivor::checkCollisionsArrows() {
    if (_playerInvincibility > 0)
        return;
    for (unsigned int i = 0; i < _arrows.size(); i++) {
        auto &arrow = _arrows[i];
        if (CheckCollisionCircles(_tomato->getPosition(), _tomato->getRadius(),
            arrow->getPosition(), arrow->getRadius())) {
            _arrows.erase(std::remove(_arrows.begin(), _arrows.end(), _arrows[i]), _arrows.end());
            _timer -= _arrowDamage;
            _playerInvincibility = _invincibilityTime;
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
    for (auto& arrow : _arrows)
        arrow->setTexture(arrow_texture);
}

void TomatoSurvivor::spawnBonus() {
    _bonuses.emplace_back(std::make_unique<Bonus>(
        _bonusSize, (int)rand() % (int)GAME_SIZE.x, (int)rand() % (int)GAME_SIZE.y));
    for (auto& bonus : _bonuses)
        bonus->setTexture(water_texture);
}

void TomatoSurvivor::increaseDifficulty() {
    _arrowSpeed *= 1.25;
    _arrowSize *= 1.5;
    _arrowDamage += 10.0;
    _arrowSpawnDelay *= 0.75;
    _maxNumberArrows += 1.0;
}

} // namespace TomatoSurvivor

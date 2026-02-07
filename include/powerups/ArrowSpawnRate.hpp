#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class ArrowSpawnRate : public APowerUp {
  public:
    ArrowSpawnRate(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Arrow Spawn Rate";
        std::mt19937 gen{std::random_device{}()};
        _power.arrowSpawnRate = -0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases arrow spawn rate by %d%.",
            static_cast<int>(_power.arrowSpawnRate * 100));
    }

    ~ArrowSpawnRate() = default;
};

} // namespace TomatoSurvivor

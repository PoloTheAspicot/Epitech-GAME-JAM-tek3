#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class BonusSpawnRate : public APowerUp {
  public:
    BonusSpawnRate(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Bonus Spawn Rate";
        std::mt19937 gen{std::random_device{}()};
        _power.bonusSpawnRate = 0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases bonus spawn rate by %d%.",
            static_cast<int>(_power.bonusSpawnRate * 100));
    }

    ~BonusSpawnRate() = default;
};

} // namespace TomatoSurvivor

#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class PlayerSpeed : public APowerUp {
  public:
    PlayerSpeed(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Player Speed";
        std::mt19937 gen{std::random_device{}()};
        _power.playerSpeed = 0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases player speed by %d%.",
            static_cast<int>(_power.playerSpeed * 100));
    }

    ~PlayerSpeed() = default;
};

} // namespace TomatoSurvivor

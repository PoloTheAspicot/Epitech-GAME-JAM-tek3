#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class ArrowSpeed : public APowerUp {
  public:
    ArrowSpeed(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Arrow Speed";
        std::mt19937 gen{std::random_device{}()};
        _power.arrowSpeed = -0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases arrow speed by %d%.",
            static_cast<int>(_power.arrowSpeed * 100));
    }

    ~ArrowSpeed() = default;
};

} // namespace TomatoSurvivor

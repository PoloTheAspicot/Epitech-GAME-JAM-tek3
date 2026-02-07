#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class ArrowSize : public APowerUp {
  public:
    ArrowSize(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Arrow Size";
        std::mt19937 gen{std::random_device{}()};
        _power.arrowSize = -0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases arrow size by %d%.",
            static_cast<int>(_power.arrowSize * 100));
    }

    ~ArrowSize() = default;
};

} // namespace TomatoSurvivor

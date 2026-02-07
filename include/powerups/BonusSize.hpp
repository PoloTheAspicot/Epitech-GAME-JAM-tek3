#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class BonusSize : public APowerUp {
  public:
    BonusSize(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Bonus Size";
        std::mt19937 gen{std::random_device{}()};
        _power.bonusSize = 0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases bonus size by %d%.",
            static_cast<int>(_power.bonusSize * 100));
    }

    ~BonusSize() = default;
};

} // namespace TomatoSurvivor

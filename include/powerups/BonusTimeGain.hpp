#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class BonusTimeGain : public APowerUp {
  public:
    BonusTimeGain(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Bonus Time Gain";
        std::mt19937 gen{std::random_device{}()};
        _power.bonusTimeGain = 0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases bonus time gain by %d%.",
            static_cast<int>(_power.bonusTimeGain * 100));
    }

    ~BonusTimeGain() = default;
};

} // namespace TomatoSurvivor

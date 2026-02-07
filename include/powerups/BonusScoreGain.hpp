#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class BonusScoreGain : public APowerUp {
  public:
    BonusScoreGain(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Bonus Score Gain";
        std::mt19937 gen{std::random_device{}()};
        _power.bonusScoreGain = 0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases bonus score gain by %d%.",
            static_cast<int>(_power.bonusScoreGain * 100));
    }

    ~BonusScoreGain() = default;
};

} // namespace TomatoSurvivor

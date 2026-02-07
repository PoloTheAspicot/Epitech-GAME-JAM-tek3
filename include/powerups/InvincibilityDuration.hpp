#pragma once

#include <random>

#include "APowerUp.hpp"

namespace TomatoSurvivor {
class InvincibilityDuration : public APowerUp {
  public:
    InvincibilityDuration(float x, float y) {
        _position = {x, y};
        _size = {20, 20};
        _name = "Invincibility Duration";
        std::mt19937 gen{std::random_device{}()};
        _power.invincibilityDuration = 0.1f *
            std::normal_distribution<float>{1.0f, 0.5f}(gen);
        _description = TextFormat("Increases invincibility duration by %d%.",
            static_cast<int>(_power.invincibilityDuration * 100));
    }

    ~InvincibilityDuration() = default;
};

} // namespace TomatoSurvivor

#pragma once

struct Power {
    float playerSpeed = 0.0f;
    float arrowSpeed = 0.0f;
    float arrowSize = 0.0f;
    float arrowSpawnRate = 0.0f;
    float bonusSpawnRate = 0.0f;
    float bonusSize = 0.0f;
    float bonusTimeGain = 0.0f;
    float bonusScoreGain = 0.0f;
    float invincibilityDuration = 0.0f;
};


namespace TomatoSurvivor {
class IPowerUp {
  public:
    virtual ~IPowerUp() = default;
    virtual void render() = 0;
    virtual Power getPower() = 0;
};

} // namespace TomatoSurvivor

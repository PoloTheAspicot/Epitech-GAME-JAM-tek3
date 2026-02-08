#pragma once

#include <raylib.h>

#include <iostream>
#include <string>
#include <memory>

namespace TomatoSurvivor {

class PowerUp {
  public:
    enum OPERATION {
        ADD,
        SUB,
        DIV,
        MUL,
    };
    PowerUp(float _cost, float *ref, float _value,
        OPERATION op, const char *descr);
    ~PowerUp() = default;

    bool canBuy(float timer) const;
    bool operate(float &timer) const;
    bool render(float timer, float offset, Vector2 mouse) const;

  private:
    float cost;
    float *param;
    float value;
    OPERATION operation;
    const char *description;
};

} // namespace TomatoSurvivor

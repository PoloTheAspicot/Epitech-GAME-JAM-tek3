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
        OPERATION op, std::string descr);
    ~PowerUp() = default;

    bool operate(float &timer) const;
    void render() const;

  private:
    float cost;
    float *param;
    float value;
    OPERATION operation;
    std::string description;
};

} // namespace TomatoSurvivor

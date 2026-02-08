#include "PowerUps.hpp"

namespace TomatoSurvivor
{

PowerUp::PowerUp(float _cost, float *ref, float _value,
    OPERATION op, std::string descr) {
    cost = _cost;
    param = ref;
    value = _value;
    operation = op;
    description = descr;
}

bool PowerUp::operate(float &timer) const {
    if (timer <= cost)
        return false;
    switch (operation) {
        case ADD:
            *param += value;
            break;
        case SUB:
            *param -= value;
            break;
        case DIV:
            *param /= value;
            break;
        case MUL:
            *param *= value;
            break;
        default:
            break;
    }
    return true;
}

}
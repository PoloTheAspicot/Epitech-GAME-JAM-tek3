#include "PowerUps.hpp"

namespace TomatoSurvivor
{

PowerUp::PowerUp(float _cost, float *ref, float _value,
    OPERATION op, const char *descr) {
    cost = _cost;
    param = ref;
    value = _value;
    operation = op;
    description = descr;
}

bool PowerUp::canBuy(float &timer) const {
    return (timer > cost);
}

bool PowerUp::operate(float &timer) const {
    if (!canBuy(timer))
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
    timer -= cost;
    return true;
}

bool PowerUp::render(float &timer, float offset, Vector2 mouse) const {
    Rectangle button = {offset, 100, 200, 500};
    bool hover = CheckCollisionPointRec(mouse, button);
    bool possible = canBuy(timer);

    if (possible)
        DrawRectangleRec(button, hover ? BLUE : DARKBLUE);
    else
        DrawRectangleRec(button, RED);
    DrawText(TextFormat("%s\nCost: %.0f", description, cost), button.x, button.y, 30, WHITE);
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover && possible)
        return true;
    return false;
}

}
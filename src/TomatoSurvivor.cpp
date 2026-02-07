#include "TomatoSurvivor.hpp"

namespace Tomato {

void TomatoSurvivor::update() {
    if (_tomato)
        _tomato->update();
    for (auto &sword : _swords)
        sword->update();
};

void TomatoSurvivor::render() {
    if (_tomato)
        _tomato->render();
    for (auto &sword : _swords)
        sword->render();
};

void TomatoSurvivor::loop() {
    while (true) {
        update();
        render();
    }
};

} // namespace Tomato

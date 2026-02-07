#include "entity/AEntity.hpp"

namespace Tomato {

void AEntity::update() {
    position.x += velocity.x;
    position.y += velocity.y;
};

void AEntity::render() {
};

} // namespace Tomato

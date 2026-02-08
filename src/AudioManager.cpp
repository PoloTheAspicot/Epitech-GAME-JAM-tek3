#include "AudioManager.hpp"

namespace AudioManager {

static Sound clickSound;
static Sound damageSound;
static Sound bonusSound;

void init() {
    clickSound = LoadSound("assets/minecraft_click.mp3");
    damageSound = LoadSound("assets/minecraft-critical-hit.mp3");
    bonusSound = LoadSound("assets/water-splashing.mp3");
}

void unload() {
    UnloadSound(clickSound);
    UnloadSound(damageSound);
    UnloadSound(bonusSound);
}

void playClick() { PlaySound(clickSound); }
void playDamage() { PlaySound(damageSound); }
void playBonus() { PlaySound(bonusSound); }

} // namespace AudioManager

#include "TomatoSurvivor.hpp"
#include "Menu.hpp"

int main(void)
{
    TomatoSurvivor::TomatoSurvivor game;
    menu();
    game.loop();
    return 0;
}

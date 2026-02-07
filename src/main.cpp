#include "TomatoSurvivor.hpp"
#include "Menu.hpp"
#include "Save.hpp"

int main(void)
{
    TomatoSurvivor::TomatoSurvivor game;
    SaveManager::loadData();
    menu();
    game.loop();
    SaveManager::writeSave();
    return 0;
}

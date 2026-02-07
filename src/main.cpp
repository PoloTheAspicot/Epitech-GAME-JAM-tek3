#include "TomatoSurvivor.hpp"
#include "Menu.hpp"
#include "Save.hpp"

int main(void)
{
    SaveManager::loadData();
    TomatoSurvivor::TomatoSurvivor game;
    
    bool running = true;
    while (running && !WindowShouldClose()) {
        menu();
        
        if (WindowShouldClose()) {
            break;
        }
        
        game.reset();
        game.loop();
        
        // After game ends, if return_to_menu is true, loop back to menu
        if (!game.return_to_menu || WindowShouldClose()) {
            running = false;
        }
    }
    
    SaveManager::writeSave();
    return 0;
}

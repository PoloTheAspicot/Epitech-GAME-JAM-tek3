#include <raylib.h>
#include <cstdlib>
#include "TomatoSurvivor.hpp"
#include "Save.hpp"

namespace TomatoSurvivor {

void TomatoSurvivor::death_menu()
{
    // Update best score if current score is better
    SaveManager::updateBestScore(static_cast<int>(getScore()));
    SaveManager::writeSave();

    Texture2D bg = LoadTexture("assets/background.jpg");
    bg.height = 900;
    bg.width = 800;
    
    bool waiting_for_input = true;
    while (!WindowShouldClose() && waiting_for_input)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(bg, 0, 0, WHITE);
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f));
        DrawText("GAME OVER", 200, 300, 60, RED);
        DrawText(TextFormat("Final Score: %.0f", getScore()), 180, 380, 30, BLACK);
        DrawText(TextFormat("Best Score: %d", SaveManager::getBestScore()), 210, 430, 30, BLACK);
        DrawText("Press ENTER to return to menu", 160, 520, 25, YELLOW);
        EndDrawing();
        
        if (IsKeyPressed(KEY_ENTER)) {
            waiting_for_input = false;
            return_to_menu = true;
        }
    }
    
    UnloadTexture(bg);
}

} // namespace TomatoSurvivor
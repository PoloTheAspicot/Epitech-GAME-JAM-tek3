#include <raylib.h>
#include <cstdlib>
#include "AudioManager.hpp"

void shop()
{
    bool starting = false;
    Texture2D bg = LoadTexture("assets/background.jpg");
    bg.height = 900;
    bg.width = 800;
    while (!WindowShouldClose() && !starting)
    {
        Vector2 mouse = GetMousePosition();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(bg, 0, 0, WHITE);
        DrawText("Unlocked at 1 000 000 score", 70, 400, 45, RED);
        DrawText("Press enter to return", 260, 500, 20, BLACK);
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER)) {
            AudioManager::playClick();
            starting = true;
        }
    }
    ClearBackground(RAYWHITE);
    if (!starting) {
        CloseWindow();
        exit(0);
    }
}
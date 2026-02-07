#include <raylib.h>
#include <cstdlib>
#include "TomatoSurvivor.hpp"

namespace TomatoSurvivor {

void TomatoSurvivor::pause_menu()
{
    bool returning = false;
    bool abandoning = false;
    Texture2D bg = LoadTexture("assets/background.jpg");
    bg.height = 900;
    bg.width = 800;
    
    Rectangle resume_btn = {275, 350, 250, 60};
    Rectangle abandon_btn = {275, 480, 250, 80};
    
    while (!WindowShouldClose() && !returning && !abandoning)
    {
        Vector2 mouse = GetMousePosition();
        bool hover_resume = CheckCollisionPointRec(mouse, resume_btn);
        bool hover_abandon = CheckCollisionPointRec(mouse, abandon_btn);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(bg, 0, 0, WHITE);
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.4f));
        DrawText("PAUSE", 280, 150, 80, YELLOW);
        DrawRectangleRec(resume_btn, hover_resume ? LIGHTGRAY : GRAY);
        DrawText("RESUME (ENTER)", 290, 365, 25, BLACK);
        DrawRectangleRec(abandon_btn, hover_abandon ? Fade(RED, 0.5f) : RED);
        DrawText("ABANDON", 330, 505, 30, WHITE);
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER) || (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_resume)) {
            returning = true;
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_abandon) {
            abandoning = true;
        }
    }
    
    UnloadTexture(bg);
    if (abandoning) {
        still_alive = false;
        return_to_menu = true;
        abandoned = true;
    }
}

} // namespace TomatoSurvivor
#include <raylib.h>
#include <cstdlib>

#define X_POS (800-371)/2

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
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER))
            starting = true;
    }
    ClearBackground(RAYWHITE);
    if (!starting) {
        CloseWindow();
        exit(0);
    }
}
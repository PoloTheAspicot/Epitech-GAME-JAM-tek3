#include <raylib.h>
#include <cstdlib>

void pause_menu()
{
    bool starting = false;
    Texture2D bg = LoadTexture("assets/background.jpg");
    bg.height = 900;
    bg.width = 800;
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(WHITE, 0.5f));
    while (!WindowShouldClose() && !starting)
    {
        Vector2 mouse = GetMousePosition();

        BeginDrawing();
        DrawText("Pause Menu", 200, 400, 60, BLUE);
        DrawText("Press enter to return", 260, 500, 20, BLACK);
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
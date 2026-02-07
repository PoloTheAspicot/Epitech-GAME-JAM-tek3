#include <raylib.h>
#include <ctime>
#include <random>

#define WINDOW_SIZE 600

int main(void)
{
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "raylib [core] example - input keys");

    srand(time(0));
    Vector2 ballPosition = { (float)WINDOW_SIZE/2, (float)WINDOW_SIZE/2 };
    Vector2 bonusPosition = { (int)rand() % WINDOW_SIZE, (int)rand() % WINDOW_SIZE };
    float timer = 300;
    float score = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        timer -= GetFrameTime();
        if (CheckCollisionCircles(ballPosition, 40, bonusPosition, 30)) {
            bonusPosition = { (int)rand() % WINDOW_SIZE, (int)rand() % WINDOW_SIZE };
            timer += 10;
            score += 100;
        }
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircleV(ballPosition, 40, RED);

            DrawCircleV(bonusPosition, 30, GREEN);

            DrawText(TextFormat("TIME: %.0f SECONDS", timer), 10, 10, 20, BLACK);
            DrawText(TextFormat("SCORE: %.0f", score), 10, 30, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}


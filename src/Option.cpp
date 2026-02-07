#include <raylib.h>
#include <cstdlib>

#define X_POS (800-371)/2

void menu()
{
    SetTargetFPS(60);
    bool starting = false;
    Texture2D button = LoadTexture("assets/button.png");
    Rectangle button_hitbox_play = {X_POS, 250, 371, 99};
    Rectangle button_hitbox_option = {X_POS, 450, 371, 99};
    Texture2D shop = LoadTexture("assets/cart.png");
    shop.height = 128;
    shop.width = 128;
    Rectangle hitbox_shop = {800-128, 900-128, 128, 128};
    Texture2D bg = LoadTexture("assets/background.jpg");
    bg.height = 900;
    bg.width = 800;
    while (!WindowShouldClose() && !starting)
    {
        Vector2 mouse = GetMousePosition();
        bool hover = CheckCollisionPointRec(mouse, button_hitbox_play);
        bool hover_option = CheckCollisionPointRec(mouse, button_hitbox_option);
        bool hover_shop = CheckCollisionPointRec(mouse, hitbox_shop);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(bg, 0, 0, WHITE);
        Color tint = hover ? GRAY : WHITE;
        Color tint_option = hover_option ? GRAY : WHITE;
        Color tint_shop = hover_shop ? GREEN : WHITE;
        DrawTexture(button, X_POS, 250, tint);
        DrawTexture(button, X_POS, 450, tint_option);
        DrawTexture(shop, 800-128, 900-128, tint_shop);
        DrawText("PLAY", 340, 280, 40, tint);
        DrawText("OPTION", 320, 480, 40, tint_option);
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover)
            starting = true;
    }
    ClearBackground(RAYWHITE);
    if (!starting) {
        CloseWindow();
        exit(0);
    }
}
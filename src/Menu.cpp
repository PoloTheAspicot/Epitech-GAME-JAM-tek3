#include <raylib.h>
#include <cstdlib>
#include "Option.hpp"
#include "Shop.hpp"
#include "Save.hpp"

#define X_POS (800-371)/2

void menu()
{
    SetTargetFPS(60);
    bool starting = false;
    Image title_image = LoadImage("assets/title.png");
    ImageResize(&title_image, 554, 202);
    Texture2D title = LoadTextureFromImage(title_image);
    Texture2D button = LoadTexture("assets/button.png");
    Rectangle button_hitbox_play = {X_POS, 230, 371, 99};
    Rectangle button_hitbox_option = {X_POS, 400, 371, 99};
    Texture2D shop_tex = LoadTexture("assets/cart.png");
    shop_tex.height = 128;
    shop_tex.width = 128;
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
        DrawTexture(title, 130, 0, WHITE);
        DrawTexture(button, X_POS, 230, tint);
        DrawTexture(button, X_POS, 400, tint_option);
        DrawTexture(shop_tex, 800-128, 900-128, tint_shop);
        DrawText("PLAY", 340, 260, 40, tint);
        DrawText("OPTION", 320, 430, 40, tint_option);
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover)
            starting = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_option)
            option();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_shop)
            shop();
    }
    ClearBackground(RAYWHITE);
    if (!starting) {
        // write save before exiting
        SaveManager::writeSave();
        CloseWindow();
        exit(0);
    }
}
#include <raylib.h>
#include <cstdlib>
#include <string>
#include "Config.hpp"

const char* GetKeyName(int key) {
    switch (key) {
        case KEY_UP: return "UP";
        case KEY_DOWN: return "DOWN";
        case KEY_LEFT: return "LEFT";
        case KEY_RIGHT: return "RIGHT";
        case KEY_W: return "Z";
        case KEY_S: return "S";
        case KEY_A: return "Q";
        case KEY_D: return "D";
        case KEY_Q: return "A";
        case KEY_E: return "E";
        case KEY_R: return "R";
        case KEY_T: return "T";
        case KEY_Y: return "Y";
        case KEY_U: return "U";
        case KEY_I: return "I";
        case KEY_O: return "O";
        case KEY_P: return "P";
        case KEY_F: return "F";
        case KEY_G: return "G";
        case KEY_H: return "H";
        case KEY_J: return "J";
        case KEY_K: return "K";
        case KEY_L: return "L";
        case KEY_Z: return "W";
        case KEY_X: return "X";
        case KEY_C: return "C";
        case KEY_V: return "V";
        case KEY_B: return "B";
        case KEY_N: return "N";
        case KEY_SEMICOLON: return "M";
        case KEY_EIGHT: return "8";
        case KEY_FOUR: return "4";
        case KEY_SIX: return "6";
        case KEY_TWO: return "2";
        case KEY_SPACE: return "SPACE";
        case KEY_ENTER: return "ENTER";
        default: return "UNKNOWN";
    }
}

void option()
{
    bool starting = false;
    Texture2D bg = LoadTexture("assets/background.jpg");
    bg.height = 900;
    bg.width = 800;

    int selecting = -1;

    while (!WindowShouldClose() && !starting)
    {
        Vector2 mouse = GetMousePosition();

        if (selecting != -1) {
            int key = GetKeyPressed();
            if (key != 0) {
                if (selecting == 0) Config::KEY_UP_MOVE = (KeyboardKey)key;
                if (selecting == 1) Config::KEY_DOWN_MOVE = (KeyboardKey)key;
                if (selecting == 2) Config::KEY_LEFT_MOVE = (KeyboardKey)key;
                if (selecting == 3) Config::KEY_RIGHT_MOVE = (KeyboardKey)key;
                selecting = -1;
            }
        }

        Rectangle rectUp = { 300, 200, 200, 40 };
        Rectangle rectDown = { 300, 250, 200, 40 };
        Rectangle rectLeft = { 300, 300, 200, 40 };
        Rectangle rectRight = { 300, 350, 200, 40 };

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mouse, rectUp)) selecting = 0;
            else if (CheckCollisionPointRec(mouse, rectDown)) selecting = 1;
            else if (CheckCollisionPointRec(mouse, rectLeft)) selecting = 2;
            else if (CheckCollisionPointRec(mouse, rectRight)) selecting = 3;
            else selecting = -1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(bg, 0, 0, WHITE);

        DrawText("OPTIONS - KEYBINDINGS", 200, 100, 30, BLACK);
        DrawText("Click to remap", 320, 150, 20, DARKGRAY);
        DrawRectangleRec(rectUp, selecting == 0 ? LIGHTGRAY : GRAY);
        DrawText(TextFormat("UP: %s", GetKeyName(Config::KEY_UP_MOVE)), rectUp.x + 10, rectUp.y + 10, 20, BLACK);
        DrawRectangleRec(rectDown, selecting == 1 ? LIGHTGRAY : GRAY);
        DrawText(TextFormat("DOWN: %s", GetKeyName(Config::KEY_DOWN_MOVE)), rectDown.x + 10, rectDown.y + 10, 20, BLACK);
        DrawRectangleRec(rectLeft, selecting == 2 ? LIGHTGRAY : GRAY);
        DrawText(TextFormat("LEFT: %s", GetKeyName(Config::KEY_LEFT_MOVE)), rectLeft.x + 10, rectLeft.y + 10, 20, BLACK);
        DrawRectangleRec(rectRight, selecting == 3 ? LIGHTGRAY : GRAY);
        DrawText(TextFormat("RIGHT: %s", GetKeyName(Config::KEY_RIGHT_MOVE)), rectRight.x + 10, rectRight.y + 10, 20, BLACK);
        DrawText("Press ENTER to save", 290, 500, 20, BLACK);

        EndDrawing();
        if (IsKeyPressed(KEY_ENTER) && selecting == -1)
            starting = true;
    }
    UnloadTexture(bg);
    ClearBackground(RAYWHITE);
    if (!starting) {
        CloseWindow();
        exit(0);
    }
}

#include "TomatoSurvivor.hpp"

namespace TomatoSurvivor {

void TomatoSurvivor::ChosePowerUp() {
    std::vector<PowerUp> randomPowerUps;
    std::vector<int> indexes;
    int len = _allPowerUps.size();
    bool choice_made = false;
    Rectangle ignore_button = {300, 650, 200, 100};

    for (int i = 0; i < 3; i++) {
        int randomIndex = rand() % len;
        indexes.push_back(randomIndex);
    }
    for (int i = 0; i < indexes.size(); i++) {
        randomPowerUps.push_back(_allPowerUps[i]);
    }

    while (!WindowShouldClose() && !choice_made) {
        Vector2 mouse = GetMousePosition();
        bool hover_ignore = CheckCollisionPointRec(mouse, ignore_button);

        BeginDrawing();
        ClearBackground(ORANGE);
        DrawText(TextFormat("%s%.1f", TEXT_TIME, _timer), 300, 20, 40, RED);
        DrawText(TextFormat("%s%.1f", TEXT_TIME, _timer), 300 + 2, 20 + 2, 40, WHITE);
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.4f));
        for (int i = 0; i < randomPowerUps.size(); i++) {
            if (randomPowerUps[i].render(_timer, i * 250 + 50, mouse)) {
                choice_made = randomPowerUps[i].operate(_timer);
            }
        }
        DrawRectangleRec(ignore_button, RED);
        DrawText(TextFormat("IGNORE OFFERS"), 310, 650, 25, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hover_ignore)
            choice_made = true;
        EndDrawing();
    }
}

}
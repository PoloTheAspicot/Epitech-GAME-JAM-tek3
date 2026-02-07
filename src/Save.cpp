#include "json.hpp"
#include "Save.hpp"
#include "Config.hpp"

#include <fstream>
#include <iostream>
#include <sys/stat.h>

using json = nlohmann::json;

namespace {
    bool file_exists(const std::string &path) {
        struct stat buffer;
        return (stat(path.c_str(), &buffer) == 0);
    }
    int s_money = 0;
    int s_best_previous_score = 0;
}

namespace SaveManager {

void loadData(const std::string &path)
{
    if (!file_exists(path)) {
        s_money = 0;
        s_best_previous_score = 0;
        writeSave(path);
        return;
    }

    std::ifstream in(path);
    if (!in.is_open()) {
        std::cerr << "Failed to open save file for reading: " << path << std::endl;
        return;
    }

    try {
        json save;
        in >> save;

        if (save.contains("up_key")) Config::KEY_UP_MOVE = static_cast<KeyboardKey>(save["up_key"].get<int>());
        if (save.contains("down_key")) Config::KEY_DOWN_MOVE = static_cast<KeyboardKey>(save["down_key"].get<int>());
        if (save.contains("left_key")) Config::KEY_LEFT_MOVE = static_cast<KeyboardKey>(save["left_key"].get<int>());
        if (save.contains("right_key")) Config::KEY_RIGHT_MOVE = static_cast<KeyboardKey>(save["right_key"].get<int>());
        if (save.contains("pause_key")) Config::KEY_PAUSE = static_cast<KeyboardKey>(save["pause_key"].get<int>());
        if (save.contains("money")) s_money = save["money"].get<int>();
        if (save.contains("best_previous_score")) s_best_previous_score = save["best_previous_score"].get<int>();
    } catch (const std::exception &e) {
        std::cerr << "Error parsing save file: " << e.what() << std::endl;
    }
}

void writeSave(const std::string &path)
{
    json save;
    save["up_key"] = static_cast<int>(Config::KEY_UP_MOVE);
    save["down_key"] = static_cast<int>(Config::KEY_DOWN_MOVE);
    save["left_key"] = static_cast<int>(Config::KEY_LEFT_MOVE);
    save["right_key"] = static_cast<int>(Config::KEY_RIGHT_MOVE);
    save["pause_key"] = static_cast<int>(Config::KEY_PAUSE);
    save["money"] = s_money;
    save["best_previous_score"] = s_best_previous_score;

    std::ofstream out(path);
    if (!out.is_open()) {
        std::cerr << "Failed to open save file for writing: " << path << std::endl;
        return;
    }
    out << save.dump(4);
}

int getBestScore() {
    return s_best_previous_score;
}

void updateBestScore(int score) {
    if (score > s_best_previous_score) {
        s_best_previous_score = score;
    }
}

} // namespace SaveManager

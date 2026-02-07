#ifndef SAVE_HPP
#define SAVE_HPP

#include <string>

namespace SaveManager {
    void loadData(const std::string &path = "save.json");
    void writeSave(const std::string &path = "save.json");
    
    int getBestScore();
    void updateBestScore(int score);
}

#endif // SAVE_HPP
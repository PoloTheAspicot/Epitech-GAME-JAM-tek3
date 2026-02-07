#ifndef SAVE_HPP
#define SAVE_HPP

#include <string>

namespace SaveManager {
    void loadData(const std::string &path = "save.json");
    void writeSave(const std::string &path = "save.json");
    
    // Get and update best score
    int getBestScore();
    void updateBestScore(int score);
}

#endif // SAVE_HPP
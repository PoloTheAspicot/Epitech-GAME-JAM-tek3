#include "../include/json.hpp"
#include "../include/Save.hpp"
using json = nlohmann::json;

void Save()
{
    json save;
    save["up_key"] = "arrow_up";
    save["down_key"] = "arrow_down";
    save["left_key"] = "arrow_left";
    save["right_key"] = "arrow_right";
    save["money"] = 0;
}
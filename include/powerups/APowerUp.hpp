#pragma once

#include <raylib.h>

#include <string>

#include "IPowerUp.hpp"

namespace TomatoSurvivor {

class APowerUp : public IPowerUp {
  public:
    virtual ~APowerUp() = default;

    void render() override {
        DrawRectangle(_position.x, _position.y, _size.x, _size.y, BLACK);
        DrawText(_name.c_str(), _position.x + _size.x + 10, _position.y + 10, 20, BLACK);
        DrawText(_description.c_str(), _position.x + _size.x + 10, _position.y + 30, 20, BLACK);
    }

    Power getPower() override {
        return _power;
    }

  protected:
    Power _power;
    Vector2 _position;
    Vector2 _size;
    std::string _name;
    std::string _description;
};

} // namespace TomatoSurvivor

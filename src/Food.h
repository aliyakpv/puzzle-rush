#ifndef FOOD_H
#define FOOD_H

#include <deque>
#include "raylib.h"

class Food
{
public:
    Vector2 position;
    Texture2D texture;

    Food(std::deque<Vector2> snakeBody);
    ~Food();
    
    void render();
    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody);
};

#endif
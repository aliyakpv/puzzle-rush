#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <deque>
#include "raylib.h"

class Obstacle
{
public:
    std::deque<Vector2> positions;
    Texture2D texture;

    Obstacle(std::deque<Vector2> snakeBody);
    ~Obstacle();
    
    void render();
    Vector2 generateRandomPos(std::deque<Vector2> snakeBody);
};

#endif
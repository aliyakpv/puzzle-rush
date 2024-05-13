#include "Obstacle.h"
#include "Constants.h"
#include "Utils.h"

Obstacle::Obstacle(std::deque<Vector2> snakeBody)
{
    for (int i = 0; i < 10; ++i) { 
        positions.push_back(generateRandomPos(snakeBody));
    }

    Image image = LoadImage("assets/textures/block.png");
    UnloadImage(image);
    texture = LoadTextureFromImage(image);
}

Obstacle::~Obstacle()
{
    UnloadTexture(texture);
}

void Obstacle::render()
{
    for (const auto& pos : positions) {
        
        
        DrawTexture(
            texture, 
            Constants::OFFSET + pos.x * Constants::CELL_SIZE, 
            Constants::OFFSET + pos.y * Constants::CELL_SIZE,
            WHITE
        );
    }
}

Vector2 Obstacle::generateRandomPos(std::deque<Vector2> snakeBody)
{
    Vector2 position = GenerateRandomCell();
    while (ElementInDeque(position, snakeBody))
    {
        position = GenerateRandomCell();
    }
    return position;
}

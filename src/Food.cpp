#include "Food.h"
#include "Utils.h"
#include "Constants.h"

Food::Food(std::deque<Vector2> snakeBody)
{
    Image image = LoadImage("assets/textures/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPos(snakeBody);
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::render()
{
    DrawTexture(
        texture,
        Constants::OFFSET + position.x * Constants::CELL_SIZE,
        Constants::OFFSET + position.y * Constants::CELL_SIZE,
        WHITE
    );
}

Vector2 Food::GenerateRandomPos(std::deque<Vector2> snakeBody)
{
    Vector2 position = GenerateRandomCell();
    while (ElementInDeque(position, snakeBody))
    {
        position = GenerateRandomCell();
    }
    return position;
}

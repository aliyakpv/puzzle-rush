#include "Snake.h"
#include "Constants.h"
#include <raymath.h>

Snake::Snake()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
    addSegment = false;
}

void Snake::render()
{
    for (unsigned int i = 0; i < body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{
            Constants::OFFSET + x * Constants::CELL_SIZE,
            Constants::OFFSET + y * Constants::CELL_SIZE,
            (float)Constants::CELL_SIZE,
            (float)Constants::CELL_SIZE
        };
        DrawRectangleRounded(segment, 0.5, 6, DARKGREEN);
    }
}

void Snake::Update()
{
    body.push_front(Vector2Add(body[0], direction));
    if (addSegment == true)
    {
        addSegment = false;
    }
    else
    {
        body.pop_back();
    }
}

void Snake::Reset()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
}

#include "Utils.h"
#include "Constants.h"
#include <raymath.h>

double lastUpdateTime = 0;

bool ElementInDeque(Vector2 element, std::deque<Vector2>& deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

Vector2 GenerateRandomCell()
{
    float x = GetRandomValue(0, Constants::CELL_COUNT - 1);
    float y = GetRandomValue(0, Constants::CELL_COUNT - 1);
    return Vector2{x, y};
}

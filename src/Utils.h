#ifndef UTILS_H
#define UTILS_H

#include <deque>
#include "raylib.h"

bool ElementInDeque(Vector2 element, std::deque<Vector2>& deque);

bool EventTriggered(double interval);

Vector2 GenerateRandomCell();

#endif
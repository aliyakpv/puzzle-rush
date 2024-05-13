#include "EasyLevel.h"
#include "raylib.h"
#include "Constants.h"
#include <iostream>

void EasyLevel::update() {
    // Update logic for EasyLevel
}

void EasyLevel::render() {
    ClearBackground(WHITE);
    DrawRectangleLinesEx(
        Rectangle{
            (float)Constants::OFFSET - 5,
            (float)Constants::OFFSET - 5,
            (float)Constants::CELL_SIZE * Constants::CELL_COUNT + 10,
            (float)Constants::CELL_SIZE * Constants::CELL_COUNT + 10
        },
        5,
        DARKGREEN
    );
    DrawText("Snake", Constants::OFFSET - 5, 20, 40, DARKGREEN);
}


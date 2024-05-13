#include "HardLevel.h"
#include "raylib.h"
#include "Constants.h"
#include <iostream>

void HardLevel::update() {
    // Update logic for EasyLevel
}

void HardLevel::render() {
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


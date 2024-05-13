#include "MainMenu.h"
#include "GamePlay.h"
#include "EasyLevel.h"
#include "MediumLevel.h"
#include "HardLevel.h"
#include "Game.h"
#include "raylib.h"
#include <iostream>

void MainMenu::handleInput(Game& game) {
    if (IsKeyPressed(KEY_ONE)) {
        levelType = LevelType::Easy;
    } else if (IsKeyPressed(KEY_TWO)) {
        levelType = LevelType::Medium;
    } else if (IsKeyPressed(KEY_THREE)) {
        levelType = LevelType::Hard;
    } else if (IsKeyPressed(KEY_FOUR)) {
        CloseWindow();
    }
}

void MainMenu::update(Game& game) {
    if (this->levelType != LevelType::None){

        GamePlay* gamePlay = new GamePlay();
        Level* level = nullptr;

        switch (this->levelType) {
            case LevelType::Easy:
                level = new EasyLevel();
                break;
            case LevelType::Medium:
                level = new MediumLevel();
                break;
            case LevelType::Hard:
                level = new HardLevel();
                break;
            default:
                std::cout << "Invalid level selected.\n";
                return;
        }

        gamePlay->setLevel(level);
        game.setState(gamePlay);
    }
}

void MainMenu::render(Game& game) {
    ClearBackground(WHITE);

    DrawText("Select a level:", 100, 100, 20, BLACK);
    DrawText("1. Easy", 100, 150, 20, BLACK);
    DrawText("2. Medium", 100, 180, 20, BLACK);
    DrawText("3. Hard", 100, 210, 20, BLACK);
    DrawText("4. Exit", 100, 240, 20, BLACK);
}

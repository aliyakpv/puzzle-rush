#include "Game.h"
#include "GameState.h"
#include "Constants.h"
#include "MainMenu.h"
#include "raylib.h"

Game::Game() : currentState(nullptr) {
    // initial state
    currentState = new MainMenu();
}

Game::~Game() {
    delete currentState;
}

Game& Game::getInstance(){
    static Game instance;
    return instance;
}

void Game::setState(State* state) {
    delete currentState;
    currentState = state;
}

void Game::gameLoop() {
    int height = 2 * Constants::OFFSET + Constants::CELL_SIZE *  Constants::CELL_COUNT;
    int width = 2 *  Constants::OFFSET + Constants::CELL_SIZE *  Constants::CELL_COUNT;

    InitWindow(height, width, "Snake");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(WHITE);

        if (currentState){
            currentState->handleInput(*this);
            currentState->update(*this);
            currentState->render(*this);
        }
        
        EndDrawing();
    }

    CloseWindow();
}

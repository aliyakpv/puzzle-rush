#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game {
private:
    Game(); 
    State* currentState;

public:
    static Game& getInstance();
    ~Game();
    void setState(State* state);
    void gameLoop();
};

#endif 

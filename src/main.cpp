#include "Game.h"

int main() {

    Game& game = Game::getInstance();
    game.gameLoop();

    return 0;
}
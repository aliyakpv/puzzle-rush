#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameState.h"
#include "Level.h"
#include "Snake.h"
#include "Food.h"
#include "Obstacle.h"

class GamePlay : public State {
private:
    Level* currentlevel;
public:
    Snake snake = Snake();
    Food food = Food(snake.body);
    Obstacle obstacle = Obstacle(snake.body);
    bool running = false;
    bool allowMove = false;
    Sound eatSound;
    Sound wallSound;

    void setLevel(Level* level);
    void handleInput(Game& game) override;
    void update(Game& game) override;
    void render(Game& game) override;

    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void CheckCollisionWithObstacle();
    void GameOver();

};

#endif // GAMEPLAY_H
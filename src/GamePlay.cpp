#include "GamePlay.h"
#include "Game.h"
#include "raylib.h"
#include "Utils.h"
#include <iostream>
#include "Constants.h"
#include <raymath.h>


void GamePlay::handleInput(Game& game) {
    if (IsKeyPressed(KEY_UP) && snake.direction.y != 1 && allowMove){
        snake.direction = {0, -1};
        running = true;
        allowMove = false;
    }
    if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1 && allowMove){
        snake.direction = {0, 1};
        running = true;
        allowMove = false;
    }
    if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1 && allowMove){
        snake.direction = {-1, 0};
        running = true;
        allowMove = false;
    }
    if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1 && allowMove){
        snake.direction = {1, 0};
        running = true;
        allowMove = false;
    }
}

void GamePlay::update(Game& game) {
    if (EventTriggered(0.2)){
        allowMove = true;

        if (running){
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
            CheckCollisionWithObstacle();
        }
    }
    
}

void GamePlay::render(Game& game) {
    if (currentlevel) {
        currentlevel->render();
        snake.render();
        food.render();
        obstacle.render();
    }
}

void GamePlay::setLevel(Level* level) {
    delete currentlevel;
    currentlevel = level;
}

void GamePlay::CheckCollisionWithFood(){
    if (Vector2Equals(snake.body[0], food.position)){
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        PlaySound(eatSound);
    }
}

void GamePlay::CheckCollisionWithEdges(){
    if (snake.body[0].x == Constants::CELL_COUNT || snake.body[0].x == -1){
        GameOver();
    }
    if (snake.body[0].y == Constants::CELL_COUNT || snake.body[0].y == -1){
        GameOver();
    }
}

void GamePlay::CheckCollisionWithTail(){
    std::deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if (ElementInDeque(snake.body[0], headlessBody)){
        GameOver();
    }
}

void GamePlay::CheckCollisionWithObstacle(){
    if (ElementInDeque(snake.body[0], obstacle.positions)){
        GameOver();
    }
}

void GamePlay::GameOver(){
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
    PlaySound(wallSound);
}

#ifndef STATE_H
#define STATE_H

class Game;

class State {
public:
    virtual ~State() {}
    virtual void handleInput(Game& game) = 0;
    virtual void update(Game& game) = 0;
    virtual void render(Game& game) = 0;
};

#endif 

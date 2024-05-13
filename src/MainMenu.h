#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"

enum class LevelType {
    None,
    Easy,
    Medium,
    Hard
};

class MainMenu : public State {
private:
    LevelType levelType;
public:
    void handleInput(Game& game) override;
    void update(Game& game) override;
    void render(Game& game) override;
};

#endif // MAINMENU_H
#ifndef HARDLEVEL_H
#define HARDLEVEL_H

#include "Level.h"
#include "Obstacle.h"

class HardLevel : public Level {
public:
    void update() override;
    void render() override;
};

#endif

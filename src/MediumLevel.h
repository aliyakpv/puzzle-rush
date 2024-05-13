#ifndef MEDIUMLEVEL_H
#define MEDIUMLEVEL_H

#include "Level.h"
#include "Obstacle.h"

class MediumLevel : public Level {
public:
    void update() override;
    void render() override;
};

#endif

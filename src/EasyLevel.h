#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include "Level.h"

class EasyLevel : public Level {
public:
    void update() override;
    void render() override;
};

#endif

#ifndef LEVEL_H
#define LEVEL_H


class Level {
public:
    virtual ~Level() {}
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif 

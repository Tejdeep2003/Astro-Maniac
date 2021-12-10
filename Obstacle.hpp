#ifndef Obstacle_hpp
#define Obstacle_hpp
#include "GameObject.hpp"

class Obstacle : public GameObject
{
public:
    Obstacle(const char *texturesheet, int x, int y, int width, int height);
    ~Obstacle();
};

#endif

#ifndef Fuel_hpp
#define Fuel_hpp
#include "GameObject.hpp"

class Fuel : public GameObject
{
public:
    Fuel(const char *texturesheet, int x, int y, int width, int height);
    ~Fuel();
};

#endif
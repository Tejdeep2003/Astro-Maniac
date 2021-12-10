#ifndef Alien_hpp
#define Alien_hpp
#include "GameObject.hpp"

class Alien : public GameObject
{
public:
    Alien(const char *texturesheet, float x, float y, int width, int height, int index);
    // ~Alien();
    void update();
    void update1();
    void update2();
    void update3();
    bool AlienReachedEndpoint();
    void Render();
    static const char *images[];

private:
    int flag = 0;
    bool reachedEnd = false;
    const char *picture;
    int index;
    
};

#endif

#include "Alien.hpp"
#include <time.h>
#include "Game.hpp"
#include <math.h>
using namespace std;
Alien::Alien(const char *texturesheet, float x, float y, int width, int height, int index) : GameObject(texturesheet, x, y, width, height)
{
    this->index = index;
}
// Alien::~Alien() {}
void Alien::update()
{
    switch (index)
    {
    case 0:
        update1();
        break;
    case 1:
        update2();
        break;
    case 2:
        update3();
        break;
    }

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = w;
    destRect.h = h;
    reachedEnd = AlienReachedEndpoint();
}

void Alien::update1()
{
    xpos += 5 * sin(ypos / 10);
    ypos += 3;
}

void Alien::update2()
{
    xpos -= (1 + 4 * sin(ypos / 10));
    ypos += 5;
}

void Alien::update3()
{
    xpos += 0;
    ypos += 2;
}

bool Alien::AlienReachedEndpoint()
{
    return ypos >= 900;
}

const char *Alien::images[] = {"images/alien.png", "images/monster.png", "images/ufo.png"};

void Alien::Render()
{
    if (reachedEnd)
    {
        // cout << "Rendering new alien" << endl;
        // srand(time(0));
        xpos = Game::randomNumberGenerator(9619) % 800;
        ypos = 0;
        reachedEnd = false;
        // srand(time(0));
        index = Game::randomNumberGenerator(46578) % 3;
        objTexture = TextureManager::LoadTexture(images[index]);
    }

    GameObject::Render();
}
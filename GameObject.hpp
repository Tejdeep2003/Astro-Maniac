#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"
#include "main.hpp"
#include "TextureManager.hpp"
class GameObject
{
public:
    GameObject(const char *texturesheet, float x, float y, int width, int height);
    ~GameObject();

    void update(float p, float q);
    void Render();
    float getX() { return xpos; }
    float getY() { return ypos; }
    void setX(float x){xpos = x;}
    void setY(float y){ypos = y;}
    int getHeight() { return h; }
    int getWidth() { return w; }
    void handleEvents();

protected:
    float xpos;
    float ypos;
    int w;
    int h;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
};
#endif //GAMEOBJECT_HPP
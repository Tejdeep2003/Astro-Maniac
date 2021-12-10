#ifndef Game_hpp
#define Game_hpp

#include "GameObject.hpp"
#include "main.hpp"
using namespace std;
class Game
{
public:
    Game();
    ~Game();

    void init(const char *title, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render();
    void clean();
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static int randomNumberGenerator(int limit)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, limit);
        return dis(gen);
    }
    // static bool isCollided;
    // static SDL_Event *event;
    // friend class TextureManager;
    // friend class GameObject;

private:
    bool isRunning = false;
    int cnt = 0;
    SDL_Window *window;
};

#endif //GAME_H

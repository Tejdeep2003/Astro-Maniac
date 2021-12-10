#ifndef Player_hpp
#define Player_hpp
#include "GameObject.hpp"

class Player : public GameObject
{
public:
    Player(const char *texturesheet, float x, float y, int width, int height);
    ~Player();

    int getVelX() { return vel_X; }
    int getVelY() { return vel_Y; }
    void handleEvents();
    void Animate();
    bool isMoving() { return moving; }
    int getDirection() { return dir; }
    int getMove() { return move; }

private:
    int vel_X;
    int vel_Y;
    bool moving;
    int move;
    int dir;
};

#endif //PLAYER_H
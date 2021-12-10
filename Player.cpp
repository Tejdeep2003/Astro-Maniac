#include "Player.hpp"
#include "Game.hpp"

Player::Player(const char *texturesheet, float x, float y, int width, int height) : GameObject(texturesheet, x, y, width, height) {}

void Player::handleEvents()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        move = 0;
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_a: //going right
            if (getX() > 745)
            {
                vel_X = 0;
            }
            else
            {
                vel_X = 5;
                dir = 2;
            }
            break;
        case SDLK_d:
            if (getX() < 0)
            {
                vel_X = 0;
            }
            else
            {
                vel_X = -5;
                dir = 1;
            }
            break;
        }
    }
    else
    {
        vel_X = 0;
    }
    setX(getX() + vel_X);
    Animate();
}

void Player::Animate()
{
    move++;
    if ((vel_X > 0 || move < 30) && dir == 2)
    {
        moving = true;
        if (move < 6)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right0.png"));
        else if (move < 12)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right1.png"));
        // else if(move < 45)
        //     objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right2.png"));
        else if (move < 18)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right2.png"));
        else if (move < 24)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right1.png"));
        else
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right0.png"));
    }
    else if ((vel_X < 0 || move < 30) && dir == 1)
    {
        moving = true;
        if (move < 6)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left0.png"));
        else if (move < 12)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left1.png"));
        // else if(move < 45)
        //     objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left2.png"));
        else if (move < 18)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left2.png"));
        else if (move < 24)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left1.png"));
        else
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left0.png"));
    }
    else if (moving)
    {
        moving = false;
        dir = 0;
        objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/astronaut.png"));
    }
    Render();
}
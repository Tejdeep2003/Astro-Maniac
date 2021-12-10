#include "Game.hpp"
#include "Player.hpp"
#include "Alien.hpp"
#include "Obstacle.hpp"
#include "Fuel.hpp"
#include <bits/stdc++.h>
#include <time.h>

Player *player;
Obstacle *obstacle;
Fuel* fuel;
GameObject *background;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;
Alien *aliens[3];
using namespace std;
bool isFuel =false;

int a = 0;
bool collision = false;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	player = new Player("images/astronaut.png", 430, 710, 170, 170);
	obstacle = new Obstacle("images/meteor.png", 850, 400, 80, 80);
	fuel = new Fuel("images/fuel.jpg", 430, 0, 80, 80);
	background = new GameObject("images/space.png", 0, 0, 900, 900);

	for (int i = 0; i < 3; i++)
	{
		int ranIndex = randomNumberGenerator(123456)%3;
		aliens[i] = new Alien(Alien::images[ranIndex], rand() % 800, 0, 80, 80, ranIndex);
	}
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		}
		break;
	default:
		break;
	}
	if (player != NULL)
	{
		player->handleEvents();
		a = player->getVelX();
	}
}

inline double distanceSq(float x1, float y1, float x2, float y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool checkCollision(GameObject *go, float dis)
{
	if ((distanceSq(go->getX(), go->getY(), player->getX(), player->getY()) < dis)) //checking collision
	{
		player = NULL;
		return true;
	}
	return false;
}

bool isDead()
{
	if(checkCollision(obstacle, 10000))
		return false;
	for (int i = 0; i < 3; i++)
	{
		if (checkCollision(aliens[i], 2000))
			return false;
	}
	return true;
}

void Game::update()
{
	if(!isRunning)
		return;
	if (player != NULL)
	{
		player->update(a, 0);
		obstacle->update(-2, 2);
		for (int i = 0; i < 3; i++)
			aliens[i]->update();
	}
	isRunning = isDead();
	background->update(0, 0);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	background->Render();
	if (player != NULL)
	{
		player->Render();
	}
	for (int i = 0; i < 3; i++)
	{
		aliens[i]->Render();
	}
	obstacle->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
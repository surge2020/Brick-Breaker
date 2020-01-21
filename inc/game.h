#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "menu.h"
#include "paddle.h"
#include "ball.h"
#include "wall.h"
#include "collision.h"

class Game {
public:
	void initialize();
	bool getRunning();
	void input();
	void keyDown(SDL_Event* event);
	void keyUp(SDL_Event* event);
	void update();
	void render();
	void clean();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running;
	Menu* menu;
	Paddle* paddle;
	Ball* ball;
	Wall* wall;
	Collision* collision;
	SDL_Surface* surface;
	SDL_Texture* texture;
};

#endif
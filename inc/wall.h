#ifndef WALL
#define WALL

#include <vector>
#include <SDL2/SDL.h>
#include "brick.h"

class Wall {
public:
	Wall(SDL_Renderer* renderer);
	void generate();
	std::vector<Brick> bricks;
	void reset();
	void render();
private:
	SDL_Renderer* renderer;
};

#endif
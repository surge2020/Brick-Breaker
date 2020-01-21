#include "wall.h"

Wall::Wall(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	generate();
}

void Wall::generate()
{
	Brick brick(renderer);
	int x = 40;
	int y = 40;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			brick.initialize(x, y);
			bricks.push_back(brick);
			x += 75 + 40;
		}
		x = 40;
		y += 50 + 40;
	}
}

void Wall::reset()
{
	bricks.clear();
	generate();
}

void Wall::render()
{
	for (Brick brick : bricks) {
		brick.render();
	}
}
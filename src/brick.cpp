#include "brick.h"

Brick::Brick(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	broken = false;
	surface = IMG_Load("res/brick.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Brick::initialize(int x, int y)
{
	brickRect = {x, y, 75, 50};
	broken = false;
}

bool Brick::getBroken()
{
	return broken;
}

void Brick::setBroken(bool b)
{
	broken = b;
}

SDL_Rect Brick::getRect()
{
	return brickRect;
}

void Brick::render()
{
	if (broken) {
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRect(renderer, &brickRect);
	} 
	else {
		SDL_RenderCopy(renderer, texture, NULL, &brickRect);
	}
}
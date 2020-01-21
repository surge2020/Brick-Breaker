#include "paddle.h"

Paddle::Paddle(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	paddle = {300, 400, 100, 25};
	left = false;
	right = false;
	surface = IMG_Load("res/paddle.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Paddle::reset()
{
	paddle = {300, 400, 100, 25};
	left = false;
	right = false;
}

SDL_Rect Paddle::getRect()
{
	return paddle;
}

void Paddle::setLeft(bool b)
{
	left = b;
}

void Paddle::setRight(bool b)
{
	right = b;
}

void Paddle::update()
{
	if (left) {
		paddle.x -= 2;
	}
	if (right) {
		paddle.x += 2;
	}
}

void Paddle::render()
{
	SDL_RenderCopy(renderer, texture, NULL, &paddle);
}
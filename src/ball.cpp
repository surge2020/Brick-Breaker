#include "ball.h"

Ball::Ball(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	ball = {100, 200, 25, 25};
	velocityX = 1;
	velocityY = 1;
	surface = IMG_Load("res/ball.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Ball::reset()
{
	ball = {100, 200, 25, 25};
	velocityX = 1;
	velocityY = 1;
}

SDL_Rect Ball::getRect()
{
	return ball;
}

void Ball::reverseX()
{
	velocityX *= -1;
}

void Ball::reverseY()
{
	velocityY *= -1;
}

int Ball::getX()
{
	return velocityX;
}

int Ball::getY()
{
	return velocityY;
}

void Ball::update()
{
	ball.x += velocityX;
	ball.y += velocityY;
}

void Ball::render()
{
	SDL_RenderCopy(renderer, texture, NULL, &ball);
}
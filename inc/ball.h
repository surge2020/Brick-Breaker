#ifndef BALL
#define BALL

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Ball {
public:
	Ball(SDL_Renderer* renderer);
	void reset();
	SDL_Rect getRect();
	void reverseX();
	void reverseY();
	int getX();
	int getY();
	void update();
	void render();
private:
	SDL_Renderer* renderer;
	SDL_Rect ball;
	int velocityX;
	int velocityY;
	SDL_Surface* surface;
	SDL_Texture* texture;
};

#endif
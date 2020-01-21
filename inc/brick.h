#ifndef BRICK
#define BRICK

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Brick {
public:
	Brick(SDL_Renderer* renderer);
	void initialize(int x, int y);
	bool getBroken();
	void setBroken(bool b);
	SDL_Rect getRect();
	void render();
private:
	SDL_Renderer* renderer;
	SDL_Rect brickRect;
	bool broken;
	SDL_Surface* surface;
	SDL_Texture* texture;
};

#endif
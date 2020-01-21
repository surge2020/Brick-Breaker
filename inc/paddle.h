#ifndef PADDLE
#define PADDLE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Paddle {
public:
	Paddle(SDL_Renderer* renderer);
	void reset();
	SDL_Rect getRect();
	void setLeft(bool b);
	void setRight(bool b);
	void update();
	void render();
private:
	SDL_Renderer* renderer;
	SDL_Rect paddle;
	bool left;
	bool right;
	SDL_Surface* surface;
	SDL_Texture* texture;
};

#endif
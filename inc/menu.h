#ifndef MENU
#define MENU

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Menu {
public:
	Menu(SDL_Renderer* renderer);
	bool getMenu();
	void setMenu(bool b);
	void render();
private:
	SDL_Renderer* renderer;
	bool menu;
	SDL_Surface* surface;
	SDL_Texture* texture;
};

#endif
#include "menu.h"

Menu::Menu(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	menu = true;
	surface = IMG_Load("res/menu.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

bool Menu::getMenu()
{
	return menu;
}

void Menu::setMenu(bool b)
{
	menu = b;
}

void Menu::render()
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}
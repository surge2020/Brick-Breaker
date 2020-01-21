#include "game.h"

void Game::initialize()
{
	window = SDL_CreateWindow(
		"Brick Breaker",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		500, 500, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	running = true;
	menu = new Menu(renderer);
	paddle = new Paddle(renderer);
	ball = new Ball(renderer);
	wall = new Wall(renderer);
	collision = new Collision(menu, paddle, ball, wall);
	// Game background
	surface = IMG_Load("res/background.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

bool Game::getRunning()
{
	return running;
}

void Game::input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		case SDL_KEYDOWN:
			keyDown(&event);
			break;
		case SDL_KEYUP:
			keyUp(&event);
			break;
		default:
			break;
		}
	}
}

void Game::keyDown(SDL_Event* event)
{
	switch (event->key.keysym.sym) {
	case SDLK_LEFT:
		paddle->setLeft(true);
		break;
	case SDLK_RIGHT:
		paddle->setRight(true);
		break;
	case SDLK_RETURN:
		menu->setMenu(false);
	default:
		break;
	}
}

void Game::keyUp(SDL_Event* event)
{
	switch (event->key.keysym.sym) {
	case SDLK_LEFT:
		paddle->setLeft(false);
		break;
	case SDLK_RIGHT:
		paddle->setRight(false);
		break;
	default:
		break;
	}
}

void Game::update()
{
	if (menu->getMenu() == false) {
		collision->update();
		paddle->update();
		ball->update();
	}
}

void Game::render()
{

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	if (menu->getMenu() == true) {
		menu->render();
		
	} else {
		paddle->render();
		wall->render();
		ball->render();
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
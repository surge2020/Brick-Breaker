#include "game.h"

int main()
{
	Game* game = new Game();
	game->initialize();
	while (game->getRunning()) {
		game->input();
		game->update();
		game->render();
		SDL_Delay(1000/60);
	}
	game->clean();
	return 0;
}
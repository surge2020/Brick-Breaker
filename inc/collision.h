#ifndef COLLISION
#define COLLISION

#include <SDL2/SDL.h>
#include "menu.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "wall.h"

class Collision {
public:
	Collision(Menu* menu, Paddle* paddle, Ball* ball, Wall* wall);
	void ballWindow();
	void paddleWindow();
	void ballPaddle();
	void ballBrick();
	void checkWin();
	void update();
private:
	Menu* menu;
	Paddle* paddle;
	Ball* ball;
	Wall* wall;
};

#endif
#include "collision.h"

Collision::Collision(Menu* menu, Paddle* paddle, Ball* ball, Wall* wall)
{
	this->menu = menu;
	this->paddle = paddle;
	this->ball = ball;
	this->wall = wall;
}

void Collision::ballWindow()
{
	SDL_Rect ballRect = ball->getRect();
	// Top left
	if (ballRect.x <= 0 && ballRect.y <= 0) {
		ball->reverseX();
		ball->reverseY();
	}
	// Top right
	else if (ballRect.x >= 475 && ballRect.y <= 0) {
		ball->reverseX();
		ball->reverseY();
	}
	// Bottom right
	else if (ballRect.x >= 475 && ballRect.y >= 475) {
		ball->reverseX();
		ball->reverseY();
	}
	// Bottom left
	else if (ballRect.x <= 0 && ballRect.y >= 475) {
		ball->reverseX();
		ball->reverseY();
	}
	// Left side
	else if (ballRect.x <= 0) {
		ball->reverseX();
	}
	// Right side
	else if (ballRect.x >= 475) {
		ball->reverseX();
	}
	// Top side
	else if (ballRect.y <= 0) {
		ball->reverseY();
	}
	// Bottom side
	else if (ballRect.y >= 475) {
		menu->setMenu(true);
		paddle->reset();
		ball->reset();
		wall->reset();
	}
}

void Collision::paddleWindow()
{
	SDL_Rect paddleRect = paddle->getRect();
	if (paddleRect.x <= 0) {
		paddle->setLeft(false);
	}
	else if (paddleRect.x >= 400) {
		paddle->setRight(false);
	}
}


void Collision::ballPaddle()
{
	SDL_Rect ballRect = ball->getRect();
	SDL_Rect paddleRect = paddle->getRect();
	// Top left
	if (ballRect.x + ballRect.w == paddleRect.x && 
			ballRect.y + ballRect.h == paddleRect.y) {
			ball->reverseX();
			ball->reverseY();
	}
	// Top right
	else if (ballRect.x == paddleRect.x + paddleRect.w &&
			 ballRect.y + ballRect.h == paddleRect.y) {
		ball->reverseX();
		ball->reverseY();
	}
	// Left side
	else if (ballRect.x + ballRect.w == paddleRect.x &&
			 ballRect.y + ballRect.h > paddleRect.y &&
			 ballRect.y < paddleRect.y + paddleRect.h) {
		ball->reverseX();
	}
	// Right side
	else if (ballRect.x == paddleRect.x + paddleRect.w &&
			 ballRect.y + ballRect.h > paddleRect.y &&
			 ballRect.y < paddleRect.y + paddleRect.h) {
		ball->reverseX();
	}
	// Top side
	else if (ballRect.x + ballRect.w >= paddleRect.x &&
			 ballRect.x <= paddleRect.x + paddleRect.w &&
			 ballRect.y + ballRect.h == paddleRect.y) {
		ball->reverseY();
	}
}

void Collision::ballBrick()
{
	SDL_Rect ballRect = ball->getRect();
	for (Brick& brick : wall->bricks) {
		SDL_Rect brickRect = brick.getRect();
		if (brick.getBroken() == false) {
			// Top left
			if (ballRect.x + ballRect.w == brickRect.x &&
				ballRect.y + ballRect.h == brickRect.y) {
				// Up & right
				if (ball->getX() == 1 && ball->getY() == -1) {
					ball->reverseX();
				}
				// Down & left
				else if (ball->getX() == -1 && ball->getY() == -1) {
					ball->reverseY();
				}
				else {
					ball->reverseX();
					ball->reverseY();
				}
				brick.setBroken(true);
			}
			// Top right
			else if (ballRect.x == brickRect.x + brickRect.w &&
					 ballRect.y + ballRect.h == brickRect.y) {
				// Down & right
				if (ball->getX() == 1 && ball->getY() == 1) {
					ball->reverseY();
				}
				// Up & left
				else if (ball->getX() == -1 && ball->getY() == -1) {
					ball->reverseX();
				}
				else {
					ball->reverseX();
					ball->reverseY();
				}				
				brick.setBroken(true);
			}
			// Bottom right
			else if (ballRect.x == brickRect.x + brickRect.w &&
					 ballRect.y == brickRect.y + brickRect.h) {
				// Down & left
				if (ball->getX() == -1 && ball->getY() == 1) {
					ball->reverseX();
				}
				// Up & right
				else if (ball->getX() == 1 && ball->getY() == -1) {
					ball->reverseY();
				}
				else {
					ball->reverseX();
					ball->reverseY();
				}	
				brick.setBroken(true);
			}
			// Bottom left
			else if (ballRect.x + ballRect.w == brickRect.x &&
					 ballRect.y == brickRect.y + brickRect.h) {
				// Up & left
				if (ball->getX() == -1 && ball->getY() == -1) {
					ball->reverseY();
				}
				// Down & right
				if (ball->getX() == 1 && ball->getY() == 1) {
					ball->reverseX();
				}
				else {
					ball->reverseX();
					ball->reverseY();
				}
				brick.setBroken(true);
			}
			// Left side
			else if (ballRect.x + ballRect.w == brickRect.x &&
					 ballRect.y + ballRect.h > brickRect.y &&
					 ballRect.y < brickRect.y + brickRect.h) {
				ball->reverseX();
				brick.setBroken(true);
			}
			// Right side
			else if (ballRect.x == brickRect.x + brickRect.w &&
					 ballRect.y + ballRect.h > brickRect.y &&
					 ballRect.y < brickRect.y + brickRect.h) {
				ball->reverseX();
				brick.setBroken(true);
			}
			// Top side
			else if (ballRect.x + ballRect.w >= brickRect.x &&
					 ballRect.x <= brickRect.x + brickRect.w &&
					 ballRect.y + ballRect.h == brickRect.y) {
				ball->reverseY();
				brick.setBroken(true);
			}
			// Bottom side
			else if (ballRect.x + ballRect.w >= brickRect.x &&
					 ballRect.x <= brickRect.x + brickRect.w &&
					 ballRect.y == brickRect.y + brickRect.h) {
				ball->reverseY();
				brick.setBroken(true);
			}
		}
	}
}

void Collision::checkWin()
{
	bool win = false;
	for (Brick brick : wall->bricks) {
		if (brick.getBroken() == false) {
			win = false;
			break;
		}
		else {
			win = true;
		}
	}
	if (win == true) {
		menu->setMenu(true);
		paddle->reset();
		ball->reset();
		wall->reset();
	}
}

void Collision::update()
{
	ballWindow();
	paddleWindow();
	ballPaddle();
	ballBrick();
	checkWin();
}
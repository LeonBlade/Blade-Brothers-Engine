/*
 * Game.h
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>

#include <GL/glut.h>
#include <stdlib.h>

#include "Graphics.h"
#include "Keyboard.h"
#include "GameState.h"

class Game
{
public:
	Game(int window);
	virtual ~Game();

	void onInit();

	void onUpdate();
	void onDraw();

	void onKeyDown();
	void onKeyUp();

	void onMouse(int button, int state, int x, int y);

private:
	GameState *currentState;
	int glWindow;
};

#endif /* GAME_H_ */

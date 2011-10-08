/*
 * Game.cpp
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#include "Game.h"
#include "Graphics.h"
#include "Entity.h"
#include "Map.h"
#include "Log.h"
#include "FPS.h"

Entity *guy = new Entity();
Map *map = new Map();

Game::Game(int window)
{
	glWindow = window;
	Log::info("Engine has launched");
}

Game::~Game()
{

}

void Game::onInit()
{
	guy->onLoad("../Resources/character.png");
	//map->onCreate("New Map", "../Resources/tiles.png", 10, 10);
	map->onLoad("../Resources/testing.map");
}

void Game::onUpdate()
{
	if (Keyboard::isDown(GLUT_KEY_LEFT))
		guy->setVelocityX(-1);
	if (Keyboard::isDown(GLUT_KEY_RIGHT))
		guy->setVelocityX(1);
	if (Keyboard::isDown(GLUT_KEY_UP))
		guy->setVelocityY(-1);
	if (Keyboard::isDown(GLUT_KEY_DOWN))
		guy->setVelocityY(1);

	if (Keyboard::isUp(GLUT_KEY_LEFT) && Keyboard::isUp(GLUT_KEY_RIGHT))
		guy->setVelocityX(0);
	if (Keyboard::isUp(GLUT_KEY_UP) && Keyboard::isUp(GLUT_KEY_DOWN))
		guy->setVelocityY(0);

	// TODO: Add update stuff here
	guy->onUpdate();
}

void Game::onDraw()
{
	map->onDraw(LayerGround);
	map->onDraw(LayerMiddle);

	guy->onDraw();

	map->onDraw(LayerAbove);
}

void Game::onMouse(int button, int state, int x, int y)
{

}

void Game::onKeyDown()
{
	if (Keyboard::isDown(27)) // ESCAPE
	{
		Log::info("Engine shutting down...");

		guy->onCleanup();
		Graphics::removeTexture("../Resources/tiles.png");

		Log::info("Engine terminated");

		glutDestroyWindow(glWindow);
		exit(0);
	}

	if (Keyboard::isDown('r'))
	{
		//map->onResize(15, 12);
	}
}

void Game::onKeyUp()
{

}

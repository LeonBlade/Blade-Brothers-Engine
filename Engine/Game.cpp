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
	guy->onLoad("character.png");
	map->onCreate("New Map", "tiles.png", 20, 15);
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

	guy->onDraw();
}

void Game::onKeyDown()
{
	if (Keyboard::isDown(27)) // ESCAPE
	{
		Log::info("Engine shutting down...");

		guy->onCleanup();
		Graphics::removeTexture("tiles.png");

		Log::info("Engine terminated");

		glutDestroyWindow(glWindow);
		exit(0);
	}

	if (Keyboard::isDown('c'))
	{
		int x = (guy->getX() - (int)guy->getX() % 16) / 16;
		int y = (guy->getY() - (int)guy->getY() % 16) / 16;

		Log::info("Changing tile in current location... %i %i", x, y);
		map->setTile(x, y, (MapTile){{2, 0, 0}, false});
	}
	if (Keyboard::isDown('s'))
		map->onSave("test.map");
	if (Keyboard::isDown('l'))
		map->onLoad("test.map");
}

void Game::onKeyUp()
{

}

/*
 * main.cpp
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <GL/glut.h>

#include "Game.h"
#include "FPS.h"
#include "Keyboard.h"

GLvoid onKeyDown(unsigned char key, int x, int y);
GLvoid onKeyUp(unsigned char key, int x, int y);

GLvoid onSpecialKeyDown(int key, int x, int y);
GLvoid onSpecialKeyUp(int key, int x, int y);

GLvoid onMouse(int button, int state, int x, int y);

GLvoid resizeGL(int w, int h);
GLvoid onUpdate(int value);
GLvoid drawGL();

Game *theGame;

int main(int argc, char *argv[])
{
	// set the glut display mode and window size
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(520, 180);

	// create the instance of our game
	theGame = new Game(glutCreateWindow("Blade Brothers Engine"));

	// enable texture 2d
	glEnable(GL_TEXTURE_2D);

	// enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// initialize the game now
	// we must make sure to initialize the game after the OGL shit otherwise it blows up
	theGame->onInit();

	// initialize user GL
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// set the draw function
	glutDisplayFunc(&drawGL);
	glutIdleFunc(&drawGL);
	// set the resize function
	glutReshapeFunc(&resizeGL);
	// timer function
	glutTimerFunc(2, &onUpdate, 1);
	// keyboard event
	glutKeyboardFunc(&onKeyDown);
	glutKeyboardUpFunc(&onKeyUp);
	// other special keys
	glutSpecialFunc(&onSpecialKeyDown);
	glutSpecialUpFunc(&onSpecialKeyUp);
	// mouse events
	glutMouseFunc(&onMouse);

	// call the main loop
	glutMainLoop();

	return 0;
}

GLvoid resizeGL(int width, int height)
{
	if (width != 640 || height != 480)
		glutReshapeWindow(640, 480);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, width, height);
	glOrtho(0.0f, 320, 240, 0.0f, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

GLvoid onUpdate(int value)
{
	FPS::onUpdate();
	theGame->onUpdate();

	glutTimerFunc(2, &onUpdate, 1);
}

GLvoid drawGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	theGame->onDraw();

	glutSwapBuffers();
}

GLvoid onKeyDown(unsigned char key, int x, int y)
{
	// avoid thrashing this procedure
	usleep(100);
	Keyboard::setKey(key, true);
	theGame->onKeyDown();
}

GLvoid onKeyUp(unsigned char key, int x, int y)
{
	// avoid thrashing this procedure
	usleep(100);
	Keyboard::setKey(key, false);
	theGame->onKeyUp();
}

GLvoid onSpecialKeyDown(int key, int x, int y)
{
	Keyboard::setKey(key, true);
	theGame->onKeyDown();
}

GLvoid onSpecialKeyUp(int key, int x, int y)
{
	Keyboard::setKey(key, false);
	theGame->onKeyUp();
}

GLvoid onMouse(int button, int state, int x, int y)
{
	theGame->onMouse(button, state, x, y);
}

/*
 * Keyboard.cpp
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#include <stdio.h>
#include <stdarg.h>

#include "Keyboard.h"
#include "Log.h"

Keyboard *Keyboard::instance = new Keyboard();

Keyboard::Keyboard()
{
	Log::info("Keyboard initialized...");
	keys = new bool[256];
}

Keyboard::~Keyboard()
{
	delete keys;
}

bool Keyboard::isDown(unsigned char key)
{
	return Keyboard::instance->keys[key];
}

bool Keyboard::isUp(unsigned char key)
{
	return !Keyboard::instance->keys[key];
}

void Keyboard::setKey(unsigned char key, bool state)
{
	Keyboard::instance->keys[key] = state;
}

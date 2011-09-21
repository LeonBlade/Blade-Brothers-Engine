/*
 * Keyboard.h
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard
{
public:
	Keyboard();
	virtual ~Keyboard();

	static bool isDown(unsigned char key);
	static bool isUp(unsigned char key);

	static void setKey(unsigned char key, bool state);

private:
	bool *keys;
	static Keyboard *instance;
};

#endif /* KEYBOARD_H_ */

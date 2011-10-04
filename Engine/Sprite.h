/*
 * Sprite.h
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>

#include <libpng/png.h>
#include <GL/glut.h>
#include <stdlib.h>

class Sprite
{
public:
	Sprite();
	Sprite(std::string file, bool pixels = true);
	virtual ~Sprite();

	void bindTexture();
	static Sprite *getLBS();

	GLuint getTexture();
	int getWidth();
	int getHeight();

private:
	GLuint texture;
	int width;
	int height;
	static Sprite *lastBind;
};

#endif /* SPRITE_H_ */

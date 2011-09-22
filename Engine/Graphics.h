/*
 * Graphics.h
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <string>
#include <map>

#include <GL/glut.h>
#include <GL/glpng.h>

struct Rectangle
{
	int x, y, w, h;
};

#include "Sprite.h"

class Graphics
{
public:
	Graphics();
	virtual ~Graphics();

	static Sprite *addTexture(std::string file, bool pixels = true);
	static bool hasTexture(std::string file);
	static Sprite *getTexture(std::string file);
	static void removeTexture(std::string file);

	static void drawSprite(Sprite *sprite, Rectangle to, Rectangle from);

private:
	std::map<std::string, Sprite*> textures;
	static Graphics *instance;
};

#endif /* GRAPHICS_H_ */

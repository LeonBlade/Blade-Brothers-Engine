/*
 * Graphics.cpp
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#include "Graphics.h"
#include "Log.h"

Graphics *Graphics::instance = new Graphics();

Graphics::Graphics()
{
	Log::info("Graphics initialized...");
	textures.clear();
}

Graphics::~Graphics()
{
	Log::info("Graphics destruction");
	textures.clear();
}

Sprite *Graphics::addTexture(std::string file, bool pixels)
{
	Log::info("Adding texture '%s'", file.c_str());
	if (!hasTexture(file))
	{
		Sprite *s = new Sprite(file, pixels);
		Graphics::instance->textures.insert(std::pair<std::string, Sprite*>(file, s));
		return s;
	}
	else
		return Graphics::getTexture(file);

	return NULL;
}

bool Graphics::hasTexture(std::string file)
{
	Log::info("Checking texture '%s'", file.c_str());
	if (Graphics::instance->textures.count(file))
		return true;
	return false;
}

Sprite *Graphics::getTexture(std::string file)
{
	Log::info("Getting texture '%s'", file.c_str());
	if (hasTexture(file))
	{
		std::map<std::string, Sprite*>::iterator it;
		it = Graphics::instance->textures.find(file);
		return it->second;
	}
	else
	{
		return Graphics::addTexture(file);
	}
}

void Graphics::removeTexture(std::string file)
{
	Log::info("Removing texture '%s'", file.c_str());
	std::map<std::string, Sprite*>::iterator it;
	it = Graphics::instance->textures.find(file);
	delete it->second;
	Graphics::instance->textures.erase(it);
}

void Graphics::drawSprite(Sprite *sprite, Rectangle to, Rectangle from)
{
	// push the matrix so we can mess with our own
	glPushMatrix();
	glLoadIdentity();

	// translate this object to it's X and Y position
	glTranslated(to.x + to.w / 2, to.y + to.h / 2, 0);

	glBegin(GL_QUADS);
	{
		float min_x = (float) (from.x) / sprite->getWidth();
		float max_y = (float) (from.y) / sprite->getHeight();
		float max_x = (float) (from.x + from.w) / sprite->getWidth();
		float min_y = (float) (from.y + from.h) / sprite->getHeight();

		glNormal3d(0, 0, 0);

		glTexCoord2f(min_x, max_y);
		glVertex2f(-to.w/2, -to.h/2);

		glTexCoord2f(max_x, max_y);
		glVertex2f(to.w/2, -to.h/2);

		glTexCoord2f(max_x, min_y);
		glVertex2f(to.w/2, to.h/2);

		glTexCoord2f(min_x, min_y);
		glVertex2f(-to.w/2, to.h/2);
	}
	glEnd();

	// translate our matrix back
	glTranslated(-to.x, -to.y, 0);

	// restore the last matrix
	glPopMatrix();
}

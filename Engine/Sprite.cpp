/*
 * Sprite.cpp
 *
 *  Created on: Sep 1, 2011
 *      Author: LeonBlade
 */

#include "Sprite.h"
#include "Log.h"

Sprite::Sprite(std::string file, bool pixels)
{
	pngInfo info;
	if (pixels)
		texture = pngBind(file.c_str(), PNG_NOMIPMAP, PNG_ALPHA, &info, GL_CLAMP, GL_NEAREST, GL_NEAREST);
	else
		texture = pngBind(file.c_str(), PNG_NOMIPMAP, PNG_ALPHA, &info, GL_CLAMP, GL_LINEAR, GL_LINEAR);

	if (texture != 0)
	{
		width = info.Width;
		height = info.Height;
		Log::info("Texture '%s' loaded successfully Width: %i - Height: %i", file.c_str(), width, height);
	}
	else
		Log::error("Texture '%s' failed to load", file.c_str());
}

Sprite::~Sprite()
{
	Log::info("Deallocating sprite... %i", (int)texture);
	glDeleteTextures(1, &texture);
}

void Sprite::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}

GLuint Sprite::getTexture()
{
	return texture;
}

int Sprite::getWidth()
{
	return width;
}

int Sprite::getHeight()
{
	return height;
}

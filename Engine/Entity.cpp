/*
 * Entity.cpp
 *
 *  Created on: Sep 12, 2011
 *      Author: LeonBlade
 */

#include "Entity.h"
#include "Graphics.h"
#include "FPS.h"
#include "Log.h"

Entity::Entity()
{
	Log::info("Creating a new Entity");
	sprite = NULL;
	position.x = 0;
	position.y = 0;
	velocity.x = 0;
	velocity.y = 0;
	animation = new Animation();

	AnimationFrame a;
	Rectangle r = {0,0,0,0};
	for (int i = 0; i < 16; i++)
		a.frames[i] = r;
	a.size = 0;

	Rectangle middle = {16,0,16,32};
	Rectangle right = {32,0,16,32};
	Rectangle left = {0,0,16,32};

	Animation::addFrame(a, left);
	Animation::addFrame(a, middle);
	Animation::addFrame(a, right);

	animation->addAnimation("down_walk", a);
	animation->pause("down_walk", 1);
}

Entity::~Entity()
{

}

// loading the entity sprite eventually will be replaced with Lua
void Entity::onLoad(std::string file)
{
	sprite = Graphics::addTexture(file);
	spriteName = file;
}

// position
// set
void Entity::setPosition(Vector2 p, bool relative)
{
	if (relative)
	{
		position.x += p.x;
		position.y += p.y;
	}
	else
		position = p;
}

void Entity::setPosition(float x, float y, bool relative)
{
	Vector2 p = { x, y };
	setPosition(p, relative);
}

void Entity::setX(float x, bool relative)
{
	if (relative)
		position.x += x;
	else
		position.x = x;
}

void Entity::setY(float y, bool relative)
{
	if (relative)
		position.y += y;
	else
		position.y = y;
}

// get
Vector2 Entity::getPosition()
{
	return position;
}

float Entity::getX()
{
	return position.x;
}

float Entity::getY()
{
	return position.y;
}

void Entity::setVelocity(Vector2 v)
{
	velocity.x = v.x;
	velocity.y = v.y;
}

void Entity::setVelocity(float x, float y)
{
	Vector2 v = { x, y };
	setVelocity(v);
}

void Entity::setVelocityX(float x)
{
	velocity.x = x;
}

void Entity::setVelocityY(float y)
{
	velocity.y = y;
}

void Entity::onUpdate()
{
	animation->onUpdate();

	position.x += (velocity.x / 4);
	position.y += (velocity.y / 4);
}

void Entity::onDraw()
{
	sprite->bindTexture();
	Graphics::drawSprite(sprite, (Rectangle){position.x, position.y, 16, 32}, animation->getFrame());
}

void Entity::onCleanup()
{
	Graphics::removeTexture(spriteName);
}

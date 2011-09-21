/*
 * Entity.h
 *
 *  Created on: Sep 12, 2011
 *      Author: LeonBlade
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>

#include "Sprite.h"
#include "Animation.h"

struct Vector2
{
	float x, y;
};

class Entity
{
public:
	Entity();
	virtual ~Entity();

	// loading the entity sprite eventually will be replaced with Lua
	void onLoad(std::string file);

	// position
	// set
	void setPosition(Vector2 p, bool relative = false);
	void setPosition(float x, float y, bool relative = false);
	void setX(float x, bool relative = false);
	void setY(float y, bool relative = false);
	// get
	Vector2 getPosition();
	float getX();
	float getY();

	// velocity
	void setVelocity(Vector2 v);
	void setVelocity(float x, float y);
	void setVelocityX(float x);
	void setVelocityY(float y);

	void onUpdate();
	void onDraw();

	void onCleanup();

private:
	std::string spriteName;
	Sprite *sprite;
	Vector2 position;
	Vector2 velocity;
	Animation *animation;
};

#endif /* ENTITY_H_ */

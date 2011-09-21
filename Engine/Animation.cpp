/*
 * Animation.cpp
 *
 *  Created on: Sep 3, 2011
 *      Author: LeonBlade
 */

#include "Animation.h"
#include "FPS.h"
#include "Log.h"

Animation::Animation()
{
	lastTime = 0;
	playing = false;
	currentFrame = 0;
	frameIncrease = 1;
	oscillating = false;
}

Animation::~Animation()
{
	animations.clear();
}

int Animation::addFrame(AnimationFrame &frames, Rectangle &frame)
{
	frames.frames[frames.size] = frame;
	frames.size++;
	return frames.size;
}

void Animation::removeFrame(AnimationFrame &frames, int id)
{
	delete &frames.frames[id];
	frames.size--;
}

void Animation::addAnimation(std::string name, AnimationFrame frames)
{
	Log::info("Adding animation '%s'", name.c_str());
	animations.insert(std::pair<std::string, AnimationFrame>(name, frames));
}

void Animation::removeAnimation(std::string name)
{
	Log::info("Removing animation '%s'", name.c_str());
	animations.erase(animations.find(name));
}

void Animation::play(std::string name, bool ocillate, int frame)
{
	Log::info("Playing animation '%s'", name.c_str());
	if (animations.count(name))
	{
		playing = true;
		currentFrame = frame;
		currentAnimation = name;
		oscillating = ocillate;
	}
	else
		Log::error("Animation '%s' does not exist", name.c_str());
}

void Animation::pause(std::string name, int frame)
{
	playing = false;
	currentFrame = frame;
	currentAnimation = name;
}

void Animation::onUpdate()
{
	if (playing)
	{
		if (lastTime + 100 > glutGet(GLUT_ELAPSED_TIME))
			return;

		lastTime = glutGet(GLUT_ELAPSED_TIME);
		currentFrame += frameIncrease;

		std::map<std::string, AnimationFrame>::iterator it;
		it = animations.find(currentAnimation);
		if (oscillating)
		{
			if (frameIncrease > 0)
			{
				if (currentFrame >= it->second.size - 1)
					frameIncrease = -frameIncrease;
			}
			else
			{
				if (currentFrame <= 0)
					frameIncrease = -frameIncrease;
			}

		}
		else
		{
			if (currentFrame >= it->second.size - 1)
				currentFrame = 0;
		}
	}
}

Rectangle Animation::getFrame()
{
	std::map<std::string, AnimationFrame>::iterator it;
	it = animations.find(currentAnimation);

	return it->second.frames[currentFrame];
}

bool Animation::isPlaying()
{
	return playing;
}

std::string Animation::getCurrentAnimation()
{
	return currentAnimation;
}

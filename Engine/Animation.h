/*
 * Animation.h
 *
 *  Created on: Sep 3, 2011
 *      Author: LeonBlade
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <map>
#include <string>

#include "Graphics.h"

struct AnimationFrame
{
	Rectangle frames[16];
	int size;
};

class Animation
{
public:
	Animation();
	virtual ~Animation();

	static int addFrame(AnimationFrame &frames, Rectangle &frame);
	static void removeFrame(AnimationFrame &frames, int id);

	void addAnimation(std::string name, AnimationFrame frames);
	void removeAnimation(std::string name);

	void play(std::string name, bool ocillate = false, int frame = 0);
	void pause(std::string name, int frame = 0);
	void onUpdate();

	bool isPlaying();
	std::string getCurrentAnimation();
	Rectangle getFrame();

private:
	bool playing;
	std::string currentAnimation;
	int currentFrame;
	int frameIncrease;
	bool oscillating;
	int lastTime;
	std::map<std::string, AnimationFrame> animations;
};

#endif ANIMATION_H_

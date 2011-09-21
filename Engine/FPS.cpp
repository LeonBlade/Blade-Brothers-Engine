/*
 * FPS.cpp
 *
 *  Created on: Sep 3, 2011
 *      Author: LeonBlade
 */

#include "FPS.h"
#include "Log.h"

FPS *FPS::instance = new FPS();

FPS::FPS()
{
	Log::info("FPS initialized...");
	frameCount = 0;
	fps = 0;
	currentTime = 0;
	previousTime = 0;
	speedFactor = 0;
}

FPS::~FPS()
{

}

int FPS::getFPS()
{
	return FPS::instance->fps;
}

float FPS::getSpeedFactor()
{
	return FPS::instance->speedFactor;
}

void FPS::onUpdate()
{
	// increase frame count
	FPS::instance->frameCount++;

	// calculate speed factor
	FPS::instance->speedFactor = (glutGet(GLUT_ELAPSED_TIME) - FPS::instance->currentTime) / 100;

	// get the number of milliseconds since glutInit called
	// (or first call to glutGet(GLUT ELAPSED TIME)).
	FPS::instance->currentTime = glutGet(GLUT_ELAPSED_TIME);

	//  Calculate time passed
	int timeInterval = FPS::instance->currentTime - FPS::instance->previousTime;

	if(timeInterval > 1000)
	{
		//  calculate the number of frames per second
		FPS::instance->fps = FPS::instance->frameCount / (timeInterval / 1000.0f);

		//  Set time
		FPS::instance->previousTime = FPS::instance->currentTime;

		//  Reset frame count
		FPS::instance->frameCount = 0;
	}
}

/*
 * FPS.h
 *
 *  Created on: Sep 3, 2011
 *      Author: LeonBlade
 */

#ifndef FPS_H_
#define FPS_H_

#include <GL/glut.h>

class FPS
{
public:
	FPS();
	virtual ~FPS();

	static void onUpdate();
	static int getFPS();
	static float getSpeedFactor();

private:
	int currentTime;
	int previousTime;
	int frameCount;
	int fps;
	float speedFactor;
	static FPS *instance;
};

#endif /* FPS_H_ */

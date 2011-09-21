/*
 * Log.h
 *
 *  Created on: Sep 2, 2011
 *      Author: LeonBlade
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <stdarg.h>

class Log
{
public:
	static void info(const char *message, ...);
	static void warning(const char *message, ...);
	static void error(const char *message ...);
};

#endif /* LOG_H_ */

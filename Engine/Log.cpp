/*
 * Log.cpp
 *
 *  Created on: Sep 2, 2011
 *      Author: LeonBlade
 */

#include "Log.h"

void Log::info(const char *message, ...)
{
	char buffer[1024];
	va_list args;
	va_start(args, message);
	vsprintf(buffer, message, args);
	printf("[INFO] %s\n", buffer);
	va_end(args);
}

void Log::warning(const char *message, ...)
{
	char buffer[1024];
	va_list args;
	va_start(args, message);
	vsprintf(buffer, message, args);
	printf("[WARNING] %s\n", buffer);
	va_end(args);
}

void Log::error(const char *message, ...)
{
	char buffer[1024];
	va_list args;
	va_start(args, message);
	vsprintf(buffer, message, args);
	printf("[ERROR] %s\n", buffer);
	va_end(args);
}

#ifndef LOGGER_H
#define LOGGER_H

#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_INFO 0
#define LOG_ERROR 1
#define LOG_WARNING 2
#define LOG_DEBUG 3
/**
 * Customize the logger of Raylib (Require vprintf)
 * @param msgType The type of log (LOG_INFO, LOG_ERROR, LOG_WARNING, LOG_DEBUG)
 * @param text The text to send
 * @param args The args to format text
 */
void logger(int msgType, const char *text, va_list args);

#endif
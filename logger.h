#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef _LOGGER_H_
#define _LOGGER_H_

#define LOG_DEBUG 0
#define LOG_INFO  1
#define LOG_WARN  2
#define LOG_ERROR 3

typedef struct LOGGER {
    int level;
    char *datetime_format;
} LOGGER;

typedef LOGGER* Logger;

Logger Logger_create();
void log_add(Logger l, int level, const char *msg);
void log_debug(Logger l, const char *msg);
void log_info(Logger l, const char *msg);
void log_warn(Logger l, const char *msg);
void log_error(Logger l, const char *msg);

#endif
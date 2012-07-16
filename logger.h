#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <process.h>
#include <string.h>

#ifndef _LOGGER_H_
#define _LOGGER_H_

#define LOG_DEBUG 0
#define LOG_INFO  1
#define LOG_WARN  2
#define LOG_ERROR 3

typedef struct LOGGER {
    int level;
    char *datetime_format;
    char buf[];
} LOGGER;

typedef LOGGER* Logger;

Logger Logger_create();
void Logger_destory(Logger l);
void log_add(Logger l, int level, const char *msg);
void log_debug(Logger l, const char *fmt, ...);
void log_info(Logger l, const char *fmt, ...);
void log_warn(Logger l, const char *fmt, ...);
void log_error(Logger l, const char *fmt, ...);

#endif

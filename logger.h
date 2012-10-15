#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef _LOGGER_H_
#define _LOGGER_H_

#define LOG_DEBUG 0
#define LOG_INFO  1
#define LOG_WARN  2
#define LOG_ERROR 3

#define LOG_COLOR_RED    "\x1b[31m"
#define LOG_COLOR_YELLOW "\x1b[33m"
#define LOG_COLOR_GREEN  "\x1b[32m"
#define LOG_COLOR_CYAN   "\x1b[36m"
#define LOG_COLOR_RESET  "\x1b[0m"

#define LOG_LEVEL_CHARS "DIWEF"
#define LOG_MAX_MSG_LEN 1024

typedef struct LOGGER {
    int level;
    char *datetime_format;
    //void *device;
} LOGGER;

typedef LOGGER* Logger;

Logger Logger_create();
void log_add(Logger l, int level, const char *msg);
void log_debug(Logger l, const char *fmt, ...);
void log_info(Logger l, const char *fmt, ...);
void log_warn(Logger l, const char *fmt, ...);
void log_error(Logger l, const char *fmt, ...);

#endif

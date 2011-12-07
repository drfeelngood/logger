#include "logger.h"

Logger Logger_create()
{
    Logger l;

    l = (Logger) malloc(sizeof(Logger));
    l->datetime_format = "%Y-%m-%d %H:%M:%S";
    l->level = LOG_INFO;

    return(l);
}

void log_add(Logger l, int level, const char *msg)
{
    const char *c = "DIWEF";
    time_t meow = time(NULL);
    char buf[64];

    if (level < l->level) return;

    strftime(buf, sizeof(buf), l->datetime_format, localtime(&meow));
    printf("[%d] %c, %s : %s\n", (int)getpid(), c[level], buf, msg);
}

void log_debug(Logger l, const char *msg){ log_add(l, LOG_DEBUG, msg); }
void log_info(Logger l, const char *msg){ log_add(l, LOG_INFO, msg); }
void log_warn(Logger l, const char *msg){ log_add(l, LOG_WARN, msg); }
void log_error(Logger l, const char *msg){ log_add(l, LOG_ERROR, msg); }

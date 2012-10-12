#include "logger.h"

Logger Logger_create()
{
    Logger l;

    l = (Logger) malloc(sizeof(Logger));
    l->datetime_format = "%Y-%m-%d %H:%M:%S";
    l->level = LOG_INFO;

    return(l);
}

void log_add(Logger l, int level, const char *fmt, va_list ap)
{
    if (level < l->level) return;

    time_t meow = time(NULL);
    int n = vscprintf(fmt, ap);
    char buf[64];
    char *msg;
    
    vsprintf(b2, n, fmt, ap);
    
    strftime(buf, sizeof(buf), l->datetime_format, localtime(&meow));
    printf("[%d] %c, %s : %s\n", (int)getpid(), LOG_LEVEL_CHARS[level], buf, msg);
}

void log_debug(Logger l, const char *fmt, ...)
{ 
    va_list va;
    va_start(va, fmt);
    log_add(l, LOG_DEBUG, fmt, va);
    va_end(va);
}

void log_info(Logger l, const char *fmt, ...)
{ 
    
    va_list va;
    va_start(va, fmt);
    log_add(l, LOG_INFO, fmt, ...); 
    va_end(va);
}

void log_warn(Logger l, const char *fmt, ...)
{ 
    va_list va;
    va_start(va, fmt);
    log_add(l, LOG_WARN, fmt, ...); 
    va_end(va);
}

void log_error(Logger l, const char *fmt, ...)
{ 
    va_list va;
    va_start(va, fmt);
    log_add(l, LOG_ERROR, fmt, ...); 
    va_end(va);
}

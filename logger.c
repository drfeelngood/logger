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
    if (level < l->level) return;

    time_t meow = time(NULL);
    char buf[64];
    
    strftime(buf, sizeof(buf), l->datetime_format, localtime(&meow));
    printf("[%d] %c, %s : %s\n", (int)getpid(), LOG_LEVEL_CHARS[level], buf, msg);
}

void log_debug(Logger l, const char *fmt, ...)
{ 
    va_list ap;
    char msg[LOG_MAX_MSG_LEN];

    va_start(ap, fmt);
    vsnprintf(msg, sizeof(msg), fmt, ap);
    log_add(l, LOG_DEBUG, msg);
    va_end(ap);
}

void log_info(Logger l, const char *fmt, ...)
{ 
    va_list ap;
    char msg[LOG_MAX_MSG_LEN];
    
    va_start(ap, fmt);
    vsnprintf(msg, sizeof(msg), fmt, ap);
    log_add(l, LOG_INFO, msg); 
    va_end(ap);
}

void log_warn(Logger l, const char *fmt, ...)
{ 
    va_list ap;
    char msg[LOG_MAX_MSG_LEN];
    
    va_start(ap, fmt);
    vsnprintf(msg, sizeof(msg), fmt, ap);
    log_add(l, LOG_WARN, msg); 
    va_end(ap);
}

void log_error(Logger l, const char *fmt, ...)
{ 
    va_list ap;
    char msg[LOG_MAX_MSG_LEN];
    
    va_start(ap, fmt);
    vsnprintf(msg, sizeof(msg), fmt, ap);
    log_add(l, LOG_ERROR, msg); 
    va_end(ap);
}

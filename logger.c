#include "logger.h"

Logger Logger_create()
{
    Logger l;

    l = (Logger) calloc(1, sizeof(Logger) + 1024);
    l->datetime_format = "%Y-%m-%d %H:%M:%S";
    l->level = LOG_INFO;

    return(l);
}

void Logger_destory(Logger l)
{
    free( l );
}
void log_add(Logger l, int level, const char *msg)
{
    const char *c = "DIWEF";
    time_t meow = time( NULL );
    char buf[64];

    if (level < l->level) return;

    strftime( buf, sizeof(buf), l->datetime_format, localtime(&meow) );
    printf( "[%d] %c, %s : %s\n", (int)_getpid(), c[level], buf, msg );
}

void log_debug(Logger l, const char *fmt, ...)
{
    char *msg = l->buf;
    va_list ap;
    va_start( ap, fmt );
    vsprintf_s( msg, 1024, fmt, ap );
    log_add( l, LOG_DEBUG, msg );
    va_end( ap );
}
void log_info(Logger l, const char *fmt, ...)
{ 
    char *msg = l->buf;
    va_list ap;
    va_start( ap, fmt );    
    vsprintf_s( msg, 1024, fmt, ap );
    log_add( l, LOG_INFO, msg );
    va_end( ap );
}
void log_warn(Logger l, const char *fmt, ...)
{ 
    char *msg = l->buf;
    va_list ap;
    va_start( ap, fmt );    
    vsprintf_s( msg, 1024, fmt, ap );
    log_add( l, LOG_WARN, msg );
    va_end( ap );
}
void log_error(Logger l, const char *fmt, ...)
{ 
    char *msg = l->buf;
    va_list ap;
    va_start( ap, fmt ); 
    vsprintf_s( msg, 1024, fmt, ap );   
    log_add( l, LOG_ERROR, msg ); 
    va_end( ap );

}

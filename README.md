# ANSI C Logger [![Build Status](https://secure.travis-ci.org/drfeelngood/logger.png)](http://travis-ci.org/drfeelngood/logger)

Simple library for uniform logging.

```c
int main()
{
    char *foo;
    int bar = 10;

    Logger *l = Logger_create(NULL);
    l->level = LOG_DEBUG;

    log_debug(l, "%d", __LINE__);
    
    log_info(l, "Hello world");

    foo = "Information";
    log_warn(l, "Foo[%-30s] Bar[%d]", foo, bar); 

    log_error(l, "Foo Bar");

    Logger_free(l);
}
```

Prints in stdout:

```
[38493] D, 2012-10-12 09:57:58 : 26
[38493] I, 2012-10-12 09:57:58 : Hello world
[38493] W, 2012-10-12 09:57:58 : Foo[Information                   ] Bar[10]
[38493] E, 2012-10-12 09:57:58 : Foo Bar
```

You can select a file instead of stdout and save the logs to a file with:

```c
...
Logger *l = Logger_create("/tmp/log_file");
...
```

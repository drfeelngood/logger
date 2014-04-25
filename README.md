# logger [![Build Status](https://secure.travis-ci.org/drfeelngood/logger.png)](http://travis-ci.org/drfeelngood/logger)

Simple library for uniform logging.

```c
int main()
{
    char *foo;
    int bar = 10;

    Logger *l = Logger_create();
    l->level = LOG_DEBUG;

    log_debug(l, "%d", __LINE__);
    
    log_info(l, "Hello world");

    foo = "Information";
    log_warn(l, "Foo[%-30s] Bar[%d]", foo, bar); 

    log_error(l, "Foo Bar");

    Logger_free(l);
}

// [38493] D, 2012-10-12 09:57:58 : 26
// [38493] I, 2012-10-12 09:57:58 : Hello world
// [38493] W, 2012-10-12 09:57:58 : Foo[Information                   ] Bar[10]
// [38493] E, 2012-10-12 09:57:58 : Foo Bar
```

#### Options

* **fp** The stream pointer (defaut: stdout)
* **level** Log level (default: LOG_INFO)
* **datetime_format** strftime format string

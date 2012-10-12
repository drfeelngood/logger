# ANSI C Logger

Simple library for uniform logging.

```c
int main()
{
    Logger l = Logger_create();

    log_debug(l, "%d", __LINE__);
    
    log_info(l, "Hello world");

    log_warn(l, "Foo[%-30s] Bar[%d]", foo, bar); 

    log_error(l, "Foo Bar");
}
```

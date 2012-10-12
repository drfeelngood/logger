# ANSI C Logger

Simple library for uniform logging.

```
int main(int argc, char **)
{
    Logger l = Logger_create();

    int x = 0;
    while ( x < 100 ) {
        log_info(l, "log log log");
        x++;
    }
}
```

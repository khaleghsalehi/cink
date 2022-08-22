![Cink Logo](cink.png)

**Cink is a tiny and fast in-memory cache library for embedded systems.**

Supported commands:
```
put(char *key, char *value, long timestamp);
get(char *key);
del(char *key);
```
* How to use:
```
    put("1234567", "sample test here 0", seconds);
    put("1234ABC", "sample test here 1 ", seconds);
    put("1234EFG", "sample test here 2", seconds);
    put("1234EFG", "sample test here 3", seconds);

    syslog(LOG_NOTICE, "{%ld} key available in list", count_cache());

    syslog(LOG_NOTICE, "%s", get("1234567"));
    syslog(LOG_NOTICE, "%s", get("1234ABC"));

    del("1234567");
    del("1234ABC");

    syslog(LOG_NOTICE, "{%ld} key available in list", count_cache());
```
* Example @cink.c
```
 make
 cd build
 ./cink
```
*Cink is under development (for fun)


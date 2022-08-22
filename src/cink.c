#include <pthread.h>
#include <stdio.h>
#include "lib/cink.h"

int main(int argc, char *argv[]) {
    pthread_t p_thread;
    int t_id = 1020;

    // here we start cink service.
    init_background_service();
    pthread_create(&p_thread, NULL, check_ttl, (void *) &t_id);

    time_t seconds;
    seconds = time(NULL);

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

    return 0;
}
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

    put("123456789", "sample test here", seconds);
    syslog(LOG_NOTICE, "%s", get("123456789"));
    return 0;
}